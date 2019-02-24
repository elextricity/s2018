
typedef struct score {
	int p1score;
	int p2score;
	int x1;
	int y1;
	int x2;
	int y2;
} score;


draw_score(score* scores, uint8_t *buff); 

update_score(score* scores, int player);