Given  friendly number and  unfriendly numbers, determine how many numbers are divisors of the friendly number but not the unfriendly numbers.

Input Format

The first line contains  space-separated integers,  (the number of unfriendly numbers) and  (the friendly number), respectively. The second line contains  space-separated unfriendly numbers.

Constraints

Output Format

Print the the number of unique divisors of  (i.e.: divisors that are not shared with those of the unfriendly numbers) as a single integer.

Sample Input

8 16
2 5 7 4 3 8 3 18
Sample Output

1
Explanation

There are  unfriendly numbers: .
Our friendly number, , is , and its even divisors are .

Let  be the number of friendly divisors that are not also unfriendly divisors. Let's determine which divisors of  are not also divisors of the unfriendly numbers:

 is a divisor of all unfriendly numbers, so we disregard it.
 is a divisor of unfriendly numbers , , and , so we disregard it.
 is a divisor of unfriendly numbers  and , so we disregard it.
 is a divisor of unfriendly number , so we disregard it.
 is not a divisor of any unfriendly number, so we increment  to .
As there are no more friendly divisors to check, we print the value of  (which is ) on a new line.
