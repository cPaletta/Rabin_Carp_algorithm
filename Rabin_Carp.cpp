#include <iostream>
#include <math.h>
#define size 13
using namespace std;

int Hash(string Word)
{
    int sum = 0;
    for (int i = 0; i < Word.length(); i++)
    {
        sum += Word[i];
    }
    return sum % (size - 1);
}


void Rabin_Carp(int tablica[], string pattern, string text)
{
    int text_leng = text.length();
    int patter_leng = pattern.length();
    int wartosc;
    int wartosc_pattern = Hash(pattern);

    cout << "Wartoscc pattern: " << wartosc_pattern << endl << endl;


    for (int i = 0; i <= text_leng - patter_leng; i++)  //Przechodzimy po ca³ym tekœcie
    {
        int wartosc = Hash(text.substr(i, patter_leng)); //Przedzia³ od i o d³ugoœci patter_leng
        tablica[i] = wartosc;

        if (wartosc == wartosc_pattern)
        {
            int j = 0;
            while (j < patter_leng && pattern[j] == text[i + j]) {
                j++;
                if (j == patter_leng) {
                    cout << "Wzorzec znaleziony na indeksie: " << i << endl;
                    return;
                }
            }
        }
    }


}


int main()
{
    string pattern = "abd";
    string text = "aafsdafsgggdsgfaabdaaaaaaa";

    int* tablica = new int[text.length() - pattern.length()+1];

    Rabin_Carp(tablica, pattern, text);
    cout << text.length() << endl;

    for (int i = 0; i <= text.length() - pattern.length(); i++)
    {
        cout <<i<<"  " << tablica[i] << endl;
    }

}