Bitville is a seaside city that has a number of shopping centers connected by bidirectional roads, each of which has a travel time associated with it. Each of the shopping centers may have a fishmonger who sells one or more kinds of fish. Two cats, Big Cat and Little Cat, are at shopping center  (each of the centers is numbered consecutively from  to ). They have a list of fish they want to purchase, and to save time, they will divide the list between them. Determine the total travel time for the cats to purchase all of the types of fish, finally meeting at shopping center . Their paths may intersect, they may backtrack through shopping center , and one may arrive at a different time than the other. The minimum time to determine is when both have arrived at the destination.

For example, there are  shopping centers selling  types of fish. The following is a graph that shows a possible layout of the shopping centers connected by  paths. Each of the centers is labeled . Here  and  represent Big Cat and Little Cat, respectively. In this example, both cats take the same path, i.e.  and arrive at time  having purchased all three types of fish they want. Neither cat visits shopping centers  or .

image
Function Description

Complete the shop function in the editor below. It should return an integer that represents the minimum time required for their shopping.

shop has the following parameters:
- n: an integer, the number of shopping centers
- k: an integer, the number of types of fish
- centers: an array of strings of space-separated integers where the first integer of each element is the number of types of fish sold at a center and the remainder are the types sold
- roads: a 2-dimensional array of integers where the first two values are the shopping centers connected by the bi-directional road, and the third is the travel time for that road

Input Format

The first line contains  space-separated integers:  (the number of shopping centers),  (the number of roads), and  (the number of types of fish sold in Bitville), respectively.

Each line  of the  subsequent lines () describes a shopping center as a line of space-separated integers. Each line takes the following form:

The first integer, , denotes the number of types of fish that are sold by the fishmonger at the  shopping center.
Each of the  subsequent integers on the line describes a type of fish sold by that fishmonger, denoted by , where  going forward.
Each line  of the  subsequent lines () contains  space-separated integers that describe a road. The first two integers,  and , describe the two shopping centers it connects. The third integer, , denotes the amount of time it takes to travel the road.

Constraints

All  are different for every fixed .
Each road connectes  distinct shopping centers (i.e., no road connects a shopping center to itself).
Each pair of shopping centers is directly connected by no more than  road.
It is possible to get to any shopping center from any other shopping center.
Each type of fish is always sold by at least one fishmonger.
Output Format

Print the minimum amount of time it will take for the cats to collectively purchase all  fish and meet up at shopping center .

Sample Input

5 5 5
1 1
1 2
1 3
1 4
1 5
1 2 10
1 3 10
2 4 10
3 5 10
4 5 10
Sample Output

30
Explanation

image
 represents a location Big Cat visits,  represents a location where Little Cat visits.

Big Cat can travel  and buy fish at all of the shopping centers on his way.

Little Cat can then travel , and buy fish from the fishmonger at the  shopping center only.
