#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == ' ')
            name.erase(name.find(' '), 1);
    }
    cout << name << endl;
    cout << "Your name has " << name.length() << " letters!" << endl;
    return 0;
}