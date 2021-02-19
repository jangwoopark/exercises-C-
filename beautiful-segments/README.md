You are given an array, , consisting of  integers.

A segment, , is beautiful if and only if the bitwise AND of all numbers in  with indices in the inclusive range of  is not greater than . In other words, segment  is beautiful if .

You must answer  queries. Each query, , consists of  integers: , , and . The answer for each  is the number of beautiful segments  such that  and .

Input Format

The first line contains two space-separated integers,  (the number of integers in ) and  (the number of queries).

The second line contains  space-separated integers, where the  integer denotes the  element of array .

Each line  of the  subsequent lines contains  space-separated integers, , , and , respectively, describing query .

Constraints

 holds for test cases worth at least  of the problem's score.
 holds for test cases worth at least  of the problem's score.
Output Format

Print  lines, where the  line contains the number of beautiful segments for query .

Sample Input

5 3
1 2 7 3 4
1 5 3
2 4 6
3 5 2
Sample Output

13
5
2
Explanation

The beautiful segments for all queries are listed below.

Query 0: The beautiful segments are .

Query 1: The beautiful segments are .

Query 2: The beautiful segments are .
