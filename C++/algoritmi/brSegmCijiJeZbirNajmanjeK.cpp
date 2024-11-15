/*
Напиши програм који у низу целих бројева (не обавезно позитивних) одређује број сегмената (поднизова узастопних елемената) чији 
је збир мањи или једнак од датог броја K.

Input:
Са стандардног улаза се уноси дужина низа n, а затим у наредном реду n елемената низа 
(целих бројева између -1000 и 1000, раздвојених размацима). Након тога се уноси број K

Output:
На стандардни излаз исписати тражени број сегмената.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int segmNum(vector<int> &ps, int l, int d, vector<int> &pom, int k){
    if(l >= d)
        return 0;
    
    int s = l + (d - l) / 2;

    int levo = segmNum(ps, l, s, pom, k);
    int desno = segmNum(ps, s + 1, d, pom, k);

    int mixed = 0; // predstavlja broj mesovitih parova, to jest onih koji zalaze i u levu i desnu stranu niza
    //Sada treba da napravimo algoritam koji ce spojiti levu i desnu stranu niza u odnosu na desni deo niza.
    int i = l, j = s + 1, num = 0;
    int r = 1;
    while(l <= s || j <= d){
        if(j > d || (i <= s && ps[i] <= ps[j]))
            pom[++num] = ps[i++];
        else{
            while(r <= s && ps[j] - ps[r] <= k){
                r++;
            }
            mixed += r - 1;
            pom[num++] = ps[j++];
        } 
    }

    copy(begin(pom), next(begin(pom), d - l + 1), next(begin(ps), l));

    return levo + desno + mixed;
}

int segmNum(vector<int> &v, int k){
    vector<int> ps(v.size());
    ps[0] = 0;
    partial_sum(v.begin(), v.end(), next(begin(ps)));

    vector<int> pom(v.size());
    return segmNum(ps, 0, ps.size() - 1, ps, k);

}

int main(){

    int n, k;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    cin >> k;
    cout << segmNum(v, k) << endl;
    

    exit(EXIT_SUCCESS);
}