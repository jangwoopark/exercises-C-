Given a sequence of  numbers, , what's the maximum size of a subsequence of  in which every pair is a nice pair?

The pair  is a nice pair iff at least one of the following condition holds.

The parity of the number of distinct prime divisors of  is equal to that of . For example,  has two distinct prime divisors:  and .
The parity of the sum of all positive divisors of  is equal to that of .
Input Format

The first line contains a single integer . The second line contains  space-separated integers .

Constraints

Output Format

Print the maximum size of any subsequence of  in which every pair is a nice pair.

Sample Input 0

4
2 3 6 8
Sample Output 0

3
Explanation 0

d	Prime divisors (count)	Divisors (sum)
2	2 (1)	1, 2 (3)
3	3 (1)	1, 3 (4)
6	2, 3 (2)	1, 2, 3, 6 (12)
8	2 (1)	1, 2, 4, 8 (15)
You can verify that the pairs  are nice, while  and  are not.

The largest subsequence of  in which all pairs are nice pairs is  and its size is .
