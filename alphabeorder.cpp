#include <iostream>
#include <string>
using namespace std;

string word;
string list[5];

void ordering()
{
    if (word[0] == 'a')
        list[0] = word;
    else if (word[0] == 'b')
        list[1] = word;
    else if (word[0] == 'c')
        list[2] = word;
}

int main()
{
    int a = 0;
    while (a < 3)
    {
        cout << "Enter a word: ";
        cin >> word;
        ordering();
        a++;
    }

    for (int i = 0; i < 3; i++)
        cout << list[i] << endl;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

string word;
string list[5];

void ordering()
{
    if (word[0] == 'a')
        list[0] = word;
    else if (word[0] == 'b')
        list[1] = word;
    else if (word[0] == 'c')
        list[2] = word;
}

int main()
{
    int a = 0;
    while (a < 3)
    {
        cout << "Enter a word: ";
        cin >> word;
        ordering();
        a++;
    }

    for (int i = 0; i < 3; i++)
        cout << list[i] << endl;

    return 0;
}
