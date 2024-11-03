#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int brParovaDatogZbira(int s, int n, vector<int> &v){
    sort(v.begin(), v.end());

    int br = 0;
    for(int i = 0; i < n; i++){
        int x = s - v[i];
        if(binary_search(v.begin() + i + 1, v.end(), x))
            br++;
    }
    return br;
}

int main(){

    int s, n;
    cin >> s >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << brParovaDatogZbira(s, n, v) << endl;
    

    exit(EXIT_FAILURE);
}