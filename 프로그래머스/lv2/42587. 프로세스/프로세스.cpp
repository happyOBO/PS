#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


int solution(vector<int> priorities, int location) {
	map<int, int> p_frequency;
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++)
	{
		if (p_frequency.find(priorities[i]) != p_frequency.end())
		{
			p_frequency[priorities[i]]++;
		}
		else
		{
			p_frequency.insert({ priorities[i], 1 });
		}
		q.push({ priorities[i],i });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>> > pq;
	for (pair<int, int> p_f : p_frequency)
	{
		pq.push(p_f);
	}

	int order = 1;
	pair<int, int> top, curr;
	while (!q.empty())
	{
		curr = q.front();

		top = pq.top();
		q.pop();
		pq.pop();
		if (curr.first < top.first)
		{
			// 다시 넣어준다.
			q.push(curr);
			pq.push(top);
		}
		else
		{
			if (curr.second == location)
				return order;
			order++;
			top.second--;
			if (0 < top.second)
			{
				pq.push(top);
			}
		}
		if (pq.empty())
		{
			break;
		}
	}
	return -1;
}