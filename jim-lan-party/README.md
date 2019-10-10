During the Steam Summer Sale, Jim's  friends have purchased  games, which are numbered from  to . The games are multiplayer. Jim has invited his friends to his basement where they will play by making a LAN-Party.

Each friend has already decided the game he would like to play for the rest of the day. So there will be a group of friends who will play the same game together.

But then, they face a problem: Currently, none of the friends' PCs are connected. So they have to be connected using the available  wires. Jim decides to connect friends  and  with the th wire one by one. So he starts with wire 1, then with wire 2 and so on.

A group can start playing their game, only if all the members are connected (if not directly, then there must exist a path connecting them). They want to start playing as soon as possible.

For each game, find out the wire after adding which the group can start playing. It is also possible that a group will never get connected. In such a case, this group starts crying and you should display -1.

Input Format

On the first line there will be ,  and  each separated by a single space. On the second line we will give you  integers separated by a single space: The -th integer denotes the game friend  wants to play (all between  and ). The next  lines will denote  wires: ith line denotes ith wire and is denoted by  and  pairs each separated by a single space.

Constraints

 For each game , the number of players playing  will be positive.

Note Each game is chosen by at least one player. If a group consists of only one member, then print 0, since this lucky (?) lone player can start right away!

Output Format

Print on the th line the answer for the th game.

Sample Input

5 2 4
1 2 2 2 1
1 2 
2 3
1 5
4 5 
Sample Output

3
4
Explanation

The group with the game 1 can play after the 3rd wire is added. The group with game 2 can play only after the 4th wire has been added because after adding the 4th wire, a path between (2,3) (3,4) and (2,4) gets created.
