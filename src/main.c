#include "robco.h"

int main(int argc, char **argv)
{
	struct timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec);
	//setFont(24);
	
	int row,col;				
	initscr();
	if(has_colors() == FALSE)
	{	
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	
	getmaxyx(stdscr,row,col);
	keypad(stdscr, TRUE);
    cbreak();
    noecho(); // Don't echo any keypresses
	curs_set(FALSE);
	
	//ROBCO INIT

    while(!robcoLogin()){
    }
    //robcoSystem();
}
