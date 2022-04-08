#ifndef dice_h
#define dice_h

#include <iomanip> // Used for random integer generation
#include <ctime> // Used to generate random seeds
class Dice
{
    public:
        Dice()
        {
            int t = std::time(NULL);
            std::srand(t);
        }

        int roll(void)
        {
            return 1 + std::rand() % 6;
        }
};

#endif