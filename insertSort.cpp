#include <iostream>
#include <ctime>
using namespace std;

void insertSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n - 1; i++)
    {
        temp = arr[i];
        j = 0;
        while ((j < i) && (arr[j] < temp))
        {
            swap(arr[j - 1], arr[j]);
            j++;
        }
        arr[j] = temp;

        for (int k = 0; k < n - 1; k++)
        {
            cout << arr[k] << ' ';
        }
        cout << endl;
    }
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
    cout << endl;
    return 0;
}