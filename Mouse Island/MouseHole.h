#ifndef MouseIsland_H_INCLUDED
#define MouseIsland_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Board.h"


class MouseHole
{
public:
    MouseHole();
    MouseHole(int Ypos, int Xpos, Board& TwoDimentionalVector);

    void SetYpos(int NewPos);
    void SetXpos(int NewPos);
    int ReturnYPos();
    int ReturnXPos();
    int ReturnPos();
    int ReturnXpos()
    {
        return Xpos;
    }
    int ReturnYpos()
    {
        return Ypos;
    }
private:
    int Ypos;
    int Xpos;
    int MouseHoleSymbol='#';

};

MouseHole::MouseHole()
{
    std::cout << "Creating MouseHole." << std::endl;
}

MouseHole::MouseHole(int Ypos, int Xpos,Board& MyBoard)
{
    this->Ypos=Ypos;
    this->Xpos=Xpos;
    MyBoard.SetPos(Ypos,Xpos,MouseHoleSymbol);
}

int MouseHole::ReturnYPos()
{
    return Ypos;
}

int MouseHole::ReturnXPos()
{
    return Xpos;
}

void MouseHole::SetYpos(int NewPos)
{
    Ypos=NewPos;
}


#endif
