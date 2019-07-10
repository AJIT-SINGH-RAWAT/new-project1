

#include<stdlib.h>
#include<iostream>
using namespace std;
void display_board();
void player_turn();
bool gameover();
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,column;
char turn='X';
bool draw = false;



void display_board(){
    system("CLS");

cout<<"\t\t\t\tT I C K     C R O S S     G A M E\n\n";
cout<<"\t\tPlayer1 [X]\n";
cout<<"\t\tPlayer2 [O]\n";


cout<<"\t\t     |     |     \n";
cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
cout<<"\t\t_____|_____|_____\n";
cout<<"\t\t     |     |     \n";
cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
cout<<"\t\t_____|_____|_____\n";
cout<<"\t\t     |     |     \n";
cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
cout<<"\t\t     |     |     \n";

}



void player_turn(){
    int choice;
if (turn=='X')
cout<<"\n\t Player1 [X] turn";
if (turn=='O')
cout<<"\n\t Player2 [O] turn";
cin>>choice;

switch(choice){
case 1:row =0;column=0;break;
case 2:row =0;column=1;break;
case 3:row =0;column=2;break;
case 4:row =1;column=0;break;
case 5:row =1;column=1;break;
case 6:row =1;column=2;break;
case 7:row =2;column=0;break;
case 8:row =2;column=1;break;
case 9:row =2;column=2;break;
default:cout<<"Invalid Choice";break;

}

if (turn =='X'&&board[row][column]!='X'&&board[row][column]!='O'){
    board[row][column]='X';
    turn='O';
}
else if (turn =='O'&&board[row][column]!='X'&&board[row][column]!='O')
{
    board[row][column]='O' ;
    turn='X';
}
else{
    cout<<"Box already filled \n Please try again\n\n";
    player_turn();
}




}

bool gameover(){
  //check wins

 for (int i=0;i<3;i++)
 if (board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i]&&board[0][i]==board[2][i])
return false;

if (board[0][0]==board[1][1]&&board[0][0]==board[2][2]||board[0][2]==board[1][1]&&board[0][2]==board[2][0])
    return false;



// if there is any box is not filled

 for (int i=0;i<3;i++)
  for (int j=0;j<3;j++)
  if (board[i][j]!='X' && board[i][j]!='O')
  return true;

  //Draw

  draw=true;
  return false;



}

int main(){
while(gameover())
{
display_board();
player_turn();
display_board();
}

if (turn=='X' && draw == false)
cout<<"Player2 [O] Wins !! Congratulations";
else if (turn=='O' && draw == false)
cout<<"Player1 [X] Wins !! Congratulations";
else
    cout<<"GAME DRAW\n";


return 0;

}

