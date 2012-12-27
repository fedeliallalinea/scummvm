#ifndef XEEN_MAZE_SOURCE
# error "Private header included"
#endif

enum DRAWID
{
    SKY_TOP, SKY_BOTTOM, GROUND,
    
    SURF00, SURF01, SURF02, SURF03, SURF04, SURF05, SURF06, SURF07, SURF08,
    SURF09, SURF10, SURF11, SURF12, SURF13, SURF14, SURF15, SURF16,
    SURF17, SURF18, SURF19, SURF20, SURF21, SURF22, SURF23, SURF24,
    
    // WALLS FACING TO CAMERA
    FWALL_DISTANT,
    FWALL_4_4L, FWALL_4_3L, FWALL_4_2L, FWALL_4_1L, FWALL_4_CEN, FWALL_4_1R, FWALL_4_2R, FWALL_4_3R, FWALL_4_4R,
    FWALL_3_2L, FWALL_3_1L, FWALL_3_CEN, FWALL_3_1R, FWALL_3_2R,
    FWALL_2_1L, FWALL_2_CEN, FWALL_2_1R,
    FWALL_1_1L, FWALL_1_CEN, FWALL_1_1R,
    FWALL_0_1L, FWALL_0_CEN, FWALL_0_1R,
    
    // WALLS PERPENDICULAR TO CAMERA
    SWALL_4_4L, SWALL_4_3L, SWALL_4_2L, SWALL_4_1L, SWALL_4_1R, SWALL_4_2R, SWALL_4_3R, SWALL_4_4R,    
    SWALL_3_4L, SWALL_3_3L, SWALL_3_2L, SWALL_3_1L, SWALL_3_1R, SWALL_3_2R, SWALL_3_3R, SWALL_3_4R,
    SWALL_2_2L, SWALL_2_1L, SWALL_2_1R, SWALL_2_2R,
    SWALL_1_1L, SWALL_1_1R,
    SWALL_0_1L, SWALL_0_1R,
    
    // OBJECTS
    OBJ_1_1L, OBJ_1_CEN, OBJ_1_1R,
    OBJ_2_1L, OBJ_2_CEN, OBJ_2_1R,
    OBJ_3_2L, OBJ_3_1L, OBJ_3_CEN, OBJ_3_1R, OBJ_3_2R,

    OBJ_HERE,
    
    XXX
};

struct DrawListItem
{
    DRAWID id;
    uint16 sprite;      //< The CCFileId of the sprite to draw
    uint8 frame;        //< Sprite cell index to draw
    uint16 count;
    int16 x;            //< X position to draw at
    int16 y;            //< Y position to draw at
    uint16 scale;       //< ?
    uint16 flags;       //< ?
        
    // The draw sprite is flipped horizontally.
    bool flipped() const { return flags & 0x8000; }
    void setFlipped(bool state) { flags &= ~0x8000; flags |= (state) ? 0x8000 : 0; }
};

