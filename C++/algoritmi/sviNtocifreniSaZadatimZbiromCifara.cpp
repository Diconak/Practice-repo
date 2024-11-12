/*
Написати програм који исписује све n-тоцифрене бројеве који имају дати збир цифара.

Прва линија садржи збир k, а друга број цифара n

На стандардни излаз исписати све тражене бројеве, уређене по величини.

*/

#include<iostream>
#include<vector>

using namespace std;

void ispisi(vector<int> &v){
    for(auto a : v)
        cout << a;
    cout << '\n';
}

void trazeneKombinacije(int k, vector<int> &v, int num){
   if(num == v.size()){
        ispisi(v);
   }else{
         int preostaloCifara = v.size() - num;
        int maksZbirIza = 9 * (preostaloCifara - 1);
        int minC = max(num == 0 ? 1 : 0, k - maksZbirIza);
        int maksC = min(9, k);
        for (int c = minC; c <= maksC; c++) {
            v[num] = c;
             trazeneKombinacije(k-c, v, num+1);
        }
   }
}

int main(){

    int k, n;
    cin >> k >> n;
    vector<int> v(n);

    trazeneKombinacije(k, v, 0);

    exit(EXIT_SUCCESS);
}