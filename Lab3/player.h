
typedef struct player {
	int y;
	int x;
	int vy;
	int width;
	int height;
	int ai;
} player;

void draw_player(player* p1, uint8_t *buff);

void update_player(player* p1);