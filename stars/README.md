Little John has drawn  stars on his paper where each star has a weight . He draws a straight line that divides the paper into two parts such that each part has a subset of stars in them. Let the weight of each part be the summation of weights of the stars in the part. He wants to draw the line such that the difference in the sum of weights between the two parts is as small as possible while maximizing the smaller part's weight.

Your task is to compute the weight of smaller part corresponding to this line where no stars are allowed to be on the line and line can be of any slope.

Input Format
The first line of the input contains an integer .
Each of next  lines contains three integers  and  specifying the positions of  star and .
No three points lie on a line.

Constraints



Output Format
Print an integer being the answer to the test.

Sample Input 0

4
1 1 2
-1 1 2
-1 -1 4
1 -1 5
Sample Output 0

6
Explanation
You can imagine a line along the  and see that point  and  lie on left side summing up to 6, while the other side has sum as .

Sample Input 1

10
748798831 -200797120 595
-774675771 179630170 159
-338760201 945958360 750
955629379 -312997434 516
755005057 -672683474 405
-743176829 190325067 86
-301478753 -718170081 923
-795908444 985440803 854
-102868895 671114060 246
-698209449 12550066 190
Sample Output 1

2358
Explanation

 and  are two sets of weights.
