#include "include.h"
/* -----------------------------------------------------------------------------
 * https://codefights.com/challenge/PYqXBbXgEoDeZmJm3
 * -----------------------------------------------------------------------------
 * Description:
 *
 * You are given a positive integer N, your task is to calculate the total
 * number of primes less than or equal to N with additional requirement that
 * each digit of those primes should be a prime number itself.
 * 
 * Example:
 * 
 * For N = 11, the output should be
 *   primeDigits(11) = 4.
 *   There are 5 primes less than N or equal to it: 2, 3, 5, 7 and 11. But there
 *   is a digit 1 (even two of them) in 11, and 1 is not a prime number. Thus,
 *   the answer is 4.
 * 
 * Input/Output:
 * 
 * [time limit] 500ms (cpp)
 * [input] integer N
 * 
 * Constraints:
 * 0 ≤ N ≤ 106
 * 
 * [output] integer
 *
 * -----------------------------------------------------------------------------
 * Score: 168 chars
 */

// helper ints as we iterate throught the list
int i, j,
// number of primes
p;

int primeDigits(int N) {
    if (N++ > 1) {
    int d[N] = {1,1};

    // sieve of eratosthenes
    for (i = 2; i < N; i++) {
        // if prime, check primality of digits
        if (!d[i]) {
            j = i;
            do
                if (d[j%10]) goto z;
            while ((j /= 10) > 0);
            // if we've made it here without jumping, prime
            p++;
        }
        z:;
        // mark all multiples not prime
        for (j = i*2; j < N; j += i) {
            d[j] = 1;
        }
    }
    }
    return p;
}
