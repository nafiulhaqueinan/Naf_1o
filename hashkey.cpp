//
// Created by Md.NAFIUL HAQUE on 5/27/2024.
//

#include "defination.h"
#include <cassert>

uint64_t generatePositionKey(const S_BOARD &pos) {
    uint64_t finalKey = 0;

    for (int sq = 0; sq < Board_sq_Num; ++sq) {
        int piece = pos.pieces[sq];
        if (piece != NO_SQ && piece != EMPTY) {
            assert(piece >= wP && piece <= bK);
            finalKey ^= piecekeys[piece][sq];
        }
    }

    if (pos.side == WHITE) {
        finalKey ^= sideKey;
    }

    if (pos.enPas != NO_SQ) {
        assert(pos.enPas >= 0 && pos.enPas < Board_sq_Num);
        finalKey ^= piecekeys[EMPTY][pos.enPas];
    }

    assert(pos.castleperm >= 0 && pos.castleperm <= 15);
    finalKey ^= Castlekeys[pos.castleperm];

    return finalKey;
}
