#include <iostream>

#include "cartesianPoint.hpp"
#include "polarPoint.hpp"

int main(int argc, const char * argv[])
{
    CartesianPoint r1(1,2);
    CartesianPoint r2(2,4);

    std::cout << "In rectangular coordinates: " << std::endl;

    CartesianPoint r3 = r1 + r2;
    std::cout << "(1,2) + (2,4) = ";
    std::cout << "(" << r3.getX() << "," << r3.getY() << ")\n";

    CartesianPoint r4 = r1 - r2;
    std::cout << "(1,2) - (2,4) = ";
    std::cout << "(" << r4.getX() << "," << r4.getY() << ")\n";

    std::cout << "To verify operators are inverses of each other" << std::endl;

    CartesianPoint r5 = r1 + (r2 - r2);
    std::cout << "(1,2) + [(2,4) - (2,4)] = ";
    std::cout << "(" << r5.getX() << "," << r5.getY() << ")\n";

    CartesianPoint r6 = (r1 + r2) - r2;
    std::cout << "[(1,2) + (2,4)] - (2,4) = ";
    std::cout << "(" << r6.getX() << "," << r6.getY() << ")\n\n";

    std::cout << "In polar coordinates: " << std::endl;
    PolarPoint p1(3, 160);
    PolarPoint p2 (7, 20);

    PolarPoint p3 = p1 * p2;
    std::cout << "(3,160°) * (7,20°) = ";
    std::cout << "(" << p3.getR() << "," << p3.getTheta() << "°)\n";
    
    PolarPoint p4 = p1 / p2;
    std::cout << "(3,160°) / (7,20°) = ";
    std::cout << "(" << p4.getR() << "," << p4.getTheta() << "°)\n";

    std::cout << "To verify operators are inverses of each other" << std::endl;

    PolarPoint p5 = p1 * (p2 / p2);
    std::cout << "(3,160°) * [(7,20°) / (7,20°)] = ";
    std::cout << "(" << p5.getR() << "," << p5.getTheta() << "°)\n";

    PolarPoint p6 = (p1 * p2) / p2;
    std::cout << "[(3,160°) * (7,20°)] / (7,20°) = ";
    std::cout << "(" << p6.getR() << "," << p6.getTheta() << "°)\n\n";

    return 0;
}