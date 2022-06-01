#ifndef Dog_h
#define Dog_h

#include "animal.hpp"

#include <iostream>
#include <string>

class Dog: public Animal
{
    private:
        std::string breed;
        std::string bark;

    public:
        void setBreed(std::string breed_);
        void setBark(std::string bark_);

        std::string getBreed();
        std::string getBark();

        void printInfo();

        void Speak();

        Dog(std::string name_, int age_, std::string breed, std::string bark);
        Dog();
};

void Dog::setBreed(std::string breed_)
{
    int n = breed_.length();

    breed_[0] = toupper(breed_[0]);

    for (int i=1; i<n; i++)
    {
        if (breed_[i-1] == ' ')
        {
            breed_[i] = toupper(breed_[i]);
        }
        else
        {
            breed_[i] = tolower(breed_[i]);
        }
    }

    breed = breed_;
}

void Dog::setBark(std::string bark_)
{
    int n = bark_.length();

    bark_[0] = toupper(bark_[0]);

    for (int i=1; i<n; i++)
    {
        if (bark_[i-1] == ' ')
        {
            bark_[i] = toupper(bark_[i]);
        }
        else
        {
            bark_[i] = tolower(bark_[i]);
        }
    }

    bark = bark_;
}

std::string Dog::getBreed()
{
    return breed;
}

std::string Dog::getBark()
{
    return bark;
}

void Dog::printInfo()
{
    std::cout << "Name: \t\t" << getName() << std::endl;
    std::cout << "Age: \t\t" << getAge() << std::endl;
    std::cout << "Species: \t" << getSpecies() << std::endl;
    std::cout << "Breed: \t\t" << getBreed() << std::endl;
    std::cout << "Bark: \t\t" << getBark() << std::endl;
}

void Dog::Speak()
{
    std::cout << getBark() << std::endl;
}

Dog::Dog(std::string name_, int age_, std::string breed_, std::string bark_): Animal(name_, age_, "Canis familiaris")
{
    setBreed(breed_);
    setBark(bark_);
}

Dog::Dog(): Animal("Canis familiaris")
{
    breed = "NA";
    bark = "Wow";
}

#endif