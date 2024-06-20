//
// Created by Md.NAFIUL HAQUE on 1/12/2024.
//

#include "defination.h"
#include "bits/stdc++.h"


#define RAND_64 ( \
    static_cast<long long>(rand()) | \
    (static_cast<long long>(rand()) << 15) | \
    (static_cast<long long>(rand()) << 30) | \
    (static_cast<long long>(rand()) << 45) | \
    ((static_cast<long long>(rand()) & 0xf) << 60) \
)

int Sq120ToSq64[Board_sq_Num];
int Sq64ToSq120[64];

ll64 setmask[64];
ll64 clearmask[64];

ll64 piecekeys[13][120];
ll64 sideKey;
ll64 Castlekeys[16];



void initHashKEYS(){
    for(int i=0;i<13;i++){
        for(int j=0;j<13;j++){
            piecekeys[i][j]=RAND_64;
        }
    }
    sideKey=RAND_64;
    for(int i=0;i<16;i++){
        Castlekeys[i]=RAND_64;
    }
}


void init_bit_mask(){
    int index=0;
    for(index=0;index<64;index++){
        setmask[index]=0ULL;
        clearmask[index]=0ULL;
    }
    for(index=0;index<64;index++){
        setmask[index]|=(1ULL<<index);
        clearmask[index]= ~setmask[index];
    }

}


void InitSq120ToSq64(){
    int idx=0;
    int file=FILE_A;
    int rank=RANK_1;
    int sq=A1;
    int sq64=0;
    for(idx=0;idx<Board_sq_Num;idx++){
        Sq120ToSq64[idx]=65;
    }
    for(idx=0;idx<64;idx++){
        Sq64ToSq120[idx]=120;
    }
    for(rank=RANK_1;rank<=RANK_8;rank++){
        for(file=FILE_A;file<=FILE_H;file++){
            sq= FR2SQ(file,rank);
            Sq64ToSq120[sq64]=sq;
            Sq120ToSq64[sq]=sq64;
            sq64++;
        }
    }
}


void AllInit(){
    InitSq120ToSq64();
    init_bit_mask();
    initHashKEYS();

}
