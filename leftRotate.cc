/********************************************************************
 A left rotation operation on an array of size  shifts each of the array's elements  
 unit to the left. For example, if left rotations are performed on array , 
 then the array would become .

 Given an array of  integers and a number, , 
 perform  left rotations on the array. Then print the updated array as a single 
 line of space-separated integers.

 Input Format

 The first line contains two space-separated integers denoting the respective values of  
 (the number of integers) and  (the number of left rotations you must perform). 
 The second line contains  space-separated integers describing the respective 
 elements of the array's initial state.

 Output Format

 Print a single line ofspace-separated integers denoting the final state of 
 the array after performing left rotations.

 Sample Input
 5 4
 1 2 3 4 5

 Sample Output
 5 1 2 3 4

********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> array_left_rotation(vector<int> arr, int length, int rotation) 
{
    vector<int> temp(length);
    int newIndex = 0;

    // get rotation in bounds
    rotation = rotation % length;

    for (int i = 0; i < length; i++)
    {
        newIndex = (i - rotation) < 0 ? length + (i - rotation)
                    : i - rotation;
        
        temp[newIndex] = arr[i];
    }

    return temp;
    
}

int main()
{
    int length;
    int rotation;
    cin >> length >> rotation;
    vector<int> arr(length);
    for(int a_i = 0;a_i < length;a_i++){
        cin >> arr[a_i];
    }
    vector<int> output = array_left_rotation(arr, length, rotation);
    for(int i = 0; i < length;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
