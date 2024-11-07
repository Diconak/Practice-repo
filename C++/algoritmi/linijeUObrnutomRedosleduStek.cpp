#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){

    string line;
    stack<string> s;
    while(cin >> line){
        s.push(line);
    }    

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    exit(EXIT_FAILURE);
}