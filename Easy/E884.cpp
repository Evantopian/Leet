#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;


vector<string> uncommonFromSentences(string s1, string s2) {

    vector<string> common;
    stringstream strs(s1);
    string words;

    auto map1 = unordered_map<string, int>{};
    auto map2 = unordered_map<string, int>{};

    while (getline(strs, words, ' ')){
        map1[words]++;  
        cout << words;
    }
    strs.str(string());

    strs(s2);
    while (getline(strs, words, ' ')) map2[words]++;
    strs.str(string());


    for (auto &it : map1) 
        if (map1[it.first] == 1 && map2[it.first] == 0) common.push_back(map1[it.first]);

    for (auto &it : map2) 
        if (map2[it.first] == 1 && map1[it.first] == 0) common.push_back(map2[it.first]);


    return common;
}


int main(){
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";

    vector<string> vec = uncommonFromSentences(s1, s2);
    for (auto & it : vec) cout << it << ",";
}