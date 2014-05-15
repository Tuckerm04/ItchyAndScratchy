///The input file is structured as so:
///int Size of map (for some reason map doesnt print if is it isnt square)
///int Number of time to run simulation
///string name of file to put results in

///The program moves mouse and cat in random directions
///mouse can drown, be caught by cat, and get away on bridge
///all other scenarios were never implemented.
///W's represent Water
///B's represent Bridges


#include <iostream>
#include <vector>
#include "Mouse.h"
#include "Cat.h"
#include "Board.h"
#include "MouseHole.h"
#include <ctime>
#include <fstream>
#include "Windows.h"


using namespace std;


int ReturnRandNumfrom1to4();
void CatMoveInRandDir(Board& GameBoard,Cat& Scratchy);
void MouseMoveInRandDir(Board& GameBoard,Mouse& Itchy);
int MovingAroundLoop(int BoardLength, int BoardWidth, int TimesToRun);
bool DidScratchyCatchItchy(Board& MyNewBoard,Cat& Scratchy,Mouse& Itchy);
int FileContents(string NameOfFile);
vector<int> OpenFileAndPutIntsInVector(string Infilename);
bool ItchyDrowned(Board& GameBoard, Mouse Itchy);
void OutputFile(string OutputFileName, vector<string> OutFileContents, vector<int> OutFileNumbers); // This function takes the name of your new file
vector<string> OpenFileAndPutStringsInVector(string Infilename);
bool DidScratchyFindItchyInHole(Board& MyNewBoard, Cat& Scratchy, Mouse& Itchy, MouseHole& Hole);


int main()
{
    /*
    cout << endl << endl;
  Board Fuck;
  Fuck.FillBoard(10,15);
  Fuck.PrintBoard();
*/
    string Infilename;
    cout << "Enter the name of the file that has the board size in it. ";  // Getting a file from the user
    cin  >> Infilename;
    vector<string> MyStringVector=OpenFileAndPutStringsInVector(Infilename);
    vector<int> MyIntVector=OpenFileAndPutIntsInVector(Infilename);


    int NumOfTimesToRun=MyIntVector[0];
    int BoardLength=MyIntVector[1];
    int BoardWidth=MyIntVector[2];
    cout << NumOfTimesToRun<<endl;
    string Letter=MyStringVector[3];
    cout << Letter << endl;




    int Counter=0;
    int timesDrowned=0;
    int timesCaught=0;
    int timesescaped=0;
    int timesGotLucky=0;
    while(Counter<NumOfTimesToRun)
    {
        int Results=MovingAroundLoop(BoardLength, BoardWidth, NumOfTimesToRun);
        if(Results==1)
        {
            timesDrowned++;
        }
        else if(Results==2)
        {
            timesCaught++;
        }

        else if(Results==3)
        {
            timesescaped++;
        }
        else if (Results==4)
        {
            timesGotLucky++;
        }

        Counter++;
    }
    string FirstString="times Caught=";
    string SecondString="times Drowned=";
    string ThirdString="times escaped=";
    string FourthString="times got Lucky=";


    vector<string> StringVector;
    StringVector.push_back(FirstString);
    StringVector.push_back(SecondString);
    StringVector.push_back(ThirdString);
    StringVector.push_back(FourthString);
    vector<int> IntVector;
    IntVector.push_back(timesCaught);
    IntVector.push_back(timesDrowned);
    IntVector.push_back(timesescaped);
    IntVector.push_back(timesGotLucky);

    OutputFile(Letter,StringVector,IntVector);


    //vector<int> Info=MovingAroundLoop(MyNewBoard,Scratchy,Itchy,NumOfTimesToRun);
    //cout << "times Caught=" << Info[0] << "." << endl;
   // cout << "Times drowned=" << Info[1] << "." << endl;



return 0;
}



int ReturnRandNumfrom1to4()
{
   int RandInt;
        srand(time(0));
        RandInt=1+rand()%4;
        return RandInt;
}

