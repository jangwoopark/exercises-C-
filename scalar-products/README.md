Integer sequence  having length  is defined as follows:

, where 
Write a function generator, , to generate the remaining values for  through . The values returned by  describe two-dimensional vectors , where each sequential pair of values describes the respective  and  coordinates for some vector  in the form . In other words, .

Let  be the set of scalar products of  and  for each , where . Determine the number of different residues in  and print the resulting value modulo .

Input Format

A single line of three space-separated positive integers:  (the value of ),  (the modulus), and  (the number of two-dimensional vectors), respectively.

Constraints

Output Format

Print a single integer denoting the number of different residues  in .

Sample Input

4 5 3
Sample Output

2
Explanation

Sequence   .

This gives us our vectors: , , and .

Scalar product .
Scalar product .
Scalar product .

There are  residues  in  (i.e.:  and ), so we print the result of  (which is ).
