#include <cassert>
#include <limits>

// Funções externas Corrigidas (com um sublinhado)
extern int _ESBMC_nondet_int();
extern bool _ESBMC_nondet_bool();

void verificacao_de_overflow() {
    int x = _ESBMC_nondet_int();
    int y = _ESBMC_nondet_int();
    int resultado_soma = x + y;
}

void preenche_array() {
    int meu_array[5];
    int indice = _ESBMC_nondet_int();
    meu_array[indice] = 123;
}

int divisao_arriscada() {
    int b = _ESBMC_nondet_int();
    
    // LINHA CORRIGIDA: __ESBMC_assume precisa de dois sublinhados
    __ESBMC_assume(b >= 0 && b <= 1);
    
    int divisor = b == 0 ? 0 : 1;

    int resultado_divisao = 100 / divisor;
    return 0;
}

int main() {
    verificacao_de_overflow();
    preenche_array();
    divisao_arriscada();
    
    return 0;
}
