// https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/


#include<bits/stdc++.h>
using namespace std;

int xMove[] = {2,1,-1,-2,-2,-1,1,2};
int yMove[] = {1,2,2,1,-1,-2,-2,-1};

bool isValid(vector<vector<int> > board, int row, int col, int n){
    if(row>=0 && col>=0 && row<n && col<n && board[row][col]==0)    return true;
    return false;
}


bool findMoves(vector<vector<int>>& board, int row, int col, int move, int n){
    if(move == (n*n)){
        return true;
    }

    for(int i=0;i<8;i++){
        int newRow = row + xMove[i];
        int newCol = col + yMove[i];
        if(isValid(board,newRow,newCol,n)){
            move++;
            board[newRow][newCol] = move;
            if(findMoves(board,newRow,newCol,move,n)) return true;
            move--;
            board[newRow][newCol] = 0;
        }
    }
    return false;
}

int main(){
    // int n;
    // cin>>n;
    // vector<vector<int> > board;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         board[i][j] = 0;
    //     }
    // }
    int n = 5;
    vector<vector<int> > board = {{0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0 }};
    int moves = 1;
    board[0][0] = 1;
    if(findMoves(board,0,0,moves,n))
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else cout<<"Not Possible to fill all the cells";
}