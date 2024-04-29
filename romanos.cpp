#include "romanos.hpp"
#include <unordered_map>

int romano_para_decimal(const std::string& romano) {
    std::unordered_map<char, int> valores = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int decimal = 0;
    int tamanho = romano.size();

    for (int i = 0; i < tamanho; i++) {
        if (valores.find(romano[i]) == valores.end()) {
            return -1; // Caractere inválido
        }

        if (i + 1 < tamanho && valores[romano[i]] < valores[romano[i + 1]]) {
            decimal += valores[romano[i + 1]] - valores[romano[i]];
            i++; // Avança mais um caractere pois já usamos dois
        } else {
            decimal += valores[romano[i]];
        }
    }

    return decimal;
}
