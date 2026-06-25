#include <iostream>
#include "circle.h"
#include "point.h"

int main(){
    Circle c;
    Point p;

    std::cin >> c.centre.x >> c.centre.y >> c.radius >> p.x >> p.y;

    double d = distance(&c, &p);
    
    std::cout << CheckPointInCircle(d - c.radius) << std::endl;

    return 0;
} 