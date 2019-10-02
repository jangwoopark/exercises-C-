The country of Byteland contains  cities and  bidirectional roads. There is a path between any two cities. The roads in Byteland were built long ago, and now they are in need of repair. You have been hired to fix all the roads. You intend to do this by dispatching robots on some of the roads. Each robot will repair the road he is currently on and then moves to one of the adjacent unrepaired roads. After repairing that, it will move to another adjacent unrepaired road, repair that and so on.

Two roads are adjacent if they have the same city at one of their endpoints. For the process to be efficient, no two robots will ever repair the same road, and no road can be visited twice. What is the minimum number of robots needed to accomplish the task?

Input Format

The first line contains the number of test cases .  test cases follow. The first line of each test case contains , the number of cities in Byteland. The cities are numbered . The following  lines contain the description of the roads. The  line contains two integers  and , meaning that there is a road connecting cities with numbers  and .

Constraints

Output Format

Print  lines, one corresponding to each test case containing the required answer for that test case.

Sample Input

3  
4  
0 1  
0 2  
0 3  
6  
0 1  
1 2  
2 3  
2 4  
4 5  
7  
0 1  
1 2  
2 3  
2 4  
4 5  
3 6
Sample Output

1  
1  
2
Explanation

For the first case, one robot is enough to repair all roads: 
For the second case, one robot is again enough: 
The the third case, there is no way to repair all the roads with one robot and at least two are needed.
