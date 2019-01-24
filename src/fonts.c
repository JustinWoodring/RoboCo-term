#include "robco.h"

void setFont(int ptSz)
{
	char * command = "setfont ../fonts/stech-";
	strcat(command, ptSz);
	strcat(command, ".psf.gz");
	system(command);
}