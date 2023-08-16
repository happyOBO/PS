#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

string solution(string number, int k)
{
	list<char> li;
	for (char c : number)
	{
		li.push_back(c);
	}

	for (int i = 0; i < k; i++)
	{
		list<char>::iterator prev_it = li.begin();
		for (list<char>::iterator it = li.begin(); it != li.end(); ++it)
		{
			if (it == li.begin()) continue;
			else
			{
				if (*it > *prev_it)
				{
					li.erase(prev_it);
					break;
				}
				prev_it = it;
			}
		}
	}

	string answer = "";
	while (!li.empty())
	{
		answer += li.front();  li.pop_front();
	}
	
	return answer;
}