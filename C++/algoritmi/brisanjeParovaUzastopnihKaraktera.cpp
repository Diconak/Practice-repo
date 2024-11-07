#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){

    stack<char> s;
    string val;
    cin >> val;
    for(auto a : val){
        if(!s.empty() && s.top() == a)
            s.pop();
        else
            s.push(a);
    }
    
    val = "";
    while(!s.empty()){
        val = s.top() + val;
        s.pop();
    }

    cout << val << endl;

    exit(EXIT_FAILURE);
}