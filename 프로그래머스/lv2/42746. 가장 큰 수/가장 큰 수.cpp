#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> v;

	for (int& num : numbers)
	{
		v.push_back(to_string(num));
	}

	sort(v.begin(), v.end(),
		[](string a, string b)
		{
			int min_len = min(a.size(), b.size());
			int max_len = max(a.size(), b.size());

			if (min_len == max_len)
			{
				return a > b;
			}

			else
			{
				for (int i = 0; i < min_len; i++)
				{
					if (a[i] != b[i])
						return a[i] > b[i];
				}

				// 123 , 12345 와 같이 숫자가 앞에서부터 포함 관계인 경우
				if (a.size() < b.size())
				{
					for (int i = min_len; i < max_len; i++)
					{
						if (a[0] != b[i])
							return a[0] > b[i];
					}
				}
				else
				{
					for (int i = min_len; i < max_len; i++)
					{
						if (a[i] != b[0])
							return a[i] > b[0];
					}
				}
			}

			return true;
		});

	for(string& num : v)
	{
		answer += num;
	}
	return answer;
}
