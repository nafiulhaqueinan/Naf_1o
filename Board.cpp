//
// Created by Md.NAFIUL HAQUE on 5/27/2024.
//

#include <bits/stdc++.h>
#include "defination.h"
using namespace std;

int Parse_Fen(const string &fen, S_BOARD &pos) {
    assert(!fen.empty());

    int rank = RANK_8;
    int file = FILE_A;
    int piece = 0;
    int count = 0;
    int sq64 = 0;
    int sq120 = 0;

    reset_board(pos);

    auto fen_itr = fen.begin();
    while (rank >= RANK_1 && fen_itr != fen.end()) {
        count = 1;
        switch (*fen_itr) {
            case 'p': piece = bP; break;
            case 'r': piece = bR; break;
            case 'n': piece = bN; break;
            case 'b': piece = bB; break;
            case 'k': piece = bK; break;
            case 'q': piece = bQ; break;
            case 'P': piece = wP; break;
            case 'R': piece = wR; break;
            case 'N': piece = wN; break;
            case 'B': piece = wB; break;
            case 'K': piece = wK; break;
            case 'Q': piece = wQ; break;
            case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8':
                piece = EMPTY;
                count = *fen_itr - '0';
                break;
            case '/':
            case ' ':
                rank--;
                file = FILE_A;
                fen_itr++;
                continue;
            default:
                cout << "FEN ERROR LOC->file BOARD.cpp " << endl;
                return -1;
        }

        for (int i = 0; i < count; i++) {
            sq64 = rank * 8 + file;
            sq120 = SQ120(sq64);
            if (piece != EMPTY) {
                pos.pieces[sq120] = piece;
            }
            file++;
        }
        fen_itr++;
    }

    assert(*fen_itr == 'w' || *fen_itr == 'b');
    pos.side = (*fen_itr == 'w') ? WHITE : BLACK;
    fen_itr += 2;

    for (int i = 0; i < 4; i++) {
        if (*fen_itr == ' ') {
            break;
        }
        switch (*fen_itr) {
            case 'K': pos.castleperm |= WKCA; break;
            case 'Q': pos.castleperm |= WQCA; break;
            case 'k': pos.castleperm |= BKCA; break;
            case 'q': pos.castleperm |= BQCA; break;
            default: break;
        }
        fen_itr++;
    }

    fen_itr++;
    assert(pos.castleperm >= 0 && pos.castleperm <= 15);

    if (*fen_itr != '-') {
        file = fen_itr[0] - 'a';
        rank = fen_itr[1] - '1';
        assert(file >= FILE_A && file <= FILE_H);
        assert(rank >= RANK_1 && rank <= RANK_8);
        pos.enPas = FR2SQ(file, rank);
    }

    pos.posKey = generatePositionKey(&pos);
    return 0;
}

void reset_board(S_BOARD &pos) {
    for (int i = 0; i < Board_sq_Num; i++) {
        pos.pieces[i] = OFFBOARD;
    }
    for (int i = 0; i < 64; i++) {
        pos.pieces[SQ120(i)] = EMPTY;
    }
    for (int i = 0; i < 3; i++) {
        pos.BigPce[i] = 0;
        pos.MajPce[i] = 0;
        pos.MinPce[i] = 0;
        pos.pawns[i] = 0ULL;
    }
    for (int i = 0; i < 13; i++) {
        pos.pceNum[i] = 0;
    }
    pos.KingSq[0] = pos.KingSq[1] = NO_SQ;
    pos.side = BOTH;
    pos.enPas = NO_SQ;
    pos.fiftyMove = 0;
    pos.ply = 0;
    pos.hisPly = 0;
    pos.castleperm = 0;
    pos.posKey = 0ULL;
}

void PrintBoard(const S_BOARD &pos) {
    int sq, file, rank, piece;
    cout << "\ngame_board\n" << endl;
    for (rank = RANK_8; rank >= RANK_1; rank--) {
        cout << rank + 1;
        for (file = FILE_A; file <= FILE_H; file++) {
            sq = FR2SQ(file, rank);
            piece = pos.pieces[sq];
            cout << PceChar[piece];
        }
        cout << endl;
    }
}
