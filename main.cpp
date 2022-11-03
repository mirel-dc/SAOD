#include <iostream>
#include <ctime>
using namespace std;

void arrOut(int arr[], int n);
void arrRand(int arr[], int n, int maxim);
void bubbleSort(int arr[], int n);
void shakerSort(int arr[], int n);
void insertSort(int arr[], int n);
void podshetSort(int arr[], int n);
void extractSort(int arr[], int n);
void treeSort(int arr[], int n);
void shellSort(int arr[], int n);
void kStat(int arr[], int n, int k);
void mergeSort(int arr[], int n);

int main()
{
    int i, loop = 1, command = 0;
    srand(time(NULL));
    const int n = 10, maxim = 100;

    int arr[n];

    arrRand(arr, n, maxim);
    arrOut(arr, n);

    mergeSort(arr, n);

    arrOut(arr, n);
    /*
        while (loop == 1)
        {
            arrRand(arr, n, maxim);
            cout << "Choose sort method: " << endl;
            cout << "1: Bubble Sort" << endl;
            cout << "2: Shaker Sort" << endl;
            cout << "3: Insert Sort" << endl;
            cout << "4: Podshet Sort" << endl;
            cout << "5: Extract Sort" << endl;
            cout << "6: Tree Sort" << endl;
            cout << "7: Shell Sort" << endl;
            cout << "8: k-Statistic" << endl;
            cout << "9: Merge Sort" << endl;
            cin >> command;
            arrOut(arr, n);

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

            case 5:
                extractSort(arr, n);
                arrOut(arr, n);
                break;

            case 6:
                treeSort(arr, n);
                arrOut(arr, n);
                break;

            case 7:
                shellSort(arr, n);
                arrOut(arr, n);
                break;

            case 8:
                int k;
                cout << "Vvedite posiciyu chisla" << endl;
                cin >> k;
                kStat(arr, n, k);
                break;

            case 9:
                mergeSort(arr, n);
                arrOut(arr, n);
                break;

            default:
                break;
            }

            cout << "1 - continue" << endl;
            cin >> loop;
            cout << "---------------------" << endl;
        }*/

    return 0;
}

void arrRand(int arr[], int n, int maxim)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % maxim;
    }
}

void arrOut(int arr[], int n)
{
    cout << "Array: " << endl;
    for (int i = 0; i < n; i++)
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

    while (left <= right)
    {
        for (i = right; i >= left; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
            }
        }
        left++;
        for (i = left; i <= right; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
            }
        }
        right--;
        arrOut(arr, n);
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

void extractSort(int arr[], int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}

void kucha(int arr[], int n, int i)
{
    int maxim = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[maxim])
        maxim = l;
    if (r < n && arr[r] > arr[maxim])
        maxim = r;
    if (maxim != i)
    {
        swap(arr[i], arr[maxim]);
        kucha(arr, n, maxim);
    }
}

void treeSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        kucha(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        kucha(arr, i, 0);
        arrOut(arr, n);
    }
}

void shellSort(int arr[], int n)
{
    arrOut(arr, n);
    int d = n / 2;
    while (d > 0)
    {
        for (int i = 0; i < n - d - 1; i++)
        {
            bool flag = false;
            int j = i;
            arrOut(arr, n);
            cout << arr[j] << " - " << arr[j + d] << " ::" << d << endl;
            while (j >= 0 && arr[j] > arr[j + d])
            {
                swap(arr[j], arr[j + d]);
                j = j - d;
            }
        }
        d /= 2;
    }
}

void kStat(int arr[], int n, int k)
{
    int l = 1, r = n, i, j, x;
    while (l < r - 1)
    {
        x = arr[k];
        i = l;
        j = r;
        do
        {
            while (arr[i] < x)
                i++;
            while (arr[j] > x)
                j--;
            if (i <= j)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        } while (i < j);
        if (j < k)
            l = i;
        if (i > k)
            r = j;
    }
    arrOut(arr, n);
    cout << "Nuwnoe chislo: " << arr[k] << endl;
}

void mergeSort(int arr[], int n)
{
    int rght, wid, rend;
    int i, j, m, t;
    int b[n];

    for (int k = 1; k < n; k *= 2)
    {
        arrOut(arr, n);
        cout << k << endl;
        for (int left = 0; left + k < n; left += k * 2)
        {
            rght = left + k;
            rend = rght + k;
            if (rend > n)
                rend = n;
            m = left;
            i = left;
            j = rght;
            while (i < rght && j < rend)
            {
                if (arr[i] <= arr[j])
                {
                    b[m] = arr[i];
                    i++;
                }
                else
                {
                    b[m] = arr[j];
                    j++;
                }
                m++;
            }
            while (i < rght)
            {
                b[m] = arr[i];
                i++;
                m++;
            }
            while (j < rend)
            {
                b[m] = arr[j];
                j++;
                m++;
            }
            for (m = left; m < rend; m++)
            {
                arr[m] = b[m];
            }
        }
    }
}
