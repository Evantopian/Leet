#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

string kthDistinct(vector<string>& arr, int k) {
    auto str_map = unordered_map<string, int>{};
    

    //for (auto &it : arr) str_map[it]++;

    for (int i = 0; i < arr.size(); i++){
        str_map[arr[i]]++;

        if (str_map[arr[i]] > 1){
            arr.erase(arr.begin()+i);
            i--;
        }




    }


    //for (auto it : arr) cout << it << endl;

    if (arr.size() < k) return "";

    return arr[k-1];
}



int main(){
    vector<string> vec{"d","b","c","b","c","a"};
    cout << kthDistinct(vec, 2) << endl;
}