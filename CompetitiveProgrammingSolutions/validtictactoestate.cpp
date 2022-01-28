//https://leetcode.com/problems/valid-tic-tac-toe-state/
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        
        int counterEmpty=0, counterX=0, counterO=0;
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
        if(counterEmpty==9)
            return true;
        else if(counterEmpty==8 && counterX==1)
            return true;
        else if(counterX-counterO==1){ // O shouldnt win
            int finalCount=0, Oij1=0, Oij2=0, k=2;
            for(int i=0; i<3; i++){
                int Oj=0, Oi=0;
                for(int j=0; j<3; j++){
                    if(board[i][j]=='O')
                        Oj++;
                    if(board[j][i]=='O')
                        Oi++;
                }
                if(board[i][i]=='O')
                    Oij1++;
                if(board[i][k]=='O'){
                    Oij2++;
                    k--;
                }
                
                if(Oj!=3)
                    finalCount++;
                if(Oi!=3)
                    finalCount++;
            }
            if(Oij1!=3)
                finalCount++;
            if(Oij2!=3)
                finalCount++;
            
            if(finalCount==8)
                return true;
        }
        else if(counterX-counterO==0){ // X shouldnt win
            int finalCount=0, Xij1=0, Xij2=0, k=2;
            for(int i=0; i<3; i++){
                int Xj=0, Xi=0;
                for(int j=0; j<3; j++){
                    if(board[i][j]=='X')
                        Xj++;
                    if(board[j][i]=='X')
                        Xi++;
                }
                if(board[i][i]=='X')
                    Xij1++;
                if(board[i][k]=='X'){
                    Xij2++;
                    k--;
                }
                
                if(Xj!=3)
                    finalCount++;
                if(Xi!=3)
                    finalCount++;
            }
            if(Xij1!=3)
                finalCount++;
            if(Xij2!=3)
                finalCount++;
            
            if(finalCount==8)
                return true;
        }
        return false;
    }
};