#include <graphics.h>
void drawLineBresenham(int x1, int y1, int x2, int y2) {
	int dx = abs(x2 - x1), dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1; int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy; int x = x1, y = y1;
	while (1) {
		putpixel(x, y, WHITE);;
		if (x == x2 && y == y2)
			break;
		int err2 = 2 * err;
		if (err2 > -dy) {
			err -= dy;
			x += sx;
		}
		if (err2 < dx) {
			err += dx;
			y += sy;
		} 
	} 
}
int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	int x1, y1, x2, y2;
	printf("Enter the coordinates of the first point (x1, y1): ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the coordinates of the second point (x2, y2): ");
	scanf("%d %d", &x2, &y2);
	printf("\nDrawing line using Bresenham's algorithm...\n");

	// Drawing the line using Bresenham's algorithm
	drawLineBresenham(x1, y1, x2, y2);
	printf("\nBresenham's Algorithm Line Drawing Table:\n");
	printf("Step\tX\t\tY\n");
	printf("----------------------------------------------\n");
	int dx = abs(x2 - x1), dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1; int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;	int x = x1, y = y1;
	while (1) {
		printf("%d\t%d\t\t%d\n", abs(x - x1), x, y);
		if (x == x2 && y == y2)
			break;
		int err2 = 2 * err;
		if (err2 > -dy) {
			err -= dy; x += sx;
		}
		if (err2 < dx) {
			err += dx;	y += sy;
		}
	}
	outtextxy(10, 20, "LAB-2.b.Bressenham :: Sumit Budhathoki :: A-36");
	getch();  closegraph();
	return 0;
}