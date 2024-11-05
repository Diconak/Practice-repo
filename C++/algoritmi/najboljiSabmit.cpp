#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n;
    cin >> n;
    int max = -5, submit;
    for(int i = 0; i < n; i++){
        cin >> submit;
        max = submit > max ? submit : max;
        cout << max << ":max\n";
    }

    exit(EXIT_FAILURE);
}