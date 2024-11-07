#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
            cin >> v[i];
    }    

    deque<int> d;
    d.push_back(v[0]);
    for(int i = 1; i < n; i++){
        if(v[i] < d.front())
            d.push_front(v[i]);
        if(v[i] >= d.back())
            d.push_back(v[i]);
    }


    exit(EXIT_FAILURE);
}