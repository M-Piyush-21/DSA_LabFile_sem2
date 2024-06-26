
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 100;


void dfs(int graph[][MAXN], bool visited[], int n, int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; ++i)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs(graph, visited, n, i);
        }
    }
}


void bfs(int graph[][MAXN], bool visited[], int n, int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < n; ++i)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[MAXN][MAXN]; 
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }

    bool visited[MAXN] = {false}; 

    cout << "Depth First Search (DFS): ";
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(graph, visited, n, i);
        }
    }
    cout << endl;


    fill(visited, visited + n, false);

    cout << "Breadth First Search (BFS): ";
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            bfs(graph, visited, n, i);
        }
    }
    cout << endl;

    return 0;
}