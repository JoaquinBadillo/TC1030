#include <iostream>
#include "Shapes.h"

int main() {
    Shape s1(1, 2);
    Circle c1(1, 2, 1);
    Triangle t1(0, 0, 1, 1, "Right-angled");
    Rectangle r1(0, 0, 2, 1);
        
    Shape* shapes[5];

    shapes[0] = &c1;
    shapes[1] = new Rectangle();
    shapes[2] = new Rectangle(1, 2, 3, 4);
    shapes[3] = new Circle(2, 3, 5);

    for (int i = 0; i < 4; i++)
    {
        Shape* current = shapes[i];

        std::cout << current -> draw() << "\n";
    }
    return 0;
}
