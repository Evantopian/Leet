#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty())
    {
        return false;
    }

    int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
    int lo = 0, ho = rows;
    while (lo <= ho)
    {
        int mid = lo + (ho - lo) / 2;

        if (matrix[mid][0] == target)
        {
            return true;
        }
        if (matrix[mid][cols] >= target && matrix[mid][0] <= target || rows <= 1)
        {
            return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
        }
        if (matrix[mid][0] > target)
        {
            ho = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return false;
}
int main()
{
    vector<vector<int>> vect{{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
    cout << ((searchMatrix(vect, 4) == 0) ? "False" : "True") << endl;
}