#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "utils.h"

#include <algorithm>

#define DEBUG 1

// retorna o k-ésimo maior elemento do vetor.
// Os elementos de v podem ser permutados durante a execução.
// pré-condição: o vetor não possui elementos repetidos
// k=1 retorna o maior elemento
// k=2 retorna o segundo maior elemento
// k=....
// k=n retorna o menor elemento
using namespace std;

int k_maior(std::vector<int> &v, int k){
    if(v.size() < k || k <= 0) return -1;
    
    sort(v.begin(), v.end());

    return v[v.size() - k];
}

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    auto v = gerar_vetor_aleatorio_sem_reps(n, 42);

    int res = k_maior(v, k);

    #if DEBUG
    imprimir_vetor(v.data(), n);
    #endif

    #if DEBUG
    std::cout << "O " << k << "-ésimo maior elemento do vetor é o " << res << "!\n";
    #endif    

    return EXIT_SUCCESS;
}