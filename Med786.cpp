#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<int> &v)
{
    for (int i = 0, j = i + 1; j < v.size(); i += 2, j = i + 1)
    {
        cout << "(" << v[i] << ", " << v[j] << "), ";
    }
    if (v.size() % 2 != 0)
        cout << "(" << v[v.size() - 1] << "), ";
    cout << endl;
}

// intutive approach:
// convert the vector into fractions
// sort the new vector
vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    // base cases
    if (arr.size() < 2)
        return {};
    if (arr.size() == 2)
        return arr;

    vector<string> frac_vec;

    // set fracs:
    //  n > d

    // (n*(n+1))/2  -> O(n^2)
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = arr.size() - 1; j != i; j--)
        {
            frac_vec.push_back(arr[i] + "/" + arr[j]);
        }
    }

    for (int i = 0; i < frac_vec.size() - 1; i++)
    {
        for (int j = 0; j < frac_vec.size() - 1)
    }

    // bubble sort

    cout << "fsize: " << frac_vec.size();
    print_vector(frac_vec);

    return {};
}

int main()
{

    vector<int> prime_vec{1, 2, 3, 5};
    print_vector(prime_vec);
    kthSmallestPrimeFraction(prime_vec, 7);
}