#include<bits/stdc++.h>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char mark;
int currentplayer;
string s1,s2;

bool markplace(int slot){
    int row=(slot-1)/3;
    int col=(slot-1)%3;
    if (board[row][col]!='X' && board[row][col] !='o'){
        board[row][col]=mark;
        return true;

    }
    else{
        return false;
    }
}

void displayboard(){
    cout<<" "<<board[0][0]<<" | " <<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<< "---|---|---" <<endl;
    cout<<" "<<board[1][0]<<" | " <<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<< "---|---|---" <<endl;
    cout<<" "<<board[2][0]<<" | " <<board[2][1]<<" | "<<board[2][2]<<endl;
}

int checkwinner(){
    for (int i=0;i<3;i++){
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return currentplayer;
        }
    }
     for (int i=0;i<3;i++){
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return currentplayer;
        }
     }
      if (board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            return currentplayer;
        }

        if (board[0][2]==board[1][1] && board[1][1]==board[2][0]){
            return currentplayer;
        }
        return 0;


}

void swapmarkerandplayer(){
    if(mark=='X'){
        mark='O';

    } 
    else{
        mark='X';

    }
    if (currentplayer==1) currentplayer=2;
    else currentplayer=1;
}


void maingame(){
    cout<<"enter player1 name: ";
    cin>>s1;
    cout<<"enter player2 name:";
    cin>>s2;
    cout<<s1<<" choose your marker('X' OR 'O')"<<endl;

    char marker1;
    cin>>marker1;

    currentplayer=1;
    mark=marker1;


    displayboard();

    int winner=0;
    for(int i=0;i<9;i++){
        if (currentplayer==1){
            cout<<"its "<<s1<<" turn"<<endl;
            cout<<"enter your slot: "<<endl;
        }
        else{
            cout<<"its "<<s2<<" turn"<<endl;
            cout<<"enter your slot: "<<endl;
        }


        int slot;
        cin>>slot;


        if (slot<1 || slot>9){
            cout<<"choose between 1-9: "<<endl;
            i--;
            continue;
        }

        if(!markplace(slot)){
            cout<<"slot occupied,choose another slot: "<<endl;
            i--;
            continue;
        }
        displayboard();


        winner=checkwinner();
        if(winner==1){
            cout<<s1<<" is the winner"<<endl;
            break;
        }

        swapmarkerandplayer();
    }
    if (winner==0){
        cout<<"its a tie"<<endl;
    }


}


int main(){
   maingame();
    return 0;
}