DrawListItem outdoorDrawList[] = 
{
    {SKY_TOP,      0xFFFF,      0, 0,     8,      8,      0, 0x0000},
    {SKY_BOTTOM,   0xFFFF,      1, 0,      8,     25,      0, 0x0000},
    {GROUND,       0xFFFF,      0, 0,      8,     67,      0, 0x0000},
    {SURF00,       0xFFFF,     18, 0,      8,     67,      0, 0x0000},
    {SURF01,       0xFFFF,     19, 0,     38,     67,      0, 0x0000},
    {SURF02,       0xFFFF,     20, 0,     84,     67,      0, 0x0000},
    {SURF03,       0xFFFF,     24, 0,    134,     67,      0, 0x0000},
    {SURF04,       0xFFFF,     23, 0,    117,     67,      0, 0x0000},
    {SURF05,       0xFFFF,     22, 0,    117,     67,      0, 0x0000},
    {SURF06,       0xFFFF,     21, 0,    103,     67,      0, 0x0000},
    {SURF07,       0xFFFF,     11, 0,      8,     73,      0, 0x0000},
    {SURF08,       0xFFFF,     12, 0,      8,     73,      0, 0x0000},
    {SURF09,       0xFFFF,     13, 0,     30,     73,      0, 0x0000},
    {SURF10,       0xFFFF,     17, 0,    181,     73,      0, 0x0000},
    {SURF11,       0xFFFF,     16, 0,    154,     73,      0, 0x0000},
    {SURF12,       0xFFFF,     15, 0,    129,     73,      0, 0x0000},
    {SURF13,       0xFFFF,     14, 0,     87,     73,      0, 0x0000},
    {SURF14,       0xFFFF,      6, 0,      8,     81,      0, 0x0000},
    {SURF15,       0xFFFF,      7, 0,      8,     81,      0, 0x0000},
    {SURF16,       0xFFFF,     10, 0,    202,     81,      0, 0x0000},
    {SURF17,       0xFFFF,      9, 0,    145,     81,      0, 0x0000},
    {SURF18,       0xFFFF,      8, 0,     63,     81,      0, 0x0000},
    {SURF19,       0xFFFF,      3, 0,      8,     93,      0, 0x0000},
    {SURF20,       0xFFFF,      5, 0,    169,     93,      0, 0x0000},
    {SURF21,       0xFFFF,      4, 0,     31,     93,      0, 0x0000},
    {SURF22,       0xFFFF,      0, 0,      8,    109,      0, 0x0000},
    {SURF23,       0xFFFF,      2, 0,    201,    109,      0, 0x0000},
    {SURF24,       0xFFFF,      1, 0,      8,    109,      0, 0x0000},

    {FWALL_4_4L,   0xFFFF,      1, 0,    -64,     61,     14, 0x2000},
    {FWALL_4_3L,   0xFFFF,      1, 0,    -40,     61,     14, 0x0000},
    {FWALL_4_2L,   0xFFFF,      1, 0,    -16,     61,     14, 0x0000},
    {FWALL_4_1L,   0xFFFF,      1, 0,      8,     61,     14, 0x0000},
    {FWALL_4_4R,   0xFFFF,      1, 0,    128,     61,     14, 0xA000},
    {FWALL_4_3R,   0xFFFF,      1, 0,    104,     61,     14, 0x8000},
    {FWALL_4_2R,   0xFFFF,      1, 0,     80,     61,     14, 0x8000},
    {FWALL_4_1R,   0xFFFF,      1, 0,     56,     61,     14, 0x8000},
    {FWALL_4_CEN,  0xFFFF,      1, 0,     32,     61,     14, 0x0000},
    {OBJ_3_CEN,    0xFFFF,      0, 0,     -9,     61,     14, 0x0000},
    {OBJ_3_1L,     0xFFFF,      0, 0,    -58,     61,     14, 0x0000},
    {OBJ_3_1R,     0xFFFF,      0, 0,     40,     61,     14, 0x0000},
    {OBJ_3_2L,     0xFFFF,      0, 0,    -82,     61,     14, 0x0000},
    {OBJ_3_2R,     0xFFFF,      0, 0,     64,     61,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,    -41,     61,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,    -26,     61,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,    -34,     61,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,    -16,     61,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,     23,     61,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,     16,     61,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,    -58,     61,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,     40,     61,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,    -17,     61,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,     -1,     58,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,     -9,     58,     14, 0x0000},
    {XXX,          0xFFFF,      0, 0,     72,     58,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,     72,     58,     12, 0x8000},
    {XXX,          0xFFFF,      0, 0,     69,     63,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,     75,     63,     12, 0x8000},
    {XXX,          0xFFFF,      0, 0,     73,     53,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,     71,     53,     12, 0x8000},
    {XXX,          0xFFFF,      0, 0,     80,     57,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,     64,     57,     12, 0x8000},
    {FWALL_3_2L,   0xFFFF,      2, 0,    -11,     54,      8, 0x0000},
    {FWALL_3_1L,   0xFFFF,      1, 0,    -21,     54,     11, 0x0000},
    {FWALL_3_2R,   0xFFFF,      2, 0,    165,     54,      8, 0x8000},
    {FWALL_3_1R,   0xFFFF,      1, 0,     86,     54,     11, 0x8000},
    {FWALL_3_CEN,  0xFFFF,      1, 0,     33,     54,     11, 0x0000},
    {OBJ_2_CEN,    0xFFFF,      0, 0,     -8,     54,     12, 0x0000},
    {OBJ_2_1L,     0xFFFF,      0, 0,    -73,     54,     12, 0x0000},
    {OBJ_2_1R,     0xFFFF,      0, 0,     57,     54,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,    -65,     54,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,    -81,     54,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,     49,     54,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,     65,     54,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,    -24,     54,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,      9,     50,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,     -8,     50,     12, 0x0000},
    {XXX,          0xFFFF,      0, 0,     72,     53,      8, 0x0000},
    {XXX,          0xFFFF,      0, 0,     72,     53,      8, 0x8000},
    {XXX,          0xFFFF,      0, 0,     77,     58,      8, 0x0000},
    {XXX,          0xFFFF,      0, 0,     67,     58,      8, 0x8000},
    {XXX,          0xFFFF,      0, 0,     81,     47,      8, 0x0000},
    {XXX,          0xFFFF,      0, 0,     63,     47,      8, 0x8000},
    {XXX,          0xFFFF,      0, 0,     94,     52,      8, 0x0000},
    {XXX,          0xFFFF,      0, 0,     50,     52,      8, 0x8000},
    {FWALL_2_1L,   0xFFFF,      2, 0,      8,     40,      0, 0x0000},
    {FWALL_2_1R,   0xFFFF,      2, 0,    146,     40,      0, 0x8000},
    {FWALL_2_CEN,  0xFFFF,      1, 0,     32,     40,      6, 0x0000},
    {OBJ_1_CEN,    0xFFFF,      0, 0,     -7,     30,      7, 0x0000},
    {OBJ_1_1L,     0xFFFF,      0, 0,   -112,     30,      7, 0x2000},
    {OBJ_1_1R,     0xFFFF,      0, 0,     98,     30,      7, 0x2000},
    {XXX,          0xFFFF,      0, 0,   -112,     30,      8, 0x2000},
    {XXX,          0xFFFF,      0, 0,     98,     30,      8, 0x2000},
    {XXX,          0xFFFF,      0, 0,    -38,     30,      8, 0x0000},
    {XXX,          0xFFFF,      0, 0,     25,     30,      8, 0x0000},
    {XXX,          0xFFFF,      0, 0,     -7,     30,      8, 0x0000},
    {XXX,          0xFFFF,      0, 0,     72,     48,      4, 0x0000},
    {XXX,          0xFFFF,      0, 0,     72,     48,      4, 0x8000},
    {XXX,          0xFFFF,      0, 0,     85,     53,      4, 0x0000},
    {XXX,          0xFFFF,      0, 0,     59,     53,      4, 0x8000},
    {XXX,          0xFFFF,      0, 0,     89,     41,      4, 0x0000},
    {XXX,          0xFFFF,      0, 0,     55,     41,      4, 0x8000},
    {XXX,          0xFFFF,      0, 0,    106,     47,      4, 0x0000},
    {XXX,          0xFFFF,      0, 0,     38,     47,      4, 0x8000},
    {FWALL_1_1L,   0xFFFF,      0, 0,      8,     24,      0, 0x0000},
    {FWALL_1_1R,   0xFFFF,      0, 0,    169,     24,      0, 0x8000},
    {FWALL_1_CEN,  0xFFFF,      1, 0,     32,     24,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,    -23,     40,      0, 0x2000},
    {XXX,          0xFFFF,      0, 0,    200,     40,      0, 0xA000},
    {FWALL_0_1L,   0xFFFF,      0, 0,      8,     47,      0, 0x0000},
    {FWALL_0_1R,   0xFFFF,      0, 0,    169,     47,      0, 0x8000},
    {FWALL_0_CEN,  0xFFFF,      1, 0,    -56,     -4,  32768, 0x6000},
    {OBJ_HERE,     0xFFFF,      0, 0,     -5,      2,      0, 0x6000},
    {XXX,          0xFFFF,      0, 0,    -67,      2,      0, 0x6000},
    {XXX,          0xFFFF,      0, 0,     44,     73,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,     44,     73,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,     58,     14,      0, 0x6000},
    {XXX,          0xFFFF,      0, 0,    169,     73,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,    169,     73,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,     -5,     14,      0, 0x6000},
    {XXX,          0xFFFF,      0, 0,    110,     73,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,    110,     73,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,     -5,     14,      0, 0x6000},
    {XXX,          0xFFFF,      0, 0,    110,     73,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,    110,     73,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,     72,     43,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,     72,     43,      0, 0x8000},
    {XXX,          0xFFFF,      0, 0,     93,     48,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,     51,     48,      0, 0x8000},
    {XXX,          0xFFFF,      0, 0,     97,     36,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,     47,     36,      0, 0x8000},
    {XXX,          0xFFFF,      0, 0,    118,     42,      0, 0x0000},
    {XXX,          0xFFFF,      0, 0,     26,     42,      0, 0x8000}
};

