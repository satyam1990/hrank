/******************************************************************************
 Function Description
 Complete the repeatedString function in the editor below. It should return an 
 integer representing the number of occurrences of a in the prefix of length n
 in the infinitely repeating string.
 
 repeatedString has the following parameter(s):
	s: a string to repeat
	n: the number of characters to consider

 *****************************************************************************/

#include <iostream>

using namespace std;

long countA(string s, long n)
{
	long count = 0;

	for (long i = 0; i < n; i++)
	{
		if (s[i] == 'a')
			count++;
	}

	return count;
}

long repeatedString(string s, long n)
{
	long count = 0;

	if (n <= s.length())
	{
		count = countA(s, n);
	}
	else if ( n > s.length())
	{
		// get count of a's in base string
		count = countA(s, s.length());

		// n / s.length() will get us number to do multiply with
		// to incorporate repeatition
		count = count * (n / s.length());

		// as n may not fully divide so adjust the remainder
		count += countA(s, n % s.length());
	}

	return count;
}

int main()
{
	long n = 1001;
	string s = "ab";

	cout << "No. of a's: " << repeatedString(s, n) << endl;

	return 0;
}
