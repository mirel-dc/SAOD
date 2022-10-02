#include <iostream>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool flag = false;
    for (i = 0; i < n - 1; i++)
    {
        if (flag)
            break;
        flag = true;
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
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

    cout << endl;

    bubbleSort(arr, N);
    cout << "After sort: \n";
    for (i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
