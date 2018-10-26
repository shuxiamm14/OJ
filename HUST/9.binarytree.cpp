#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <stack>
using namespace std;
struct node
{
    char value;
    node *left;
    node *right;
};

string preStr;
string bewStr;

void prePrint(node *rt)
{
    if (rt == NULL)
        return;
    cout << rt->value;
    prePrint(rt->left);
    prePrint(rt->right);
}

void bewPrint(node *rt)
{
    if (rt == NULL)
        return;
    bewPrint(rt->left);
    cout << rt->value;
    bewPrint(rt->right);
}

void afterPrint(node *rt)
{
    if (rt == NULL)
        return;
    afterPrint(rt->left);
    afterPrint(rt->right);
    cout << rt->value;
}

node *insertNode(node *rt, char value)
{
    if (rt == NULL)
    {
        rt = new node();
        rt->value = value;
        return rt;
    }
    //cout <<rt->value <<" " <<value <<endl;
    int standFlag = 0, curr = 0;
    for (int i = 0; i < bewStr.size(); i++)
    {
        if (bewStr[i] == value)
            curr = i;
        else if (bewStr[i] == rt->value)
        {
            standFlag = i;
        }
    }
    // cout <<"curr: " <<curr <<" stad: " <<standFlag <<endl;
    if (curr < standFlag)
    {
        rt->left = insertNode(rt->left, value); //cout <<"insertLeft" <<endl;
    }
    else
    {
        rt->right = insertNode(rt->right, value); //cout <<"insertRight" <<endl;
    }
    return rt;
}

int main()
{
    while (cin >> preStr >> bewStr)
    {
        if (preStr.size() != bewStr.size())
            continue;
        node *root = new node();
        root->value = preStr[0];
        for (int i = 1; i < preStr.size(); i++)
            root = insertNode(root, preStr[i]);
        //        bewPrint(root);
        //        cout <<endl;
        afterPrint(root);
        cout << endl;
    }
    return 0;
}
