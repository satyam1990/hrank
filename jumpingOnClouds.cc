/******************************************************************************
 Function Description
 
 Complete the jumpingOnClouds function in the editor below. It should return 
 the minimum number of jumps required, as an integer.
 
 jumpingOnClouds has the following parameter(s):
	c: an array of binary integers
 *****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int jumpingOnClouds(vector<int> c)
{
	int jumps = 0;
	int i = 0;

	while( i < c.size() - 1)
	{
		if (c[i+2] == 0)
			i += 2;
		else
			i += 1;
		
		jumps++;
	}

	return jumps;
}

int main()
{
	vector<int> clouds = {0,0,0,0,1,0,0,0,1,0};
	cout << "Minimum Steps Required: " << jumpingOnClouds(clouds) << endl;

	return 0;
}

