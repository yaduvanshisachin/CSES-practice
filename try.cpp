#include<bits/stdc++.h>
using namespace std;

int main() {

    pair<int,int> arr[3] = {{1,2} ,{2, 3}, {3, 4}};
    
    for(auto &it : arr) {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}