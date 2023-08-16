#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

string solution(string number, int k)
{
	string answer = "";
	// 0 ~ number.size() - 1 - k 까지만 탐색
	// 8888912 , k = 4 일 때 9가 맨 앞자리로 오면 9123 밖에 안되므로 올 수가 없음
	// 7 : 4 
	// 0) 7, 4 // 0 ~ 3
	// 1) 6, 3 // 0 ~ 3
	
	int search_size = number.size() - k;

	int start_idx = 0;
	for (int i = 0; i < search_size; i++)
	{
		char max_num = number[start_idx];
		int max_num_idx = start_idx;

		for (int j = start_idx; j <= k + i; j++)
		{
			if (max_num < number[j])
			{
				max_num = number[j];
				max_num_idx = j;
			}
		}

		start_idx = max_num_idx + 1;
		answer += max_num;
	}

	return answer;
}
