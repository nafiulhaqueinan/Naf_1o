//
// Created by Md.NAFIUL HAQUE on 1/8/2024.
//
#ifndef CHESS_ENGINE_DEFINATION_H
#define CHESS_ENGINE_DEFINATION_H
#include "bits/stdc++.h"
#include "stdlib.h"





#define MAXGAMEMOVES 2048
typedef unsigned long long ll64;

#define NAME "Naf1.o"
#define  Board_sq_Num 120
#define  START_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";


//wP=white_pwn, wN=white knight
//B=bisop,R=rook,Q=queen,K=King

enum{EMPTY,wP,wN,wB,wR,wQ,wK,bP,bN,bB,bR,bQ,bK};
enum{FILE_A,FILE_B,FILE_C,FILE_D,FILE_E,FILE_F,FILE_G,FILE_H,FILE_NONE};
enum{RANK_1,RANK_2,RANK_3,RANK_4,RANK_5,RANK_6,RANK_7,RANK_8,RANK_NONE};
enum{WHITE,BLACK,BOTH};
enum{
    A1=21,B1,C1,D1,E1,F1,G1,H1,
    A2=31,B2,C2,D2,E2,F2,G2,H2,
    A3=41,B3,C3,D3,E3,F3,G3,H3,
    A4=51,B4,C4,D4,E4,F4,G4,H4,
    A5=61,B5,C5,D5,E5,F5,G5,H5,
    A6=71,B6,C6,D6,E6,F6,G6,H6,
    A7=81,B7,C7,D7,E7,F7,G7,H7,
    A8=91,B8,C8,D8,E8,F8,G8,H8,NO_SQ,OFFBOARD
};
enum {FALSE,TRUE};
enum {WKCA=1,WQCA=2,BKCA=4,BQCA=8};
typedef  struct {
    int move;
    int castelperm;
    int enPas;
    int fiftyMove;
    ll64 poskey;

} N_Undo;

typedef struct {
    int pieces[Board_sq_Num];
    ll64 pawns[3];


    int KingSq[2];

    int side;
    int enPas;
    int fiftyMove;

    int ply;
    int hisPly;

    int castleperm;

    ll64 posKey;

    int pceNum[13];
    int BigPce[3];
    int MajPce[3];
    int MinPce[3];
    N_Undo  history[MAXGAMEMOVES];

    //piece List
    int pList[13][10];

}S_BOARD;

// MACROS
#define FR2SQ(f, r) ((21 + (f)) + ((r) * 10))
#define SQ64(sq120) (Sq120ToSq64[(sq120)])
#define SQ120(sq64) (Sq64ToSq120[(sq64)])
#define pop(b) PopBit(b)
#define CNT(b) CountBits(b)
#define CLRBIT(bb,sq) ((bb) &=clearmask[(sq)])
#define SETBIT(bb,sq) ((bb) |=  setmask[(sq)])



// FUNCTIONS
//init
extern void AllInit();



//bitboard
extern int PopBit(ll64 *bb);
extern int CountBits(ll64 b);
extern void PrintBitBoard(ll64 bb);

// GLOBALS
extern int Sq120ToSq64[Board_sq_Num];
extern int Sq64ToSq120[64];
extern ll64 setmask[64];
extern ll64 clearmask[64];
extern ll64 piecekeys[13][120];
extern ll64 sideKey;
extern ll64 Castlekeys[16];
extern char PceChar[];
extern char SideChar[];
extern char RankChar[];
extern char FileChar[];

//hashkeys
extern ll64 generatePositionKey( const S_BOARD *pos);

//board
extern void reset_board(S_BOARD *pos);
extern int  Parse_Fen(char *fen,S_BOARD *pos);
extern void PrintBoard(const S_BOARD *pos);
#endif // CHESS_ENGINE_DEFINATION_H