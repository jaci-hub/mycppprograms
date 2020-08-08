#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int count = 1;
    cout << "Enter your full name: ";
    getline(cin, name);

    for (int m = 0; m < name.length(); m++)
    {
        if (name[m] == ' ')
            count++;
    }
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == ' ')
            name.erase(name.find(' '), 1);
    }
    cout << "Your full name has " << count << " names and " << name.length() << " letters!" << endl;

    return 0;
}