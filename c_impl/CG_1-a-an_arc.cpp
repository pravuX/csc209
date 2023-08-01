#include <graphics.h>

main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	arc(250, 250, 120, 300, 100);
	outtextxy(10, 20, "LAB-1.a.an arc :: Sumit Budhathoki :: A-36");
	getch();
	closegraph();
}