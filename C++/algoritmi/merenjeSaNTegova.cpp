/*
Дато је n тегова, за сваки тег позната је његова маса. Датим теговима треба измерити масу S, tако да се укупна маса изабраних 
тегова најмање разликује од S. Написати програм којим се одређује минимална разлика при таквом мерењу.

Прва линија стандардног улаза садржи природан број n. Следећих n линија садрже реалне бројеве, сваки у посебној линији
, који представљају масе датих тегова. Последња линија стандардног улаза садржи реалан број S који представља масу коју меримо.

На стандардном излазу приказати у једној линији минималну разлику добијену при мерењу, разлику приказати на две децимале.
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

double tegovi(vector<double> &v, double sum ,int i, int S){
    if(v.size() == i)
        return abs(sum - S);

    double min1 = tegovi(v, sum + v[i], i + 1, S);
    double min2 = tegovi(v, sum, i + 1, S);
    return min(min1, min2);
}

int main(){

    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    double S;
    cin >> S;
    
    cout << tegovi(v, 0, 0, S) << endl;
    exit(EXIT_FAILURE);
}