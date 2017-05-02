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
