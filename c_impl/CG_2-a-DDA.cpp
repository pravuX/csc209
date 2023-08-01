#include <stdio.h>
#include <graphics.h>

void drawLineDDA(int x1, int y1, int x2, int y2)
{
	int i;
	printf("Enter starting points:\n");
	scanf("%d %d", &x1, &y1);
	printf("Enter end points:\n");
	scanf("%d %d", &x2, &y2);
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = dx / (float) steps;
    float yinc = dy / (float) steps;
    float x = x1;
    float y = y1;
    printf("\nStep\tX\tY\tPlot(X, Y)\n");
    for (int i = 0; i <= steps; i++) 
	{
        printf("%d\t%.1f\t%.1f\t(%d, %d)\n", i, x, y, int(x), int(y));
        x += xinc;
        y += yinc;
    }
    x=x1;
	y=y1;
	for(i=0;i<steps;i++)
	{
		putpixel(x,y,15);
		x=x+xinc;
		y=y+yinc;
	}
	outtextxy(10, 20, "LAB-2.a.DDA :: Sumit Budhathoki :: A-36");
}
int main() 
{
	int x1, y1, x2, y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawLineDDA(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}