
#include<bits/stdc++.h>
using namespace std;

char slotno[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

char current_marker;
int current_player;

void display()
{
    cout << "          " << slotno[0][0] << " | " << slotno[0][1] << " | " << slotno[0][2] << endl;
    cout << "          " <<"__________\n";
    cout << "          " << slotno[1][0] << " | " << slotno[1][1] << " | " << slotno[1][2] << endl;
    cout << "          " << "__________\n";
    cout << "          " << slotno[2][0] << " | " << slotno[2][1] << " | " << slotno[2][2] << endl;
}
bool placeMarker(int slot)
{
    int row = slot / 3;
    int col;

    if(slot % 3 == 0) {
        row = row - 1;
        col = 2;
    }
    else {
        col = slot % 3 - 1;
    }
    if(slotno[row][col] != 'X' && slotno[row][col] != 'O') {
        slotno[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}
int winner()
{
    for(int i = 0; i < 3; i++)
    {

        if(slotno[i][0] == slotno[i][1] && slotno[i][1] == slotno[i][2])
        {
            return current_player;
        }

        if(slotno[0][i] == slotno[1][i] && slotno[1][i] == slotno[2][i])
        {
            return current_player;
        }
    }
    if(slotno[0][0] == slotno[1][1] && slotno[1][1] == slotno[2][2])
    {
        return current_player;
    }
    if(slotno[0][2] == slotno[1][1] && slotno[1][1] == slotno[2][0])
    {
        return current_player;
    }
    return 0;
}
void swap()
{
    if(current_marker == 'X')
    {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }
    if(current_player == 1)
    {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

void game()
{
    cout << "Player 1 enter marker: ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;
    display();

    int player_won;

    for(int i = 0; i < 9; i++)
    {
        cout <<"Player "<< current_player << " Enter your slot: ";
        int slot;
        cin >> slot;

        if(slot < 1 || slot > 9) {
            cout << "That slot is invalid! Try another slot!"; i--; continue;
        }

        if(!placeMarker(slot)) {
            cout << "That slot occupied! Try another slot!"; i--; continue;
        }
        display();

        player_won = winner();

        if(player_won == 1)
        {
            cout << "Congratulations player one! You won!"; break;
        }
        if(player_won == 2)
        {
            cout << "Congratulations player two! You won!"; break;
        }

        swap();
    }
    if(player_won == 0)
    {
        cout << "It's a tie! :( ";
    }
}


int main()
{
cout<<"           "<<"WELCOME"<<endl<<endl;
game();
}
