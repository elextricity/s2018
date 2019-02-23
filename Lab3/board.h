#ifndef BALL
#define BALL
#include "ball.h"
#include "player.h"
#include "score.h"
#endif


typedef struct board {
	int width;
	int height;
	int xstart;
	int ystart;
	gameball* ball;
	player* player1;
	player* player2;
	score* score;
} board;


void draw_board(board* board);