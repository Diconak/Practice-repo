#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n, m;
    cin >> m;
    vector<int> niz1(m);
    for(int i = 0; i < m; i++)
        cin >> niz1[i];
    
    cin >> n; 
    vector<int> niz2(n);
    for(int i = 0; i < n; i++)
        cin >> niz2[i];

    vector<int> v;

    int i = 0, j = 0;
    while(1){
        if(i != m && j != n){
            if(niz1[i] > niz2[j]){
                v.push_back(niz2[j]);
                j++;
            }
            else{
                v.push_back(niz1[i]);
                i++;
            }
        }
        else if(i == m && j != n){
            v.push_back(niz2[j]);
            j++;
        }
        else if(i != m && j == n){
            v.push_back(niz1[i]);
            i++;
        }
        else{
            break;
        }
    }

    for(auto a : v)
        cout << a << ' ';
    cout << endl;

    exit(EXIT_FAILURE);
}