/******************************************************************************
 Function Description
 
 Complete the function hourglassSum in the editor below. It should return an 
 integer, the maximum hourglass sum in the array.
 
 hourglassSum has the following parameter(s):
	arr: an array of integers

 *****************************************************************************/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int doSum(vector<vector<int>> arr, int i, int j)
{
	int sum = 0;

	// first row sum
	sum += arr[i][j] + arr[i][j+1] + arr[i][j+2];

	// last row sum
	sum += arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

	// center element sum
	sum += arr[i+1][j+1];
	
	return sum;
}

int hourglassSum(vector<vector<int>> arr)
{
	int highestSum = INT_MIN;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int currSum = doSum(arr, i, j);
			
			if (highestSum < currSum)
				highestSum = currSum;
		}
	}

	return highestSum;
}

int main()
{
	vector<vector<int>> arr = {
					{1,1,1,0,0,0},
					{0,1,0,0,0,0},
					{1,1,1,0,0,0},
					{0,0,2,4,4,0},
					{0,0,0,2,0,0},
					{0,0,1,2,4,0}
				};

	cout << "Highest hour glass sum: " << hourglassSum(arr) << endl;

	return 0;
}
