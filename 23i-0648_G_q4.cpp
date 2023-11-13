//Muhammad Asif 
//23i-0648
//CS-G
#include <iostream>
using namespace std;

// Function Prototypes
void findAndReplace(char text[], const char find[], const char replace[], int max_length);
void shifttext(char text[], int start, int end, int shiftBy, int max_length);
int string_length(const char arr[]);

//Main Function
int main() {
    const int max_text_length = 510;
    char text[max_text_length];

    cout << "Please enter the text[500 chars max]: ";
    cin.getline(text, max_text_length);
	
	//Loop to find and replace word
    while (true) {
        char find[20], replace[20];

        cout << "PLease enter the text to find (or just press enter to exit): ";
        cin.getline(find, 20);

        if (find[0] == '\0') break;

        cout << "Please enter text to replace: ";
        cin.getline(replace, 20);

        findAndReplace(text, find, replace, max_text_length);

        // Display the result
        cout << "\nResult:\n" << text << "\n";
    }

    cout << "\nProgram terminated." << endl;
    return 0;
}

int string_length(const char arr[]) {
    int length = 0;
    while (arr[length] != '\0') {
        ++length;
    }
    return length;
}

//Function to make proper adjustment in text
void shifttext(char text[], int start, int end, int shift, int max_length) 
{
    if (shift == false || start > end) 
    return;
	// Shift right
    if (shift > 0)   
        for (int i = end; i >= start && i + shift < max_length; --i) 
            text[i + shift] = text[i];
    // Shift left
    else 
        for (int i = start; i <= end && i + shift < max_length; ++i) 
            text[i + shift] = text[i];
}

//Find and replace text Function
void findAndReplace(char text[], const char find[], const char replace[], int max_length) {
    int text_length = string_length(text);
    int find_length = string_length(find);
    int replace_length = string_length(replace);
    
int k = text_length - find_length;
	int i = 0;
    while(i<=k) 
    {
        bool found = 1;
        int j = 0;
       	while(j < find_length)
        {
            if (text[i + j] != find[j]) 
            {
                found = 0;
                break;
            }
        j++;    
        }

        if (found) 
        {
            int shift_amount = replace_length - find_length;
            int new_length = text_length + shift_amount;
            if (new_length >= max_length) 
            {
                cout << "Error: Replacement text is too long." << endl;
                return;
            }
            
            shifttext(text, i + find_length, text_length, shift_amount, max_length);
            
            for (int j = 0; j < replace_length; j++) 
                text[i + j] = replace[j];
                
            text_length = new_length;
            i += replace_length;
            
        } 
        else 
            ++i;
    }
}

