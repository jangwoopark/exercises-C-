You are situated in an  dimensional grid at position . The dimensions of the grid are . In one step, you can walk one step ahead or behind in any one of the  dimensions. This implies that there are always  possible moves if movements are unconstrained by grid boundaries. How many ways can you take  steps without leaving the grid at any point? You leave the grid if at any point , either  or .

For example, you start off in a 3 dimensional grid at position . The dimensions of the grid are , so each of your axes will be numbered from  to . If you want to move  step, you can move to the following coordinates: .

image
If we started at  in the same grid, our new paths would lead to . Other moves are constrained by .

Function Description

Complete the gridWalking function in the editor below. It should return an integer that represents the number of possible moves, modulo .

gridWalking has the following parameter(s):

m: an integer that represents the number of steps
x: an integer array where each  represents a coordinate in the  dimension where 
D: an integer array where each  represents the upper limit of the axis in the  dimension
Input Format

The first line contains an integer , the number of test cases.

Each of the next  sets of lines is as follows:

The first line contains two space-separated integers,  and .
The next line contains  space-separated integers .
The third line of each test contains  space-separated integers .
Constraints

Output Format

Output one line for each test case. Since the answer can be really huge, output it modulo .

Sample Input

1
2 3
1 1
2 3
Sample Output

12
Explanation

We are starting from (1, 1) in a  2-D grid, and need to count the number of possible paths with length equal to .

Here are the  paths:
