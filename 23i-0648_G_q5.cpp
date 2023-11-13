//Muhammad Asif 
//23i-0648
//CS-G
#include <iostream>
#include <iomanip>
#include<ctime>
using namespace std;

void drawboard(int n , int m , int board[][150]);
int play(int n, int m, int board[][150], int s,int &score);
void showOutput(int score,int jumps);

int main()
{
srand(time(0));
int m ,n , s;

do{
cout<<"Enter no. of rows (between 1 to 100): ";
cin>>n;
cout<<"Enter no. of columns (between 1 to 150): ";
cin>>m;
if(n<1||n>100||m<1||m>150)
cout << "The number of rows and columns are out of the allowed range,Enter the values again." << endl;
}
while(n<1||n>100||m<1||m>150);

int board[100][150];
drawboard(n,m,board);

do{
cout << "Enter a initial value 's' (between 0 and " << n  << "): ";
cin >> s;
   	if (s < 0 || s >= n) {
        cout << "The starting position 's' is out of the allowed range." << std::endl;   
    }
}    
while (s<0 || s>= n) ;
int score ;
int jumps = play(n, m, board, s,score);

    showOutput(score, jumps);

return 0;
}

//1)Function to drawboard
void drawboard(int n, int m ,int board[][150])
{
cout<<setw(m*4)<<setfill('-')<<""<<","<<endl;
for (int i = 0 ; i<n ; i++)
{

for (int j = 0 ; j<m ; j++)
{
cout<<"|"<<setw(3)<<setfill(' ');
board[i][j]=rand()%m;
cout<<board[i][j];
}
cout<<"|"<<endl;

}
cout<<setw(m*4)<<setfill('-')<<""<<"`"<<endl;
}

int play(int n, int m, int board[][150], int s , int &score) {
    score = 0;
    int jumps = 0;
    int k = 0;
    score=score+ board[s][0];
    cout << "Player score: " << score <<endl;
  	int q = board[s][0];

    do {
        score = score + board[k][q];
        if (board[k][q] == 0) score = 0;
        k = (k + 1) % n;
        jumps++;
        cout << "Player score: " << score <<endl;
        if (jumps>100){
        cout<<"Game Over!"<<endl;
        break;
        }
    } while (score < 100);

    return jumps;
}

void showOutput(int score, int jumps) {
    cout << "\nJumps: " << jumps << endl;
    cout<<"Final score= "<<score<<endl;
    
   }



