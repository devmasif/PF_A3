//Muhammad Asif 
//23i-0648
//CS-G
#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
//Prototypes 
void DisplayMenu();   
int Select(int choice);	
void PracticeAdd();		
void PracticeSub();		

int main()
{
srand(time(0));	
	DisplayMenu();
	
	int choice = Select(choice);
	switch(choice)
	{
		case 1:
		PracticeAdd();
		break;
		case 2:
		PracticeSub();
		break;
		default:
		cout<<"Invalid choice"<<endl;
	}

return 0;
}
//Functions
//F1
void DisplayMenu()
{
cout<<"-----------Practice Arithmetic-----------\n\t1.Addition\n\t2.Subtraction\n";
}
//F2
int Select(int choice)
{

cout<<"Enter your choice (1/2): ";cin>>choice;
while(choice!=1&&choice!=2)
{
cout<<"Invalid choice, Enter  choice again  (1/2): ";cin>>choice;
}
return choice;
}
//F3
void PracticeAdd(){

int correct_answers=0,wrong_answers=0;
int answer;
char decision;
	do
	{
		int a = rand()%500;
		int b = rand()%200;
		cout<<a<<"+"<<b<<" =?";cin>>answer;
		if (answer == a+b)
		{
			cout<<"CORRECT ANSWER"<<endl;
			correct_answers=correct_answers+1;
		}	
		else
		{
			cout<<"WRONG ANSWER"<<endl;
			wrong_answers=wrong_answers+1;
		}
		cout<<"\nContinue(y/n)? ";cin>>decision;
	}
	while(decision=='y'||decision=='Y');
	cout<<"No. of CORRECT answers ="<<correct_answers<<endl;
	cout<<"No. of Wrong answers ="<<wrong_answers<<endl;
}
//F4
void PracticeSub(){

int correct_answers=0,wrong_answers=0;
int answer;
char decision;
	do
	{
		int a = rand()%500;
		int b = rand()%200;
		cout<<a<<"-"<<b<<" =?";cin>>answer;
		if (answer == a-b)
		{
			cout<<"CORRECT ANSWER"<<endl;
			correct_answers=correct_answers+1;
		}
		else
		{
			cout<<"WRONG ANSWER "<<endl;
			wrong_answers=wrong_answers+1;
		}
	cout<<"\nContinue(y/n)? ";cin>>decision;
	}
	while(decision=='y'||decision=='Y');
	cout<<"No. of CORRECT answers = "<<correct_answers<<endl;
	cout<<"No. of Wrong answers = "<<wrong_answers<<endl;
}


