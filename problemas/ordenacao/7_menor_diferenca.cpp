#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Dado um vetor de inteiros não-negativos v, retorne um par de inteiros 
//cuja diferença é a menor possível dentre todas as diferenças possíveis
//entre dois elementos do vetor.
//Exemplo: v = {10, 14, 4, 7}
//menor_diferenca(v) = {4, 7}
//O vetor de entrada não deve ser modificado.
pair<int,int> menor_diferenca(vector<int> &v){
    vector<int> s = v;
    sort(s.begin(), s.end());

    if(s.size() <= 1) return make_pair(-1, -1);

    int menor_diferenca = s[1] - s[0];
    pair<int, int> pares = make_pair(s[0], s[1]);
    for (size_t i = 2; i < s.size(); i++){
        if((s[i] - s[i - 1]) < menor_diferenca){
            menor_diferenca = s[i] - s[i - 1];
            pares.first = s[i - 1];
            pares.second = s[i];
        }
    }

    return pares;
}

int main(){
    vector<int> v = {10, 14, 4, 7};

    pair<int,int> res = menor_diferenca(v);

    cout << res.first << " " << res.second << "\n";

    return EXIT_SUCCESS;
}