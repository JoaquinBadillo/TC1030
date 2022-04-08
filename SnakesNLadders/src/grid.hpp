#ifndef grid_h
#define grid_h

#include <string>
#include <cmath>
#include "tiles.hpp"
#include "player.hpp"


class Grid
{
    protected:
        Tile layout[5][6];

    public:
        Grid()
        {
            // Default Constructor: Creates a 5 by 6 Grid of "Tiles" with 3 Snake tiles and 3 Ladder tiles.
            int num = 1;

            for (int i=0; i<5; i++)
            {
                for (int j=0; j<6; j++)
                {
                    if (num % 10 == 4)
                    {
                        layout[i][j] = Tile(num, "S");
                    }
                    else if (num % 10 == 6)
                    {
                        layout[i][j] = Tile(num, "L");
                    }
                    else
                    {
                        layout[i][j] = Tile(num, "N");
                    }

                    num++;
                }
            }
        }

        void printGrid(void)
        {
            // Display grid in terminal
            for (int i=0; i<5; i++)
            {
                for (int j=0; j<6; j++)
                {
                    std::cout << layout[i][j].text() << "\t";
                }
                std::cout << "\n\n";
            }
        }

        void updateLayout(Player gamer, int gamerID)
        {
            layout[gamer.getPositionY()][gamer.getPositionX()].setState(gamerID);
        }

        void updateLayout(int previousX, int previousY, Player gamer, int gamerID)
        {
            layout[previousY][previousX].resetState(gamerID);
            layout[gamer.getPositionY()][gamer.getPositionX()].setState(gamerID);
        }

        int tileBonus(int x, int y)
        {
            return layout[y][x].getBonus();
        }

        int tileNum(int x, int y)
        {
            return layout[y][x].getNum();
        }
};

#endif