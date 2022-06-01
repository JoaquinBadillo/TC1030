#include <iostream>
#include "shape.hpp"

int main(void)
{
    Rectangle rect(10, 5);
    Circle circ(1);

    std::cout << "Rectangle: \n";
    std::cout << "Area:\t\t" << rect.area() << "\n";
    std::cout << "Perimeter:\t" << rect.perimeter() << "\n\n";

    std::cout << "Circle: \n";
    std::cout << "Area:\t\t" << circ.area() << "\n";
    std::cout << "Perimeter:\t" << circ.perimeter() << "\n";
}