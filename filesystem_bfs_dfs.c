
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;

// Breadth-First Search
void BFS(int start)
{
    int front = 0, rear = 0;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// Depth-First Search
void DFS(int current)
{
    int i;

    visited[current] = 1;
    printf("%d ", current);

    for (i = 0; i < n; i++)
    {
        if (graph[current][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

// Check whether a file is reachable using BFS
int searchBFS(int start, int target)
{
    int front = 0, rear = 0;
    int i;
    int seen[MAX] = {0};

    queue[rear++] = start;
    seen[start] = 1;

    while (front < rear)
    {
        int current = queue[front++];

        if (current == target)
            return 1;

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !seen[i])
            {
                queue[rear++] = i;
                seen[i] = 1;
            }
        }
    }

    return 0;
}

// Check whether a file is reachable using DFS
int searchDFS(int current, int target, int seen[])
{
    int i;

    if (current == target)
        return 1;

    seen[current] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[current][i] == 1 && !seen[i])
        {
            if (searchDFS(i, target, seen))
                return 1;
        }
    }

    return 0;
}

int main()
{
    int i, j;
    int start, target;
    int seen[MAX] = {0};

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter adjacency matrix (%d x %d):\n", n, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("Enter target file node (0 to %d): ", n - 1);
    scanf("%d", &target);

    if (start < 0 || start >= n ||
        target < 0 || target >= n)
    {
        printf("Invalid node number.\n");
        return 1;
    }

    BFS(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    if (searchBFS(start, target))
        printf("BFS Search: File found.\n");
    else
        printf("BFS Search: File not found.\n");

    if (searchDFS(start, target, seen))
        printf("DFS Search: File found.\n");
    else
        printf("DFS Search: File not found.\n");

    return 0;
}
