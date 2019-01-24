#include "robco.h"

int robcoLogin(){
    char ** array = genArray();
    int line = rand() % 64927; 
	int attempts = 4;
    int cy = 0;//current y
    int cx = 0;//current x
    
	slowType(0,0,"Welcome to ROBCO Industries (TM) Termlink", CH_DELAY);
	slowType(2,0,"Password Required", CH_DELAY);
	slowType(4,0,"Attempts Remaining:", CH_DELAY);
	//Begin loop
    int firstrun = 1;
    while(attempts>0){
        if(firstrun){
            printLogin(array, cy, cx, line, 1);
            firstrun = 0;
        }
        else{
            printLogin(array, cy, cx, line, 0);
        }
        for(int i = 1; i<=attempts; i++){
            slowType(4, 20+(i*2), " ", CH_DELAY);
            attron(A_REVERSE);
            slowType(4, 19+(i*2), " ", CH_DELAY);
            attroff(A_REVERSE);
        }
        for(int i = 4; i>attempts; i--){
            attroff(A_REVERSE);
            slowType(4, 20+(i*2), " ", CH_DELAY);
            slowType(4, 19+(i*2), " ", CH_DELAY);
        }
        int c = getch();
        switch(c){
            case KEY_UP:
                if(cy > 0 && cy != 17){
                    cy--;
                }
                break;
            case KEY_LEFT:
                if(cx != 0){
                    cx--;
                }
                else if(cx == 0 && cy > 16){
                    cx = 11;
                    cy = cy - 17;
                }
                break;
            case KEY_RIGHT:
                if(cx != 33 && cx != 11){
                    cx++;
                }
                else if(cy < 17){
                    cx = 0;
                    cy = cy + 17;
                }
                break;
            case KEY_DOWN:
                if(cy != 16 && cy != 33){
                    cy++;
                }
                break;
            case 10:
                attempts--;
                //if(check(cy, cx, password)){
                //     return 1;
                // }
        }
    }
    clear();
    printw("You have been locked out! Please wait 10 seconds to try again.");
    refresh();
    usleep(10000000);
    clear();
    refresh();
    return 0;
}