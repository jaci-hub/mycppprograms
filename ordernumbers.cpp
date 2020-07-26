#include <iostream>

using namespace std;

int main()
{
    int list[10];
    int c, d;

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter number: ";
        cin >> list[i];
    }

    cout << "Ascending order: " << endl;
    for (int m = 0; m < 10; m++)
    {
        for (int n = m + 1; n < 10; n++)
            if (list[m] > list[n])
            {
                c = list[m];
                list[m] = list[n];
                list[n] = c;
            }
        cout << list[m] << " ";
    }
    cout << endl;

    cout << "Descending order: " << endl;
    for (int o = 0; o < 10; o++)
    {
        for (int p = o + 1; p < 10; p++)
            if (list[o] < list[p])
            {
                d = list[o];
                list[o] = list[p];
                list[p] = d;
            }
        cout << list[o] << " ";
    }
    cout << endl;

    return 0;
}