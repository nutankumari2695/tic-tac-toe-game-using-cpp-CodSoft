#include<iostream>
#include<stdlib.h>
using namespace std;

char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, col;
bool draw = false;

void display()
{
    system("cls");
    cout << "\n\t     Tic-Tac-Toe Game" << endl;
    cout << "\t\tPlayer1 [X] \n\t\tPlayer2 [0]\n\n";

    cout << "\t\t      |    |     \n";
    cout << "\t\t  " << arr[0][0] << "   | " << arr[0][1] << "  | " << arr[0][2] << "  \n";
    cout << "\t\t _____|____|_____\n";
    cout << "\t\t      |    |     \n";
    cout << "\t\t  " << arr[1][0] << "   | " << arr[1][1] << "  |  " << arr[1][2] << "  \n";
    cout << "\t\t _____|____|_____\n";
    cout << "\t\t      |    |     \n";
    cout << "\t\t  " << arr[2][0] << "   | " << arr[2][1] << "  |  " << arr[2][2] << "  \n";
    cout << "\t\t      |    |     \n";
}

void player_turns()
{
    int choice;
    if(turn == 'X')
        cout<<"\n\tPlayer1 [X] turn:";
    if(turn =='0')
        cout << "\n\tPlayer2 [0] turn:";

    cin >> choice;

    switch(choice)
    {
        case 1:row=0; col=0; break;
        case 2:row=0; col=1; break;
        case 3:row=0; col=2; break;
        case 4:row=1; col=0; break;
        case 5:row=1; col=1; break;
        case 6:row=1; col=2; break;
        case 7:row=2; col=0; break;
        case 8:row=2; col=1; break;
        case 9:row=2; col=2; break;
        default:
            cout<<"Invalid choice\n";
            break;
    }

    if(arr[row][col] != 'X' && arr[row][col] != '0')
    {
        if(turn == 'X')
            arr[row][col] = 'X';
        else
            arr[row][col] = '0';

        if(turn == 'X')
            turn = '0';
        else
            turn = 'X';
    }
    else
    {
        cout<<"Box already filled\n Please try again!!\n";
        player_turns();
    }
}

bool gameover()
{
    for(int i=0; i<3; i++)
        if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] || arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
            return false;

    if(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] || arr[0][2] == arr[1][1] && arr[0][0] == arr[2][0])
        return false;

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(arr[i][j] != 'X' && arr[i][j] != '0')
                return true;

    draw = true;
    return false;
}

int main()
{
    char playAgain;
    do
    {
        while(gameover())
        {
            display();
            player_turns();
        }

        display();

        if(turn == 'X' && draw == false)
            cout << "Player2 [0] wins!! Congratulations\n";
        else if(turn == '0' && draw == false)
            cout << "Player1 [X] wins!! Congratulations\n";
        else
            cout << "GAME DRAW!!!\n";

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        if(playAgain == 'Y' || playAgain == 'y')
        {
            turn = 'X';
            draw = false;
            arr[0][0] = '1'; arr[0][1] = '2'; arr[0][2] = '3';
            arr[1][0] = '4'; arr[1][1] = '5'; arr[1][2] = '6';
            arr[2][0] = '7'; arr[2][1] = '8'; arr[2][2] = '9';
        }
    }
    while(playAgain == 'Y' || playAgain == 'y');

    return 0;
}
