/*
Дат је скуп од n предмета, за сваки предмет позната је његова вредност (реалан број). Предмете треба да поделе два брата тако 
да се укупнa вредност предмета које појединачно браћа добијају минимално разликују. При подели предмета сваки брат добија целе
предмете и сваки предмет после поделе припада неком брату. Написати програм којим се одређује минимална разлика вредности коју
браћа добијају при братској подели.
Прва линија стандардног улаза садржи природан број n. Следећих nлинија садрже реалне бројеве, сваки у посебној линији
, који представљају вредности предмета.
На стандардном излазу приказати у једној линији минималну разлику вредности добијену при братској подели,
разлику приказати на две децимале.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

float bratskaPodela(vector<int> &v,float prvi, float drugi, int i){
    if(i == v.size())
        return abs(prvi - drugi);

    double raz1 = bratskaPodela(v, prvi + v[i], drugi, i+1);
    double raz2 = bratskaPodela(v, prvi, drugi + v[i], i+1);
    
    return min(raz1, raz2);
}

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    cout << bratskaPodela(v, 0,0,0) << endl;

    exit(EXIT_FAILURE);
}