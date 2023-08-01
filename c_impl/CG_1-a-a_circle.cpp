#include <graphics.h>

main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	circle(200, 250, 200);
	outtextxy(10, 20, "LAB-1.a.line :: Sumit Budhathoki :: A-36");
	getch();
	closegraph();
}