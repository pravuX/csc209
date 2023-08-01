#include <graphics.h>

main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	rectangle(200, 200, 400, 400);
	outtextxy(10, 20, "LAB-1.a.square :: Sumit Budhathoki :: A-36");
	getch();
	closegraph();
}