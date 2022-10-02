#include <iostream>
#include <ctime>
using namespace std;

void insertSort(int arr[], int n)
{
}

int main()
{
    srand(time(NULL));
    int i, N = 10;

    int arr[N];
    for (i = 0; i < N - 1; i++)
    {
        arr[i] = rand() % 20;
    }

    cout << "Before sort: \n";
    for (i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ' ';
    }

    cout << endl;

    insertSort(arr, N);
    cout << "After sort: \n";
    for (i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}