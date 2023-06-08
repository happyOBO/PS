#include <bits/stdc++.h>
#include <climits>

using namespace std;
bool IsRangeIn(pair<int, int>& pos, int M, int N);

pair<int, int> Directions[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int bfs(pair<int,int> start, vector<vector<bool>>& graph)
{
	
	queue<pair<int,int>> q;
	q.push(start);
	graph[start.first][start.second] = true;

	int M, N;
	M = graph.size();
	N = graph[0].size();

	pair<int, int> curr, next;
	int area = 1;
	while (!q.empty())
	{
		curr = q.front();
		q.pop();

		for (pair<int,int>& dir : Directions)
		{
			next = { curr.first + dir.first , curr.second + dir.second };
			if (IsRangeIn(next, M, N) && !graph[next.first][next.second])
			{
				graph[next.first][next.second] = true;
				q.push(next);
				++area;
			}
		}
	}

	return area;
}

bool IsRangeIn(pair<int, int>& pos, int M , int N)
{
	if (pos.first < 0 || M <= pos.first)
	{
		return false;
	}

	if (pos.second < 0 || N <= pos.second)
	{
		return false;
	}

	return true;
}

int main() {

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<bool>> graph (N,vector<bool>(M, false));

	int lx, ly, rx, ry;
	for (int i = 0; i < K; ++i)
	{
		cin >> lx >> ly >> rx >> ry;
		for (int y = ly; y < ry; ++y)
		{
			for (int x = lx; x < rx; ++x)
			{
				graph[y][x] = true;
			}
		}
	}

	int count = 0, area;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (!graph[y][x])
			{
				++count;
				area = bfs({y, x}, graph);
				pq.push(area);
			}
		}
	}

	cout << count << "\n";
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}

