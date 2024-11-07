#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){

    queue<string> red;
    int k;
    cin >> k;

    string s;
    while(cin >> s){
        red.push(s);
    }

    int n = red.size() - k;
    for(int i = 0; i < n; i++){
        red.pop();
    }

    while(!red.empty()){
        cout << red.front() << endl;
        red.pop();
    }

    exit(EXIT_FAILURE);
}