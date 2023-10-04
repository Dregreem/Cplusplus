#include <iostream>

using namespace std;

int board[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
string player1, player2;
char token = 'X', token2 = '0';
int digit ;
int row, column;
int turn = 0;
bool results;


void display_board() 
{
	cout <<"\t\t\t\t\tWELCOME TO TIC-TAC-TOE GAME" << endl;
	cout <<"Here are the rules\n 1 - Play fairly and dont cheat\n 2 - Respect your opponent\n 3 - In case of a problem contact KB" << endl;
	
	cout << "\t\t\t\t\t|----|----|----|" << endl;
	cout << "\t\t\t\t\t| " << board[0][0]<<"  | "<< board[0][1]<<"  |  " << board[0][2]<<" |  " << endl;
	cout << "\t\t\t\t\t|----|----|----|" << endl;
	cout << "\t\t\t\t\t| " << board[1][0]<< "  | "<< board[1][1]<< "  |  " << board[1][2]<<" |  " << endl;
	cout << "\t\t\t\t\t|----|----|----|" << endl;
	cout << "\t\t\t\t\t| " << board[2][0]<< "  | "<< board[2][1]<< "  |  "<< board[2][2]<<" |" << endl;
	cout << "\t\t\t\t\t|____|____|____|" << endl;		


}
void userinterface()
{

	cout << "Please enter your name PLAYER-1 : " << endl;
	cin >> player1;
	cout << "Please enter your name PLAYER-2 : " << endl;
	cin >> player2;
	cout << "PLayer-1 is " << player1 << "  your token is X and Player - 2 is " << player2 << "  and your token is Q" << endl;

}
bool logic_of_the_game()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
        {
            return true;
        }
    }

    if (board[1][1] != ' ')
    {
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        {
            return true;
        }
    }
    return false;
}
void getusermove()
{
	while (turn < 9 && logic_of_the_game() == false)
	{
        if (turn % 2 == 0)
        {
            cout << "Enter a number between 1 and 9 " << player1 << endl;;
            cin >> digit;

            switch (digit) {
            case 1:
                row = 0;
                column = 0;
                turn++;
                
                break;
            case 2:
                row = 0;
                column = 1;
                turn++;
                
                break;
            case 3:
                row = 0;
                column = 2;
                turn++;
                
                break;
            case 4:
                row = 1;
                column = 0;
                turn++;
                
                break;
            case 5:
                row = 1;
                column = 1;
                turn++;
                
                break;
            case 6:
                row = 1;
                column = 2;
                turn++;
                
                break;
            case 7:
                row = 2;
                column = 0;
                turn++;
                
                break;
            case 8:
                row = 2;
                column = 1;
                turn++;
                
                break;
            case 9:
                row = 2;
                column = 2;
                turn++;
                
                break;
            default:
                cout << "You didn't enter a number between 1 and 9." << endl;
                getusermove();
                return;
            }
            if (board[row][column] == 'X' || board[row][column] == '0') {
                cout << "That place is already taken. Please try again." << endl;
                getusermove();
                return;
            }
            else
            {
                board[row][column] = 'X';
            }

        }
        else
        {
            cout << "Enter a number between 1 and 9 " << player2 << endl;;
            cin >> digit;

            switch (digit) {
            case 1:
                row = 0;
                column = 0;
                turn++;
                
                break;
            case 2:
                row = 0;
                column = 1;
                turn++;
                
                break;
            case 3:
                row = 0;
                column = 2;
                turn++;
                
                break;
            case 4:
                row = 1;
                column = 0;
                turn++;
                
                break;
            case 5:
                row = 1;
                column = 1;
                turn++;
                
                break;
            case 6:
                row = 1;
                column = 2;
                turn++;
                
                break;
            case 7:
                row = 2;
                column = 0;
                turn++;
                
                break;
            case 8:
                row = 2;
                column = 1;
                turn++;
                
                break;
            case 9:
                row = 2;
                column = 2;
                turn++;

                break;
            default:
                cout << "You didn't enter a number between 1 and 9." << endl;
                getusermove();
                return;
            }
            if (board[row][column] == 'X' || board[row][column] == '0')
 {
                cout << "That place is already taken. Please try again." << endl;
                getusermove();
                return;
            }
            else
            {
                board[row][column] = '0';
            }

        }

	}
    
    return;
}


int main() {
	display_board();
	userinterface();
	getusermove();
    logic_of_the_game();

    if (logic_of_the_game && token == 'X' && turn % 2 == 1 && turn < 9)
    {
        cout << "Conguralations The Player-1 has WON the GAME" << endl;
    }
    if (logic_of_the_game && token2 == '0' && turn % 2 == 0 && turn<9)
    {
        cout << "Conguralations The Player-2 has WON the GAME" << endl;
    }
    else(!logic_of_the_game && turn < 9);
    {
        cout << "Conguralations It is a DRAW, better luck next time both of you " << endl;
    }


	return 0;
}