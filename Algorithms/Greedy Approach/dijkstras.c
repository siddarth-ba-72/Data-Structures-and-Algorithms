#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int minDistance(int dist[], bool sptSet[], int V)
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
	{
		if (sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void printMST(int dist[], int V, int graph[][V])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
	{
		printf("%d \t\t %d \n", i, dist[i]);
	}
	int sum = 0;
	for (int i = 1; i < V; i++)
	{
		sum += graph[i][dist[i]];
	}
	printf("\nMinimum Cost = %d\n", sum);
}

void dijkstra(int V, int graph[][V], int src)
{
	int dist[V];
	bool sptSet[V];

	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;

	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, sptSet, V);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
		{
			if (!sptSet[u])
			{
				if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				{
					dist[v] = dist[u] + graph[u][v];
				}
			}
		}
	}
	printMST(dist, V, graph);
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

	int src;
	printf("Enter the source vertex: ");
	scanf("%d", &src);

	dijkstra(V, graph, src);
	return 0;
}
