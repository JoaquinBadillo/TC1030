#ifndef System_h
#define System_h

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

#include <iostream>
#include <vector>

class Interface
{
    public:
        virtual void saveCat(Cat& g) = 0;
        virtual void saveDog(Dog& p) = 0;
        virtual void searchCats(int age_) = 0;
        virtual void searchDogs(int age_) = 0;
        virtual void showCats() = 0;
        virtual void showDogs() = 0;
        virtual void menu() = 0;
};

class System: public Interface
{
    private:
        std::vector<Cat*> cats;
        std::vector<Dog*> dogs;

    public:
        void saveCat(Cat& g);
        void saveDog(Dog& p);

        void operator()(Cat& g);
        void operator()(Dog& p);

        void searchCats(int age_);
        void searchDogs(int age_);

        void showCats();
        void showDogs();

        void menu();
        void operator()();
};

void System::saveCat(Cat& g)
{
    cats.push_back(&g);
    std::cout << g.getName() << ": ";
    !g; // Speak
}

void System::saveDog(Dog& p)
{
    dogs.push_back(&p);
    std::cout << p.getName() << ": ";
    !p; // Speak
}

void System::operator()(Cat& g)
{
    this -> saveCat(g);
}

void System::operator()(Dog& p)
{
    this -> saveDog(p);
}

void System::searchCats(int age_)
{
    std::vector<Cat*>::iterator it1;
    int counter = 0;

    for (it1 = cats.begin(); it1 != cats.end(); it1++)
    {
        Cat& cat = *(*it1);

        if (cat.getAge() <= age_)
        {
            if (counter == 0)
            {
                std::cout << "Showing all cats that are " << age_ << " years or less old.\n" << std::endl;
            }

            // Print info
            cat();
            std::cout << std::endl;

            counter++;
        }
    }

    if (counter == 0)
    {
        std::cout << "Sorry, we found no results for your search.\n" << std::endl;
    }
}

void System::searchDogs(int age_)
{   
    std::vector<Dog*>::iterator it2;
    int counter = 0;

    for (it2 = dogs.begin(); it2 != dogs.end(); it2++)
    {
        Dog& dog = *(*it2);

        if (dog.getAge() <= age_)
        {
            if (counter == 0)
            {
                std::cout << "Showing all dogs that are " << age_ << " years or less old.\n" << std::endl;
            }

            // Print info
            dog();
            std::cout << std::endl;

            counter++;
        }
    }

    if (counter == 0)
    {
        std::cout << "Sorry, we found no results for your search.\n" << std::endl;
    }
}

void System::showCats()
{
    std::vector<Cat*>::iterator it1;

    for (it1 = cats.begin(); it1 != cats.end(); it1++)
    {
        Cat& cat = *(*it1);

        // Print info
        cat();
        std::cout << std::endl;
    }
}

void System::showDogs()
{
    std::vector<Dog*>::iterator it2;

    for (it2 = dogs.begin(); it2 != dogs.end(); it2++)
    {  
        Dog& dog = *(*it2);

        // Print info
        dog();
        std::cout << std::endl;
    }
}

void System::menu()
{
    std::cout << "Choose one of the following options: " << std::endl;
    std::cout << "1. Show all dogs." << std::endl;
    std::cout << "2. Show all cats." << std::endl;
    std::cout << "3. Search dogs by age." << std::endl;
    std::cout << "4. Search cats by age." << std::endl;
    std::cout << "0. Exit." << std::endl;

    std::cout << std::endl;
}

void System::operator()()
{
    this -> menu();
}

#endif