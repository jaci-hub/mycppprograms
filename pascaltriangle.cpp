#include <iostream>

using namespace std;

int main()
{
    cout << "How many rows: ";
    int r;
    cin >> r;
    for (int n = 0; n < r; n++)
    {
        int x = 1;
        for (int j = r - 1; j >= n; j--)
            cout << " ";
        for (int k = 0; k <= n; k++)
        {
            cout << x << " ";
            x = x * (n - k) / (k + 1);
        }
        cout << endl;
    }
    return 0;
}

//https://www.mathsisfun.com/pascals-triangle.html
//Explanation of line 15, **A formula for any entry in the triangle**
//line 15 is pretty much 'n choose k' --> C(n,k)