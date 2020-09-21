#include <iostream>

using namespace std;

void initialize(int board[]);
bool check(int board[], int q1, int q2);
void solve(int board[]);
void display(int board[]);

int main(){
    int board[8];
    initialize(board);
    solve(board);
    return 0;
}

void initialize(int board[]){
    for(unsigned int i = 1; i < 8; ++i)
        board[i] = -1;
    board[0] = 0;
}

bool check(int board[], int q1, int q2){
    if(q1 < 0)
        return false;
    return(board[q1] == board[q2] || abs(board[q1] - board[q2]) == abs(q2 - q1) || check(board, q1-1,q2));
}

void solve(int board[]){
    int currentQueen = 0, count = 0;
    while(currentQueen >= 0){
        while(check(board, currentQueen - 1, currentQueen))
            ++board[currentQueen];
        if(board[currentQueen] > 7)
            board[currentQueen--] = -1;
        else
            if(++currentQueen > 7){
                display(board);
                ++count;
                --currentQueen;
            }
        ++board[currentQueen];
    }
    cout << count << endl;
}

void display(int board[]){
    for(unsigned int i = 0; i < 8; ++i)
        cout << i << ":" << board[i] << " ";
    cout << endl;
}
