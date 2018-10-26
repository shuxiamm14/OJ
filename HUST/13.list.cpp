#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#define maxn 1000
int a[maxn];
typedef struct node
{
    int data;
    struct node *next;
}LinkedList;
  
int cmp(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}
  
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int i,j;
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        qsort(a,n,sizeof(int),cmp);
  
        LinkedList* head=NULL;
        struct node* cur;
        struct node* prev;
  
        cur=(struct node*)malloc(sizeof(struct node));
        if(cur!=NULL)
        {
            cur->next=NULL;
            cur->data=a[0];
            head=cur;
            prev=cur;
        }
        for(i=1;i<n;i++)
        {
            cur=(struct node*)malloc(sizeof(struct node));
            cur->data=a[i];
            cur->next=NULL;
            prev->next=cur;
            prev=cur;
        }
        cur=head;
        while(cur!=NULL)
        {
            if(cur==head)printf("%d",cur->data);
            else printf(" %d",cur->data);
            cur=cur->next;
        }
        printf("\n");
    }
    return 0;
}