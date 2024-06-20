//
// Created by Md.NAFIUL HAQUE on 5/27/2024.
//
#include "defination.h"

ll64 generatePositionKey( const S_BOARD *pos){
    int sq=0;
    ll64 finalkey=0;
    int piece = EMPTY;
    for( sq=0 ; sq<Board_sq_Num ; sq++){
       piece=pos->pieces[sq];
       if(piece != NO_SQ && piece != EMPTY){
           assert(piece>=wP && piece<=bK);
           finalkey ^= piecekeys[piece][sq];
       }
    }
    if(pos->side == WHITE){
        finalkey ^= sideKey;
    }
    if(pos->enPas != NO_SQ){
        assert(pos->enPas>=0 && pos->enPas<Board_sq_Num);
        finalkey ^= piecekeys[EMPTY][pos->enPas];
    }
    assert(pos->castleperm>=0 && pos->castleperm<=15);
    finalkey ^= Castlekeys[pos->castleperm];
    return finalkey;
}

