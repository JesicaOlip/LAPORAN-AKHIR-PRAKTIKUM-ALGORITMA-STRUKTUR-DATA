#include "circle.h"
#include <cmath>

double distance(const Circle * c, const Point * p){
    double dx = p->x - c->centre.x;
    double dy = p->y - c->centre.y;
    return sqrt(dx*dx + dy*dy);
}
 
std::string CheckPointInCircle(double distance){
    if (distance > EPSILON)  return "Outside";
    if (distance < -EPSILON) return "Inside";
    return "On Circle";
}