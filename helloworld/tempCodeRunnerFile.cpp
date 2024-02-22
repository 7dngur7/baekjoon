#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, m, a, b, answernum = 1;
int farr[105][105] = {};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	queue<pair<int, int>> q = {};
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		farr[a][b] = 1;
		farr[b][a]=1;

		q.push({a, b});
	}

	while (!q.empty())
	{
		auto current = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (i != current.second && (farr[current.second][i] > farr[current.first][current.second] + 1 || farr[current.second][i] == 0))
			{
				farr[current.second][i] = farr[current.first][current.second] + 1;
				farr[i][current.second]=farr[current.first][current.second] + 1;
				q.push({current.second, i});
				
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << farr[i][j];
		}
		cout << "\n";
	}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			farr[i][0] += farr[i][j];
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (farr[i][0] < farr[answernum][0])
		{
			answernum = i;
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << farr[i][j];
		}
		cout << "\n";
	}

	cout << answernum;
}
