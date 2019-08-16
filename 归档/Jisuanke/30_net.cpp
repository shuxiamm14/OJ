//无脑博士的试管
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>

using namespace std;

int A, B, C;
bool vis[25][25][25];

struct node{
    int a,b,c;
}pre,nxt;

queue<node>Q;

void solve(){

    pre.a = 0, pre.b = 0, pre.c = C;
    while( !Q.empty() ) Q.pop();
    Q.push( pre );
    vis[0][0][C] = true;
    while( !Q.empty() ){
        pre = Q.front(); Q.pop();

        int a = pre.a, b = pre.b, c = pre.c;
        if( a > 0 ){
            if( b < B ){
                nxt.a = a-min(a,(B-b));
                nxt.b = b+min(a,(B-b));
                nxt.c = c;
                if( !vis[nxt.a][nxt.b][nxt.c] )
                    Q.push( nxt ), vis[nxt.a][nxt.b][nxt.c] = true;
            }
            if( c < C ){
                nxt.a = a-min(a,(C-c));
                nxt.b = b;
                nxt.c = c+min(a,(C-c));
                if( !vis[nxt.a][nxt.b][nxt.c] )
                    Q.push( nxt ), vis[nxt.a][nxt.b][nxt.c] = true;
            }
        }
        if( b > 0 ){
            if( a < A ){
                nxt.a = a+min(b,(A-a));
                nxt.b = b-min(b,(A-a));
                nxt.c = c;
                if( !vis[nxt.a][nxt.b][nxt.c] )
                    Q.push( nxt ), vis[nxt.a][nxt.b][nxt.c] = true;
            }
            if( c < C ){
                nxt.a = a;
                nxt.b = b-min(b,(C-c));
                nxt.c = c+min(b,(C-c));
                if( !vis[nxt.a][nxt.b][nxt.c] )
                    Q.push( nxt ), vis[nxt.a][nxt.b][nxt.c] = true;
            }
        }
        if( c > 0 ){
            if( a < A ){
                nxt.a = a+min(c,(A-a));
                nxt.b = b;
                nxt.c = c-min(c,(A-a));
                if( !vis[nxt.a][nxt.b][nxt.c] )
                    Q.push( nxt ), vis[nxt.a][nxt.b][nxt.c] = true;
            }
            if( b < B ){
                nxt.a = a;
                nxt.b = b+min(c,(B-b));
                nxt.c = c-min(c,(B-b));
                if( !vis[nxt.a][nxt.b][nxt.c] )
                    Q.push( nxt ), vis[nxt.a][nxt.b][nxt.c] = true;
            }
        }
    }
}
int main(){
    while( scanf("%d%d%d",&A,&B,&C) != EOF){
        memset( vis, 0, sizeof(vis) );
        solve();
        bool tmp[25];
        memset(tmp,0,sizeof(tmp));
        for(int b = 0; b <= B; b++)
            for(int c = 0; c <= C; c++)
                tmp[c] |= vis[0][b][c];
        bool flag = false;
        for(int i = 0; i <= C; i++)
            if( tmp[i] ){
                if( !flag ) printf("%d",i), flag =true;
                else printf(" %d",i);
            }
        puts("");
    }
    return 0;
}
