#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int solution(vector<vector<int>> routes)
{
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> q;

	for (vector<int>& route : routes)
	{
		q.push({ route[0], route[1] });
	}

	int answer = 1;
	int camera = q.top().second; q.pop();
	pair<int, int> next;
	while (!q.empty())
	{
		next = q.top(); q.pop();
		if (camera < next.first)
		{
			answer++;
			camera = next.second;
		}
		// 겹치는 경우 현재 카메라 위치를 그대로 유지
	}

	return answer;
}
