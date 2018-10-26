#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        if (s[s.size() - 1] == '.')
            cout << s.size() - 1 << endl;
        else
            cout << s.size() << " ";
    }
    return 0;
}