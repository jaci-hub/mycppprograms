#include <iostream>

using namespace std;

int a;

int fact(int x)
{
    if (x == 0)
        return 1;
    else if (x == 1)
        return 1;
    else if (x == 2)
        return 2;
    else
        return x * fact(x - 1);
}
void num()
{
    cin >> a;
    if (a <= 0)
    {
        cout << "Enter an INTEGER: ";
        num();
    }
}
int main()
{
    cout << "Enter an integer: ";
    num();
    cout << fact(a) << endl;
    return 0;
}