void CatMoveInRandDir(Board& GameBoard,Cat& Scratchy)
{
        int RandNum=ReturnRandNumfrom1to4();
            if(RandNum==1)
            {
                Scratchy.MoveDown(GameBoard);
                //Scratchy.IncrementYpos();
                cout << string(100,'\n');
                GameBoard.PrintBoard();
            }
            if(RandNum==2)
            {
                Scratchy.MoveUp(GameBoard);
                //Scratchy.DecrementYpos();
                cout << string(100,'\n');
                GameBoard.PrintBoard();
            }
            if(RandNum==3)
            {
                Scratchy.MoveLeft(GameBoard);
                //Scratchy.DecrementXpos();
                cout << string(100,'\n');
                GameBoard.PrintBoard();
            }
            if(RandNum==4)
            {
                Scratchy.MoveRight(GameBoard);
    //Scratchy.IncrementXpos();
                cout << string(100,'\n');
                GameBoard.PrintBoard();
            }

}

void MouseMoveInRandDir(Board& GameBoard,Mouse& Itchy)
{
    int RandNum=ReturnRandNumfrom1to4();
            if(RandNum==4)
            {
                Itchy.MoveDown(GameBoard);
                //Scratchy.IncrementYpos();
                cout << string(100,'\n');
                GameBoard.PrintBoard();
            }
            if(RandNum==3)
            {
                Itchy.MoveUp(GameBoard);
                //Scratchy.DecrementYpos();
                cout << string(100,'\n');
                GameBoard.PrintBoard();
            }
            if(RandNum==2)
            {
                Itchy.MoveLeft(GameBoard);
                //Scratchy.DecrementXpos();
                cout << string(100,'\n');
                GameBoard.PrintBoard();
            }
            if(RandNum==1)
            {
                Itchy.MoveRight(GameBoard);
    //Scratchy.IncrementXpos();
                cout << string(100,'\n');
                GameBoard.PrintBoard();
            }
}

int MovingAroundLoop(int BoardLength, int BoardWidth, int TimesToRun)
{
    int timesCaught=0;
    int TimesDrowned=0;
    int LoopInt=0;
    int Counter=0;
    Board MyNewBoard;
    MyNewBoard.FillBoard(BoardLength,BoardWidth);
    Mouse Itchy(2,3,MyNewBoard);
    Cat Scratchy(3,3,MyNewBoard);
      MouseHole Hole(3,5,MyNewBoard);
    MyNewBoard.PrintBoard();



while(1)
{
/*
       int input;

       cout << "enter 1" << endl;
    cin >>input;
*/
        //Sleep(0700);
        if(MyNewBoard.ReturnPos(Scratchy.ReturnYpos()+1,Scratchy.ReturnXpos())!='B'
           &&MyNewBoard.ReturnPos(Scratchy.ReturnYpos()-1,Scratchy.ReturnXpos())!='B'
           &&MyNewBoard.ReturnPos(Scratchy.ReturnYpos(),Scratchy.ReturnXpos()-1)!='B'
            &&MyNewBoard.ReturnPos(Scratchy.ReturnYpos(),Scratchy.ReturnXpos()+1)!='B'
           )
        {
            CatMoveInRandDir(MyNewBoard,Scratchy);

        }
        else if(MyNewBoard.ReturnPos(Scratchy.ReturnYpos()+1,Scratchy.ReturnXpos())=='W'||
                MyNewBoard.ReturnPos(Scratchy.ReturnYpos()+1,Scratchy.ReturnXpos())=='B')
        {
            Scratchy.MoveUp(MyNewBoard);

        }
        else if(MyNewBoard.ReturnPos(Scratchy.ReturnYpos()-1,Scratchy.ReturnXpos())=='W'||
                MyNewBoard.ReturnPos(Scratchy.ReturnYpos()-1,Scratchy.ReturnXpos())=='B')
        {
            Scratchy.MoveDown(MyNewBoard);

        }
        else if(MyNewBoard.ReturnPos(Scratchy.ReturnYpos(),Scratchy.ReturnXpos()+1)=='W'||
                MyNewBoard.ReturnPos(Scratchy.ReturnYpos(),Scratchy.ReturnXpos()+1)=='B')
        {
            Scratchy.MoveLeft(MyNewBoard);

        }
        else if(MyNewBoard.ReturnPos(Scratchy.ReturnYpos(),Scratchy.ReturnXpos()-1)=='W'||
                MyNewBoard.ReturnPos(Scratchy.ReturnYpos(),Scratchy.ReturnXpos()-1)=='B')
        {
            Scratchy.MoveRight(MyNewBoard);

        }




    if(MyNewBoard.ReturnPos(Itchy.ReturnYpos(),Itchy.ReturnXpos())!='W'
       &&MyNewBoard.ReturnPos(Itchy.ReturnYpos(),Itchy.ReturnXpos())!='B')
        {
            MouseMoveInRandDir(MyNewBoard,Itchy);
        }

        else if(MyNewBoard.ReturnPos(Itchy.ReturnYpos(),Itchy.ReturnXpos())=='B')
        {
            cout << "Itchy got away on the bridge." << endl;
            return 3;
        }

        else if(MyNewBoard.ReturnPos(Itchy.ReturnYpos(),Itchy.ReturnXpos())=='W')
        {

            cout << "Itchy has drowned!" << endl;
            return 1;

        }
         if(DidScratchyCatchItchy(MyNewBoard,Scratchy,Itchy)==true)
        {

            cout << "Scratchy caught Itchy! :(" << endl;
           return 2;
        }
        if(DidScratchyFindItchyInHole(MyNewBoard,Scratchy,Itchy,Hole)==true)
        {
            cout<< "Itchy got lucky" << endl;
            return 4;
        }





}


////vector<int> InfoVector;
//InfoVector.push_back(timesCaught);
//InfoVector.push_back(TimesDrowned);
//return InfoVector;
}

