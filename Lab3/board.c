#include "board.h"


void draw_board(board* board, uint8_t *buff) {
	drawrect(buff, board->xstart, board->ystart, board->width, board->height, 0);
	int i;
	int y = board->ystart + 2;
	int x = board->width/2 + board->xstart;
	for(i = 0; i < 9; i++) {
		drawline(buff, x, y, x, y+4, 0);
		drawline(buff, x+1, y, x+1, y+4, 0);	
		y = y + 6;
	}
}
