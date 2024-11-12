/*
Напиши програм који одређује све положаје n дама на шаховској табли димензије n×n такве да се никоје две даме међусобно не нападају.
Да се даме не би нападале у свакој врсти мора бити тачно једна дама, при чему никоје две даме нису у истој колони. 
Распоред је зато одређен низом од n различитих бројева од 1 до n који редом представљају бројеве колона у којима се даме налазе у 
врстама од 1 до n. 
Sa ulaza dobijam broj n.
Na izlazu nam se ocekuju sve raspodele dama.
*/

#include<iostream>
#include<vector>

using namespace std;

/*
Da se dame ne bi napadale za njih mora da vazi da:
    -U svakom redu ima tacno jedna dama
    -U svakoj koloni ima samo jedna dama
    -Na svakoj dijagonali ima tacno 1 dama
    -Na tabli ima tacno n dama
*/

void drawBoard(vector<vector<int>> &v, int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(v[i][j] == 1){
                cout << j+1 << ' ';
            }
    
    cout << '\n';
}

bool provera(vector<vector<int>> &v ,int n, int k, int i){
    //proveravamo za kolonu
    for(int j = 0; j < n; j++){
        if(j != k && v[j][i] == 1)
            return false;
    }
    //proveravamo vrstu
    for(int j = 0; j < n; j++){
        if(j != i && v[k][j] == 1)
            return false;
    }
    
    //proveravamo glavna dijagonala
    for(int j = 0; j < n; j++){
        for(int l = 0; l < n; l++){
            if(j != k && l != i && abs(k - i) == abs(l - j))
                return false;
        }
    }

    /*for(int j = 0; j < n; j++){
        for(int l = 0; l < n; l++)
            if(j != k && l != i && abs(k + i) == abs(l + j))
                return false;
    }*/

    return true;
}

void ndama(vector<vector<int>> &v ,int n, int k){
    if(n == k){
        drawBoard(v, n);   
        return;
    }

    for(int i = 0; i < n; i++){
        v[k][i] = 1;
        if(provera(v, n, k, i))
            ndama(v, n, k + 1);
        v[k][i] = 0;
    }
}

int main(){

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(auto row : v)
        for(auto a : row)
            a = 0;
    
    ndama(v, n, 0); 

    exit(EXIT_SUCCESS);
}