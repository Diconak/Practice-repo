#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main(){

    map<string, int> m;
    string pom;
    while(cin >> pom)
        m[pom]++;
    
    for(auto a : m)
        if(a.second == 2){
            cout << a.first << endl;
            break;
        }

    exit(EXIT_FAILURE);
}