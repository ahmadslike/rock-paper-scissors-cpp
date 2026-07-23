#include <iostream>
#include <cstdlib>  
#include <ctime>     
#include <string>    

using namespace std;

enum enGameChoice {Stone = 1, Paper = 2, Scissors = 3};

struct stCalculatePoint
{
    short User = 0;
    short Computer = 0;
    short Draw = 0;
    enGameChoice PlayerResult;
    enGameChoice CompResult;
};

short ReadNumberOfRound()
{
    short RoundNumber = 0;
    do
    {
        cout << "How many rounds do you want [1 to 10]? ";
        cin >> RoundNumber;
    } while (RoundNumber < 1 || RoundNumber > 10);
    return RoundNumber;
}
enGameChoice UserChoice() //2
{
    short UserChoice = 0;
    do
    {
    cout << "\nYour Choice [1]: Stone, [2]: Paper, [3]: Scissors ? ";
    cin >> UserChoice;
    }while(UserChoice < 1 || UserChoice > 3);
    return (enGameChoice)UserChoice;
}
short RandomNumber(short From, short To) //3
{
    short randNum = rand() % (To - From + 1) + From;
    return randNum;
}
enGameChoice ComputerChoice() //4
{
    short ComputerChoice = RandomNumber(1, 3);
    return (enGameChoice)ComputerChoice;
}
void whoIsWinner(stCalculatePoint &Winner) //5
{
    Winner.PlayerResult = UserChoice();
    Winner.CompResult = ComputerChoice();

    if (Winner.PlayerResult == Winner.CompResult)
    {
        Winner.Draw += 1;
    }

    else if ((Winner.PlayerResult == enGameChoice::Paper && Winner.CompResult == enGameChoice::Stone) ||
        (Winner.PlayerResult == enGameChoice::Stone && Winner.CompResult == enGameChoice::Scissors) ||
        (Winner.PlayerResult == enGameChoice::Scissors && Winner.CompResult == enGameChoice::Paper))
    {
        Winner.User += 1;
    }

    else
    {
        Winner.Computer += 1;
    }
}
string GetChoiceName(enGameChoice Choice) //6
{
    if (Choice == enGameChoice::Stone)
    {
        return "Stone";
    }
    else if (Choice == enGameChoice::Paper)
    {
        return "Paper";
    }
    else if (Choice == enGameChoice::Scissors)
    {
        return "Scissors";
    }
    else
    {
        return "Unknown";
    }
}
void PlayGameRounds(stCalculatePoint &Winner, int NumberOFLoop) //7 Loop form 2 to 6
{
    for(short i = 1; i <= NumberOFLoop; i++)
    {
        cout << "\n____________ Round[" << i << "] ____________" << endl;
        
        short PrevUser = Winner.User;
        short PrevComp = Winner.Computer;

        whoIsWinner(Winner);

        cout << "Player1 Choice : " << GetChoiceName(Winner.PlayerResult) << endl;
        cout << "Computer Choice : " << GetChoiceName(Winner.CompResult) << endl;


        if(Winner.User > PrevUser)
        {
            cout << "\033[42;30mRound Winner : [ Player1 ]\033[0m" << endl;
        }
        else if(Winner.Computer > PrevComp)
        {
            cout << "\033[41;37mRound Winner : [ Computer ]\033[0m" << endl;
            system("speaker-test -t sine -f 800 -l 1 > /dev/null 2>&1 &");
        }
        else
        {
            cout << "\033[43;30mRound Winner : [ No winner ]\033[0m" << endl;
        }
        cout << "\n____________________________________________\n" << endl;
    }
}
void PrintFinalResults(stCalculatePoint &Winner, int NumberOFLoop) //8
{
    cout << "\n____________________________________________\n";
    cout << "                   +++ Game Over +++                   " << endl;
    cout << "\n____________________________________________\n";
    cout << "____________ [ Game Results ] ____________" << endl;
    cout << "Game Round : " << NumberOFLoop << endl;
    cout << "Player1 won times : " << Winner.User << endl;
    cout << "Computer won times : " << Winner.Computer << endl;
    cout << "Draw times : " << Winner.Draw << endl;
        if(Winner.User > Winner.Computer)
    {
        cout << "\033[42;30mFinal Winner : [ Player1 ]\033[0m" << endl; 
    }
    else if(Winner.User < Winner.Computer)
    {
        cout << "\033[41;37mFinal Winner :  [ Computer ]\033[0m" << endl;
        system("speaker-test -t sine -f 800 -l 1 > /dev/null 2>&1 &");
    }
    else
    {
        cout << "\033[43;30mFinal Winner : [ No winner ]\033[0m" << endl;
    }
}
void StartGame() // 9 Loop from 1 to 9
{
    char PlayAgain = 'Y';
    do
    {
    system("clear");
    stCalculatePoint Winner;
    int NumberOFLoop = ReadNumberOfRound();
    PlayGameRounds(Winner, NumberOFLoop);
    PrintFinalResults(Winner, NumberOFLoop);
    cout << "\nDo you want to play again y/n ?";
    cin >> PlayAgain;
    }while(PlayAgain == 'Y' || PlayAgain == 'y'); 
}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}