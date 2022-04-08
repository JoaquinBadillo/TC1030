#ifndef ClassMethod_h
#define ClassMethod_h

#include <iostream>

class InternalMethods
{
    public:
        void myMethod()
        {
            std::cout << "This is an internal method" << std::endl;
        }
};

class ExternalMethods
{
    public:
        void myMethod();
};

void ExternalMethods::myMethod()
{
    std::cout << "This is an external method" << std::endl;
}
#endif