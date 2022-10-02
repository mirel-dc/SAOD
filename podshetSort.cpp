#include <iostream>
#include <ctime>
using namespace std;

void podshetSort(int arr[], int n)
{
    int *tempArr = new int[n];
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        tempArr[i] = 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        k = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if ((arr[j] < arr[i]) || ((arr[j] == arr[i]) && (j < i)))
            {
                k = k + 1;
            }
        }
        tempArr[k] = arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = tempArr[i];
    }

    delete[] tempArr;
}

int main()
{
    srand(time(NULL));
    int i, Maximum;

    Maximum = 10;
    int arr[15];
    int N = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < N - 1; i++)
    {
        arr[i] = rand() % Maximum;
    }

    cout << "Before sort: \n";
    for (i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ' ';
    }

    cout << endl;

    podshetSort(arr, N);
    cout << "After sort: \n";
    for (i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
