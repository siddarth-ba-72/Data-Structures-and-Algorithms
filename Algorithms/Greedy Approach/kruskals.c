#include <stdio.h>
#include <stdlib.h>

void kruskals(int V, int graph[][V])
{
	int ne = 1;
	int u, v;
	while (ne < V)
	{
		int min = 999;
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (graph[i][j] < min)
				{
					min = graph[i][j];
					u = i;
					v = j;
				}
			}
		}
		graph[u][v] = 999;
		graph[v][u] = 999;
		printf("%d - %d \t%d \n", u, v, min);
		ne++;
	}
}

int main()
{
	int V;
	printf("Enter the number of vertices: ");
	scanf("%d", &V);

	int graph[V][V];
	printf("Enter the Cost Matrix: \n");
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
		{
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 0)
				graph[i][j] = 999;
		}

	kruskals(V, graph);
	return 0;
}