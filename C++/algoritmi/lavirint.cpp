#include<iostream>
#include<vector>
#include<utility>

using namespace std;

vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

bool lavirint(int m, int n, vector<vector<int>> &matrix, int i, int j){
    if(matrix[i][j] == 'x')
        return false;
    
    if(i == m - 1 && j == n - 1)
        return true;
    
    bool k;
    for(auto a : moves)
    {
        int i1 = i + a.first;
        int j1 = j + a.second;
        matrix[i][j] = 'x';
        if(i1 <= m - 1 && j1 <= n - 1 && i1 >= 0 && j1 >= 0 )
            k = lavirint(m, n, matrix, i1, j1);
            if(k == true)
                return true; 
    }
    return k;
}

int main(){

    int n,m;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    
    if(lavirint(m,n,matrix, 0, 0))
        cout << "da" << endl;
    else 
        cout << "ne" << endl;

    exit(EXIT_FAILURE);
}