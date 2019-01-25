#import "roboco.h"

char ** genArray(){
    char * chars = "!@#$%^&*+-:;\"\'_/|=?,.!@#$%^&*+-:;\"\'_/|=?,.<>{}[]()";
    char passwords[][12] = {"NAMES", "FACES", "SHOT", "GLOW", "SURE", "BATTLE", "SICK", "WEEK",
                        "FIRE", "GEAR", "HURT", "SELL", "SUPPLIED", "LOYALIST", "FEVERISH",
                        "CITIZENS", "SERVANTS", "RESULTS", "MARKS", "SEEK", "COPY", "HALF",
                        "MENU", "HOSTILE", "ACTIVE", "LOTS", "HELP", "PAIN", "SELDOM",
                        "SERVICE", "CONTROL", "COLD", "ROBBED", "STRIKING", "FALLEN", "REJECTED"};
	char ** array = calloc(V_ARRAY+1, sizeof(char *));
	for(int y = 0; y<V_ARRAY; y++){
		array[y] = calloc(H_ARRAY, sizeof(char));
	}
	for(int y = 0; y<V_ARRAY; y++){
		for(int x = 0; x<H_ARRAY; x++){
			int random = rand() % strlen(chars);
			array[y][x] = chars[random];
		}
	}

    int password;
    int cpasswordint = rand() % N_PASSWORDS;
    for(int r = 0; r < N_PASSWORDS; r++){
        while(1){
            password = rand() % NELEMS(passwords);
            if (passwords[password][0]=='#'){
                continue;
            }
            else{
                break;
            }
        }
        if(r == cpasswordint){
            /*for(int y = V_ARRAY+1, x = 0; x<strlen(passwords[password]); x++){
                array[y][x]=passwords[password][x];
            }*/
        }
        int rx = rand() % H_ARRAY;
        int ry = 2.5*r;
        
        for(int s = 0, y = ry, x = rx; s<strlen(passwords[password]);){
            array[y][x]=passwords[password][s++];
            if(x<H_ARRAY-1){x++;}else{y++;x=0;}
        }
        for(int i = 0; i < strlen(passwords[password]); i++){
            passwords[password][0] = '#';
        }
    }
        return array;
}
