Consider four numbers: , , , and . You must change at most  bits in  and  to form the numbers  and  satisfying the equation . Here, the | symbol denotes the bitwise OR operation.

Given  sets of the numbers defined above, find and print the respective values of  and  on new lines; if no such value exists, print  instead. If there are multiple solutions, make  as small as possible; if there are still multiple solutions, make  as small as possible.

Notes:

, , and  are given in Hexadecimal (base 16), and  is given in decimal (base 10).
If the number of bits changed in  is  and the number of bits changed in B is , then  must be .
Input Format

The first line contains an integer, , denoting the number of queries. The subsequent lines describe each respective query as follows:

The first line contains a single integer denoting the value of .
Each of the next  lines contains a Hexadecimal (base 16) number describing the respective values of , , and .
Constraints

Output Format

Print two lines of output for each query:

The first line should contain a Hexadecimal (base 16) number denoting the value of .
The second line must contain a Hexadecimal (base 16) number denoting the value of .
If no valid answer exists, you must instead print one line of output with the integer .

Note: The letters in Hexadecimal numbers must be in uppercase.

Sample Input

3
8
2B
9F
58
5
B9
40
5A
2
91
BE
A8
Sample Output

8
58
18
42
-1
Explanation

Query 0:
In this query, .
Change  to .  bits are changed.

aorb(1).png

Change B =  to .  bits are changed.

aorb(2).png


Query 1:
In this query, .
Change  to .  bits are changed.
Change  to . Only  bit is changed.


Query 2:
There is no valid answer, so we print .
