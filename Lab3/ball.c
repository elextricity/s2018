#include "ball.h"

void draw_ball(gameball* ball, uint8_t *buff) {
	fillcircle(buff, ball->px, ball->py, ball->radius, 0);
}

void update_ball(gameball* ball) {
	ball->px = ball->px + ball->vx;
	ball->py = ball->py + ball->vy;
}