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
int scorer;

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
	clear_buffer(buff);
	draw_board(gameboard, buff);
	draw_score(gameboard->score, buff);
	draw_player(gameboard->player1, buff);
	draw_player(gameboard->player2, buff);
	draw_ball(gameboard->ball, buff);
	write_buffer(buff);
}


void checkCollision() {

	if(gameboard->ball->py + gameboard->ball->radius == gameboard->ystart + gameboard->height) {
		gameboard->ball->vy = gameboard->ball->vy * -1;
	}

	if(gameboard->ball->py - gameboard->ball->radius == gameboard->ystart) {
		gameboard->ball->vy = gameboard->ball->vy * -1;
	}

	if(gameboard->ball->px + gameboard->ball->radius >= gameboard->xstart + gameboard->width) {
		if(gameboard->ball->px + gameboard->ball->radius > gameboard->xstart + gameboard->width) {
			reset = 1;
			scorer = 0;
		}
		else {
			gameboard->ball->vx = gameboard->ball->vx * -1;
		}
	}

	if(gameboard->ball->px - gameboard->ball->radius <= gameboard->xstart) {
		if(gameboard->ball->px + gameboard->ball->radius < gameboard->xstart) {
			reset = 1;
			scorer = 1;
		}
		else {
			gameboard->ball->vx = gameboard->ball->vx * -1;
		}
	}

	if(isai == 1) {
		if(gameboard->player2->y < 8) {
			gameboard->player2->vy = -1*gameboard->player2->vy;
		}
		else if (gameboard->player2-> > 55) {
			gameboard->player2->vy = -1*gameboard->player2->vy;
		}
	}

}

void reset() {
gameboard->ball1->px = 63;
gameboard->ball1->py = 32;
gameboard->ball1->vx = rand() % 5;
gameboard->ball1->vy = rand() % 5;
gameboard->player1->y = 26;
gameboard->player1->x = 6;
gameboard->player1->width = 2;
gameboard->player1->height = 12;
gameboard->player2->y = 26;
gameboard->player2->x = 119;
gameboard->player2->width = 2;
gameboard->player2->height = 12;
gameboard->player1->vy = 0;
gameboard->player2->vy = 3;
}

void update() {
	
	update_player(gameboard->player1);
	update_player(gameboard->player2);
	update_ball(gameboard->ball);

	if(gameboard->player1->y <= gameboard->ystart) {
		gameboard->player1->y = gameboard->ystart;
	}

	if(gameboard->player1->y + gameboard->player1->height >= gameboard->ystart + gameboard->height) {
		gameboard->player1->y = gameboard->ystart + gameboard->height - gameboard->player1->height;
	}

	if(gameboard->player2->y <= gameboard->ystart) {
		gameboard->player2->y = gameboard->ystart;
	}

	if(gameboard->player2->y + gameboard->player2->height >= gameboard->ystart + gameboard->height) {
		gameboard->player2->y = gameboard->ystart + gameboard->height - gameboard->player2->height;
	}

	if(gameboard->ball->py + gameboard->ball->radius >= gameboard->ystart + gameboard->height) {
		gameboard->ball->py = gameboard->ystart + gameboard->height - gameboard->ball->radius;
	}
	if(gameboard->ball->py - gameboard->ball->radius <= gameboard->ystart) {
		gameboard->ball->py = gameboard->ystart - gameboard->ball->radius;
	}

	if(gameboard->ball->px + gameboard->ball->radius >= gameboard->xstart + gameboard->width) {
		if((gameboard->ball->py + gameboard->ball->radius > gameboard->player2->y) && (gameboard->ball->py - gameboard->ball->radius < gameboard->player2->y + gameboard->player2->height)) {
			gameboard->ball->px = gameboard->xstart + gameboard->width - gameboard->ball->radius;
		}
	}

	if(gameboard->ball->px - gameboard->ball->radius <= gameboard->xstart) {
		if((gameboard->ball->py + gameboard->ball->radius > gameboard->player1->y) && (gameboard->ball->py - gameboard->ball->radius < gameboard->player1->y + gameboard->player1->height)) {
			gameboard->ball->px = gameboard->ball->radius + gameboard->xstart
		}
	}

	if(reset == 1) {
		update_score(gameboard->score, scorer);
		reset();
		reset = 0;
	}

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
gameboard->ball->px = 63;
gameboard->ball->py = 32;
gameboard->ball->vx = rand() % 5;
gameboard->ball->vy = rand() % 5;
gameboard->ball->radius = 3;
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
gameboard->player2->vy = 3;
mode = 0;
ADMUX = (1<<REFS0);
ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
reset = 0;
	DDRD |= 0x80; 
	PORTD &= ~0x80;
	PORTD |= 0x00;
	
	DDRB |= 0x05;
	PORTB &= ~0x05;
	PORTB |= 0x00;

	sei();

	lcd_init();
	lcd_command(CMD_DISPLAY_ON);
	lcd_set_brightness(0x18);
	write_buffer(buff);
	_delay_ms(1500);
	if(mode == 0) {
		gameboard->player2->ai = 0;
		isai = 0;
	}
	else if(mode == 1){
		gameboard->player2->ai = 1;
		isai = 1;
	} else {

	}

}

int main() {


init();
while(1) {
	checkInput();
	checkCollision();
	update();
	draw();
}






}