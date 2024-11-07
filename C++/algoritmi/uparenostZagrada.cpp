#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){

    stack<char> s;
    string izraz;
    cin >> izraz;

    for(char a : izraz){
        if(a == '(' || a == '[' || a == '{')
            s.push(a);
        
        if(a == ')' && s.top() == '(')
            s.pop();
        if(a == ']' && s.top() == '[')
            s.pop();
        if(a == '}' && s.top() == '{')
            s.pop();
    }

    if(s.empty())
        cout << "da" << endl;
    else
        cout << "ne" << endl;

    exit(EXIT_FAILURE);
}