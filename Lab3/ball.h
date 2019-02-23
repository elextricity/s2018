
typedef struct gameball {
	int px;
	int py;
	int vx;
	int vy;
	int radius;
} gameball;


void draw_ball(gameball* ball,  uint8_t *buff);

void update_ball(gameball* ball);