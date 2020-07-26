#include <cmath>
#include <iostream>

using namespace std;

double a, b, c, m, n, p, q, delta, x1, x2, xv, yv;

void par_a()
{
    cout << "Enter parameter 'a': ";
    cin >> a;
    if (a == 0)
    {
        cout << "a cannot be 0." << endl;
        par_a();
    }
}

int main()
{
    cout << "y = ax^2 + bx + c" << endl;
    par_a();
    cout << "Enter parameter 'b': ";
    cin >> b;
    cout << "Enter parameter 'c': ";
    cin >> c;
    delta = pow(b, 2.0) - 4.0 * a * c;
    xv = -(b / (2.0 * a));
    if (xv == -0)
        xv = 0;
    yv = -(delta / (4.0 * a));
    if (yv == -0)
        yv = 0;
    if (delta < 0 && a < 0)
    {
        cout << "The function has no real zeros." << endl;
        cout << "Its parabola is concave down." << endl;
        cout << "It has a maximum point at Vertix = "
             << "(" << xv << "," << yv << ")" << endl;
        cout << "It is negative for any value of x." << endl;
    }
    else if (delta < 0 && a > 0)
    {
        cout << "The function has no real zeros." << endl;
        cout << "Its parabola is concave up." << endl;
        cout << "It has a minimum point at Vertix = "
             << "(" << xv << "," << yv << ")" << endl;
        cout << "It is positive for any value of x." << endl;
    }
    else if (delta == 0 && a < 0)
    {
        cout << "The function has only one real zero: " << xv << endl;
        cout << "Its parabola is concave down." << endl;
        cout << "It has a maximum point at Vertix = "
             << "(" << xv << "," << yv << ")" << endl;
        cout << "It is negative for any value of x, except " << xv << endl;
    }
    else if (delta == 0 && a > 0)
    {
        cout << "The function has only one real zero: " << xv << endl;
        cout << "Its parabola is concave up." << endl;
        cout << "It has a minimum point at Vertix = "
             << "(" << xv << "," << yv << ")" << endl;
        cout << "It is positive for any value of x, except " << xv << endl;
    }
    else if (delta > 0 && a < 0)
    {
        x1 = (-(b) + sqrt(delta)) / (2.0 * a);
        x2 = (-(b)-sqrt(delta)) / (2.0 * a);
        cout << "The zeros of the function are x1= " << x1 << " and "
             << "x2= " << x2 << endl;
        cout << "Its parabola is concave down." << endl;
        cout << "It has a maximum point at Vertix = "
             << "(" << xv << "," << yv << ")" << endl;
        m = x1 < x2 ? x1 : x2;
        n = x2 > x1 ? x2 : x1;
        cout << "It is positive from " << m << " to " << n << endl;
        cout << "It is negative from -inf to " << m << " and from " << n
             << " to +inf." << endl;
    }
    else if (delta > 0 && a > 0)
    {
        x1 = (-(b) + sqrt(delta)) / (2.0 * a);
        x2 = (-(b)-sqrt(delta)) / (2.0 * a);
        cout << "The zeros of the function are x1= " << x1 << " and "
             << "x2= " << x2 << endl;
        cout << "Its parabola is concave up." << endl;
        cout << "It has a minimum point at Vertix = "
             << "(" << xv << "," << yv << ")" << endl;
        p = x1 < x2 ? x1 : x2;
        q = x2 > x1 ? x2 : x1;
        cout << "It is negative from " << p << " to " << q << endl;
        cout << "It is positive from -inf to " << p << " and from " << q
             << " to +inf." << endl;
    }
    return 0;
}