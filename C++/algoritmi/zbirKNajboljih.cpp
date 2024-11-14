/*
Ученик је радио n задатaкa и за сваки задатак je добио одређени број поена. Одредити збир поена на k задатака које је најбоље урадио.

У првој линији стандардног улаза унети природан број n број задатака које је ученик радио, у другој природан број k број задатака 
које је најбоље урадио, а затим у следећих n линија број поена које је добио на задацима.

Укупан број поена које је освојио на k најбоље оцењених задатака.
 */

//Zadatak se moze resiti soritaranjem, al moze efikasnije podeli pa vladaj

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void kNajboljih(vector<int> &v, int k, int l, int d){
    if(k >= d - l + 1)
        return;

    int m = l; //Pivot
    for(int i = l+1; i <= d; i++)
        if(v[i] >= v[l])
            swap(v[++m], v[i]); //Prebacujemo sve elemente manje od pivota, is swapujemo ih, i pomeramo pivot
    swap(v[m], v[l]);//Prebacujemo pivot na ispravnu poziciju

    if(k <= m - l)
        kNajboljih(v,k, l, m - 1);
    else
        kNajboljih(v,k - (m - l + 1), m + 1, d);

}

int main(){

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    kNajboljih(v, k, 0, n - 1);

    int sum = 0;
    for(int i = 0; i < k; i++)
        sum += v[i];
    cout << sum << '\n';

    exit(EXIT_SUCCESS);
}