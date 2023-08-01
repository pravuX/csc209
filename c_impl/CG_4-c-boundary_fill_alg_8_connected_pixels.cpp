#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

// Function to perform boundary fill using 4-connected pixels
void boundaryFill8(int x, int y, int fcolor, int bcolor)
{
    if ((getpixel(x, y) != bcolor) && (getpixel(x, y) != fcolor))
    {
    	putpixel(x, y, fcolor);
    	boundaryFill8(x + 1, y, fcolor, bcolor);
        boundaryFill8(x - 1, y - 1, fcolor, bcolor);
        boundaryFill8(x, y + 1, fcolor, bcolor);
        boundaryFill8(x, y - 1, fcolor, bcolor);
        boundaryFill8(x + 1, y + 1, fcolor, bcolor);
        boundaryFill8(x - 1, y, fcolor, bcolor);
        boundaryFill8(x - 1, y + 1, fcolor, bcolor);
        boundaryFill8(x + 1, y - 1, fcolor, bcolor);
    }
}

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    rectangle(100, 100, 250, 250);
    boundaryFill8(105, 105, 12, 15);
    outtextxy(10, 20, "LAB-4.c.Boundary fill 8 connected pixels :: Sumit Budhathoki :: A-36");
    getch();
    closegraph();
	return 0;
}
