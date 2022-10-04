#include <iostream>
#include <ctime>
using namespace std;

void insertSort(int arr[], int n)
{
    int i, j = 0, temp;
    for (i = 1; i < n - 1; i++)
    {
        temp = arr[i];
        j = i;
        while ((j > 0) && (arr[j - 1] > temp))
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

int main()
{
    srand(time(NULL));
    int i;
    const int N = 10;

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
    cout << "\n--------------" << endl;

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