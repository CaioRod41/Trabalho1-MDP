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
            i++; 
        } else {
            decimal += valores[romano[i]];
        }
    }

    for (int i = 0; i < tamanho - 1; i++) {
        if (romano[i] == romano[i + 1] && (romano[i] == 'V' || romano[i] == 'L' || romano[i] == 'D')) {
            return -1; 
        }
           if (i + 3 < tamanho && romano[i] == romano[i + 1] && romano[i] == romano[i + 2] && romano[i] == romano[i + 3]) {
            return -1; // Mais de 3 caracteres repetidos consecutivamente
        }
    }

    return decimal;
}
