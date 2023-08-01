#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

// Function to perform boundary fill using 4-connected pixels
void boundaryFill4(int x, int y, int fcolor, int bcolor)
{
    if ((getpixel(x, y) != bcolor) && (getpixel(x, y) != fcolor))
    {
    	putpixel(x, y, fcolor);
    	boundaryFill4(x + 1, y, fcolor, bcolor);
        boundaryFill4(x - 1, y, fcolor, bcolor);
        boundaryFill4(x, y + 1, fcolor, bcolor);
        boundaryFill4(x, y - 1, fcolor, bcolor);
    }
}

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    circle(100, 200, 90);
    boundaryFill4(105, 205, 11, 15);
    outtextxy(10, 20, "LAB-4.b.Boundary fill 4 connected pixels :: Sumit Budhathoki :: A-36");
    getch();
    closegraph();
    return 0;
}
