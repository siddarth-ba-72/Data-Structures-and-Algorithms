#include <stdio.h>
#include <stdlib.h>

void dfs(int i, int n, int graph[n][n], int visited[n])
{
	visited[i] = 1;
	printf("%d ", i);
	for (int j = 0; j < n; j++)
	{
		if (graph[i][j] && visited[j] == 0)
		{
			dfs(j, n, graph, visited);
		}
	}
}

int main()
{
	int n;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);

	int graph[n][n];
	printf("Enter the cost matrix: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}

	int visited[n];
	for (int i = 0; i < n; i++)
		visited[i] = 0;

	dfs(0, n, graph, visited);
}
