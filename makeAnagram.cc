/********************************************************************
 Given two strings,  and , that may or may not be of the same length, 
 determine the minimum number of character deletions required to make  
 and  anagrams. Any characters can be deleted from either of the strings.

 In other words, both strings must contain the same exact letters in the 
 same exact frequency For example, bacdc and dcbac are anagrams, 
 but bacdc and dcbad are not.

 Input Format

The first line contains a single string, a. 
The second line contains a single string, b.

Output Format

Print a single integer denoting the number of characters you must delete 
to make the two strings anagrams of each other.

Sample Input
cde
abc

Sample Output
4
********************************************************************/

#include <iostream>
#include <map>

using namespace std;

int number_needed(string a, string b) {
    map<char, int> str1Map;
    map<char, int> str2Map;
    int count = 0;
    int aLen = a.length();
    int bLen = b.length();

    for (int i = 0; i < aLen; i++)
        str1Map[a[i]]++;
    for (int i = 0; i < bLen; i++)
        str2Map[b[i]]++;

    // check how many to be removed from a
    for (map<char, int>::iterator it = str1Map.begin(); it != str1Map.end(); it++)
    {
        char curr = it->first;
        if (str1Map[curr] != str2Map[curr]
            && str1Map[curr] > str2Map[curr])
            count += str1Map[curr] - str2Map[curr];
    }

    // check how many to be removed from b
    if (bLen > aLen - count)
        count += bLen - (a.length() - count);

    return count;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
