#include <bits/stdc++.h>

using namespace std;

string getCode(string s)
{
    /*int code = 0;
    for (char ch : s)
    {
        code += ch;
    }

    return code;*/

    sort(s.begin(), s.end());

    return s;
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    map<string, int> myMap;
    int count = 0;

    for (int windowSize = 1; windowSize < s.length(); windowSize++)
    {
        for (int i = 0; i < (s.length() - windowSize) + 1; i++)
        {
            string window = s.substr(i, windowSize);
            string hashCode = getCode(window);
            myMap[hashCode]++;
	    cout << "Window: " << window << " Code: " << hashCode << endl;
            for (int j = i+1; j < (s.length() - windowSize) + 1; j++)
            {
                string str = s.substr(j, windowSize);

                if (myMap.find(getCode(str)) != myMap.end())
		{
	    	    cout << "Str: " << str << " Code: " << getCode(str) << " Incre" << endl;
                    count++;
		}
            }

	    myMap.clear();
        }
    }

    return count;
}

int main()
{
	cout << sherlockAndAnagrams("anagram") << endl;
	return 0;
}
