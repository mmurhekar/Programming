// Arrival and departure Time of a vertex in BFS, DFS and Topological Sort.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct node_t {
	int v;
	struct node_t* next;
	node_t(int v)
	{
		this->v = v;
		this->next = NULL;
	}
} node_t;

node_t* graph[100];
int indegree[100];

void add_edge(node_t* graph[], int u, int v)
{
	node_t* n1, *curr;
	n1 = new node_t(v);

	curr = graph[u];
	while (curr && curr->next != NULL)
		curr = curr->next;

	if (curr)
		curr->next = n1;
	else
		graph[u] = n1;
}

void DFS(node_t* graph[], int v, vector<bool> &visited, vector<int> &arival, vector<int> &departure, int &time)
{
	arival[v] = ++time;

	visited[v] = true;

	node_t* curr = graph[v];
	while ( curr != NULL )
	{
		if (!visited[curr->v])
			DFS(graph, curr->v, visited, arival, departure, time);

		curr = curr->next;
	}

	departure[v] = ++time;
}

void topologicalSort(node_t* graph[], int v, vector<bool>& visited, vector<int>& departure, int& time)
{
	visited[v] = true;

	time++; // Arival Time

	node_t* curr = graph[v];
	while (curr != NULL)
	{
		// Visit if not visited
		if (!visited[curr->v])
			topologicalSort(graph, curr->v, visited, departure, time);

		curr = curr->next;
	}

	// Set departure time of vertex V
	departure[time] = v;
	time++;
}

void bfs(node_t* graph[], int ind[])
{
	node_t* curr;
	bool visited[100];

	for (int i = 0; i < 6; i++)
		visited[i] = false;

	queue<int> q;

	for (int i = 0; i < 6; i++)
	{
		node_t* node;
		if (ind[i] == 0)
		{
			node = graph[i];
			q.push(i);
		}
	}
	
	while (!q.empty())
	{
		int idx = q.front();
		q.pop();

		cout << idx << " ";

		curr = graph[idx];
		while (curr)
		{
			if (--ind[curr->v] == 0)
			{
				q.push(curr->v);
			}
			curr = curr->next;
		}
	}
}

void KahnsAlgo_topologicalSort(node_t* graph[], int ind[])
{
	node_t* curr;

	// Calculate indgree of each vertex.
	for (int i = 0; i < 6; i++)
	{
		curr = graph[i];
		while (curr != NULL) {
			ind[curr->v]++; // Indegree of vertex V
			curr = curr->next;
		}
	}

	bfs(graph, ind);
}

int main()
{
	int N = 8;

	vector<int> arival(N);
	vector<int> departure(N);
	vector<int> dep(36);
	vector<bool> visited(N);

	int time = -1;

	//add_edge(graph, 0, 1);
	//add_edge(graph, 0, 2);
	//add_edge(graph, 2, 3);
	//add_edge(graph, 2, 4);
	//add_edge(graph, 3, 1);
	//add_edge(graph, 3, 5);
	//add_edge(graph, 4, 5);
	//add_edge(graph, 6, 7);

	add_edge(graph, 5, 2);
	add_edge(graph, 5, 0);
	add_edge(graph, 4, 0);
	add_edge(graph, 4, 1);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 1);


	for (int i = 0; i < 6; i++) {
		visited[i] = false;
		arival[i] = 0;
		departure[i] = 0;
	}

	for (int i = 0; i < 6; i++)
	{
		if (!visited[i]) {
			DFS(graph, i, visited, arival, departure, time);
		}
	}

	for (int i = 0; i < 6; i++)
	{
		cout << "Vertex " << i << " (" << arival[i] << ", " << departure[i] << ")" << endl;
	}

	for (int i = 0; i < 6; i++) {
		visited[i] = false;
		arival[i] = 0;
	}

	for (int i = 0; i < 36; i++)
		dep[i] = -1;

	time = -1;
	for (int i = 0; i < 6; i++)
	{
		topologicalSort(graph, i, visited, dep, time);
	}

	for (int i = 35; i >= 0; i--)
	{
		if (dep[i] != -1)
			cout << dep[i] << " ";
	}

	cout << endl;

	KahnsAlgo_topologicalSort(graph, indegree);

	return 0;
}