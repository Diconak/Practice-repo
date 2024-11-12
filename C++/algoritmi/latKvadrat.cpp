#include<iostream>
#include<vector>

using namespace std;

/*
123
231
312

123
312
231
*/

bool provera(vector<vector<int>> &mat, int i, int j, int n){
    for(int k = 0; k < n; k++)
        if(k != j && mat[i][k] == mat[i][j]);
            return true;
    for(int k = 0; k < n; k++)
        if(k != i && mat[k][j] != mat[i][j])
            return true;
    return false;
}

void latkv(vector<vector<int>> &mat, int n, int k){
    	int i = k / n, j = k % n;
        if(mat[i][j] != 0){
            if(k == n * n - 1){
                for(int g = 0; g < n; g++){
                    for(int h = 0; h < n; h++)
                        cout << mat[g][h];
                    cout << '\n';
                }
                cout << '\n';
            }
            else{
                latkv(mat, n, k + 1);
            }
        }
        else{
            for(int g = 1; g <= n; g++){
                mat[i][j] = g;
                if(!provera(mat, i, j, n)){
                    latkv(mat, n, k);
                }
            }
            mat[i][j] = 0;
        }

}

int main(){

    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    
    latkv(mat, n, 0);

    exit(EXIT_FAILURE);
}