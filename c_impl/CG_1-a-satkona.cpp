#include <graphics.h>

main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	line(250, 100, 100, 350);
	line(100, 350, 400, 350);
	line(250, 100, 400, 350);
	line(100, 160, 250, 410);
	line(250, 410, 400, 160);
	line(100, 160, 400, 160);
	outtextxy(10, 20, "LAB-1.a.satkona :: Sumit Budhathoki :: A-36");
	getch();
	closegraph();
}