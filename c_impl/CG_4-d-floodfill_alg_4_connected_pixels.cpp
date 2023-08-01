#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

// Function to perform boundary fill using 4-connected pixels
void floodfill4(int x, int y, int fcolor, int bcolor)
{
    if ((getpixel(x, y) != bcolor) && (getpixel(x, y) != fcolor))
    {
    	putpixel(x, y, fcolor);
    	floodfill4(x + 1, y, fcolor, bcolor);
        floodfill4(x - 1, y, fcolor, bcolor);
        floodfill4(x, y + 1, fcolor, bcolor);
        floodfill4(x, y - 1, fcolor, bcolor);
    }
}

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    rectangle(100, 100, 200, 200);
    floodfill4(105, 105, 12, 15);
    outtextxy(10, 20, "LAB-4.d.Flood fill 4 connected pixels :: Sumit Budhathoki :: A-36");
    getch();
    closegraph();
	return 0;
}
