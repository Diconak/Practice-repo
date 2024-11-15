/*
Постоје три уобичајена редоследа обилажења чворова бинарног стабла:
    -КЛД (префиксни) - најпре корен, па лево подстабло, па десно подстабло
    -ЛКД (инфиксни) - најпре лево подстабло, па корен, па десно подстабло
    -ЛДК (постфиксни) - најпре лево подстабло, па десно подстабло, па корен
У сваком од обилазака се подразумева да се редослед обиласка подстабла наслеђује, тј. да се користи исто правило као за цело стабло.
Нека је сваки чвор стабла означен различитим малим словом енглеског алфабета. На тај начин се сваким од поменутих обилазака добија
по једна ниска. Напиши прогам који учитава ниске које одговарају обиласцима КЛД и ЛКД, а исписује ниску која одговара обиласку ЛДК.

Ulaz:
Са стандардног улаза се учитавају две ниске, свака у посебном реду. Ниске одговарају обиласцима КЛД и ЛКД, а састоје се од 
различитих малих слова енглеског алфабета (и немају више од по 26 слова).

Izlaz:
На стандардни излаз исписати ниску која одговара обиласку ЛДК.



*/

#include<iostream>
#include<vector>

using namespace std;

void ldk(int pozkld, int pozlkd, int n, string kld, string lkd){
    if(n == 0)
        return;
    
    char root = kld[pozkld]; // Posto ovde imamo koren mozemo da odredimo koji je.
    int posroot = lkd.find(root); // ovde mozemo da odredimo poziciju korena u odnosu na levo stablo
    int n_levo = posroot - pozlkd; //velicina levog podstabla
    int n_desno = n - n_levo - 1; //velicina desnog podstabla

    ldk(pozkld + 1, pozlkd, n_levo, kld, lkd);
    ldk(pozkld + n_levo + 1, posroot + 1, n_desno, kld, lkd);

    cout << root;
}

int main(){

    string kld, lkd;
    cin >> kld >> lkd;
    ldk(0, 0, kld.size(), kld, lkd);
    

    exit(EXIT_SUCCESS);
}