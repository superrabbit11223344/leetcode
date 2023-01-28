#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.size() <= 1)
        return s.size();
    vector<int> dp(s.size());
    dp[0] = 1;
    int result = INT_MIN;
    unordered_map<char, int> map;
    map.insert({s[0], 0});

    int i;
    for (int j = 1; j < s.size(); j++)
    {
        if (map.find(s[j]) != map.end())
        {
            i = map[s[j]];
        }
        else
        {
            i = -1;
        }
        map[s[j]] = j;
        if (dp[j - 1] < j - i)
        {
            dp[j] = dp[j - 1] + 1;
        }
        else
        {
            dp[j] = j - i;
        }
        result = max(result, dp[j]);
    }
    return result;
}

int main()
{
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
}