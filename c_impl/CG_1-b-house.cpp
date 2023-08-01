#include <graphics.h>

main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	rectangle(100, 200, 400, 400);
	rectangle(230, 340, 270, 400);
	rectangle(130, 220, 160, 260);
	rectangle(340, 220, 370, 260);
	circle(250, 150, 20);
	line(250, 100, 100, 200);
	line(250, 100, 400, 200);
	outtextxy(10, 20, "LAB-1.b.house :: Sumit Budhathoki :: A-36");
	getch();
	closegraph();
}