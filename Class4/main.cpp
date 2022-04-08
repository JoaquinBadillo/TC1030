#include <iostream>
#include "Shapes.h"

int main() {
    Shape f1(1, 2);

    Circle c1(1, 2, 1);

    Triangle t1(0, 0, 1, 1, "Right-angled");

    Rectangle r1(0, 0, 2, 1);
    

    std::cout << "Shape:" << std::endl;
    std::cout << f1.draw() << "\nCon valor x en: " << f1.getValueX() << "\nCon valor y en: " << f1.getValueY() << std::endl;
    
    std::cout << std::endl;

    std::cout << "Circle:" << std::endl;   
    std::cout << c1.draw() << "\nCon valor x en: " << c1.getValueX() << "\nCon valor y en: " << c1.getValueY() << "\nCon radio: " << c1.getValueR() << std::endl;
    
    std::cout << std::endl;

    std::cout << "Triangle:" << std::endl;   
    std::cout << t1.draw() << "\nCon valor x en: " << t1.getValueX() << "\nCon valor y en: " << t1.getValueY() << "\nCon lado: " << t1.getSide() << "\nCon altura: " << t1.getHeight() << "\nDe tipo: " << t1.getType() << std::endl;

    std::cout << std::endl;

    std::cout << "Rectangle:" << std::endl;   
    std::cout << r1.draw() << "\nCon valor x en: " << r1.getValueX() << "\nCon valor y en: " << r1.getValueY() << "\nCon ancho: " << r1.getWidth() << "\nCon altura: " << r1.getHeight() << std::endl;
    
    Shape *shapes[5];

    shapes[0] = &c1;
    shapes[1] = new Rectangle();
    shapes[2] = new Rectangle(1, 2, 3, 4);
    shapes[3] = new Circle(2, 3, 5);

    for (int i = 0; i < 4; i++)
    {
        Shape *current = shapes[i];

        std::cout << current -> draw() << "\n";
    }
    return 0;
}
