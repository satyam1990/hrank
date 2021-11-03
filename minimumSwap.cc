/* Minimum swaps required to sort a consecutive array starting from 1 to n
 */
#include <iostream>
#include <vector>

using namespace std;

int minimumSwaps(vector<int> arr) {

    int count = 0;
    int i = 0;
    while (i < arr.size())
    {
        // check if number at its sorted index
        // otherwise swap
        if (arr[i] != i + 1)
        {
	    // index to replace current index with
	    int indexToSwap = arr[i] - 1;

            int temp = arr[i];
            arr[i] = arr[indexToSwap];
            arr[indexToSwap] = temp;
            count++;
        }
        else
        {
            i++;
        }

    }

    return count;
}

int main()
{
	vector<int> arr = {7,1,3,2,4,5,6};

	cout << "Minimum Swaps required to sort: " << minimumSwaps(arr) << endl;

	return 0;
}
