Alice and Bob are playing a game, defined below:

There is an undirected tree graph with  nodes that has the following properties:
Each node has  golden coins.
Node  is root of the tree.
The parent node of some node  is defined as .
Moves
Players move in turns.
During a move, a player can select a node  and move one or more coins to .
If the current player can't make any move, they lose the game.
The game quickly becomes boring because the result is determined by the tree's configuration and the number of coins in each node (assuming that both players play optimally).

Alice decides to instead challenge Bob by asking him  questions. For each question :

Alice picks a node  and removes the edge between  and .
She picks another node  and draws a new undirected edge between  and . So now .
Bob must determine if the first player has a winning strategy for the new tree or not. It's possible that after Alice draws the new edge, the graph will no longer be a tree; if that happens, the question is invalid. Each question is independent, so the answer depends on the initial state of the graph (and not on previous questions).

Given the tree and the number of coins in each node, can you help Bob answer all  questions?

Input Format

The first line contains an integer,  (the number of nodes).
The second line contains  space-separated integers, , describing the number of coins in each node.
Each of the  subsequent lines contains  space-separated integers denoting an undirected edge between nodes  and , respectively.
The next line contains an integer,  (the number of questions Alice asks).
Each of the  subsequent lines contains  space-separated integers,  and , respectively.

Constraints

For each question:

Output Format

On a new line for each question, print  if the first player has a winning strategy, print  if they do not, or print  if the question is not valid.

Sample Input

6
0 2 2 1 3 2
1 2
1 3
3 4
3 5
4 6
3
6 2
4 1
3 6
Sample Output

NO
YES
INVALID
Explanation

Initally the tree looks like this:goldenagain.png

After the first question (), the tree looks like this:goldenagain(1).pngAlice removes the edge conecting node  to  and makes  the new parent node of . Because this configuration does not result in a winning strategy, we print  on a new line.

After the second question (), the tree looks like this:goldenagain(5).pngAlice removes the edge conecting node  to  and makes  the new parent node of . Because this configuration results in a winning strategy, we print  on a new line.

After the third question (), the graph is no longer a tree:goldenagain(6).pngAlice removes the edge conecting node  to  and makes  the new parent node of . The graph is now partitioned into two separate subgraphs (one of which is also not a tree); because the game must be played on a single undirected tree graph, we print  on a new line.
