#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int solution(string name) {
	int answer = 0;
	int n = name.length();
	int turn = n - 1;

	// 먼저 상하 움직이는 것 카운트
	for (char c : name)
	{
		answer += min(c - 'A', 'Z' + 1 - c);
	}

	for (int i = 0; i < n; i++) {

		int ind = i + 1;
		while (ind < n && name[ind] == 'A') ind++;

		turn = min(turn, i + n - ind + min(i, n - ind));
	}

	answer += turn;
	return answer;
}
