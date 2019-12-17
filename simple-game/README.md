Big Cat and Little Cat love playing games. Today, they decide to play a Game of Stones, the Kitties are Coming edition. The game's rules are as follows:

The game starts with  stones that are randomly divided into  piles.
The cats move in alternating turns, and Little Cat always moves first.
During a move, a cat picks a pile having a number of stones  and splits it into any number of non-empty piles in the inclusive range from  to .
The first cat to be unable to make a move (e.g., because all piles contain exactly  stone) loses the game.
Little Cat is curious about the number of ways in which the stones can be initially arranged so that she is guaranteed to win. Two arrangements of stone piles are considered to be different if they contain different sequences of values. For example, arrangements  and  are different.

Given the values for , , and , find the number of winning configurations for Little Cat and print it modulo .

Note: Each cat always moves optimally, meaning that they're both playing to win and neither cat will make a move that causes them to lose the game if some other (winning) sequence of moves can be made.

Input Format

The first line of input contains three space-separated integers,  (the number of stones),  (the number of piles), and  (the maximum number of piles into which a pile can be split during a single move), respectively.

Constraints

Output Format

Print the number of initial arrangements of piles that will result in Little Cat winning, modulo .

Sample Input

4 3 3
Sample Output

3
Explanation

There are three possible arrangements:

For any arrangement, Little Cat can pick a pile containing  stones and split it into  piles with  stone each. At this point, the pile configuration will be , so Big Cat won't be able to make any moves and the game ends. We then print the result of  on a new line.
