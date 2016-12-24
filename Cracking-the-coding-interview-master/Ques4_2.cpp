/* 4.2 Given a directed graph, design an algorithm to find out whether there is a route
between two nodes.*/

/* solution:The code below provides an iterative implementation of breadth first search*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

const MAX = 100;

using namespace std;

bool isRoute(int a, int b, bool graph[][MAX])
{
	queue <int> que;
	bool visited[MAX];
	memset(visited, false, sizeof(visited));
	que.push(a);
	visited[a] = true;
	int temp;

	while (!que.empty())
	{
		temp = que.front();
		que.pop();
		for (int i=0; i<MAX; i++)
		{
			if (graph[temp][i] && !visited[i])
			{
				if (b==i)
					return true;
				que.push(i);
				visited[i] = true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("4.2.in", "r", stdin);
	int n, m, u, v;
	bool dgraph[MAX][MAX];
	cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		cin >> u >> v;
		dgraph[u][v] = true;
	}
	cout << isRoute(0, 3, dgraph);
}