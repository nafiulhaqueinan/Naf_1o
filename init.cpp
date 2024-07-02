//
// Created by Md.NAFIUL HAQUE on 1/12/2024.
//

#include "defination.h"
#include <iostream>
#include <cstdlib>

#define RAND_64 ( \
    static_cast<uint64_t>(rand()) | \
    (static_cast<uint64_t>(rand()) << 15) | \
    (static_cast<uint64_t>(rand()) << 30) | \
    (static_cast<uint64_t>(rand()) << 45) | \
    ((static_cast<uint64_t>(rand()) & 0xf) << 60) \
)

int Sq120ToSq64[Board_sq_Num];
int Sq64ToSq120[64];

uint64_t setmask[64];
uint64_t clearmask[64];

uint64_t piecekeys[13][120];
uint64_t sideKey;
uint64_t Castlekeys[16];

void initHashKEYS() {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 120; j++) {
            piecekeys[i][j] = RAND_64;
        }
    }
    sideKey = RAND_64;
    for (int i = 0; i < 16; i++) {
        Castlekeys[i] = RAND_64;
    }
}

void init_bit_mask() {
    for (int index = 0; index < 64; index++) {
        setmask[index] = 0ULL;
        clearmask[index] = 0ULL;
    }
    for (int index = 0; index < 64; index++) {
        setmask[index] |= (1ULL << index);
        clearmask[index] = ~setmask[index];
    }
}



void InitSq120ToSq64() {
    for (int idx = 0; idx < Board_sq_Num; idx++) {
        Sq120ToSq64[idx] = 65;
    }
    for (int idx = 0; idx < 64; idx++) {
        Sq64ToSq120[idx] = 120;
    }
    int sq64 = 0;
    for (int rank = RANK_1; rank <= RANK_8; rank++) {
        for (int file = FILE_A; file <= FILE_H; file++) {
            int sq = FR2SQ(file, rank);
            Sq64ToSq120[sq64] = sq;
            Sq120ToSq64[sq] = sq64;
            sq64++;
        }
    }
}



void AllInit() {
    InitSq120ToSq64();
    init_bit_mask();
    initHashKEYS();
}
