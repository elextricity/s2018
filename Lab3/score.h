#include <stdint.h>

typedef struct score {
	int p1score;
	int p2score;
	int x1;
	int y1;
	int x2;
	int y2;
} score;


void draw_score(score* scores, uint8_t *buff); 

void update_score(score* scores, int player);