#ifndef tiles_h
#define tiles_h

#include <iostream>
#include <string>

class Tile
{
    protected:
        std::string tileType = "\0";
        int num = 0;

        // Determines if there is a player standing on this tile. Index 0 corresponds to p1, index 1 to p2.
        int state[2]; 
        int bonus = 0;
    
    public:
        // Constructor
        Tile()
        {
            state[0], state[1] = 0; 
        }

        Tile(int num_, std::string tileType_)
        {
            if (num_ > 0)
            {
                num = num_;
            }

            else
            {
                std::cout << "Error: must use natural number greater than 1" << std::endl;
            }

            if (tileType_ == "N")
            {
                tileType = tileType_;
            }

            else if (tileType_ == "S")
            {
                tileType = tileType_;
                bonus = -3;
            }

            else if (tileType_ == "L")
            {
                tileType = tileType_;
                bonus = 3;
            }

            else
            {
                std::cout << "Error: Invalid tile type" << std::endl;
            }

            state[0] = 0;
            state[1] = 0;
        }

        // Setters
        void setState(int status)
        {
            if (status == 1)
            {
                state[0] = 1;
            }
            else if (status == 2)
            {
                state[1] = 2;
            }
            else
            {
                std::cout << "Error: Only 2 players allowed" << std::endl;
            }
        }

        void resetState(int i)
        {
            state[i-1] = 0;
        }

        std::string text()
        {
            // Method to facilitate display
            std::string out = tileType + ":" + std::to_string(num) + "\t";
            
            if (state[0] == 0)
            {
                if (state[1] == 0)
                {
                    out += "[ | ]";
                }
                else if (state[1] == 2)
                {
                    out += "[ |2]";
                }
            }

            else if (state[0] == 1)
            {
                if (state[1] == 0)
                {
                    out += "[1| ]";
                }
                else if (state[1] == 2)
                {
                    out += "[1|2]";
                }
            }

            return out;
        }

        int getBonus()
        {
            return bonus;
        }

        int getNum()
        {
            return num;
        }
};

#endif