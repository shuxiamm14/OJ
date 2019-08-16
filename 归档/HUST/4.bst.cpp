#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <cstring>
#define N 200
using namespace std;
struct Node
{
    int val;
    Node *left = NULL;
    Node *right = NULL;
};
void buildTree(Node *&r, int a)
{
    if (r == NULL)
    {
        r = new Node;
        r->left = r->right = NULL;
        r->val = a;
        cout << "-1" << endl;
    }
    else
    {
        if (a < r->val)
        {
            if (r->left == NULL)
            {
                Node *tmp = new Node; //左子树为空，就申请一个节点挂上去，
                tmp->left = tmp->right = NULL;
                tmp->val = a;
                r->left = tmp;
                cout << r->val << endl;
            }
            else
            {
                buildTree(r->left, a);
            }
        }
        else
        {
            if (r->right == NULL)
            {
                Node *tmp = new Node;
                tmp->left = tmp->right = NULL;
                tmp->val = a;
                r->right = tmp;
                cout << r->val << endl;
            }
            else
                buildTree(r->right, a);
        }
    }
}

int main()
{
    int n;
    int a;
    while (cin >> n)
    {
        Node *root = NULL;
        while (n--)
        {
            cin >> a;
            buildTree(root, a);
        }
    }
}
