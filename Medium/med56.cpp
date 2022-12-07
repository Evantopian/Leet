#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    for (auto i = 0; i < intervals.size() - 1; i++)
    {
        if (intervals[i][1] >= intervals[i + 1][0])
        {

            if (intervals[i][1] < intervals[i + 1][1])
            {
                intervals[i][1] = intervals[i + 1][1];
            }
            i--;
        }

        res.push_back(vector<int>(intervals[i][0], intervals[i][1]));
    }
    return res;
}

int main()
{

    vector<vector<int>> vec = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    sort(vec.begin(), vec.end());

    for (auto it : merge(vec))
    {
        cout << it[0] << ", " << it[1] << endl;
    }
}