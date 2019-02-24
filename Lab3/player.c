#include "player.h"

void draw_player(player* p1, uint8_t *buff) {
	fillrect(buff, p1->x, p1->y, p1->width, p1->height, 0);
}

void update_player(player* p1) {
	p1->y = p1->y + p1->vy;
}