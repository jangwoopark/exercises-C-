Let's define a function, , on a string, , of length  as follows:

where  denotes the ASCII value of the  character in string , , and .

Nikita has a string, , consisting of  lowercase letters that she wants to perform  queries on. Each query consists of an integer, , and you have to find the value of  where  is the  alphabetically smallest palindromic substring of . If  doesn't exist, print  instead.

Input Format

The first line contains  space-separated integers describing the respective values of  (the length of string ) and  (the number of queries).
The second line contains a single string denoting .
Each of the  subsequent lines contains a single integer denoting the value of  for a query.

Constraints

It is guaranteed that string  consists of lowercase English alphabetic letters only (i.e.,  to ).
.
Scoring

 for  of the test cases.
 for  of the test cases.
Output Format

For each query, print the value of function  where  is the  alphabetically smallest palindromic substring of ; if  doesn't exist, print  instead.

Sample Input

5 7
abcba
1
2
3
4
6
7
8       
Sample Output

97
97
696207567
98
29493435
99
-1
Explanation

There are  palindromic substrings of . Let's list them in lexicographical order and find value of :

, 
, 
, 
, 
, 
, 
, 
 doesn't exist, so we print  for .
