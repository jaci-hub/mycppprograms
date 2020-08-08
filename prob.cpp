#include <iostream>

using namespace std;

void zigzag()
{
    int peakval;
    cin >> peakval;
    if (peakval < 3 || peakval > 6)
    {
        cout << "Enter a number between 3 and 6: ";
        zigzag();
    }
    int arr[15];
    for (int j = 0; j < 15; j++)
    {
        int StartRepIndex = 2 * j * (peakval - 1);
        int EndRepIndex = StartRepIndex + peakval;
        for (int k = 1; k <= peakval; k++)
        {
            arr[StartRepIndex] = k;
            StartRepIndex++;
        }
        for (int m = peakval - 1; m >= 2; m--)
        {
            arr[EndRepIndex] = m;
            EndRepIndex++;
        }
    }
    for (int z = 0; z < 15; z++)
        cout << arr[z] << " ";
    cout << endl;
}
int main()
{
    cout << "Enter a number between 3 and 6: ";
    zigzag();
    return 0;
}