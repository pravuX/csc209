#include <graphics.h>

main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	circle(200, 190, 60);
	circle(170, 180, 8);
	circle(230, 180, 8);
	circle(200, 200, 2);
	arc(200, 220, 180, 360, 10);
	line(200, 250, 200, 350);
	line(200, 270, 250, 300);
	line(200, 270, 150, 300);
	line(200, 350, 250, 380);
	line(200, 350, 150, 380);
	outtextxy(10, 20, "LAB-1.b.human :: Sumit Budhathoki :: A-36");
	getch();
	closegraph();
}