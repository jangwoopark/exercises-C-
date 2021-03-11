Ma5termind is crazy about Action Games. He just bought a new one and got down to play it. Ma5termind usually finishes all the levels of a game very fast. But, This time however he got stuck at the very first level of this new game. Can you help him play this game.
To finish the game, Ma5termind has to cross  levels. At each level of the game, Ma5termind has to face  enemies. Each enemy has its associated power  and some number of bullets . To knock down an enemy, Ma5termind needs to shoot him with one or multiple bullets whose collective count is equal to the power of the enemy. If Ma5termind manages to knock down any one enemy at a level, the rest of them run away and the level is cleared.
Here comes the challenging part of the game. 
Ma5termind acquires all the bullets of an enemy once he has knocked him down. Ma5termind can use the bullets acquired after killing an enemy at  level only till the  level.
However, the bullets Ma5termind carried before the start of the game can be taken forward and can be used to kill more enemies.
Now, Ma5termind has to guess the minimum number of bullets he must have before the start of the game so that he clears all the  levels successfully.
NOTE
Bullets carried before the start of the game can be used to kill an enemy at any level.
One bullet decreases the power of an enemy by 1 Unit.
For better understanding of the problem look at the sample testcases.
Input Format
First line of input contains a single integer  denoting the number of test cases. 
First line of each test case contains two space separated integers  and  denoting the number of levels and number of enemies at each level respectively. 
Each of next  lines of a test case contain  space separated integers, where  integer in the  line denotes the power of  enemy on the  level. 
Each of the next  lines of a test case contains  space separated integers, where  integer in the  line denotes the number of bullets   enemy of  level has.
Constraints 
 
 
 
 
For each test file, sum of  over all the test cases does not exceed .
Output Format
For each test case, print the required answer.
Sample Input
2
3 3
3 2 1 
1 2 3
3 2 1
1 2 3
3 2 1
1 2 3
3 3 
3 2 5 
8 9 1 
4 7 6 
1 1 1 
1 1 1 
1 1 1 
Sample Output
1
5   
Explanation
For the First test case , Ma5termind kills the enemy in the following order:
Ma5termind kills the  enemy at the  level, takes all his bullets and moves to the next level.
Ma5termind kills the  enemy at the  level, takes all his bullets and moves to the next level.
Ma5termind kills the  enemy at the  level, takes all his bullets and moves to the next level.
So this way Ma5termind can successfully finish this game with only  bullet in hand before the start of the game.
For the second test case , Ma5termind kills the enemy in the following order:
Ma5termind kills the  enemy at the  level, takes all his bullets and moves to the next level.
Ma5termind kills the  enemy at the  level, takes all his bullets and moves to the next level.
Ma5termind kills the  enemy at the  level, takes all his bullets and moves to the next level.
So this way Ma5termind can successfully finish this game with only  bullet in hand before the start of the game.
NOTE: 
There can be more than one way of getting the optimal answer but that does not matter in our case, because we need to answer the minimum number of bullets required.
