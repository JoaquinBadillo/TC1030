#include <iostream>

#include "system.hpp"

int main(void)
{
    // Initialization
    System sys;

    std::string input1 = " ";
    char option = ' ';
    std::string stringAge = " ";
    int age = 0;

    std::string cont = " ";


    std::cout << "Welcome to the Happy Animals Shelter\n" << std::endl;

    // Add cats to system
    Cat c1("Garfield", 10, "Orange", "Hi");
    Cat c2("Linux", 12, "Black", "Meeowww");
    Cat c3("Felix", 8, "White", "Meow Meow");
    Cat c4("Apolo", 5, "Gray", "Mewoooowww");
    sys(c1);
    sys(c2);
    sys(c3);
    sys(c4);


    std::cout << std::endl;

    // Add dogs to system
    Dog d1("Doge", 6, "Yorkshire Terrier", "Ruff");
    Dog d2("Zeus", 7, "Bulldog", "Wow");
    Dog d3("Arctic", 8, "Husky", "Aroooo");
    Dog d4("Bolt", 9, "Harrier", "Wuff");
    sys(d1);
    sys(d2);
    sys(d3);
    sys(d4);

    std::cout << std::endl;

    do
    {
        try
        {
            sys();
            std::cout << "Option: ";

            std::getline(std::cin, input1);
            if (input1.size() != 1)
            {
                throw 2;
            }

            option = input1[0];

            switch (option)
            {
                case '0':
                    break;

                case '1':
                    sys.showDogs();
                    break;
                
                case '2':
                    sys.showCats();
                    break;
                
                case '3':
                    try
                    {
                        std::cout << "Enter the desired age: ";
                        std::getline(std::cin, stringAge);
                        age = std::stoi(stringAge);
                        sys.searchDogs(age);
                    }
                    catch (const std::invalid_argument& ia)
                    {
                        std::cerr << "Error 3: Invalid argument, " << ia.what() << " cannot cast your input to int." << "\n\n";
                    }
                    break;
            
                case '4':
                    try
                    {
                        std::cout << "Enter the desired age: ";
                        std::getline(std::cin, stringAge);
                        age = std::stoi(stringAge);
                        sys.searchCats(age);
                    }
                    catch (const std::invalid_argument& ia)
                    {
                        std::cerr << "Error 3: Invalid argument, " << ia.what() << " cannot cast your input to int." << "\n\n";
                    }
                    break;
                    
                default:
                    throw 1;
            }
        }
        catch(int errorNumber)
        {
            std::cerr << "Error " << errorNumber;
            if (errorNumber == 1)
            {
                std::cerr << ": Invalid option. \n" << std::endl;
            }
            else if (errorNumber == 2)
            {
                std::cerr << ": Invalid input length. \n" << std::endl;
            }
        }

        std::cout << "Press enter to continue: ";
        std::getline(std::cin, cont);
        std::cout << std::endl;
    } while (option != '0');
    
    std::cout << "Success." << std::endl;
    return 0;
}