#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int minKey(int key[], bool mstSet[], int V)
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
	{
		if (mstSet[v] == false && key[v] < min)
		{
			min = key[v];
			min_index = v;
		}
	}
	return min_index;
}

void printMST(int parent[], int V, int graph[][V])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
	{
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
	}
	int sum = 0;
	for (int i = 1; i < V; i++)
	{
		sum += graph[i][parent[i]];
	}
	printf("\nMinimum Cost = %d\n", sum);
}

void prims(int V, int graph[][V])
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey(key, mstSet, V);
		mstSet[u] = true;
		for (int v = 0; v < V; v++)
		{
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
	printMST(parent, V, graph);
}

int main()
{
	int V;
	printf("Enter the number of vertices: ");
	scanf("%d", &V);

	int graph[V][V];
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			printf("Enter the weight of edge %d - %d: ", i, j);
			scanf("%d", &graph[i][j]);
		}
	}

	prims(V, graph);
	return 0;
}
