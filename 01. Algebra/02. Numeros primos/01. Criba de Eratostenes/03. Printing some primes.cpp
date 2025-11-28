#include <iostream>
#include <cmath>
#include <vector>

// Definir el límite de la criba. 10^8 es suficiente para TDPRIMES.
const int MAX = 100000000;
// El array de bits solo necesita N/2 posiciones para números impares,
// dividido por 32 (bits por int) para el bit-sieve.
const int MAX_ARR = (MAX / 2 / 32) + 1;
int is_composite[MAX_ARR]; // Array de enteros para almacenar los bits

bool check_bit(int n) {
    return (is_composite[n / 64] & (1 << ((n / 2) % 32)));
}

// Función para marcar el número 'n' como compuesto
void set_bit(int n) {
    is_composite[n / 64] |= (1 << ((n / 2) % 32));
}

void solve_tdprimes() {
    // 1. Criba: Marcar todos los múltiplos de primos impares
    int limit = sqrt(MAX);
    for (int i = 3; i <= limit; i += 2) {
        if (!check_bit(i)) {
            // i es primo. Marcar sus múltiplos, empezando por i*i.
            for (long long j = (long long)i * i; j <= MAX; j += 2 * i) {
                set_bit(j);
            }
        }
    }

    // 2. Impresión: Recorrer y contar
    int prime_count = 1;

    // P1 (el primer primo) siempre es 2 y debe imprimirse.
    std::cout << 2 << "\n";

    for (int i = 3; i <= MAX; i += 2) {
        if (!check_bit(i)) {
            prime_count++;
            // Imprimir si el índice es 1, 101, 201, 301, ...
            if (prime_count % 100 == 1) {
                std::cout << i << "\n";
            }
        }
    }
}

int main() { // En este problema los métodos convencionales son muy lentos, deves optimizar todo lo posible aprovechando el input standard
    solve_tdprimes();
    return 0;
}

// https://vjudge.net/problem/SPOJ-TDPRIMES
// https://www.spoj.com/problems/TDPRIMES/