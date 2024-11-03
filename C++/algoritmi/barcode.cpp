#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int bc;
    int num = 0;
    while(cin >> bc){
        if(binary_search(v.begin(), v.end(), bc))
            num++;    
    }
    cout << num;

    exit(EXIT_FAILURE);
}