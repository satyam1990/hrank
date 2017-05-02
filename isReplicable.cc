/********************************************************************
 A kidnapper wrote a ransom note but is worried it will be traced back to him. 
 He found a magazine and wants to know if he can cut out whole words from it and 
 use them to create an untraceable replica of his ransom note. 
 The words in his note are case-sensitive and he must use whole words available 
 in the magazine, meaning he cannot use substrings or concatenation to create the words he needs.

 Given the words in the magazine and the words in the ransom note, print Yes 
 if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.

 Input Format

 The first line contains two space-separated integers describing the respective values of 
 m (the number of words in the magazine) and n (the number of words in the ransom note). 
 The second line contains m space-separated strings denoting the words present in the magazine. 
 The third line contains n space-separated strings denoting the words present in the ransom note.

 Output Format

 Print Yes if he can use the magazine to create an untraceable replica of his ransom note; otherwise, print No.

 Sample Input
 6 4
 give me one grand today night
 give one grand today

 Sample Output
 Yes

********************************************************************/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool ransom_note(vector<string>& magazine, vector<string>& ransom)
{
    map<string, int> ransomMap;
    int count = 0;

    for (int i = 0; i < ransom.size(); i++)
    {
        ransomMap[ransom[i]]++;
        count++;
    }

    for (int i = 0; i < magazine.size(); i++)
    {
        map<string, int>::iterator it = ransomMap.find(magazine[i]);
        if (it != ransomMap.end())
        {
            it->second--;
            if (it->second == 0)
                ransomMap.erase(it);

            count--;
        }
    }
    
    return count == 0; 
}

int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
