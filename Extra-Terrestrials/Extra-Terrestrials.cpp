#include <iostream>
#include <string>

/*
							TASK
You meet a group of aliens, and their language is just like English except that they say every word backwards.
How will you learn to communicate with them?

Task:
Take a word in English that you would like to say, and turn it into language that these aliens will understand.

Input Format:
A string of a word in English.

Output Format:
A string of the reversed word that represents the original word translated into alien language.

Sample Input:
howdy

Sample Output:
ydwoh
*/

using namespace std;

int main()
{
	string input, output;
	cin >> input;

	output.clear();
	for (int i = input.length()-1; i>=0; i--)
	{
		output += input[i];
	}
	cout << output;






	return 0;
}