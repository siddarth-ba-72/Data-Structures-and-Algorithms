#include <bits/stdc++.h>
using namespace std;

int main()
{
	queue<int> q;

	int n;
	cout << "n = ";
	cin >> n;

	int graph[n][n];
	cout << "Enter cost matrix: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	int visited[n];
	for (int i = 0; i < n; i++)
		visited[i] = 0;

	int i = 0;
	q.push(i);
	visited[i] = 1;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int j = 0; j < n; j++)
		{
			if (graph[node][j] && visited[j] == 0)
			{
				cout << " " << j << " ";
				q.push(j);
				visited[j] = 1;
			}
		}
	}

	return 0;
}
