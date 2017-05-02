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
