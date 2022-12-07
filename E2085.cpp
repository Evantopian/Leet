#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countWords(vector<string>& words1, vector<string>& words2) {


    auto map1 = unordered_map<string, int>{};
    auto map2 = unordered_map<string, int>{};

    for (auto &it : words1) map1[it]++;
    for (auto &it : words2) map2[it]++;

    int count = 0;
    for (auto &it : map1){
        if (map1[it.first] == 1 && map2[it.first] == 1) count++;
    }

    return count;
}



int main(){

    vector<string> w1{"a","ab"};
    vector<string> w2{"a","a","a","ab"};

    cout << countWords(w1, w2);
}