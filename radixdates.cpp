#include <iostream>
#include <ctime>
#include <locale.h>
#include <string>
using namespace std;

template <class T>
void arrOut(T arr[], int n)
{
    cout << "Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void dateToNumbers(string arr[], int a[], int n)
{
    string t;

    for (int i = 0; i < n; i++)
    {
        t = arr[i].substr(6, 7) + arr[i].substr(3, 4).substr(0, 2) + arr[i].substr(0, 2);
        a[i] = stoi(t);
    }
}

void numbersToDate(int arr[], string a[], int n)
{
    string t;
    for (int i = 0; i < n; i++)
    {
        t = to_string(arr[i]).substr(4, 6) + "." + to_string(arr[i]).substr(2, 3).substr(0, 2) + "." + to_string(arr[i]).substr(0, 2);
        a[i] = t;
    }
}

void countingSort(int arr[], int n, int div)
{
    cout << "K= " << div << endl;
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / div) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
        cout << arr[i] << endl;
    }
}

void RadixSort(int arr[], int size)
{
    int div = 1;
    int max = 6;
    for (int k = max; k > 0; k--)
    {
        countingSort(arr, size, div);
        div *= 10;
    }
}

int main()
{
    const int n = 5;
    string arrStr[n] = {"23.01.19",
                        "12.02.19",
                        "15.12.18",
                        "16.02.18",
                        "04.01.17"};
    int arr[n];
    dateToNumbers(arrStr, arr, n);
    arrOut(arr, n);
    RadixSort(arr, n);
    arrOut(arr, n);
    numbersToDate(arr, arrStr, n);
    arrOut(arrStr, n);

    return 0;
}