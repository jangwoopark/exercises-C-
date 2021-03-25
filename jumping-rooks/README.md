Nina has an  chessboard and  jumping rooks. Every cell of the chessboard is either blocked or free, and Nina can only put a single rook in any free cell.

Two jumping rooks beat each other if they are either in the same row or in the same column and all cells between them are free (note that it's possible that there are some other rooks between them). More formally, if the first rook is in cell  and the second rook is in cell  (where ), then these two rooks beat each other if and only if  are free. If the rooks are in cells  and , then cells  must all be free.

Given the configuration of the chessboard and some , help Nina place  jumping rooks in the chessboard's free cells such that the number of pairs of rooks that beat each other is minimal. Then print a single integer denoting the number of rooks that beat each other.

Input Format

The first line contains two space-separated integers describing the respective values of  (the size of the chessboard) and  (the number of rooks to place).
Each line  of the  subsequent lines contains a string of  characters describing each row in the chessboard. The  character of the  line is # if cell  is blocked or . if the cell is free.

Constraints

It is guaranteed that  is less than the number of free cells in the chessboard.
Output Format

Print a single integer denoting the minimum possible number of pairs of rooks that beat each other.

Sample Input 0

3 4
...
...
...
Sample Output 0

2
Explanation 0
For this input, one possible arrangement is:

o.o
.o.
..o
where each o is a jumping rook.

Sample Input 1

5 10
..#..
..#..
#####
..#..
..#..
Sample Output 1

4
Explanation 1
For this input, one possible arrangement is:

.o#o.
oo#oo
#####
.o#o.
o.#.o
where each o is a jumping rook.
