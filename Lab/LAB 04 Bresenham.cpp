#include<iostream>
#include<graphics.h>
#include<dos.h>
using namespace std;

void bresenhamline(int x1,int y1,int x2,int y2,int X,int Y)
{
    int dx,dy,inc1,inc2,d;
    float m;
    int color=1;

    m=(y2-y1)/(x2-x1);

    if(m<=1)
    {
        dx=x2-x1;
        dy=y2-y1;
        d=2*dy-dx;
        inc1=2*dy;
        inc2=2*(dy-dx);

        while(x1<=x2)
        {
            putpixel((X/2)+x1,(Y/2)-y1,color++);
            delay(100);

            if(color>15)
                color=1;

            if(d<=0)
                d=d+inc1;
            else
            {
                d=d+inc2;
                y1++;
            }
            x1++;
        }
    }
    else
    {
        dx=x2-x1;
        dy=y2-y1;
        d=2*dx-dy;
        inc1=2*dx;
        inc2=2*(dx-dy);

        while(y1<=y2)
        {
            putpixel((X/2)+x1,(Y/2)-y1,color++);
            delay(100);
            if(color>60)
                color=1;

            if(d<0)
            {
                d=d+inc1;
            }
            else
            {
                x1=x1+1;
                d=d+inc2;
            }
            y1=y1+1;
        }

    }

}

int main()
{
    int X,Y;
    initwindow(400,400,"bresenhamline");

    X=getmaxx();
    Y=getmaxy();

    line(0,Y/2,X,Y/2);
    line(X/2,0,X/2,Y);

    bresenhamline(1,1,100,60,X,Y);


    while(!kbhit())
    {
        delay(200);
    }

    return 0;
}
