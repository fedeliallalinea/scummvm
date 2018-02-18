/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "bladerunner/actor_walk.h"

#include "bladerunner/bladerunner.h"

#include "bladerunner/actor.h"
#include "bladerunner/game_constants.h"
#include "bladerunner/game_info.h"
#include "bladerunner/obstacles.h"
#include "bladerunner/scene.h"
#include "bladerunner/scene_objects.h"
#include "bladerunner/set.h"

namespace BladeRunner {

ActorWalk::ActorWalk(BladeRunnerEngine *vm) {
	_vm = vm;

	_walking = false;
	_running = false;
	_facing = -1;
	_status = 0;

	_nearActors.clear();
}

ActorWalk::~ActorWalk() {}

bool ActorWalk::setup(int actorId, bool run, const Vector3 &from, const Vector3 &to, bool unk1, bool *arrived) {
	Vector3 next;

	*arrived = false;

	int r = nextOnPath(actorId, from, to, next);

	if (r == 0) {
		if (actorId != 0) {
			_current = from;
			_destination = to;
			stop(actorId, false, kAnimationModeCombatIdle, kAnimationModeIdle);
		} else {
			stop(actorId, true, kAnimationModeCombatIdle, kAnimationModeIdle);
		}
		return false;
	}

	if (r == -1) {
		stop(actorId, true, kAnimationModeCombatIdle, kAnimationModeIdle);
		*arrived = true;
		return false;
	}

	_nearActors.clear();
	_vm->_sceneObjects->setMoving(actorId + kSceneObjectOffsetActors, true);
	_vm->_actors[actorId]->setMoving(true);

	if (_running) {
		run = true;
	}

	int animationMode;
	if (_vm->_actors[actorId]->inCombat()) {
		animationMode = run ? kAnimationModeCombatRun : kAnimationModeCombatWalk;
	} else {
		animationMode = run ? kAnimationModeRun : kAnimationModeWalk;
	}

	_vm->_actors[actorId]->changeAnimationMode(animationMode);

	_destination = to;
	_originalDestination = to;
	_current = from;
	_next = next;

	if (next.x == _current.x && next.z == _current.z) {
		stop(actorId, true, kAnimationModeCombatIdle, kAnimationModeIdle);
		*arrived = true;
		return false;
	}

	_facing = angle_1024(_current, next);
	_walking = true;
	_running = run;
	_status = 2;

	return true;
}

bool ActorWalk::tick(int actorId, float stepDistance, bool inWalkLoop) {
	bool walkboxFound;

	if (_status == 5) {
		if (inWalkLoop) {
			stop(actorId, true, kAnimationModeCombatIdle, kAnimationModeIdle);
			return true;
		}

		if (actorId != 0 && _vm->_rnd.getRandomNumberRng(1, 15) != 1) { // why random?
			return false;
		}
		_status = 3;
	}

	bool nearActorExists = addNearActors(actorId);
	if (_nearActors.size() > 0) {
		nearActorExists = true;
		if (_vm->_sceneObjects->existsOnXZ(actorId + kSceneObjectOffsetActors, _destination.x, _destination.z, true, true)) {
			if (actorId > 0) {
				if (_vm->_actors[actorId]->inWalkLoop()) {
					stop(actorId, true, kAnimationModeCombatIdle, kAnimationModeIdle);
					_nearActors.clear();
					return true;
				} else {
					Vector3 newDestination;
					findNearestEmptyPositionToOriginalDestination(actorId, newDestination);
					_destination = newDestination;
					return false;
				}
			} else {
				if (_vm->_playerActor->inWalkLoop()) {
					_destination = _current;
				}
				stop(0, true, kAnimationModeCombatIdle, kAnimationModeIdle);
				_nearActors.clear();
				return true;
			}
		}
	}
	_status = 3;

	if (stepDistance > distance(_current, _destination)) {
		stop(actorId, true, kAnimationModeCombatIdle, kAnimationModeIdle);
		_current = _destination;
		_current.y = _vm->_scene->_set->getAltitudeAtXZ(_current.x, _current.z, &walkboxFound);
		return true;
	}

	float distanceToNext = distance(_current, _next);
	if (1.0f < distanceToNext) {
		_facing = angle_1024(_current, _next);
	}

	bool nextIsCloseEnough = stepDistance > distanceToNext;

	if (nextIsCloseEnough || nearActorExists || _status == 3) {
		if (nextIsCloseEnough) {
			_current = _next;
		}
		_status = 1;
		Vector3 next;
		obstaclesAddNearActors(actorId);
		int r = nextOnPath(actorId, _current, _destination, next);
		obstaclesRestore();
		if (r == 0) {
			stop(actorId, actorId == 0, kAnimationModeCombatIdle, kAnimationModeIdle);
			return false;
		}
		if (r != -1) {
			_next = next;
			_facing = angle_1024(_current, _next);
			_status = 2;
			int animationMode;
			if (_vm->_actors[actorId]->inCombat()) {
				animationMode = _running ? kAnimationModeCombatRun : kAnimationModeCombatWalk;
			} else {
				animationMode = _running ? kAnimationModeRun : kAnimationModeWalk;
			}
			_vm->_actors[actorId]->changeAnimationMode(animationMode);
			if (nextIsCloseEnough) {
				return false;
			}
		}
	}

	float angle_rad = _facing / 512.0 * M_PI;

	_current.x += stepDistance * sinf(angle_rad);
	_current.z -= stepDistance * cosf(angle_rad);
	_current.y = _vm->_scene->_set->getAltitudeAtXZ(_current.x, _current.z, &walkboxFound);

	return false;
}

void ActorWalk::getCurrentPosition(int actorId, Vector3 *pos, int *facing) const {
	*pos = _current;
	*facing = _facing;
}

void ActorWalk::stop(int actorId, bool immediately, int combatAnimationMode, int animationMode) {
	_vm->_sceneObjects->setMoving(actorId + kSceneObjectOffsetActors, false);
	_vm->_actors[actorId]->setMoving(false);

	if (_vm->_actors[actorId]->inCombat()) {
		_vm->_actors[actorId]->changeAnimationMode(combatAnimationMode, false);
	} else {
		_vm->_actors[actorId]->changeAnimationMode(animationMode, false);
	}

	if (immediately) {
		_walking = false;
		_running = false;
		_status = 0;
	} else {
		_walking = true;
		_running = false;
		_status = 5;
	}
}

void ActorWalk::run(int actorId) {
	_running = true;

	int animationMode = kAnimationModeRun;
	if (_vm->_actors[actorId]->inCombat()) {
		animationMode = kAnimationModeCombatRun;
	}
	_vm->_actors[actorId]->changeAnimationMode(animationMode, false);
}

bool ActorWalk::isXYZEmpty(float x, float y, float z, int actorId) const {
	if (_vm->_scene->_set->findWalkbox(x, z) == -1) {
		return true;
	}
	if (_vm->_actors[actorId]->isImmuneToObstacles()) {
		return false;
	}
	return _vm->_sceneObjects->existsOnXZ(actorId + kSceneObjectOffsetActors, x, z, false, false);
}

bool ActorWalk::findNearestEmptyPosition(int actorId, const Vector3 &destination, int dist, Vector3 &out) const {
	bool inWalkbox;

	int facingToMinDistance = -1;
	float minDistance = -1.0f;
	float x = 0.0f;
	float z = 0.0f;

	out.x = 0.0f;
	out.y = 0.0f;
	out.z = 0.0f;

	for (int facing = 0; facing < 1024; facing += 128) {
		x = destination.x + sin_1024(facing) * dist;
		z = destination.z - cos_1024(facing) * dist;
		float distanceBetweenActorAndDestination = distance(x, z, _vm->_actors[actorId]->getX(), _vm->_actors[actorId]->getZ());

		if (minDistance == -1.0f || minDistance > distanceBetweenActorAndDestination) {
			minDistance = distanceBetweenActorAndDestination;
			facingToMinDistance = facing;
		}
	}

	int facingLeft = facingToMinDistance;
	int facingRight = facingToMinDistance;
	int facing = -1024;
	while (facing < 0) {
		x = destination.x + sin_1024(facingRight) * dist;
		z = destination.z - cos_1024(facingRight) * dist;

		if (!_vm->_sceneObjects->existsOnXZ(actorId + kSceneObjectOffsetActors, x, z, true, true) && _vm->_scene->_set->findWalkbox(x, z) >= 0) {
			break;
		}

		x = destination.x + sin_1024(facingLeft) * dist;
		z = destination.z - cos_1024(facingLeft) * dist;

		if (!_vm->_sceneObjects->existsOnXZ(actorId + kSceneObjectOffsetActors, x, z, true, true) && _vm->_scene->_set->findWalkbox(x, z) >= 0) {
			break;
		}

		facingRight -= 64;
		if (facingRight < 0) {
			facingRight += 1024;
		}
		facingLeft += 64;
		if (facingLeft >= 1024) {
			facingLeft -= 1024;
		}
		facing += 64;
	}

	float y = _vm->_scene->_set->getAltitudeAtXZ(x, z, &inWalkbox);
	if (inWalkbox) {
		out.x = x;
		out.y = y;
		out.z = z;
		return true;
	}
	return false;
}

bool ActorWalk::findNearestEmptyPositionToOriginalDestination(int actorId, Vector3 &out) const {
	return findNearestEmptyPosition(actorId, _originalDestination, 30, out);
}

bool ActorWalk::addNearActors(int skipActorId) {
	bool added = false;
	int setId = _vm->_scene->getSetId();
	for (int i = 0; i < (int)_vm->_gameInfo->getActorCount(); i++) {
		// TODO: remove null check after implemetantion of all actors
		if (_vm->_actors[i] != nullptr
			&& _vm->_actors[skipActorId] != nullptr
			&& _vm->_actors[i]->getSetId() == setId
			&& i != skipActorId) {

			if (_nearActors.contains(i)) {
				_nearActors.setVal(i, false);
			} else if (_vm->_actors[skipActorId]->distanceFromActor(i) <= 48.0f) {
				_nearActors.setVal(i, true);
				added = true;
			}
		}
	}
	return added;
}

void ActorWalk::obstaclesAddNearActors(int actorId) const {
	Vector3 position = _vm->_actors[actorId]->getPosition();
	for (Common::HashMap<int, bool>::const_iterator it = _nearActors.begin(); it != _nearActors.end(); ++it) {
		Actor *otherActor = _vm->_actors[it->_key];
		// TODO: remove null check after implemetantion of all actors
		if (otherActor == nullptr || otherActor->isRetired()) {
			continue;
		}
		Vector3 otherPosition = otherActor->getPosition();
		float x0 = otherPosition.x - 12.0f;
		float z0 = otherPosition.z - 12.0f;
		float x1 = otherPosition.x + 12.0f;
		float z1 = otherPosition.z + 12.0f;
		if (position.x < (x0 - 12.0f) || position.z < (z0 - 12.0f) || position.x > (x1 + 12.0f) || position.z > (z1 + 12.0f)) {
			_vm->_obstacles->add(x0, z0, x1, z1);
		}
	}
}

void ActorWalk::obstaclesRestore() const {
	_vm->_obstacles->restore();
}

int ActorWalk::nextOnPath(int actorId, const Vector3 &from, const Vector3 &to, Vector3 &next) const {
	next = from;

	if (distance(from, to) < 6.0) {
		return -1;
	}

	if (_vm->_actors[actorId]->isImmuneToObstacles()) {
		next = to;
		return 1;
	}
	if (_vm->_scene->_set->findWalkbox(to.x, to.z) == -1) {
		return 0;
	}
	if (_vm->_sceneObjects->existsOnXZ(actorId + kSceneObjectOffsetActors, to.x, to.z, false, false)) {
		return 0;
	}
	Vector3 next1;
	if (_vm->_obstacles->find(from, to, &next1)) {
		next = next1;
		return 1;
	}
	return 0;
}

} // End of namespace BladeRunner
