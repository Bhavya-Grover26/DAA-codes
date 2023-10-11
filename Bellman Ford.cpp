#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge
{
    int src, dest, weight;
};

bool BellmanFord(const vector<Edge>& edges, int V, int src, vector<int>& dist)
{
 int E = edges.size();
 dist.assign(V, INT_MAX);
 dist[src] = 0;
 for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            dist[v] = dist[u] + weight;
        }
    }
 // Check for negative-weight cycles
 for (int i = 0; i < E; i++)
 {
    int u = edges[i].src;
    int v = edges[i].dest;
    int weight = edges[i].weight;
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        return false; // Negative cycle found
 }
 return true;
}

int main()
{
 int V, E;
 cout << "Enter number of vertices: ";
 cin >> V;
 cout << "Enter number of edges: ";
 cin >> E;
 vector<Edge> edges(E);
 for (int i = 0; i < E; i++)
    {
        cout << "Enter source, destination and weight for edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
 int source;
 cout << "Enter the source vertex: ";
 cin >> source;
 vector<int> distances;
 if (BellmanFord(edges, V, source, distances))
 {
    cout << "Distances from source vertex " << source << " are:\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }
 }
 else
 {
    cout << "Graph contains a negative-weight cycle.\n";
 }
 return 0;
}
