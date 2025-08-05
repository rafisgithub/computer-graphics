#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void lineDrawDDA(int quadrant, int Mx, int My, int x1, int y1, int x2, int y2)
{
    int cx = Mx / 2, cy = My / 2; 
    int sx = 1, sy = -1; 

    // Determine direction based on quadrant
    switch (quadrant)
    {
        case 1: sx = 1;  sy = -1; break;
        case 2: sx = -1; sy = -1; break; 
        case 3: sx = -1; sy = 1;  break; 
        case 4: sx = 1;  sy = 1;  break; 
        default: cout << "Invalid quadrant. Defaulting to Quadrant 1.\n";
                 sx = 1; sy = -1; break;
    }

    // Calculate dx, dy
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        int px = cx + sx * round(x);
        int py = cy + sy * round(y);

        putpixel(px, py, WHITE);
        delay(100);

        x += xInc;
        y += yInc;
    }
}

int main()
{
    int X, Y;
    initwindow(600, 600, "DDA Line Drawing with Quadrants");

    X = getmaxx();
    Y = getmaxy();

    line(0, Y / 2, X, Y / 2); 
    line(X / 2, 0, X / 2, Y); 

    int x1, y1, x2, y2,id, q;

    cout << "Enter point P1 (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter point P2 (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Enter your student ID last four digit : ";
    cin >> id;
    q = id % 4;

    lineDrawDDA(q, X, Y, x1, y1, x2, y2);

    cout << "Press any key to exit..." << endl;
    while (!kbhit()) delay(200);

    closegraph();
    return 0;
}

