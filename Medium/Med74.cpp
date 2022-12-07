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

    int rows = matrix.size(), cols = matrix[0].size();
    int r = 0, c = cols - 1;
    while (r < rows && c >= 0)
    {
        if (matrix[r][matrix[0].size() - 1] > target &&
            matrix[r][0] < target)
        {
            break;
        }
        if (matrix[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    return binary_search(matrix[r-1].begin(), matrix[r-1].end(), target);
}

int main()
{
    vector<vector<int>> vect{{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
    cout << ((searchMatrix(vect, 4) == 0) ? "False" : "True") << endl;
}