HackerLand is a country with  beautiful cities and  undirected roads. Like every other beautiful country, HackerLand has traffic jams.

Each road has a crowd value. The crowd value of a path is defined as the maximum crowd value for all roads in the path. For example, if the crowd values for all roads are , then the crowd value for the path will be .

Each city  has a type value, , denoting the type of buildings in the city.

David just started his vacation in HackerLand. He wants to travel from city  to city . He also wants to see at least  different types of buildings along the path from  to . When choosing a path from city  to city  that has at least  different types of buildings along the path, David always selects the one with the minimum crowd value.

You will be given  queries. Each query takes the form of  space-separated integers, , , and , denoting the respective values for starting city, destination city, and minimum number of unique buildings that David wants to see along the way. For each query, you must print the minimum crowd value for a path between  and  that has at least  different buildings along the route. If there is no such path, print -1.

Note: A path may contain cycles (i.e., the same roads or cities may be traveled more than once).

Input Format

The first line contains  space-separated integers denoting the respective values for  (the number of cities),  (the number of roads), and  (the number of queries).

The second line contains  space-separated integers describing the respective building type for each city in array  (where the -th value is  and ).

Each of the  subsequent lines defines a road in the form of  space-separated integers, , , and , defining an undirected road with crowd value  that connects cities  and .

Each of the  subsequent lines defines a query in the form of  space-separated integers, , , and  (where ), respectively.

Constraints

Each road connect  distinct cities, meaning no road starts and ends in the same city.
Output Format

For each query, print its answer on a new line.

Sample Input

7 6 1
1 1 4 5 1 3 2
1 2 3
2 6 2
2 3 4
3 4 3
2 4 9
5 7 9
1 2 4
Sample Output

4
Explanation

The diagram below depicts the country given as Sample Input. Different values of  are shown in different colors.

davaro.png

The path for the last query (1 2 4) will be . David sees his first type of building in cities  and , his second type of building in city , his third type of building in city , and his fourth type of building in city . The crowd values for each road traveled on this path are ; the maximum of these values is . Thus, we print  on a new line.
