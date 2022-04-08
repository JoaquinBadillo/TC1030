#include <iostream>
#include "myClass.hpp"
#include "classMethod.hpp"

int main()
{
    FirstClass myObj;

    myObj.Num = 15;
    myObj.String = "Hola mundo";

    std::cout << "Num: " << myObj.Num << std::endl;
    std::cout << "String: " << myObj.String << std::endl;
    std::cout << "Att Num: " << myObj.classAttNum << std::endl;

    std::cout << std::endl;

    InternalMethods obj1;
    obj1.myMethod();

    ExternalMethods obj2;
    obj2.myMethod();

    return 0;
}