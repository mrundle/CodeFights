#include "include.h"
/* -----------------------------------------------------------------------------
 * https://codefights.com/challenge/XRGXNwsdbBrvp66jM
 * -----------------------------------------------------------------------------
 * Description:
 *
 * Given a number n, convert it into its full cardinal form.
 * 
 * Here are the names of some numbers for your convenience:
 * 
 *     ...
 * 
 * Example:
 * 
 * For n = "1255", the output should be
 * cardinal(n) = "one thousand two hundred and fifty five".
 * 
 * [time limit] 500ms (cpp)
 * [input] string n
 * 
 * A string containing a non-negative integer without leading zeros.
 * 
 * Constraints:
 * 1 ≤ n.length ≤ 15
 * 
 * [output] string
 *
 * -----------------------------------------------------------------------------
 * Score: 616
 */

// too far? #golf

// saves 1 char overall
#define S s+=
// 7 chars
#define E "teen"

string
    o[20] = {"","one","two","three","four",
            "five","six","seven","eight","nine",
            "ten","eleven","twelve","thir" E,
            "four" E,"fif" E,"six" E,
            "seven" E,"eigh" E,"nine" E},
    t[10] = {"","","twenty","thirty","forty","fifty",
            "sixty","seventy","eighty","ninety"},
    h[5] = {" trillion"," billion"," million",
            " thousand", " hundred"};//,
//cardinal(auto n) {
string cardinal(auto n) {
    
    // edge case
    if (n == "0") return "zero";
    
    // result
    string s;
    
    long H=100,
         K=1000,
         M=K*K,
         B=M*K,
         T=B*K,
         z[5]={T,B,M,K,H},
         c = stol(n),
         i;
    
    for(;i<5;i++) { 
        if (c/z[i])
            S cardinal(to_string(c/z[i])) + h[i];
        c %= z[i];
        if (s != "" && c) {
            if (s.back() != ' ') S " ";
            if (i==4 & c>1) S "and ";
        }
    }
    
    if (c<20)
        S o[c];
    else {
        S t[c/10];
        if(c%10) S " " + o[c%10];
    }
    
    return s;
}
