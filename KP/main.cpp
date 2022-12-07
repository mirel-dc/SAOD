#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <limits.h>
#define INF 5000
using namespace std;

//Количество вершин
const int n = 7;

//Граф через матрицу смежности
int graph[n][n] = {
    {0, 3, 1, 7, 0, 2, 0},
    {0, 0, 0, 1, 0, 2, 1},
    {0, 1, 0, 1, 3, 0, 0},
    {7, 1, 0, 0, 2, 0, 1},
    {1, 0, 1, 0, 0, 5, 3},
    {3, 0, 3, 0, 5, 0, 0},
    {0, 2, 0, 1, 3, 0, 0}};

void printGraph();

// DFS
bool *visited = new bool[n];
void DFS(int st);
void visitedFalse();

// FLOYD-WARSHALL MIN CYCLE
int floydGraphCycle[n][n];
vector<int> tempPath, path;
int mincycle = INF;
void toFloydCycle();
void floydWarshallCycle();
void printMatrix(int matrix[][n]);

// FLOYD-WARSHALL
int floydGraph[n][n];
void toFloyd();
void floydWarshall();

// PRIM
void primMST();

int main()
{
    int i, j, start;

    printGraph();
    visitedFalse();

    int loop = 1, command = 0;
    while (loop == 1)
    {
        cout << "Choose: " << endl;
        cout << "1: Print graph" << endl;
        cout << "2: DFS" << endl;
        cout << "3: Min Cycle" << endl;
        cout << "4: Minim path length" << endl;
        cout << "5: MST Prim" << endl;

        cin >> command;

        switch (command)
        {
        case 1:
            printGraph();
            break;

        case 2:
            cout << "Start point: >> ";
            cin >> start;
            cout << "DFS " << start << ": ";
            DFS(start - 1);
            cout << endl;
            break;

        case 3:
            cout << "Floyd-Warshall matrix: " << endl;
            toFloydCycle();
            floydWarshallCycle();
            break;

        case 4:
            cout << "Floyd-Warshall matrix: " << endl;
            toFloyd();
            floydWarshall();
            break;

        case 5:
            primMST();

        default:
            break;
        }

        cout << "1 - continue" << endl;
        cin >> loop;
        cout << "---------------------" << endl;
    }

    delete[] visited;

    return 0;
}

void printGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", graph[i][j]);
        }
        cout << endl;
    }
}

//Выполнить обход графа в глубину
void DFS(int st)
{
    int i;
    cout << st + 1 << " ";
    visited[st] = true;
    for (i = 0; i <= n; i++)
        if ((graph[st][i] != 0) && (!visited[i]))
            DFS(i);
}

void visitedFalse()
{
    int i;
    for (i = 0; i < n; i++)
    {
        visited[i] = false;
    }
}

//Определить самый короткий цикл в графе
void floydWarshallCycle()
{
    int matrix[n][n], i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = floydGraphCycle[i][j];

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                {
                    tempPath.push_back(i + 1);
                    tempPath.push_back(k + 1);
                    tempPath.push_back(j + 1);
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    if (i == j)
                    {
                        if (matrix[i][j] < mincycle)
                        {
                            path = tempPath;
                            mincycle = matrix[i][j];
                        }
                    }
                }
            }
            tempPath.clear();
        }
    }
    printMatrix(matrix);
    cout << "Min cycle length: " << mincycle << endl;
    cout << "Path: ";
    for (auto i : path)
    {
        cout << i << " ";
    }
    cout << endl;
}

void printMatrix(int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void toFloydCycle()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 0)
                floydGraphCycle[i][j] = INF;
            else
                floydGraphCycle[i][j] = graph[i][j];
        }
    }
}

//Определить кратчайший путь между всеми парами вершин
void floydWarshall()
{
    int matrix[n][n], i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = floydGraph[i][j];

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                {
                    if (k != 0)
                        cout << i + 1 << "->" << j + 1 << " = " << i + 1 << "->" << k + 1 << "->" << j + 1 << endl;
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    printMatrix(matrix);
    cout << endl;
}

void toFloyd()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                floydGraph[i][i] = 0;
            if (graph[i][j] == 0)
                if (i == j)
                    floydGraph[i][i] = 0;
                else
                    floydGraph[i][j] = INF;
            else
                floydGraph[i][j] = graph[i][j];
        }
    }
}

//Построить минимальное остовное дерево с помощью алгоритма Прима
void primMST()
{
    int no_edge;
    int selected[n];

    memset(selected, false, sizeof(selected));
    no_edge = 0;

    selected[0] = true;

    int x;
    int y;

    cout << "Edge  : Weigth";
    cout << endl;
    while (no_edge < n - 1)
    {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x + 1 << " - " << y + 1 << " :  " << graph[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
}