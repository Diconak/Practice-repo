#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){

    map<string, int> m;
    map<int, int> br_pojavljivanja;
    int k,n,x;
    cin >> n >> k;

    string s;
    br_pojavljivanja[0] = k;
    for(int i = 0; i < k; i++){
        cin >> s >> x;
        if(s == "upit"){
            cout << br_pojavljivanja[x] << endl;
        }
        else{
            br_pojavljivanja[m[s]]--;
            m[s] += x;
            br_pojavljivanja[m[s]]++;
        }
    
    }

    exit(EXIT_FAILURE);
}