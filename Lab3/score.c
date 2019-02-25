#include "score.h"

void draw_score(score* scores, uint8_t *buff) {
	char score1;
	char score2;
	score1 = '0' + scores->p1score;
	score2 = '0' + scores->p2score;

	//drawchar(buff, scores->x1, scores->y1, score1);
	//drawchar(buff, scores->x2, scores->y2, score2);
}

void update_score(score* scores, int player) {

if(player == 0) {
	scores->p1score = scores->p1score + 1;
}
else {
	scores->p2score = scores->p2score + 1;
}


}