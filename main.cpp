#include <iostream>
#include <ctime>
using namespace std;

void arrOut(int arr[], int n);
void arrRand(int arr[], int n, int maxim);

void bubbleSort(int arr[], int n);
void shakerSort(int arr[], int n);
void insertSort(int arr[], int n);
void podshetSort(int arr[], int n);

int main()
{
    int i, loop = 1, command = 0;
    srand(time(NULL));
    const int n = 10, maxim = 15;
    int arr[n];
    while (loop == 1)
    {
        arrRand(arr, n, maxim);
        arrOut(arr, n);
        cout << "Choose sort method: " << endl;
        cout << "1: Bubble Sort" << endl;
        cout << "2: Shaker Sort" << endl;
        cout << "3: Insert Sort" << endl;
        cout << "4: Podshet Sort" << endl;

        cin >> command;

        switch (command)
        {
        case 1:
            bubbleSort(arr, n);
            arrOut(arr, n);
            break;

        case 2:
            shakerSort(arr, n);
            arrOut(arr, n);
            break;

        case 3:
            insertSort(arr, n);
            arrOut(arr, n);
            break;

        case 4:
            podshetSort(arr, n);
            arrOut(arr, n);
            break;

        default:
            break;
        }

        cout << "1 - continue" << endl;
        cin >> loop;
        cout << "---------------------" << endl;
    }

    return 0;
}

void arrRand(int arr[], int n, int maxim)
{
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = rand() % maxim;
    }
}

void arrOut(int arr[], int n)
{
    cout << "Array: " << endl;
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

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

void shakerSort(int arr[], int n)
{
    int left = 0, right = n - 1, i;
    int range = n;
    int Array[n];

    for (int i = 0; i < range; i++)
    {
        Array[i] = arr[i];
    }

    while (left <= right)
    {
        for (i = right; i >= left; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                swap(Array[i - 1], Array[i]);
            }
        }
        left++;
        for (i = left; i <= right; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                swap(Array[i - 1], Array[i]);
            }
        }
        right--;
        arrOut(Array, range);
    }
}

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