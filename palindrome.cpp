#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    cout << "Enter word: ";
    getline(cin, word);
    int m = 0;
    int n = word.length() - 1;
    if (word[m++] == word[n--])
        cout << word << " is a palindrome!" << endl;
    else
        cout << word << " is not a palindrome!" << endl;

    return 0;
}