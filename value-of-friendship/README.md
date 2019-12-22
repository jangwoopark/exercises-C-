You're researching friendships between groups of  new college students where each student is distinctly numbered from  to . At the beginning of the semester, no student knew any other student; instead, they met and formed individual friendships as the semester went on. The friendships between students are:

Bidirectional. If student  is friends with student , then student  is also friends with student .
Transitive. If student  is friends with student  and student  is friends with student , then student  is friends with student . In other words, two students are considered to be friends even if they are only indirectly linked through a network of mutual (i.e., directly connected) friends.
The purpose of your research is to find the maximum total value of a group's friendships, denoted by . Each time a direct friendship forms between two students, you sum the number of friends that each of the  students has and add the sum to .

You are given  queries, where each query is in the form of an unordered list of  distinct direct friendships between  students. For each query, find the maximum value of  among all possible orderings of formed friendships and print it on a new line.

Input Format

The first line contains an integer, , denoting the number of queries. The subsequent lines describe each query in the following format:

The first line contains two space-separated integers describing the respective values of  (the number of students) and  (the number of distinct direct friendships).
Each of the  subsequent lines contains two space-separated integers describing the respective values of  and  (where ) describing a friendship between student  and student .
Constraints

Output Format

For each query, print the maximum value of  on a new line.

Sample Input 0

1
5 4
1 2
3 2
4 2
4 3
Sample Output 0

32
Explanation 0

image

The value of  is maximal if the students form the  direct friendships in the following order:

Students  and  become friends:
image

We then sum the number of friends that each student has to get .

Students  and  become friends:
image
We then sum the number of friends that each student has to get .

Students  and  become friends:
image
We then sum the number of friends that each student has to get .

Students  and  become friends:
image
We then sum the number of friends that each student has to get .

When we add the sums from each step, we get . We then print  on a new line.
