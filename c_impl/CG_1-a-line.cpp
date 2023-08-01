#include <graphics.h>

main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	line(100, 200, 400, 200);
	outtextxy(50, 170, "(100, 200)");
	outtextxy(399, 170, "(400, 200)");
	outtextxy(10, 20, "LAB-1.a.line :: Sumit Budhathoki :: A-36");
	getch();
	closegraph();
}