bool DidScratchyCatchItchy(Board& MyNewBoard, Cat& Scratchy, Mouse& Itchy)
{
    if(MyNewBoard.ReturnPos(Scratchy.ReturnYpos(),Scratchy.ReturnXpos())!='2')
       {
           return true;
       }
        else
        {
            return false;
        }
}

bool DidScratchyFindItchyInHole(Board& MyNewBoard, Cat& Scratchy, Mouse& Itchy, MouseHole& Hole)
{
    if(Itchy.ReturnXPos()==Scratchy.ReturnXpos()
       &&Itchy.ReturnXPos()==Hole.ReturnXpos()
      &&Itchy.ReturnYPos()==Scratchy.ReturnYpos()
       &&Itchy.ReturnYPos()==Hole.ReturnYPos())
       {
           return true;
       }
        else
        {
            return false;
        }
}

int FileContents(string NameOfFile)  //This fucntion takes the name of your file opens it
    {                                   //and puts the contents of the file in a string variable.
        ifstream inputfile;
        inputfile.open(NameOfFile.c_str());

        int word;
        int wordString(word);                        //converts array of characters  to string

    	inputfile >> wordString;
        int FileContent=wordString;

        while (inputfile.good())
            {
            wordString = wordString;
            inputfile >> wordString;
            FileContent=FileContent + wordString;
            }

    return FileContent;
    }

vector<int> OpenFileAndPutIntsInVector(string Infilename)
{
    ifstream InputFile;
                  // opens input file
    InputFile.open(Infilename.c_str());

    if (InputFile.fail())                  // if file name is wrong close program
        {
            cout << "Error opening " << Infilename << "\n";


        }

    int Number;
    vector<int> MyIntVector;

    while(InputFile >> Number)
    {
        MyIntVector.push_back(Number);
    }

    return MyIntVector;
}



void OutputFile(string OutputFileName, vector<string> OutFileContents, vector<int> OutFileNumbers) // This function takes the name of your new file
    {                                                          //creates the file and puts your modified file
      ofstream myfile;                                         //contents into it.
      myfile.open(OutputFileName.c_str());
      for(int i=0; i<OutFileContents.size(); i++)
      {
          myfile << OutFileContents[i];
          myfile << OutFileNumbers[i];
          myfile << endl;
      }
      myfile.close();

    }


vector<string> OpenFileAndPutStringsInVector(string Infilename)
{
    ifstream InputFile;
                  // opens input file
    InputFile.open(Infilename.c_str());

    if (InputFile.fail())                  // if file name is wrong close program
        {
            cout << "Error opening " << Infilename << "\n";
        }

    string String;
    vector<string> MyStringVector;

    while(InputFile >> String)
    {
        MyStringVector.push_back(String);
    }

    return MyStringVector;
}
