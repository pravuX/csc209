#include <graphics.h>

main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	rectangle(100, 200, 380, 350);
	outtextxy(10, 20, "LAB-1.a.rectangle :: Sumit Budhathoki :: A-36");
	getch();
	closegraph();
}