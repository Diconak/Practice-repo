/*
Напиши програм који одређује колико у низу има инверзија (позиција 0 ≤ i < j < n, таквих да је ai > aj).

Ulaz:
    Sa standardnog ulaza se unosi broj n, a zatim se unosi n celih brojeva, svaki u posebnom redu.

Izlaz:
    Na standardni izlaz ispisati trazeni broj inverzija
*/

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


//Ideja je da se napravi modifikovani Mergesort, modifikacija je u tome sto u procesu spajanja dodajemo i racunanje
//inverza gde je jedan u levoj polovini, a drugi u drugoj
int brojInverzija(vector<int> &a, int l, int d, vector<int> &tmp){
    if(l >= d)
        return 0;
    
    int s = l + (d - l) / 2;

    int left = brojInverzija(a, l, s, tmp);
    int right = brojInverzija(a, s + 1, d, tmp);
    
    int pl = l, pd = s+1, pb = 0, mixed = 0;
    //Prolazimo kroz petlju dok se jedna polovina ne isprazni
    while(pl <= s && pd <= d){
        if(a[pl] <= a[pd]) // Ako je levi pokazivac manji od desnog, dodaje se u pomocni niz, i oba pokazivaca se pomeraju
            tmp[++pb] = a[++pl];
        else{ // Inace se dodaje desni pokazivac u pomocni niz, ali se na ukupan broj srednjih inverza, dodaju svi brojevi posle njega
            mixed = s - pl + 1;
            tmp[pb++] = a[pd++];
        }
    }
    
    while(pl <= s)
        tmp[pb++] = tmp[pl++]; 
    while(pd <= d)
        tmp[pb++] = tmp[pd++];
    
    //kopira se pomocni niz u glavni niz
    copy(begin(tmp), next(begin(tmp), d - l + 1), next(begin(a), l));
    return left + mixed + right;
}

int brojInverzija(vector<int> &v, int n){
    vector<int> p1(n), p2(n);
    copy(v.begin(), v.end(), p1);
    return brojInverzija(p1, 0, n - 1, p2);
}

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    cout << brojInverzija(v, n) << '\n';

    exit(EXIT_SUCCESS);
}