#ifndef Board_H_INCLUDED
#define Board_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>
#include <curses.h>

///This is the two dimensional vector that is printed
///to the screen
class Board
{
public:
    Board();

    void PrintBoard();
    void FillBoard(int Columns, int Rows);
    int ReturnPos(int YPos,int XPos)
    {
        return TwoDimentionalVector[YPos][XPos];
    }
    void SetPos(int YPos,int XPos,int Value)
    {
        TwoDimentionalVector[YPos][XPos]=Value;
    }
public:
    std::vector < std::vector <char> > TwoDimentionalVector;
    std::vector<char> OneDimentionalVector;
    int Columns;
    int Rows;
};

Board::Board()
{

}

void Board::FillBoard(int Columns, int Rows)
{
    this->Columns=Columns;
    this->Rows=Rows;

   for(int i=0; i<Columns; i++)
    {
        OneDimentionalVector.push_back(0);
    }
    for(int i=0; i<Rows; i++)
    {
        TwoDimentionalVector.push_back(OneDimentionalVector);
    }
}


void Board::PrintBoard()
{
    int BridgeXpos=Columns/2;
    int BridgeYpos=Rows/2;
   for(int i=0; i<Columns; i++)
    {
        TwoDimentionalVector[0][i]='W';
        TwoDimentionalVector[Rows-1][i]='W';


        //TwoDimentionalVector[i][0]='W';
       //TwoDimentionalVector[i][Columns-2]='W';
        //TwoDimentionalVector[i][0]='W';
        for(int j=0; j<Rows; j++)
        {
            TwoDimentionalVector[j][0]='W';
            TwoDimentionalVector[j][Columns-1]='W';

/*
            TwoDimentionalVector[1][j]='W';
            TwoDimentionalVector[Rows-2][j]='W';
            */
            //TwoDimentionalVector[Rows-2][BridgeXpos]='B';
            TwoDimentionalVector[BridgeYpos][Columns-1]='B';
            //  TwoDimentionalVector[BridgeYpos][Columns-2]='B';
              TwoDimentionalVector[Rows-1][BridgeXpos]='B';
              /*
              TwoDimentionalVector[0][1]=0;
              TwoDimentionalVector[1][0]=0;
               TwoDimentionalVector[0][Columns-2]=0;
               TwoDimentionalVector[1][Columns-1]=0;
               TwoDimentionalVector[Rows-2][0]=0;
               TwoDimentionalVector[Rows-1][1]=0;
               TwoDimentionalVector[Rows-1][Columns-2]=0;
               TwoDimentionalVector[Rows-2][Columns-1]=0;
*/
             std::cout << TwoDimentionalVector[j][i] << " ";
        }
       std::cout << std::endl;






    }


}





#endif
