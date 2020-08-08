#include <iostream>

using namespace std;

//FIND PAIRS IN THE ARRAY WITH SUM "sum"
void hasPair(int arr[], int sum)
{
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]);//why not working?
    while (start < end)
    {
        if (arr[start] + arr[end] == sum)
        {
            cout << arr[start] << " and " << arr[end] << endl;
            start++;
        }
        while (arr[start] + arr[end] < sum)
            start++;
        while (arr[start] + arr[end] > sum)
            end--;
    }
    if (arr[start] + arr[end] != sum)
        cout << "No pairs add up to: " << sum << endl;
}

//FIND ALL THE SUBSTES IN THE ARRAY

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6};
    hasPair(a, 9);

    return 0;
}