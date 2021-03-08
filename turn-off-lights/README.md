There are  bulbs in a straight line, numbered from  to . Each bulb  has a button associated with it, and there is a cost, , for pressing this button. When some button  is pressed, all the bulbs at a distance  from bulb  will be toggled(off->on, on->off).

Given , , and the costs for each button, find and print the minimum cost of turning off all  bulbs if they're all on initially.

Input Format

The first line contains two space-separated integers describing the respective values of  and .
The second line contains  space-separated integers describing the respective costs of each bulb (i.e., ).

Constraints

Output Format

Print a long integer denoting the minimum cost of turning off all  bulbs.

Sample Input

3 1
1 1 1
Sample Output

1
Explanation

If we press the middle switch, the middle bulb and the  closest adjacent bulbs (i.e., the first and third) will turn off. Because all bulbs will be off in one button press, this cost is minimal. Thus, we print  as our answer.
