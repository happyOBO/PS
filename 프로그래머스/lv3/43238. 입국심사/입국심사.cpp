#include <string>
#include <vector>
#include <limits.h>

using namespace std;


long long solution(int n, vector<int> times);
bool canJudgeN(long long targetTimes, int n, vector<int>& times);


long long solution(int n, vector<int> times) {
    int minTime = INT_MAX;
    int maxTime = INT_MIN;
    long long answer = LONG_MAX;
    for (auto it = times.begin(); it != times.end(); it++)
    {
        minTime = min(minTime, (*it));
        maxTime = max(maxTime, (*it));
    }

    long long minTotalTime = static_cast<long long>(minTime) * static_cast<long long>(n / times.size());
    long long maxTotalTime = static_cast<long long>(maxTime) * max(static_cast<int>(n / times.size()), 1);
    long long midTotalTime = (minTotalTime + maxTotalTime) / 2;

    while (minTotalTime <= maxTotalTime)
    {
        if (canJudgeN(midTotalTime, n, times))
        {
            maxTotalTime = midTotalTime - 1;
            answer = min(answer, midTotalTime);
        }
        else
            minTotalTime = midTotalTime + 1;
        midTotalTime = (minTotalTime + maxTotalTime) / 2;

    }
    return answer;
}

bool canJudgeN(long long targetTimes, int n, vector<int>& times)
{
    long long count = 0;
    for (auto it = times.begin(); it != times.end(); it++)
        count += (targetTimes / static_cast<long long>(*it));
    return n <= count;
}