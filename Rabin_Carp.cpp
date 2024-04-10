#include <iostream>
#include <math.h>
#define size 13 // Defines the size used in the Hash function.
using namespace std;

// The Hash function calculates a hash value for a given word.
// It sums up the ASCII values of all characters in the word
// and then uses the modulo operation to ensure uniqueness.
int Hash(string Word)
{
    int sum = 0;
    for (int i = 0; i < Word.length(); i++)
    {
        sum += Word[i];
    }
    return sum % (size - 1);
}

// The Rabin-Carp function searches for a pattern within a text
// using the hash function to improve efficiency.
void Rabin_Carp(int tablica[], string pattern, string text)
{
    int text_leng = text.length(); // The length of the text.
    int patter_leng = pattern.length(); // The length of the pattern.
    int wartosc_pattern = Hash(pattern); // Hash value of the pattern.

    cout << "Pattern value: " << wartosc_pattern << endl << endl;

    // Loop through the entire text
    for (int i = 0; i <= text_leng - patter_leng; i++)  
    {
        // Hash value for a substring of text starting at index i with length patter_leng
        int wartosc = Hash(text.substr(i, patter_leng)); 
        tablica[i] = wartosc;

        // If the hash value matches the pattern's hash value, check for actual match
        if (wartosc == wartosc_pattern)
        {
            int j = 0;
            while (j < patter_leng && pattern[j] == text[i + j]) {
                j++;
                // If a match is found, print the index and return
                if (j == patter_leng) {
                    cout << "Pattern found at index: " << i << endl;
                    return;
                }
            }
        }
    }
}


int main()
{
    string pattern = "abd"; // The pattern to search for within the text.
    string text = "aafsdafsgggdsgfaabdaaaaaaa"; // The text in which to search for the pattern.

    // Allocate memory dynamically
    int* tablica = new int[text.length() - pattern.length() + 1];

    Rabin_Carp(tablica, pattern, text);
    cout << text.length() << endl;

    for (int i = 0; i <= text.length() - pattern.length(); i++)
    {
        cout << i << "  " << tablica[i] << endl;
    }
    

    delete[] tablica;
}
