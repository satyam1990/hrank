/******************************************************************************
 John works at a clothing store. He has a large pile of socks that he must pair 
 by color for sale. Given an array of integers representing the color of each 
 sock, determine how many pairs of socks with matching colors there are.

 For example, there are n = 7  socks with colors ar = [1,2,1,2,1,3,2]. There is
 one pair of color 1 and one of color 2. There are three odd socks left, one of 
 each color. The number of pairs is 2.

 Function Description

 Complete the sockMerchant function in the editor below. It must return an 
 integer representing the number of matching pairs of socks that are available.

 sockMerchant has the following parameter(s):

 n: the number of socks in the pile
 ar: the colors of each sock
 Input Format

 The first line contains an integer n, the number of socks represented in ar. 
 The second line contains n space-separated integers describing the colors 
 ar[i] of the socks in the pile.
******************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int sockMerchant(int n, vector<int> ar)
{
	map<int, int> colorMap;
	int pair = 0;

	// map sock color with number of socks
	for (int i = 0; i < n; i++)
	{
		colorMap[ar[i]]++;
	}

	// calculate how many pairs we have
	for (map<int, int>::iterator it = colorMap.begin(); 
			it != colorMap.end(); it++)
	{
		pair += it->second / 2;
	}

	return pair;
}

int main(int argc, char* argv[])
{
	int n;
	cout << "No. of socks: ";
	cin >> n;

	vector<int> ar(n);
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}

	cout << "Total Matching pair john can sell: " << sockMerchant(n, ar) << endl;

	return 0;
}
