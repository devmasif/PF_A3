//Muhammad Asif 
//23i-0648
//CS-G
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;


// Function prototypes
void list_of_words(int index, char guess_word[]);
void draw_hangman(int lives);
void decision(bool result, char name[], char word_to_guess[]);
void toLowercase(char &guess);


//Main Function
int main() 
{
//Asking user name
cout << "\t\tWelcome to Hangman! \nPlease enter your name: ";
char name[25];
cin.getline(name,25);


//Random word generator
srand(time(0));
char word_to_guess[20];
list_of_words(rand()%100 , word_to_guess);

//Variables declaration
int lives = 6 ; 
int length_of_word = 0 , name_length=0;
bool extra_life = false;

//Length of word to guess 
for (int i = 0 ; word_to_guess[i]!='\0' ; i++)
length_of_word=length_of_word+1;


//Length of name
for (int i = 0 ; name[i]!='\0' ; i++)
name_length=name_length+1;

for (int i = 0 ; i<name_length ; i++)
{
toLowercase(name[i]);
}

bool result=false;

//Displaying ___________
char current_guess_display[length_of_word+1]; // +1 for null terminator 
for (int i = 0 ; i<length_of_word ; i++)
current_guess_display[i]='_';
current_guess_display[length_of_word]='\0'; // null-terminator

char guess; 

bool guessed_letters[256] = {false};
//Game Looop
while (lives>0)
{
draw_hangman(lives);
cout<<current_guess_display<<endl;
	bool life=true;
	cout<<endl;
	cout<<"Enter your guess: ";
	cin>>guess;
	
	toLowercase ( guess );
	
	//Prompt user if same character is entered again
	if (guessed_letters[static_cast<unsigned char>(guess)]) 
	{
            cout << "You have already guessed that letter. Try again.\n";
            continue;
    }
    
    
    guessed_letters[static_cast<unsigned char>(guess)] = true; 
    
    //Extra life for same guess and name character (only once)
    if (extra_life==0)
    {
   		for (int i = 0 ; i<name_length ; i++)
    	{
    	if (guess==name[i]&&lives<6)
    	{
    	lives=lives+1;
    	extra_life=true;
    	}
    	
    	}
    }
    //Checking Conditions   
	for (int i = 0 ; i<length_of_word ; i++ )
	{
		if (guess==word_to_guess[i])
		{
		current_guess_display[i]=guess;
		life=false;
		}		
	}
	result=true;
	for (int i = 0 ; i<length_of_word ; i++)
	{
		if (current_guess_display[i]=='_')
		{
		result=false;
		break;
		}
	}	
	//checking life after each guess
	if (life)
	lives=lives-1;
	//If player guess's the word,loop ends
	if (result==1)
	break;
	system("clear");
}

draw_hangman(lives);
decision ( result , name , word_to_guess)	;
	    
    
return 0;    
}

//1)Function to create list of word 
void list_of_words(int i , char guess_word[])
{
	const int WORD_COUNT = 100;
	const int MAX_WORD_LENGTH = 20;
    static char word_list[WORD_COUNT][MAX_WORD_LENGTH] = {
        "network", "digital", "locomot", "brother", "fortune", "primary", "channel", "amazing", "whistle", "bedroom",
        "adventure", "beautiful", "chocolate", "necessary", "important", "breakfast", "strawberry", "wonderful", "perception", "chemistry",
        "furniture", "everybody", "integrate", "framework", "highlight", "ambitious", "political", "intensity", "introduce", "magnitude",
        "elephant", "magnetic", "material", "standard", "dominant", "audience", "sentence", "daughter", "hardware", "ultimate",
        "identity", "tangible", "cultural", "tropical", "reliable", "creative", "absolute", "struggle", "monetary", "external",
        "difference", "technology", "experience", "productive", "leadership", "comparison", "foundation", "population", "everything", "appreciate",
        "information", "celebration", "environment", "development", "professional", "application", "organization", "availability", "distribution", 
        "conversation","relationship", "presentation", "unemployment", "establishment", "construction", "determination", "understanding", 
        "administrator", "communication", "participation","entertainment", "qualification", "administration", "transformation", "discrimination", 
        "collaboration", "experimentation", "recommendation", "demonstration", "transportation"
    };
   
    for (int j = 0; j < MAX_WORD_LENGTH; ++j) 
    {
        guess_word[j] = word_list[i][j];
    }
    
}


//2)Function to draw hangman
void draw_hangman(int lives) 
{

    cout << "        +---+" << endl;
    cout << "        |   |" << endl;
    if (lives <= 5)
    cout << "        0   |"<<endl;
    else
    cout << "            |"<<endl;
    if (lives == 4)
    cout << "        |   |"<<endl;
    else if  (lives == 3)
    cout << "       /|   |"<<endl;
    else if (lives <= 2)
    cout << "       /|\\  |"<<endl;
    else
    cout << "            |"<<endl;
    if (lives == 1)
    cout << "       /    |"<<endl;
    else if (lives <= 0)
    cout << "       / \\  |"<<endl;
    else
    cout << "            |"<<endl;
    cout << "            |"<<endl;
    cout << "    =============" << endl;
}


//3)Fuction to display result 
void decision (bool result,char name[] , char word_to_guess[])
{
if (result)
 cout << "Congratulations "<<name<<"! You guessed the word: " << word_to_guess << endl;
else
cout << "Game over! The word was: " << word_to_guess << endl;
}


//4)Function to convert uppercase letters to lowercase 
void toLowercase(char &letter ) 
{    
        if (letter >= 65 && letter <= 90) 
        {
            
            letter = letter + (97 - 65);
        }  
}



	
