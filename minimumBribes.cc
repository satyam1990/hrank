/******************************************************************************
 Function Description
 
 Complete the function minimumBribes in the editor below. It must print an 
 integer representing the minimum number of bribes necessary, or Too chaotic 
 if the line configuration is not possible.
 
 minimumBribes has the following parameter(s):
	q: an array of integers

 *****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void minimumBribes1(vector<int> q)
{
	int bribes = 0;

	for (int i = 0; i < q.size(); i++)
	{
		// calculate desired position of current element
		int desiredPos = q[i] - 1;

		if (desiredPos <= i)
			continue;
		
		if (desiredPos > i)
		{
			// see how far from desired position
			int howFar = desiredPos - i;

			if (howFar > 2)
			{
				cout << "Too chaotic" << endl;
				return;
			}
			else
			{
				bribes += howFar;
			}

		}
	}

	cout << bribes << endl;
}

void minimumBribes(vector<int> q)
{
	int bribes = 0;

	// build the legit map
	vector<int> legitMap(q.size());
	for (int i = 0; i < q.size(); i++)
		legitMap[i] = i + 1;

	for (int i = 0; i < q.size(); i++)
	{
		if (legitMap[i] != q[i])
		{
			// swap element is 1 step away
			if (legitMap[i+1] == q[i])
			{
				int temp = legitMap[i];
				legitMap[i] = q[i];
				legitMap[i+1] = temp;

				bribes += 1;
			}
			// swap element is 2 step away
			else if (legitMap[i+2] == q[i])
			{
				int temp = legitMap[i];
				legitMap[i] = q[i+2];
				legitMap[i+2] = legitMap[i+1];
				legitMap[i+1] = temp;

				bribes += 2;
			}
			else
			{
				cout << "Too chaotic" << endl;
				return;
			}
		}
	}

	cout << bribes << endl;
}

int main()
{
	vector<int> arr = {1,2,5,6,7,8,4,9,10,3,11,12};
	minimumBribes(arr);

	return 0;
}
