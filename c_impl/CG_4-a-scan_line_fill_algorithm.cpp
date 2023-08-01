#include <iostream>
#include <graphics.h>

struct Point {
    int x, y;
};

void drawLine(Point p1, Point p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

void scanLineFill(Point points[], int n) {
    int minY = points[0].y;
    int maxY = points[0].y;

    // Find the minimum and maximum Y-coordinates of the polygon
    for (int i = 1; i < n; ++i) {
        if (points[i].y < minY) {
            minY = points[i].y;
        }
        if (points[i].y > maxY) {
            maxY = points[i].y;
        }
    }

    // Iterate through scan lines
    for (int y = minY; y <= maxY; ++y) {
        int xIntersections[20]; // Maximum 20 intersections per scan line
        int numIntersections = 0;

        // Find intersections of scan line with polygon edges
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            if ((points[i].y > y && points[j].y <= y) || (points[j].y > y && points[i].y <= y)) {
                int x = points[i].x + (y - points[i].y) * (points[j].x - points[i].x) / (points[j].y - points[i].y);
                xIntersections[numIntersections++] = x;
            }
        }

        // Sort intersections to fill the scan line
        for (int i = 0; i < numIntersections - 1; ++i) {
            for (int j = 0; j < numIntersections - i - 1; ++j) {
                if (xIntersections[j] > xIntersections[j + 1]) {
                    int temp = xIntersections[j];
                    xIntersections[j] = xIntersections[j + 1];
                    xIntersections[j + 1] = temp;
                }
            }
        }

        // Draw lines between intersections to fill the scan line
        for (int i = 0; i < numIntersections; i += 2) {
            drawLine({ xIntersections[i], y }, { xIntersections[i + 1], y });
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int n;
    std::cout << "Enter the number of vertices of the polygon: ";
    std::cin >> n;

    if (n < 3) {
        std::cout << "A polygon must have at least 3 vertices!" << std::endl;
        closegraph();
        return 1;
    }

    Point points[20]; // Maximum 20 vertices for the polygon
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter x-coordinate and y-coordinate of vertex " << i + 1 << ": ";
        std::cin >> points[i].x >> points[i].y;
        outtextxy(10, 20, "LAB-4.a.Scan line fill alg :: Sumit Budhathoki :: A-36");
    }

    // Close the polygon by connecting the last vertex with the first one
    points[n] = points[0];

    scanLineFill(points, n);

    getch();
    closegraph();
    return 0;
}
