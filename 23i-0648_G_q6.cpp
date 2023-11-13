//Muhammad Asif 
//23i-0648
//CS-G
#include <iostream>
using namespace std;

//Function Prototypes
void fun_check(int arr[] ,int size , int val , int resultant[] , int inc);
void fun_check2(int a[],int b[], int size1, int size2,int resultant[], int val , int inc=0);
void fun_check3(int a[],int b[] , int c[] , int size1 , int size2 , int size3 , int resultant[]);
void swap(int &a, int &b) ;
void sortNegatives(int arr[], int size) ;
void sortEvenOdd(int arr[], int size) ;
void Order(int arr[], int size) ;



int main()
{
int size1,size2,size3;

cout<<"Enter size of array1: ";
cin>>size1;
cout<<"Enter size of array2: ";
cin>>size2;
cout<<"Enter size of array3: ";
cin>>size3;
int arr1[size1],arr2[size2],arr3[size3];
const int size_total = size1+size2+size3;
int resultant_arr[size_total];

for (int i = 0 ; i<size_total ; )
{
	cout<<endl;
	for (int j = 0 ; j < size1 ; j++)
	{
	cout<<"Enter element "<<j+1<<" of Array1: ";
	cin>>arr1[j];
	resultant_arr[i]=arr1[j];
	i++;
	}
	
	fun_check(arr1 , size1 , -1 , resultant_arr , 0);
	
	cout<<endl;
	for (int j = 0 ; j < size2 ; j++)
	{
	cout<<"Enter element "<<j+1<<" of Array2: ";
	cin>>arr2[j];
	resultant_arr[i]=arr2[j];
	i++;
	}
	
	fun_check(arr2 , size2 , -2 , resultant_arr , size1);
	
	
	cout<<endl;
	for (int j = 0 ; j < size3 ; j++)
	{
	cout<<"Enter element "<<j+1<<" of Array3: ";
	cin>>arr3[j];
	resultant_arr[i]=arr3[j];
	i++;
	}
	
	fun_check(arr3 , size3 , -3 , resultant_arr , size2+size1);
	fun_check2(arr1 , arr2 , size1 , size2, resultant_arr , -12 , size1);
	fun_check2(arr2 , arr3 , size2 , size3, resultant_arr , -23 , size1+size2 );	
	fun_check2(arr1 , arr3 , size1 , size3, resultant_arr , -13 , size1+size2);
	fun_check3(arr1, arr2 , arr3 , size1 , size2 , size3 , resultant_arr);
	
}
Order(resultant_arr , size_total );

cout<<"Resultant array is : ";
for (int k = 0 ; k<size_total ; k++)
cout<<resultant_arr[k]<<" ";

cout<<"\n\n";
return 0;
}




//Funtion to check similar entries within same array 
void fun_check(int arr[] ,int size , int val , int resultant[] , int inc)
{
	for (int k = 0 ; k<size ; k++)
	{
		for (int j = k+1 ; j<size ; j++)
			if (arr[k]==arr[j])
			resultant[j+inc]=val;
	}
}

//Function to check similarities within any two arrays
void fun_check2(int a[],int b[], int size1, int size2,int resultant[], int val , int inc)
{
	for (int i = 0 ; i<size1 ; i++)
	{
		for (int j = 0 ; j<size2; j++)
		if (a[i]==b[j])
		resultant[j+inc]=val;
	}

}

//Function to check similarities within three arrays
void fun_check3(int a[],int b[] , int c[] , int size1 , int size2 , int size3 , int resultant[])
{
	
	for (int i = 0 ; i<size1 ; i++)
	{
		for (int j = 0 ; j<size2; j++)
		{
			for (int k = 0 ; k<size3 ; k++)
				if (a[i]==b[j]&&a[i]==c[k])
				resultant[k+size1+size2]=-123;
				
		}
	}
}

//Function to swap two values
void swap(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}

//Function for ascending order of neg values
void sortNegatives(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = i + 1; j < size; j++) 
            if (arr[i] > 0 || (arr[i] < 0 && arr[j] < 0 && arr[i] > arr[j])) 
                swap(arr[i], arr[j]);
    }
}

//Function to sort even in ascending order and then odd in ascending order
void sortEvenOdd(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i] > 0 && arr[j] > 0) 
            {
                // Sort even numbers first
                if ((arr[i] % 2 > arr[j] % 2) || (arr[i] % 2 == arr[j] % 2 && arr[i] > arr[j])) 
                    swap(arr[i], arr[j]);
            }
        }
    }
}

//Resultant/Required Order
void Order(int arr[], int size) 
{
    // First, sort negative numbers in ascending order
    sortNegatives(arr, size);
    
    // Then, sort positive numbers with even numbers first, then odd numbers
    sortEvenOdd(arr, size);
}






