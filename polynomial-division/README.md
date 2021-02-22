Consider a sequence, , and a polynomial of degree  defined as . You must perform  queries on the sequence, where each query is one of the following two types:

1 i x: Replace  with .
2 l r: Consider the polynomial  and determine whether  is divisible by  over the field , where . In other words, check if there exists a polynomial  with integer coefficients such that each coefficient of  is divisible by . If a valid  exists, print Yes on a new line; otherwise, print No.
Given the values of , , , and  queries, perform each query in order.

Input Format

The first line contains four space-separated integers describing the respective values of  (the length of the sequence),  (a coefficient in ),  (a coefficient in ), and  (the number of queries).
The second line contains  space-separated integers describing .
Each of the  subsequent lines contains three space-separated integers describing a query of either type 1 or type 2.

Constraints

For query type 1:  and .
For query type 2: .
Output Format

For each query of type 2, print Yes on a new line if  is a divisor of ; otherwise, print No instead.

Sample Input 0

3 2 2 3
1 2 3
2 0 2
1 2 1
2 0 2
Sample Output 0

No
Yes
Explanation 0

Given  and the initial sequence , we perform the following  queries:

 is not a divisor of , so we print No on a new line.
Set  to , so .
After the second query, . Because , we print Yes on a new line.
