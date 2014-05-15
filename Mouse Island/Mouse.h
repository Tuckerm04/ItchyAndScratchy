#ifndef MouseHole_H_INCLUDED
#define MouseHole_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Board.h"


class Mouse
{
public:
    Mouse();
    Mouse(int Ypos, int Xpos, Board& TwoDimentionalVector);
    void MoveUp(Board& TwoDimentionalVector);
    void MoveDown(Board& TwoDimentionalVector);
    void MoveLeft(Board& TwoDimentionalVector);
    void MoveRight(Board& TwoDimentionalVector);
    void StayInPos(Board& TwoDimentionalVector);
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
    int MouseSymbol='1';

};

Mouse::Mouse()
{
    std::cout << "Creating Mouse." << std::endl;
}

Mouse::Mouse(int Ypos, int Xpos,Board& MyBoard)
{
    this->Ypos=Ypos;
    this->Xpos=Xpos;
    MyBoard.SetPos(Ypos,Xpos,MouseSymbol);
}

void Mouse::MoveUp(Board& TwoDimentionalVector)
{
    int YPrevPos=Ypos;
    Ypos--;
    TwoDimentionalVector.SetPos(Ypos,Xpos,MouseSymbol);
    TwoDimentionalVector.SetPos(YPrevPos,Xpos,0);
}
void Mouse::MoveDown(Board& TwoDimentionalVector)
{
    int YPrevPos=Ypos;
    Ypos++;
    TwoDimentionalVector.SetPos(Ypos,Xpos,MouseSymbol);
    TwoDimentionalVector.SetPos(YPrevPos,Xpos,0);
}

void Mouse::MoveLeft(Board& TwoDimentionalVector)
{
    int XPrevPos=Xpos;
    Xpos--;
    TwoDimentionalVector.SetPos(Ypos,Xpos,MouseSymbol);
    TwoDimentionalVector.SetPos(Ypos,XPrevPos,0);
}
void Mouse::MoveRight(Board& TwoDimentionalVector)
{
    int XPrevPos=Xpos;
    Xpos++;
    TwoDimentionalVector.SetPos(Ypos,Xpos,MouseSymbol);
    TwoDimentionalVector.SetPos(Ypos,XPrevPos,0);
}

void Mouse::StayInPos(Board& TwoDimentionalVector)
{
   TwoDimentionalVector.SetPos(Ypos,Xpos,MouseSymbol);
}




int Mouse::ReturnYPos()
{
    return Ypos;
}

int Mouse::ReturnXPos()
{
    return Xpos;
}

void Mouse::SetYpos(int NewPos)
{
    Ypos=NewPos;
}

void Mouse::SetXpos(int NewPos)
{
    Xpos=NewPos;
}
#endif
