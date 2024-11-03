#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    int max = 0, x;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> x;
        m[x] += 1;
        if(m[x] > 1 && x > max)
            max = x;
    }

    cout << max << '\n';


    exit(EXIT_FAILURE);
}