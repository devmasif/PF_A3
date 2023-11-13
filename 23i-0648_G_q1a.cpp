//Muhammad Asif 
//23i-0648
//CS-G
#include <iostream>
#include<cstdlib>
using namespace std;

//Prototypes
int FindSum(int a, int b, int c); 
void ShowSum(int sum); 
double FindAvg(double a, double b, double c); 
void ShowAvg(double average);
int FindMax(int a, int b, int c);
void ShowMax(int max);
int FindMin(int a, int b, int c);
void ShowMin(int min);

int main() {
    int a, b, c;
    cout<<"Enter three numbers  \n";
    cout<<"Number 1 : ";
    cin>>a;
    cout<<"Number 2 : ";
    cin>>b;
    cout<<"Number 3 : ";
    cin>>c;
    cout<<endl;
    
    int sum = FindSum(a, b, c);  //	Findingsum using FindSum
    ShowSum(sum);
 	float average = FindAvg(a,b,c); // Finding average using FindAvg
    ShowAvg(average);
    int max = FindMax(a,b,c);		// Finding Maxnumber using FindMax
    ShowMax(max);
    int min = FindMin(a,b,c);		// Finding Minimum number using FindMin
    ShowMin(min);
    
//system("pause");
    return 0;
}
//Functions 
//F1
int FindSum(int a, int b, int c) {
    return a + b + c;
}
//F2
void ShowSum(int sum) {

cout << "The sum is " << sum << endl;
}
//F3
double FindAvg(double a, double b, double c)
{
return FindSum(a,b,c)/3.0;
}
//F4
void ShowAvg(double average){
cout<<"The Average is " << average <<endl;
}
//F5
int FindMax(int a, int b, int c){
return a>=b&&a>=c ? a : b>=a&&b>=c ? b :c ;
}
//F6
void ShowMax(int max){
cout<<"Maximum among three number is " << max <<endl;
}
//F7
int FindMin(int a, int b, int c){
return a<=b&&a<=c ? a : b<=a&&b<=c ? b :c ;
}
//F8
void ShowMin(int min){
cout<<"Minimum among three number is " << min <<endl;
}