DrawListItem* outdoorDrawIndex[XXX];

void buildOutdoorDrawIndex()
{
    for(int i = 0; i != XXX; i ++)
    {
        for(int j = 0; j != sizeof(outdoorDrawList) / sizeof(outdoorDrawList[0]); j ++)
        {
            if(outdoorDrawList[j].id == (DRAWID)i)
            {
                outdoorDrawIndex[i] = &outdoorDrawList[j];
                break;
            }
        }
    }
}


DrawListItem indoorDrawList[] =
{
    // ENVIRONMENT
    {SKY_TOP,        0xFFFF,     0, 0,  8,      8,      0,     0x0000}, //Top half of sky
    {SKY_BOTTOM,     0xFFFF,     1, 0,  8,      25,     0,     0x0000}, //Bottom half of sky
    {GROUND,         0xFFFF,     0, 0,  8,      67,     0,     0x0000}, //Ground

    // SURFACE
    {SURF00,         0xFFFF,     18, 0, 8,      67,     0,     0x0000}, //Surface tile 4 steps forward, 3 steps left
    {SURF01,         0xFFFF,     19, 0, 38,     67,     0,     0x0000}, //Surface tile 4 steps forward, 2 steps left
    {SURF02,         0xFFFF,     20, 0, 84,     67,     0,     0x0000}, //Surface tile 4 steps forward, 1 steps left
    {SURF03,         0xFFFF,     24, 0, 134,    67,     0,     0x0000}, //Surface tile 4 steps forward, 3 steps right
    {SURF04,         0xFFFF,     23, 0, 117,    67,     0,     0x0000}, //Surface tile 4 steps forward, 2 steps right
    {SURF05,         0xFFFF,     22, 0, 117,    67,     0,     0x0000}, //Surface tile 4 steps forward, 1 steps right
    {SURF06,         0xFFFF,     21, 0, 103,    67,     0,     0x0000}, //Surface tile directly 4 steps forward
    {SURF07,         0xFFFF,     11, 0, 8,      73,     0,     0x0000}, //Surface tile 3 steps forward, 3 steps left
    {SURF08,         0xFFFF,     12, 0, 8,      73,     0,     0x0000}, //Surface tile 3 steps forward, 2 steps left
    {SURF09,         0xFFFF,     13, 0, 30,     73,     0,     0x0000}, //Surface tile 3 steps forward, 1 steps left
    {SURF10,         0xFFFF,     17, 0, 181,    73,     0,     0x0000}, //Surface tile 3 steps forward, 3 steps right
    {SURF11,         0xFFFF,     16, 0, 154,    73,     0,     0x0000}, //Surface tile 3 steps forward, 2 steps right
    {SURF12,         0xFFFF,     15, 0, 129,    73,     0,     0x0000}, //Surface tile 3 steps forward, 1 steps right
    {SURF13,         0xFFFF,     14, 0, 87,     73,     0,     0x0000}, //Surface tile directly 3 steps forward
    {SURF14,         0xFFFF,     6,  0, 8,      81,     0,     0x0000}, //Surface tile 2 steps forward, 2 left
    {SURF15,         0xFFFF,     7,  0, 8,      81,     0,     0x0000}, //Surface tile 2 steps forward, 1 left
    {SURF16,         0xFFFF,     10, 0, 202,    81,     0,     0x0000}, //Surface tile 2 steps forward, 2 right
    {SURF17,         0xFFFF,     9,  0, 145,    81,     0,     0x0000}, //Surface tile 2 steps forward, 1 right
    {SURF18,         0xFFFF,     8,  0,63,     81,     0,     0x0000}, //Surface tile directly 2 steps forward
    {SURF19,         0xFFFF,     3,  0, 8,      93,     0,     0x0000}, //Surface tile 1 step forward, 1 left
    {SURF20,         0xFFFF,     5,  0, 169,    93,     0,     0x0000}, //Surface tile 1 step forward, 1 right
    {SURF21,         0xFFFF,     4,  0, 31,     93,     0,     0x0000}, //Surface tile directly 1 step forward
    {SURF22,         0xFFFF,     0,  0, 8,      109,    0,     0x0000}, //Surface tile directly 1 step left
    {SURF23,         0xFFFF,     2,  0, 201,    109,    0,     0x0000}, //Surface tile directly 1 step right
    {SURF24,         0xFFFF,     1,  0, 8,      109,    0,     0x0000}, //Surface tile player is currently on
    
    //
    {FWALL_DISTANT,  0xFFFF, 7, 0,  8,      64,     0,     0x0000}, //Far distant wall
    
    // DISTANCE: 4
    {SWALL_4_4L, 0xFFFF,     22, 0, 32,     60,     0,     0x0000}, //Side wall for tile 4 steps forward, 4 steps left
    {SWALL_4_3L, 0xFFFF,     20, 0, 56,     60,     0,     0x0000}, //Side wall for tile 4 steps forward, 3 steps left
    {SWALL_4_2L, 0xFFFF,     18, 0, 80,     60,     0,     0x0000}, //Side wall for tile 4 steps forward, 2 steps left
    {SWALL_4_1L, 0xFFFF,     16, 0, 104,    60,     0,     0x0000}, //Side wall for tile 4 steps forward, 1 steps left
    {SWALL_4_4R, 0xFFFF,     23, 0, 152,    60,     0,     0x8000}, //Side wall for tile 4 steps forward, 4 steps right
    {SWALL_4_3R, 0xFFFF,     21, 0, 144,    60,     0,     0x8000}, //Side wall for tile 4 steps forward, 3 steps right
    {SWALL_4_2R, 0xFFFF,     19, 0, 131,    60,     0,     0x8000}, //Side wall for tile 4 steps forward, 2 steps right
    {SWALL_4_1R, 0xFFFF,     17, 0, 120,    60,     0,     0x8000}, //Side wall for tile 4 steps forward, 1 steps right
    {FWALL_4_4L, 0xFFFF,     14, 0, 8,      60,     0,     0x0000}, //Facing wall for tile 4 steps forward, 4 steps left
    {FWALL_4_3L, 0xFFFF,     12, 0, 32,     60,     0,     0x0000}, //Facing wall for tile 4 steps forward, 3 steps left
    {FWALL_4_2L, 0xFFFF,     10, 0, 56,     60,     0,     0x0000}, //Facing wall for tile 4 steps forward, 2 steps left
    {FWALL_4_1L, 0xFFFF,     14, 0, 80,     60,     0,     0x0000}, //Facing wall for tile 4 steps forward, 1 steps left
    {FWALL_4_CEN,0xFFFF,     14, 0, 104,    60,     0,     0x0000}, //Facing wall for tile directly 4 steps forward
    {FWALL_4_1R, 0xFFFF,     14, 0, 128,    60,     0,     0x0000}, //Facing wall for tile 4 steps forward, 1 steps right
    {FWALL_4_2R, 0xFFFF,     14, 0, 152,    60,     0,     0x0000}, //Facing wall for tile 4 steps forward, 2 steps right
    {FWALL_4_3R, 0xFFFF,     8,  0, 176,    60,     0,     0x0000}, //Facing wall for tile 4 steps forward, 3 steps right
    {FWALL_4_4R, 0xFFFF,     8,  0, 200,    60,     0,     0x0000}, //Facing wall for tile 4 steps forward, 4 steps right
    
    {XXX,        0xFFFF,     0,  0, -64,    61,     14,    0x0000},
    {XXX,        0xFFFF,     0,  0, -40,    61,     14,    0x0000},
    {XXX,        0xFFFF,     0,  0, -16,    61,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 8,      61,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 32,     61,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 56,     61,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 80,     61,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 104,    61,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 128,    61,     14,    0x0000},    
    {OBJ_3_CEN,  0xFFFF,     0,  0, -9,     58,     14,    0x0000},    
    {OBJ_3_1L,   0xFFFF,     0,  0, -34,    58,     14,    0x0000},    
    {OBJ_3_1R,   0xFFFF,     0,  0, 16,     58,     14,    0x0000},    
    {OBJ_3_2L,   0xFFFF,     0,  0, -58,    58,     14,    0x0000},    
    {OBJ_3_2R,   0xFFFF,     0,  0, 40,     58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -41,    58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -26,    58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -34,    58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -16,    58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 23,     58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 16,     58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -58,    58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 40,     58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -17,    58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -1,     58,     14,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -9,     58,     14,    0x0000},
    
    // DISTANCE: 3
    {SWALL_3_4L, 0xFFFF,     14, 0, 8,      58,     0,     0x0000}, //Side wall for tile 3 steps forward, 4 steps left
    {SWALL_3_3L, 0xFFFF,     12, 0, 8,      55,     0,     0x0000}, //Side wall for tile 3 steps forward, 3 steps left
    {SWALL_3_2L, 0xFFFF,     10, 0, 32,     52,     0,     0x0000}, //Side wall for tile 3 steps forward, 2 steps left
    {SWALL_3_1L, 0xFFFF,     8,  0, 88,     52,     0,     0x0000}, //Side wall for tile 3 steps forward, 1 steps left
    {SWALL_3_1R, 0xFFFF,     8,  0, 128,    52,     0,     0x8000}, //Side wall for tile 3 steps forward, 1 steps right
    {SWALL_3_2R, 0xFFFF,     10, 0, 152,    52,     0,     0x8000}, //Side wall for tile 3 steps forward, 2 steps right        
    {SWALL_3_3R, 0xFFFF,     12, 0, 176,    55,     0,     0x8000}, //Side wall for tile 3 steps forward, 3 steps right        
    {SWALL_3_4R, 0xFFFF,     14, 0, 200,    58,     0,     0x8000}, //Side wall for tile 3 steps forward, 4 steps right        
    {XXX,        0xFFFF,     0,  0, 72,     58,     12,    0x0000}, //POW? sprite 4 steps forward
    {XXX,        0xFFFF,     0,  0, 72,     58,     12,    0x8000}, //POW? sprite 4 steps forward
    {XXX,        0xFFFF,     0,  0, 69,     63,     12,    0x0000}, //POW? sprite 4 steps forward
    {XXX,        0xFFFF,     0,  0, 75,     63,     12,    0x8000}, //POW? sprite 4 steps forward
    {XXX,        0xFFFF,     0,  0, 73,     53,     12,    0x0000}, //POW? sprite 4 steps forward
    {XXX,        0xFFFF,     0,  0, 71,     53,     12,    0x8000}, //POW? sprite 4 steps forward
    {XXX,        0xFFFF,     0,  0, 80,     57,     12,    0x0000}, //POW? sprite 4 steps forward
    {XXX,        0xFFFF,     0,  0, 64,     57,     12,    0x8000}, //POW? sprite 4 steps forward
    {FWALL_3_2L, 0xFFFF,     7,  0, -24,    52,     0,     0x2000}, //Facing wall for tile 3 steps forward, 2 steps left
    {FWALL_3_1L, 0xFFFF,     7,  0, 32,     52,     0,     0x0000}, //Facing wall for tile 3 steps forward, 1 step left
    {FWALL_3_CEN,0xFFFF,     7,  0, 88,     52,     0,     0x0000}, //Facing wall for tile directly 3 steps forward
    {FWALL_3_1R, 0xFFFF,     0,  0, 144,    52,     0,     0x0000}, //Facing wall for tile 3 steps forward, 1 step right
    {FWALL_3_2R, 0xFFFF,     0,  0, 200,    52,     0,     0x2000}, //Facing wall for tile 3 steps forward, 2 steps right
    {XXX,        0xFFFF,     0,  0, -79,    52,     11,    0x2000},    
    {XXX,        0xFFFF,     0,  0, -27,    52,     11,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 32,     52,     11,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 89,     52,     11,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 145,    52,     11,    0x2000},    
    {OBJ_2_CEN,  0xFFFF,     0,  0, -8,     50,     12,    0x0000},    
    {OBJ_2_1L,   0xFFFF,     0,  0, -65,    50,     12,    0x0000},    
    {OBJ_2_1R,   0xFFFF,     0,  0, 49,     50,     12,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -65,    50,     12,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -81,    50,     12,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 49,     50,     12,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 65,     50,     12,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -24,    50,     12,    0x0000},    
    {XXX,        0xFFFF,     0,  0, 9,      50,     12,    0x0000},    
    {XXX,        0xFFFF,     0,  0, -8,     50,     12,    0x0000},    
    
    // DISTANCE: 2
    {SWALL_2_2L, 0xFFFF,     6, 0,  8,      48,     0,     0x0000}, //Side wall for tile 2 steps forward, 2 steps left
    {SWALL_2_1L, 0xFFFF,     4, 0,  64,     40,     0,     0x0000}, //Side wall for tile 2 steps forward, 1 steps left
    {SWALL_2_1R, 0xFFFF,     4, 0,  144,    40,     0,     0x8000}, //Side wall for tile 2 steps forward, 1 steps right
    {SWALL_2_2R, 0xFFFF,     6, 0,  200,    48,     0,     0x8000}, //Side wall for tile 2 steps forward, 2 steps right
    {XXX,        0xFFFF,     0, 0,  72,     53,     8,     0x0000}, //POW? sprite 3 steps forward
    {XXX,        0xFFFF,     0, 0,  72,     53,     8,     0x8000}, //POW? sprite 3 steps forward
    {XXX,        0xFFFF,     0, 0,  77,     58,     8,     0x0000}, //POW? sprite 3 steps forward
    {XXX,        0xFFFF,     0, 0,  67,     58,     8,     0x8000}, //POW? sprite 3 steps forward
    {XXX,        0xFFFF,     0, 0,  81,     47,     8,     0x0000}, //POW? sprite 3 steps forward
    {XXX,        0xFFFF,     0, 0,  63,     47,     8,     0x8000}, //POW? sprite 3 steps forward
    {XXX,        0xFFFF,     0, 0,  94,     52,     8,     0x0000}, //POW? sprite 3 steps forward
    {XXX,        0xFFFF,     0, 0,  50,     52,     8,     0x8000}, //POW? sprite 3 steps forward
    {FWALL_2_1L, 0xFFFF,     6, 0,  -40,    40,     0,     0x2000}, //Facing wall for tile 2 steps forward, 1 step left
    {FWALL_2_CEN,0xFFFF,     6, 0,  64,     40,     0,     0x0000}, //Facing wall for tile directly 2 steps forward
    {FWALL_2_1R, 0xFFFF,     0, 0,  168,    40,     0,     0x2000}, //Facing wall for tile 2 steps forward, 1 step right
    {XXX,        0xFFFF,     0, 0,  -72,    40,     6,     0x2000},    
    {XXX,        0xFFFF,     0, 0,  32,     40,     6,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  137,    40,     6,     0x2000},    
    {OBJ_1_CEN,  0xFFFF,     0, 0,  -7,     25,     7,     0x0000},
    {OBJ_1_1L,   0xFFFF,     0, 0,  -112,   25,     7,     0x2000},    
    {OBJ_1_1R,   0xFFFF,     0, 0,  98,     25,     7,     0x2000},    
    {XXX,        0xFFFF,     0, 0,  -112,   29,     8,     0x2000},    
    {XXX,        0xFFFF,     0, 0,  98,     29,     8,     0x2000},    
    {XXX,        0xFFFF,     0, 0,  -38,    29,     8,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  25,     29,     8,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  -7,     29,     8,     0x0000},    
    
    // DISTANCE: 1
    {SWALL_1_1L, 0xFFFF,     2, 0,  32,     24,     0,     0x0000}, //Side wall for tile 1 step forward, 1 steps left
    {SWALL_1_1R, 0xFFFF,     2, 0,  168,    24,     0,     0x8000}, //Side wall for tile 1 step forward, 1 steps right
    {XXX,        0xFFFF,     0, 0,  72,     48,     4,     0x0000}, //POW? sprite 2 steps forward
    {XXX,        0xFFFF,     0, 0,  72,     48,     4,     0x8000}, //POW? sprite 2 steps forward
    {XXX,        0xFFFF,     0, 0,  85,     53,     4,     0x0000}, //POW? sprite 2 steps forward
    {XXX,        0xFFFF,     0, 0,  59,     53,     4,     0x8000}, //POW? sprite 2 steps forward
    {XXX,        0xFFFF,     0, 0,  89,     41,     4,     0x0000}, //POW? sprite 2 steps forward
    {XXX,        0xFFFF,     0, 0,  55,     41,     4,     0x8000}, //POW? sprite 2 steps forward
    {XXX,        0xFFFF,     0, 0,  106,    47,     4,     0x0000}, //POW? sprite 2 steps forward
    {XXX,        0xFFFF,     0, 0,  38,     47,     4,     0x8000}, //POW? sprite 2 steps forward
    {FWALL_1_1L, 0xFFFF,     0, 0,  -136,   24,     0,     0x2000}, //Facing wall for tile 1 step forward, 1 step left


    
    // DISTANCE: 0
    {SWALL_0_1L, 0xFFFF,     0, 0,  8,      12,     0,     0x0000}, //Side wall for tile directly 1 step left    
    {FWALL_1_CEN,0xFFFF,     0, 0,  32,     24,     0,     0x0000}, //Facing wall for tile directly 1 step forward    
    {SWALL_0_1R, 0xFFFF,     0, 0,  200,    12,     0,     0x8000}, //Side wall for tile directly 1 step right    
    {FWALL_1_1R, 0xFFFF,     0, 0,  200,    24,     0,     0x2000}, //Facing wall for tile 1 step forward, 1 step right    
    {XXX,        0xFFFF,     0, 0,  32,     24,     0,     0x0000},    
    {OBJ_HERE,   0xFFFF,     0, 0,  -5,     2,      0,     0x6000}, // Object in same tile as player
    {XXX,        0xFFFF,     0, 0,  -67,    10,     0,     0x6000},    
    {XXX,        0xFFFF,     0, 0,  44,     73,     0,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  44,     73,     0,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  58,     14,     0,     0x6000},    
    {XXX,        0xFFFF,     0, 0,  169,    73,     0,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  169,    73,     0,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  -5,     14,     0,     0x6000},    
    {XXX,        0xFFFF,     0, 0,  110,    73,     0,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  110,    73,     0,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  -5,     14,     0,     0x6000},    
    {XXX,        0xFFFF,     0, 0,  110,    73,     0,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  110,    73,     0,     0x0000},    
    {XXX,        0xFFFF,     0, 0,  72,     43,     0,     0x0000}, //POW? sprite 1 steps forward
    {XXX,        0xFFFF,     0, 0,  72,     43,     0,     0x8000}, //POW? sprite 1 steps forward
    {XXX,        0xFFFF,     0, 0,  93,     48,     0,     0x0000}, //POW? sprite 1 steps forward
    {XXX,        0xFFFF,     0, 0,  51,     48,     0,     0x8000}, //POW? sprite 1 steps forward
    {XXX,        0xFFFF,     0, 0,  97,     36,     0,     0x0000}, //POW? sprite 1 steps forward
    {XXX,        0xFFFF,     0, 0,  47,     36,     0,     0x8000}, //POW? sprite 1 steps forward
    {XXX,        0xFFFF,     0, 0,  118,    42,     0,     0x0000}, //POW? sprite 1 steps forward
    {XXX,        0xFFFF,     0, 0,  26,     42,     0,     0x8000}  //POW? sprite 1 steps forward
};

DrawListItem* indoorDrawIndex[XXX];

void buildDrawIndex()
{
    for(int i = 0; i != XXX; i ++)
    {
        for(int j = 0; j != sizeof(indoorDrawList) / sizeof(indoorDrawList[0]); j ++)
        {
            if(indoorDrawList[j].id == (DRAWID)i)
            {
                indoorDrawIndex[i] = &indoorDrawList[j];
                break;
            }
        }
    }
}