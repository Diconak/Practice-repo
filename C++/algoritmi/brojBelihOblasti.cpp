#include<iostream>
#include<vector>

using namespace std;

void numOfWhiteSpaces(int n, int m, vector<vector<int>> &matrix, int i, int j){
    matrix[i][j] = -1;
    if(i < n - 1 && matrix[i+1][j] == 0)
        numOfWhiteSpaces(n, m, matrix, i + 1, j);
    if(i > 0 && matrix[i - 1][j] == 0)
        numOfWhiteSpaces(n, m, matrix, i - 1, j);
    if(j < m - 1 && matrix[i][j + 1] == 0)
        numOfWhiteSpaces(n, m, matrix, i, j + 1);
    if(j > 0 && matrix[i][j - 1] == 0)
        numOfWhiteSpaces(n, m, matrix, i, j - 1);
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];

    
    int counter = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j] == 0){
                numOfWhiteSpaces(n,m,matrix,i,j);
                counter++;
            }


    cout << counter << endl;

    exit(EXIT_FAILURE);
}