#include <cstdio>
#include <string>
using std::string;

int getMax(string arr[], int n)
{
    int max = arr[0].size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i].size() > max)
            max = arr[i].size();
    }
    return max;
}

void countSort(string a[], int n, int k)
{
    string *b = new string[n];
    int *c = new int[257];

    for (int i = 0; i < 257; i++)
    {
        c[i] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        // c[k < a[j].size() ? a[j][k] + 1 : 0]++;
        if (k < a[j].size())
        {
            c[a[j][k] + 1]++;
        }
        else
        {
            c[0]++;
        }
    }

    for (int f = 1; f < 257; f++)
    {
        c[f] += c[f - 1];
    }

    for (int r = n - 1; r >= 0; r--)
    {
        // b[c[k < a[r].size() ? a[r][k] + 1 : 0] - 1] = a[r];
        if (k < a[r].size())
        {
            b[c[a[r][k] + 1] - 1] = a[r];
        }
        else
        {
            b[c[0] - 1] = a[r];
        }

        // c[k < a[r].size() ? a[r][k] + 1 : 0]--;
        if (k < a[r].size())
        {
            c[a[r][k] + 1]--;
        }
        else
        {
            c[0]--;
        }
    }

    for (int l = 0; l < n; l++)
    {
        a[l] = b[l];
    }

    delete[] b;
    delete[] c;
}

void radixSort(string b[], int r)
{
    int max = getMax(b, r);
    for (int digit = max; digit > 0; digit--)
    {
        countSort(b, r, digit - 1);
    }
}

int main(void)
{
    string data[] = {
        "aaaba",
        "dfjasdlifjai",
        "jiifjeogiejogp",
        "aabaaaa",
        "gsgj",
        "gerph",
        "aaaaaaa",
        "htjltjlrth",
        "joasdjfisdjfdo",
        "hthe",
        "aaaaaba",
        "jrykpjl",
        "hkoptjltp",
        "aaaaaa",
        "lprrjt"};
    puts("before sorting:");
    for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        printf("    %s\n", data[i].c_str());
    }
    radixSort(data, (int)(sizeof(data) / sizeof(data[0])));
    puts("after sorting:");
    for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        printf("    %s\n", data[i].c_str());
    }
    return 0;
}