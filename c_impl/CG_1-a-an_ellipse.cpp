#include <graphics.h>

main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	ellipse(250, 300, 0, 360, 185, 105);
	outtextxy(10, 20, "LAB-1.a.an allipse :: Sumit Budhathoki :: A-36");
	getch();
	closegraph();
}