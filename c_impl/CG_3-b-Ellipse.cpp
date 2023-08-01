#include<stdio.h>
#include<graphics.h>

void midptellipse(int rx, int ry, int xc, int yc)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy)
    {
        putpixel(x + xc, y + yc, WHITE);;
        putpixel(-x + xc, y + yc, WHITE);;
        putpixel(x + xc, -y + yc, WHITE);;
        putpixel(-x + xc, -y + yc, WHITE);;

        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0)
    {
        putpixel(x + xc, y + yc, WHITE);;
        putpixel(-x + xc, y + yc, WHITE);;
        putpixel(x + xc, -y + yc, WHITE);;
        putpixel(-x + xc, -y + yc, WHITE);;

        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}
main()
{
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

	int x_centre, y_centre, radius_x, radius_y;
	printf("Enter x_centre:\n");
	scanf("%d", &x_centre);
	printf("Enter y_centre:\n");
	scanf("%d", &y_centre);
	printf("Enter radius_x:\n");
	scanf("%d", &radius_x);
	printf("Enter radius_y:\n");
	scanf("%d", &radius_y);
    midptellipse(radius_x, radius_y, x_centre, y_centre);
	outtextxy(10, 20, "LAB-3.b.Mid-point Ellipse :: Sumit Budhathoki :: A-36");
    getch();
    closegraph();
}