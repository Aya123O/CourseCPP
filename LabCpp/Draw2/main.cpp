#include <iostream>
#include <graphics.h>

using namespace std;

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() { return x; }
    int getY() { return y; }
};

class Shape {
protected:
    int color;

public:
    Shape(int col = WHITE) : color(col) {}

    void setColor(int col) {
        color = col;
    }

    int getColor() {
        return color;
    }

    void draw() {}
};

class Line : public Shape {
private:
    Point start;
    Point end;

public:
    Line(int x1, int y1, int x2, int y2, int col = WHITE)
        : Shape(col), start(x1, y1), end(x2, y2) {}

    void draw() {
        setcolor(color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect : public Shape {
private:
    Point ul;
    Point lr;

public:
    Rect(int x1, int y1, int x2, int y2, int col = WHITE)
        : Shape(col), ul(x1, y1), lr(x2, y2) {}

    void draw() {
        setcolor(color);
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
        setfillstyle(SOLID_FILL, color);
        floodfill((ul.getX() + lr.getX()) / 2, (ul.getY() + lr.getY()) / 2, color);
    }
};

class Circle : public Shape {
private:
    Point center;
    int radius;

public:
    Circle(int x, int y, int r, int col = WHITE)
        : Shape(col), center(x, y), radius(r) {}

    void draw() {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
        setfillstyle(SOLID_FILL, color);
        floodfill(center.getX(), center.getY(), color);
    }
};

class Picture {
private:
    int cNum, rNum, lNum;
    Circle* pCircles;
    Rect* pRects;
    Line* pLines;

public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr) {}

    void setCircles(int cn, Circle* pC) {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rect* pR) {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line* pL) {
        lNum = ln;
        pLines = pL;
    }

    void paint() {
        for (int i = 0; i < cNum; i++) {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++) {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++) {
            pLines[i].draw();
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Picture myPic;

    Circle cArr[3] = { Circle(100, 100, 50, RED), Circle(300, 100, 75, GREEN), Circle(500, 100, 30, BLUE) };
    Rect rArr[2] = { Rect(50, 200, 200, 300, YELLOW), Rect(300, 200, 500, 350, CYAN) };
    Line lArr[2] = { Line(50, 400, 200, 450, MAGENTA), Line(300, 400, 500, 450, WHITE) };

    myPic.setCircles(3, cArr);
    myPic.setRects(2, rArr);
    myPic.setLines(2, lArr);

    myPic.paint();

    getch();
    closegraph();

    return 0;
}
