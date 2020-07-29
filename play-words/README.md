Shaka and his brother have created a boring game which is played like this:

They take a word composed of lowercase English letters and try to get the maximum possible score by building exactly 2 palindromic subsequences. The score obtained is the product of the length of these 2 subsequences.

Let's say  and  are two subsequences from the initial string. If  &  are the smallest and the largest positions (from the initial word) respectively in  ; and  &  are the smallest and the largest positions (from the initial word) respectively in , then the following statements hold true:
,
, &
.
i.e., the positions of the subsequences should not cross over each other.

Hence the score obtained is the product of lengths of subsequences  & . Such subsequences can be numerous for a larger initial word, and hence it becomes harder to find out the maximum possible score. Can you help Shaka and his brother find this out?

Input Format

Input contains a word  composed of lowercase English letters in a single line.

Constraints


each character will be a lower case english alphabet.

Output Format

Output the maximum score the boys can get from .

Sample Input

eeegeeksforskeeggeeks
Sample Output

50
Explanation

A possible optimal solution is eee-g-ee-ksfor-skeeggeeks being eeeee the one subsequence and skeeggeeks the other one. We can also select eegee in place of eeeee, as both have the same length.
