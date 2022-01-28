#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
using namespace std;

bool validTicTacToe(vector<string>& board) {
    int counterEmpty=0, counterX=0, counterO=0;
    bool res=false;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]==' ')
                    counterEmpty++;
                if(board[i][j]=='X')
                    counterX++;
                if(board[i][j]=='O')
                    counterO++;
            }
        }
        cout<<"*** "<<counterEmpty<<", "<<counterX<<", "<<counterO<<" ***\n";
        if(counterEmpty==9)
            res= true;
        else if(counterEmpty==8 && counterX==1)
            res= true;
        else if(counterX - counterO == 1 || counterX - counterO == 0)
            res= true;
        
        return res;
}

int main(){
    vector<string> b={{'O', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
    if(validTicTacToe(b))
        cout<<"VALID!\n";
    else cout<<"INVALID!\n";

    return 0;
}