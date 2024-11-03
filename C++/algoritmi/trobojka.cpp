#include<iostream>
#include<vector>

using namespace std;

void swap(int &a, int &b){
    int pom = a;
    a = b;
    b = pom;
}

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];

    int a, b;
    cin >> a >> b;

    int l = 0, d = n - 1, i = 0;
    while(i < d){
        if(v[i] < a)
            swap(v[l++], v[i++]);

        else if(v[i] <= b)
            i++;
        else
            swap(v[i], v[d--]);

    }

    for(auto a : v)
        cout << a << ' ';
    cout << endl;

    exit(EXIT_FAILURE);
}