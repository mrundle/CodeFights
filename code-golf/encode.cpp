/* -----------------------------------------------------------------------------
 * https://codefights.com/challenge/u48jf3T4spZ4J8aDg 
 * -----------------------------------------------------------------------------
 * Description:
 *
 * Run-length encoding (RLE) is a very simple form of lossless data compression
 * in which runs of data (that is, sequences in which the same data value occurs
 * in many consecutive data elements) are stored as a single data value and
 * count, rather than as the original run.
 *
 * Example:
 *
 * For s =  "aabbbccc", the output should be
 *  encode(s) = "a2b3c3".
 * 
 * Input/Output
 *
 * [time limit] 500ms (cpp)
 * [input] string s
 *     A string consisting of lowercase English letters.
 *     Constraints:
 *         1 ≤ s.length ≤ 104.
 * [output] string
 * -----------------------------------------------------------------------------
 * Score: 132 chars
 */

auto encode(auto s) {
    char b[10000], c = s[0];
    /* i = input buffer index 
     * n = number of times seen - 1
     * z = output buffer index
     */
    int i, n, z = 0;
    while (i++ < s.length())
        (c ^ s[i]) ?
            z += sprintf(b + z, "%c%d", c, n+1),
            n=0,
            c=s[i]
        :
            n++;
    return b;
}
