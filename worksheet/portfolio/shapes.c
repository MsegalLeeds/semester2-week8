
#include <stdbool.h>
#include <math.h>

#include "shapes.h"

Point makePoint( float x, float y ) {
    Point new;
    new.x = x;
    new.y = y;
    return new;
}

Line makeLine( Point p1, Point p2 ) {
    Line l;
    l.p[0] = p1;
    l.p[1] = p2;
    return l;
}

Triangle makeTriangle( Point p1, Point p2, Point p3) {
    Triangle t;
    t.p[0] = p1;
    t.p[1] = p2;
    t.p[2] = p3;
    return t;
}

float lineLength( Line l) {
    float xDist = l.p[1].x - l.p[0].x;
    float yDist = l.p[1].y - l.p[0].y;
    return sqrt(xDist*xDist + yDist*yDist);
}

float triangleArea( Triangle t) {
    float diff1 = t.p[1].y - t.p[2].y;
    float diff2 = t.p[2].y - t.p[0].y;
    float diff3 = t.p[0].y - t.p[1].y;
    float area = 0.5 * fabs(t.p[0].x * diff1 + t.p[1].x * diff2 + t.p[2].x * diff3);
    return area;
}

bool samePoint(Point p1, Point p2) {
    return fabs(p1.x - p2.x) < 1.0e-6 && fabs(p1.y - p2.y) < 1.0e-6;
}

bool pointInLine(Point p, Line l) {
    return samePoint(p, l.p[0]) ||
           samePoint(p, l.p[1]);
}

bool pointInTriangle(Point p, Triangle t) {
    return samePoint(p, t.p[0]) ||
           samePoint(p, t.p[1]) ||
           samePoint(p, t.p[2]);
}
