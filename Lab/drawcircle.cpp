#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>

int main() {
	initwindow(400,300,"Cse2101022051");
	int x = getmaxx();
	int y = getmaxy();
	
	int X = x/2;
	int Y = y/2;
	
	rectangle(0,0,x,y);
	
	line (X, 0, X,y);
	line (0, Y, x,Y);
	
	circle(X+85,Y+85,50);
	circle(X+85,Y+85,1);
	circle(X+85,Y-85,50);
	circle(X-85,Y-85,50);
	circle(X-85,Y+85,50);
	
	
	circle(X,Y,50);
	
	
	while(!kbhit())
	{
		delay(200);
	}
	return 0;
}
