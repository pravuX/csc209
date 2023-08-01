#include <stdio.h>
#include <graphics.h>

void midPointCircle(int x_centre, int y_centre, int radius)
{
    int x = radius, y = 0;

    putpixel(x + x_centre, y + y_centre, WHITE);;
    putpixel(x + x_centre, -y + y_centre, WHITE);;
    putpixel(-x + x_centre, -y + y_centre, WHITE);;
    putpixel(-x + x_centre, y + y_centre, WHITE);;

    int P = 1 - radius;

    while(x > y)
    {
        y++;

        if(P <= 0)
            P = P + 2*y + 1;
        else
        {
            x--;
            P = P + 2*y - 2*x + 1;
        }

        if(x < y)
            break;

        putpixel(x + x_centre, y + y_centre, WHITE);;
        putpixel(-x + x_centre, y + y_centre, WHITE);;
        putpixel(x + x_centre, -y + y_centre, WHITE);;
        putpixel(-x + x_centre, -y + y_centre, WHITE);;

        if(x != y)
        {
            putpixel(y + x_centre, x + y_centre, WHITE);;
            putpixel(-y + x_centre, x + y_centre, WHITE);;
            putpixel(y + x_centre, -x + y_centre, WHITE);;
            putpixel(-y + x_centre, -x + y_centre, WHITE);;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

	int x_centre, y_centre, radius;
	printf("Enter x_centre:\n");
	scanf("%d", &x_centre);
	printf("Enter y_centre:\n");
	scanf("%d", &y_centre);
	printf("Enter radius:\n");
	scanf("%d", &radius);
    midPointCircle(x_centre, y_centre, radius);
	outtextxy(10, 20, "LAB-3.a.Mid-point Circle :: Sumit Budhathoki :: A-36");
    getch();
    closegraph();
    return 0;
}