#ifndef player_h
#define player_h

#include <iostream>

class Player
{
    private:
        int x;
        int y;
    
    public:
        Player()
        {
            x = 0;
            y = 0;
        }

        void move(int score)
        {
            if (score >= 0)
            {
                for (int i=0; i < score; i++)
                {
                    if (x < 5)
                    {
                        x++;
                    }
                    else if (y < 4)
                    {
                        x = 0;
                        y++;
                    }
                    else if (x > 0)
                    {
                        x--;
                    }
                    else if (y > 0)
                    {
                        x = 6;
                        y--;
                    }
                }
            }
        }

        void bonusMove(int bonus)
        {
            if (bonus == 3)
            {
                move(3);
            }

            else if (bonus == -3)
            {
                for (int i=3; i > 0; i--)
                {
                    if (x > 0)
                    {
                        x--;
                    }
                    else if (y > 0)
                    {
                        y--;
                        x=5;
                    }
                }
            }
        }

        int getPositionX()
        {
            return x;
        }

        int getPositionY()
        {
            return y;
        }
};

#endif