#include <iostream>
#include <vector>
#include <map>
using namespace std;



struct node
{
    int a;
    node* b;

    node() : a(0), b(nullptr) {}
};

int main(){

    vector<int> n{1,2,3,4,5,6,7,8};

    for (auto it = n.begin(); it != n.end(); ++it) {

        if (*it%2 == 0) *it = 0;
        cout << *it << endl;
    }

    cout << "\n\n";

    for (int i = 0; i < n.size(); ++i) {  
        if (n[i]%2 != 0) n[i] = 1;
        cout << n[i] << endl;
    }

}