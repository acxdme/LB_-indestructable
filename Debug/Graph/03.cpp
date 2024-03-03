// Debugging Total Number of components

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> getOneComponent(bool **graph, int startingVertex, int v, bool *visited)
{
    vector<int> component;
    queue<int> pendingNodes;
    pendingNodes.push(startingVertex);
    visited[startingVertex] = true;

    while (!pendingNodes.empty())
    {
        int current = pendingNodes.front();
        pendingNodes.pop();
        component.push_back(current);
        for (int i = 0; i < v; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
    return component;
}

vector<vector<int>> getAllComponents(bool **graph, int v)
{
    vector<vector<int>> result;
    bool *visited = new bool[v]();

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> component = getOneComponent(graph, i, v, visited);
            result.push_back(component);
        }
    }

    return result;
}

int main()
{

    int v = 4; // Declare and initialize the "v" variable

    bool **graph = new bool *[v];
    for (int i = 0; i < v; i++)
    {
        graph[i] = new bool[v];
        for (int j = 0; j < v; j++)
        {
            graph[i][j] = false; // Set all values to false initially
        }
    }

    // Set some specific values in the graph
    graph[0][1] = true;
    graph[1][0] = true;
    graph[1][2] = true;
    graph[2][1] = true;
    graph[2][3] = true;
    graph[3][2] = true;
    // Add more values as needed


    vector<vector<int>> res = getAllComponents(graph, v);
    cout<<"res.size() : " << res.size() << endl;

    return 0;
}
