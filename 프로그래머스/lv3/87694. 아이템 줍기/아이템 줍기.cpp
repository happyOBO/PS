#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

const int BOUND = 50 * 50;

set<int> graph[50][50] = {};
int dist[50][50] = {};
pair<int, int> directions[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int bfs(int start, int end, vector<vector<int>>& v_graph)
{
	vector<int> dist= vector<int>(v_graph.size(),-1);
	queue<int> q;
	dist[start] = 0;
	q.push(start);

	int curr;
	while (!q.empty())
	{
		curr = q.front(); q.pop();
		for (int next : v_graph[curr])
		{
			if (dist[next] < 0)
			{
				dist[next] = dist[curr] + 1;
				q.push(next);
			}
		}
	}

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			// printf("%3d ", dist[i * 50 + j]);
			// printf("%3d ", graph[i][j]);
		}
		// cout<< endl;
	}
	return dist[end];
}

bool CheckDuplication(set<int>& s1, set<int>& s2)
{
	int counter = 0;
	if (s1.size() == 0 && s2.size() == 0)
	{
		return false;
	}
	for (int e1 : s1)
	{
		if (s2.find(e1) != s2.end())
		{
			counter++;
		}
	}
	return counter == 1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
	// idx = y * 50 + x
	vector <vector<int>> v_graph(BOUND);


	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			dist[i][j] = -1;
		}
	}

	int rect_idx = 0;
	int lx, ly, rx, ry;
	for (vector<int>& rec : rectangle)
	{
		lx = rec[0] - 1;
		ly = rec[1] - 1;
		rx = rec[2] - 1;
		ry = rec[3] - 1;

		for (int y = ly; y <= ry; y++)
		{
			for (int x = lx; x <= rx; x++)
			{
				graph[y][x].insert(rect_idx);
			}
		}
		rect_idx++;
	}

	for (vector<int>& rec : rectangle)
	{
		lx = rec[0] - 1;
		ly = rec[1] - 1;
		rx = rec[2] - 1;
		ry = rec[3] - 1;


		// 4, 2 ==> 5, 2
		// cout<< "------------------1-------------------" << endl;

		for (int y = ly; y <= ry; y++)
		{
			if (true)
			{
				if (y * 50 + lx < BOUND && (y + 1) * 50 + lx < BOUND && y + 1 <= ry && CheckDuplication(graph[y][lx],graph[y + 1][lx]))
				{
					// cout<< y << ", " << lx << " <==> " << (y + 1) << ", " << lx << endl;
					v_graph[y * 50 + lx].push_back((y + 1) * 50 + lx);
					v_graph[(y + 1) * 50 + lx].push_back(y * 50 + lx);
				}
			}
		}
		// cout<< "------------------2-------------------" << endl;
		for (int y = ly; y <= ry; y++)
		{
			if (true)
			{
				if (y * 50 + rx < BOUND && (y + 1) * 50 + rx < BOUND && y + 1 <= ry && CheckDuplication(graph[y][rx], graph[y + 1][rx]))
				{
					// cout<< y << ", " << rx << " <==> " << (y + 1) << ", " << + rx << endl;
					v_graph[y * 50 + rx].push_back((y + 1) * 50 + rx);
					v_graph[(y + 1) * 50 + rx].push_back(y * 50 + rx);
				}

			}
		}
		// cout<< "------------------3-------------------" << endl;
		for (int x = lx; x <= rx; x++)
		{
			if (true)
			{
				if (ly * 50 + x < BOUND && ly * 50 + (x + 1) < BOUND && x + 1 <= rx && CheckDuplication(graph[ly][x], graph[ly][x + 1]))
				{
					// cout<< ly << ", " <<  x << " <==> " << ly << ", " << (x + 1) << endl;
					v_graph[ly * 50 + x].push_back(ly * 50 + (x + 1));
					v_graph[ly * 50 + (x + 1)].push_back(ly * 50 + x);
				}
			}
		}
		// cout<< "------------------4-------------------" << endl;
		for (int x = lx; x <= rx; x++)
		{
			if (true)
			{
				if (ry * 50 + x < BOUND && ry * 50 + (x + 1) < BOUND && x + 1 <= rx && CheckDuplication(graph[ry][x], graph[ry][x + 1]))
				{
					// cout<< ry << ", " << + x << " <==> " << ry << ", " << (x + 1) << endl;
					v_graph[ry * 50 + x].push_back(ry * 50 + (x + 1));
					v_graph[ry * 50 + (x + 1)].push_back(ry * 50 + x);
				}
			}
		}
	}

	return bfs((characterY - 1) * 50 + characterX - 1 , (itemY - 1) * 50 + itemX - 1, v_graph);
}
