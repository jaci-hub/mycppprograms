#include <iostream>

using namespace std;

void conv()
{
    double f, c;
    int a;
    cin >> a;
    if (a == 1)
    {
        system("clear");
        cout << "Enter temperature in Fahrenheit: ";
        cin >> f;
        c = (f - 32.0) * (5.0 / 9.0);
        cout << f << " F"
             << " = " << c << " C" << endl;
    }
    else if (a == 2)
    {
        system("clear");
        cout << "Enter temperature in Celcius: ";
        cin >> c;
        f = c * (9.0 / 5.0) + 32;
        cout << c << " C"
             << " = " << f << " F" << endl;
    }
    else if (a != 1 || a != 2)
    {
        cout << "Select option 1 or 2: ";
        conv();
    }
}

int main()
{
    cout << "1- Convert from Fahrenheit to Celsius." << endl;
    cout << "2- Convert from Celsius to Fahrenheit." << endl;
    cout << "Select an option above: ";
    conv();
    return 0;
}