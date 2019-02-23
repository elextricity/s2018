#include "board.h"
#include <time.h>
#include <stdlib.h>

board board1[1];
board* gameboard;
player players[2];
gameball ball1[1];
score score[1];
int mode;
int reset;

void checkInput() {
int x = readX();
int y = readY();

if(x > someval && y > someval) {

}
else {

}


}

int readX() {
ADMUX = (ADMUX & 0xF8)| 0;
ADCSRA |= (1<<ADSC);
while(ADCSRA & (1<<ADSC));
return(ADC);

}

int readY() {
ADMUX = (ADMUX & 0xF8)| 1;
ADCSRA |= (1<<ADSC);
while(ADCSRA & (1<<ADSC));
return(ADC);

}

void draw() {
	draw_board(gameboard);
	draw_score(gameboard->score);
	draw_player();
	draw_player();
	draw_ball();


}


void checkCollision() {




	if(isai == 1) {
		if(gameboard->player2->y < 8) {

		}
		else if (gameboard->player2-> > 55) {
			
		}
	}


}

void update() {





}


void init() {
srand(time(0));  

gameboard = board1;
gameboard->width = 120;
gameboard->height = 56;
gameboard->xstart = 4;
gameboard->ystart = 4;
gameboard->player1 = &(players[0]);
gameboard->player2 = &(players[1]);
gameboard->ball = ball1;
gameboard->score = score;
gameboard->ball1->px = 63;
gameboard->ball1->py = 32;
gameboard->ball1->vx = rand() % 5;
gameboard->ball1->vy = rand() % 5;
gameboard->ball1->radius = 3;
gameboard->player1->y = 26;
gameboard->player1->x = 6;
gameboard->player1->width = 2;
gameboard->player1->height = 12;
gameboard->player1->ai = 0;
gameboard->player2->y = 26;
gameboard->player2->x = 119;
gameboard->player2->width = 2;
gameboard->player2->height = 12;
gameboard->score->p1score = 0;
gameboard->score->p2score = 0;
gameboard->score->x1 = 58;
gameboard->score->x2 = 68;
gameboard->score->y1 = 1;
gameboard->score->y2 = 1;
gameboard->player1->vy = 0;
mode = 0;
ADMUX = (1<<REFS0);
ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
reset = 0;

}

int main() {
init();
if(mode == 0) {
	gameboard->player2->ai = 0;
	isai = 0;
}
else if(mode == 1){
	gameboard->player2->ai = 1;
	isai = 1;
} else {

}

while(1) {


	draw();
}






}