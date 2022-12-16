#include <iostream>
#include <string>

using namespace std;

// 长按键入
bool isLongPressedName(string name, string typed)
{
    int i = 0, j = 0;
    while (i < name.size() && j < typed.size())
    {
        if (name[i] == typed[j])
        {
            j++;
            i++;
        }
        else
        {
            if (j == 0)
                return false;
            while (j < typed.size() && typed[j] == typed[j - 1])
                j++;
            if (name[i] == typed[j])
            {
                j++;
                i++;
            }
            else
                return false;
        }
    }
    if (i < name.size())
        return false;
    while (j < typed.size())
    {
        if (typed[j] == typed[j - 1])
            j++;
        else
            return false;
    }
    return true;
}

int main()
{
    string name = "alex";
    string typed = "aaleex";
    bool result = isLongPressedName(name, typed);
    cout << result << endl;
}