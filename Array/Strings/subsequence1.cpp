#include <bits/stdc++.h>
using namespace std;
void printSubsequence(string input, string output)
{
	// if the input is empty print the output string
	if (input.empty()) {
		cout << output << endl;
		return;
	}
    // pick the first letter 
	printSubsequence(input.substr(1), output + input[0]);

    // dont pick the letter 
	printSubsequence(input.substr(1), output);
}
int main()
{
	string output = "";
	string input = "abc";
	printSubsequence(input, output);
	return 0;
}
