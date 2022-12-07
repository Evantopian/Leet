/*
Leet Questioin# 1657
Determine if Two Strings Are Close.
link: https://leetcode.com/problems/determine-if-two-strings-are-close/
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


// Permutation question. 


// Op1: Swap any two existing characters in the string, 
// Op2: Transform all existing chars to another to equal another.

bool closeStrings(string word1, string word2){
    if (word1.length() != word2.length()) return false;
    set<char> unique_chars1;
    set<char> unique_chars2;
    for (int i = 0; i < word1.length(); i++) {
        unique_chars1.insert(word1[i]);
        unique_chars2.insert(word2[i]);
    }

    if (unique_chars1 != unique_chars2) return false;


    auto str_map1 = std::map<char, int>{};
    auto str_map2 = std::map<char, int>{};

    for (char c : word1)
        str_map1[c]++;
    
    for (char c : word2)
        str_map2[c]++;

    // check if len contains its respective len.
    map<int, int> int_cnt;
    vector<int> m1, m2;
    for (auto it = make_pair(str_map1.begin(), str_map2.begin()); it.first != str_map1.end(); ++it.first, ++it.second){
        cout << it.first->first << " " << it.first->second << " | ";
        cout << it.second->first << " " << it.second->second << endl;
        m1.push_back(it.first->second);
        m2.push_back(it.second->second);
    }

    cout << "\nFinalized: ";
    sort(m1.begin(), m1.end());
    sort(m2.begin(), m2.end());
    return m1 == m2 ? 1 : 0;
}




int main(){

    cout << "function call: \n" << closeStrings("aaabbbbccddeeeeefffff", "aaaaabbcccdddeeeeffff");


}


/*



    // how identify cost? map w1 to w2
    cout << word1 << " | " << word2 << endl;

    for (int i = 0; i < word1.length(); i++) {
        for (int j = i; j < word1.length(); j++) {
            if (word2[i] == word1[j]){
                char tmp = word1[i];
                word1[i] = word1[j];
                word1[j] = tmp;
            }
        }
    }
    cout << word1 << " | " << word2 << endl;
    if (word1 == word2) return true;

    // operation2:
    


    return word1 == word2 ? 1 : 0;
    */