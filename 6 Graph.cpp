//Using Adjacency matrix
#include <iostream>
#include <queue>
using namespace std;

int adj_mat[50][50] = {0, 0};
int visited[50] = {0};

void dfs(int s, int n, string arr[])
{
    visited[s] = 1;
    cout << arr[s] << " ";
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[s][i] && !visited[i])
            dfs(i, n, arr);

    }
}

void bfs(int s, int n, string arr[])
{
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int v;
    queue<int> bfsq;
    if (!visited[s])
    {
        cout << arr[s] << " ";
        bfsq.push(s);
        visited[s] = true;
        while (!bfsq.empty())
        {
            v = bfsq.front();
            for (int i = 0; i < n; i++)
            {
                if (adj_mat[v][i] && !visited[i])
                {
                    cout << arr[i] << " ";
                    visited[i] = true;
                    bfsq.push(i);
                }
            }
            bfsq.pop();
        }
    }
}

int main()
{
    cout << "Enter no. of cities: ";
    int n, u;
    cin >> n;
    string cities[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }
    
    cout << "\nYour cities are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "city #" << i << ": " << cities[i] << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << " : ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }
    cout << endl;
    
    for (int i = 0; i < n; i++)
        cout << "\t\t" << cities[i] ;
    for (int i = 0; i < n; i++)
    {
        cout << "\n"<<cities[i];
        for (int j = 0; j < n; j++)
            cout << "\t" << adj_mat[i][j] << "\t";
        cout << endl;
    }
    cout << "Enter Starting Vertex: ";
    cin >> u;
    cout << "DFS: ";
    dfs(u, n, cities);
    cout << endl;
    cout << "BFS: ";
    bfs(u, n, cities);
    return 0;

}














// Algorithm: Check Flight Network Connectivity
// Detailed Steps:
// 1. Start the main function.
// 2. Initialize a Graph object named graph.
// 3. Replace the cities vector with the actual list of cities in the flight network.
// 4. Replace the flights vector with the actual flight data represented as tuples of (source, destination, cost).
// 5. Iterate through each flight in the flights vector:
//  Extract source, destination, and cost from the tuple.
//  Call the addFlight method on the graph object with source, destination, and cost as arguments.
//  Call the isConnected method on the graph object.
// 6. Inside the isConnected method:
//  Create a vector visited to track visited cities, initialized to false.
//  Call the dfs method starting from any city (assume city at index 0).
//  Check if all cities are visited.
//  If true, print &quot;The flight network is connected!&quot;
//  If false, print &quot;The flight network is not connected.&quot;
// 7. End of the algorithm.










// Detailed Steps:
// a. Start the main function.
// b. Initialize a vector of cities and an adjacency matrix with all values initialized to zero.
// c. Replace the vector of cities and flights with actual flight data.
// d. Iterate through each flight in the flight data, calling addFlight for each flight.
// e. Check if the flight network is connected using the isConnected function.
// f. Inside the isConnected function:
// g. Create a vector visited to track visited cities, initialized to false.
// h. Call the dfs function starting from any city (assume city at index 0).
// i. Check if all cities are visited.
// j. If true, print &quot;The flight network is connected!&quot;
// k. If false, print &quot;The flight network is not connected.&quot;
// l. End of the algorithm.
