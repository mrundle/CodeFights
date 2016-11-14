#include "include.h"
/* -----------------------------------------------------------------------------
 * https://codefights.com/challenge/wcNrgbtmpWWn4DTwu
 * -----------------------------------------------------------------------------
 * Description:
 *
 * Pick a positive integer, write it out in English words, then count the total
 * number of letters in the words. Keep repeating this process using the total
 * as the new number to write and eventually you will reach an infinite loop at
 * the number 4, no matter which number you start from.
 *
 * Your task is to find the number of steps it takes to reach the number 4 from
 * the given integer n.
 *
 * Here are some examples of how numbers should be written and counted:
 *   1 = one (3 letters)
 *   14 = fourteen (8 letters)
 *   30 = thirty (6 letters)
 *   42 = forty two (8 letters)
 *   216 = two hundred sixteen (17 letters)
 *   1500 = one thousand five hundred (22 letters)
 *   1000000 = one million (10 letters)
 *   987654321 = nine hundred eighty seven million six hundred fifty four
 *               thousand three hundred twenty one (77 letters)
 *
 * Example:
 *
 * For n = 377, the output should be
 *   NumberOfLetters(n) = 5.
 *   
 *   377 would be written as three hundred seventy seven which has 24 letters.
 *   24 would be written as twenty four which has 10 letters.
 *   10 would be written as ten which has 3 letters.
 *   3 would be written as three which has 5 letters.
 *   5 would be written as five which has 4 letters.
 * We have now reached 4 and there were 5 steps in total, so the result is 5.
 * 
 * Input/Output
 *
 * [time limit] 500ms (cpp)
 * [input] integer n
 *   The starting number.
 *   Constraints:
 *     0 < n < 109
 * [output] integer
 *   The number of steps taken to reach 4 from n.
 *
 * -----------------------------------------------------------------------------
 * Score: 332 chars
*/

int 
    /* length of number names from 0 - 20 */
    o[21]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8,6},
    /* length of number names: billion, million, hundred, thousand */
    b[4]={7,7,8,7},
    /* length of number names (t=tens): n/a, n/a, twenty, thirty, ... */
    t[10]={0,0,6,6,5,5,5,7,6,6},
    /* the different 'levels' (5 of them) that we'll iterate through
     * based on the size of the given input
     */
    x[5]={1000000000,1000000,1000,100,1},
    /* number of times we've run NumberOfLetters */
    c;

int f(int n) {
    int i,y,r = 0;
    for (i = 0; i < 5; i++) {
        if (i <= 3) {
            y = n / x[i]; 
            if (y > 0) r += f(y) + b[i];
            n %= x[i];
        } else if (n > 20) {
            r += t[n / 10] + o[n % 10];
        } else r += o[n];
    }
    return r;
}


int NumberOfLetters(int n) {
    while (n != 4) ++c,n = f(n);
    return c;
}
