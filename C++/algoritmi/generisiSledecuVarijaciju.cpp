#include<iostream>
#include<vector>

using namespace std;

void ispisi(vector<int> &v){
    for(auto a : v){
        cout << a << ' ';
    }
    cout << endl;
}

bool generisiVarijaciju(int n, vector<int> &v){
    int k = v.size(), i = 0;
    for(i = k - 1; i >= 0 && v[i] == n; i--){
        v[i] = 1;
    }
    if(i < 0) 
        return false;

    v[i]++;
    return true;
}

int main(){

    int k, n;
    cin >> k >> n;
    vector<int> v(k);
    if(generisiVarijaciju(n, v))
        ispisi(v);
    else
        cout << '-' << endl;
    

    exit(EXIT_FAILURE);
}