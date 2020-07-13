You have an infinite number of 4 types of lego blocks of sizes given as (depth x height x width):

d	h	w
1	1	1
1	1	2
1	1	3
1	1	4
Using these blocks, you want to make a wall of height  and width . Features of the wall are:

- The wall should not have any holes in it.
- The wall you build should be one solid structure, so there should not be a straight vertical break across all rows of bricks.
- The bricks must be laid horizontally.

How many ways can the wall be built?

For example, the wall's height  and its width . Here are some configurations:

image
These are not all of the valid permutations.

Function Description

Complete the legoBlocks function in the editor below. It should return an integer that represents the number of valid wall formations for the given wall dimensions modulo .

legoBlocks has the following parameter(s):

n: an integer that represents the height of the wall
m: an integer that represents the width of the wall
Input Format

The first line contains the number of test cases .

Each of the next  lines contains two space-separated integers  and .

Constraints



Output Format

Output one line for each test case containing the number of ways to build the wall. As the numbers can be very large, output the result modulo 1000000007.

Sample Input

4  
2 2  
3 2  
2 3  
4 4
Sample Output

3  
7  
9  
3375
Explanation

For the first case, we can have:

image

For the second case, each row of the wall can contain either two blocks of width 1, or one block of width 2. However, the wall where all rows contain two blocks of width 1 is not a solid one as it can be divided vertically. Thus, the number of ways is  and .
