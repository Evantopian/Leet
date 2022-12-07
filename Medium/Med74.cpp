#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

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


vector<vector<int>> gen_sorted_matrix(int n, int m, int min, int seed){
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    random_device rd;
    mt19937 gen(rd());
    
    int max = min;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            uniform_int_distribution<> distr(max, max + seed);            
            max = distr(gen);
            matrix[i][j] = max;
        }
    }
    return matrix;
}

int main()
{
    // use this to paste a vector 
    vector<vector<int>> vect = gen_sorted_matrix(5, 4, 1, 3);
    for (auto it : vect){
        for (auto it2 : it){
            cout << it2 << ", ";
        }
        cout << endl;
    }

    cout << ((searchMatrix(vect, 4) == 0) ? "False" : "True") << endl;
}