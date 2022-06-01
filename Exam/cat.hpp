#ifndef Cat_h
#define Cat_h

#include "animal.hpp"

#include <iostream>
#include <string>

class Cat: public Animal
{
    private:
        std::string color;
        std::string meow;

    public:
        void setColor(std::string color_);
        void setMeow(std::string meow_);

        std::string getColor();
        std::string getMeow();

        void printInfo();

        void Speak();

        Cat(std::string name_, int age_, std::string color_, std::string meow_);
        Cat();
};

void Cat::setColor(std::string color_)
{
    int n = color_.length();

    color_[0] = toupper(color_[0]);

    for (int i=1; i<n; i++)
    {
        if (color_[i-1] == ' ')
        {
            color_[i] = toupper(color_[i]);
        }
        else
        {
            color_[i] = tolower(color_[i]);
        }
    }

    color = color_;
}

void Cat::setMeow(std::string meow_)
{
    int n = meow_.length();

    meow_[0] = toupper(meow_[0]);

    for (int i=1; i<n; i++)
    {
        if (meow_[i-1] == ' ')
        {
            meow_[i] = toupper(meow_[i]);
        }
        else
        {
            meow_[i] = tolower(meow_[i]);
        }
    }

    meow = meow_;
}

std::string Cat::getColor()
{
    return color;
}

std::string Cat::getMeow()
{
    return meow;
}

void Cat::printInfo()
{
    std::cout << "Name: \t\t" << getName() << std::endl;
    std::cout << "Age: \t\t" << getAge() << std::endl;
    std::cout << "Species: \t" << getSpecies() << std::endl;
    std::cout << "Color: \t\t" << getColor() << std::endl;
    std::cout << "Meow: \t\t" << getMeow() << std::endl;
}

void Cat::Speak()
{
    std::cout << meow << std::endl;
}

Cat::Cat(std::string name_, int age_, std::string color_, std::string meow_): Animal(name_, age_, "Felis silvestris catus")
{
    setColor(color_);
    setMeow(meow_);
}

Cat::Cat(): Animal("Felis silvestris catus")
{
    color = "NA";
    meow = "Meow";
}

#endif