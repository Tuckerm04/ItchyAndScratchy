#ifndef Cat_H_INCLUDED
#define Cat_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>

class Cat
{
public:
    Cat();
    Cat(int Ypos, int Xpos, Board& TwoDimentionalVector);
    void MoveUp(Board& TwoDimentionalVector);
    void MoveDown(Board& TwoDimentionalVector);
    void MoveLeft(Board& TwoDimentionalVector);
    void MoveRight(Board& TwoDimentionalVector);
    void StayInPos(Board& TwoDimentionalVector)
    {
       Ypos=Ypos;
       Xpos=Xpos;
    }

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
    int CatSymbol='2';

};

Cat::Cat()
{
    std::cout << "Creating Cat." << std::endl;
}

Cat::Cat(int Ypos, int Xpos,Board& MyBoard)
{
    this->Ypos=Ypos;
    this->Xpos=Xpos;
    MyBoard.SetPos(Ypos,Xpos,CatSymbol);
}

void Cat::MoveUp(Board& TwoDimentionalVector)
{
    int YPrevPos=Ypos;
    Ypos--;
    TwoDimentionalVector.SetPos(Ypos,Xpos,CatSymbol);
    TwoDimentionalVector.SetPos(YPrevPos,Xpos,0);
}
void Cat::MoveDown(Board& TwoDimentionalVector)
{
    int YPrevPos=Ypos;
    Ypos++;
    TwoDimentionalVector.SetPos(Ypos,Xpos,CatSymbol);
    TwoDimentionalVector.SetPos(YPrevPos,Xpos,0);
}

void Cat::MoveLeft(Board& TwoDimentionalVector)
{
    int XPrevPos=Xpos;
    Xpos--;
    TwoDimentionalVector.SetPos(Ypos,Xpos,CatSymbol);
    TwoDimentionalVector.SetPos(Ypos,XPrevPos,0);
}
void Cat::MoveRight(Board& TwoDimentionalVector)
{
    int XPrevPos=Xpos;
    Xpos++;
    TwoDimentionalVector.SetPos(Ypos,Xpos,CatSymbol);
    TwoDimentionalVector.SetPos(Ypos,XPrevPos,0);
}
#endif
