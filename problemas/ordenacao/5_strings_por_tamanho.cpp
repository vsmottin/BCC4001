#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//esta função recebe um vetor de strings de diferentes tamanhos
//e retorna um vetor com as mesmas strings, mas ordenadas por tamanho
//O vetor de entrada não deve ser modificado.
vector<string> ordenar_por_tamanho(vector<string> &v){
    vector<string> s = v;

    //selection sort :)
    for (size_t i = 0; i < s.size(); i++){
        int indice_menor = i;
        for (size_t j = i + 1; j < s.size(); j++){
            if(s[j].length() < s[indice_menor].length()) indice_menor = j;
        }
        swap(s[i], s[indice_menor]);
    }

    return s;
}



int main(){
    vector<string> v = {"gato", "macaco", "galinha", "porco", "cachorro", "pato", "vaca", "cavalo", "ovelha"};

    vector<string> res = ordenar_por_tamanho(v);

    for(auto s : res){
        cout << s << "\n";
    }

    return EXIT_SUCCESS;
}

