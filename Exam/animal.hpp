#ifndef Animal_h
#define Animal_h

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string name;
        int age;
        std::string species;
        
    public:
        void setName(std::string name_);
        void setAge(int age_);
        void setSpecies(std::string species_);

        std::string getName();
        int getAge();
        std::string getSpecies();

        virtual void Speak();
        void operator!();

        virtual void printInfo();
        void operator()();

        Animal(std::string name_, int age_, std::string species_);
        Animal(std::string species_);
        Animal();
};

void Animal::setName(std::string name_)
{
    int n = name_.length();
    name_[0] = toupper(name_[0]);

    for (int i=1; i<n; i++)
    {
        if (name_[i-1] == ' ')
        {
            name_[i] = toupper(name_[i]);
        }
        else
        {
            name_[i] = tolower(name_[i]);
        }
    }

    name = name_;
}

void Animal::setAge(int age_)
{
    if (age_ >= 0)
    {
        age = age_;
    }
    else
    {
        std::cerr << "Error: Invalid age" << std::endl;
    }
}


void Animal::setSpecies(std::string species_)
{
    int n = species_.length();
    species_[0] = toupper(species_[0]);

    for (int i=1; i<n; i++)
    {
        species_[i] = tolower(species_[i]);
    }

    species = species_;
}

std::string Animal::getName()
{
    return name;
}

int Animal::getAge()
{
    return age;
}

std::string Animal::getSpecies()
{
    return species;
}

void Animal::Speak()
{
    std::cout << " " << std::endl;
}

void Animal::operator!()
{
    this -> Speak();
}

void Animal::printInfo()
{
    std::cout << "Name: \t\t" << getName() << std::endl;
    std::cout << "Age: \t\t" << getAge() << std::endl;
    std::cout << "Species: \t\t" << getSpecies() << std::endl;
}

void Animal::operator()()
{
    this -> printInfo();
}


Animal::Animal(std::string name_, int age_, std::string species_)
{
    setName(name_);
    setAge(age_);
    setSpecies(species_);
}

Animal::Animal(std::string species_)
{
    name = "NA";
    age = 0;
    setSpecies(species_);
}

Animal::Animal()
{
    name = "NA";
    age = 0;
    species = "NA";
}
#endif