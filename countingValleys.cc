/******************************************************************************
 Function Description
 Complete the countingValleys function in the editor below. It must return an 
 integer that denotes the number of valleys Gary traversed.
 
 countingValleys has the following parameter(s):
	n: the number of steps Gary takes
	s: a string describing his path
 *****************************************************************************/

#include <iostream>

using namespace std;

int countingValleys(int n, string s)
{
	int valleysWalked = 0;
	int currentLevel = 0;
	bool incrementOnNextSeaLevel = false;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'U')
			currentLevel++;
		else
			currentLevel--;

		if (currentLevel < 0)
			incrementOnNextSeaLevel = true;
		
		if (currentLevel == 0 && incrementOnNextSeaLevel)
		{
			valleysWalked++;
			incrementOnNextSeaLevel = false;
		}
	}

	return valleysWalked;
}

int main()
{
	cout << "No. of Valleys Walked: " << countingValleys(8, "UDDDUDUU") 
		<< endl;

	return 0;
}


