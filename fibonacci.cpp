#include <iostream>

using namespace std;

int a;

int fib(int x)
{
    if (x == 1)
        return 1;
    else if (x == 2)
        return 1;
    else if (x == 3)
        return 2;
    else
        return fib(x - 1) + fib(x - 2);
}
void num()
{
    cin >> a;
    if (a <= 0)
    {
        cout << "Enter a number greater than 0: ";
        num();
    }
}
int main()
{
    cout << "Enter an integer: ";
    num();
    for (int i = 1; i <= a; i++)
        cout << fib(i) << " ";
    return 0;
}