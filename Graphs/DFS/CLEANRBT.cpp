#include <limits.h>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef struct point {
    int x;
    int y;
}point;

using namespace std;
vector<int> vec1[25];
point arr[25];
char vec[25][25];
int d[405][405];
int visited[25];
int c,h,w,min1,ver,num;

void dfs(int,int,int);

int main() {
    int i,j;
    min1=100000;
    for(i=0;i<405;i++) {
        for(j=0;j<405;j++)
            d[i][j]=100000;
    }
    int st,ed,k,v=1;
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++) scanf("%s",vec[i]);
    for(i=0;i<h;i++) {
        for(j=0;j<w;j++) {
            if(vec[i][j]=='*') {
                arr[v].x=i;
                arr[v].y=j;
                v++;
            }
        }
    }
    num=v;
    for(i=0;i<h;i++) {
        for(j=0;j<w;j++) {
            if(vec[i][j]=='o') {
                st=i;
                ed=j;
                break;
            }
        }
    }
    arr[0].x=st;
    arr[0].y=ed;
    ver=0;
    for(i=0;i<h;i++) {
        for(j=0;j<w;j++) {
            d[ver][ver]=0;
            if((i-1)>=0 && vec[i-1][j]!='x')
            d[ver][ver-w]=1;
            if(i+1<h && vec[i+1][j]!='x')
            d[ver][ver+w]=1;
            if(j+1<w && vec[i][j+1]!='x')
            d[ver][ver+1]=1;
            if(j-1>=0 && vec[i][j-1]!='x')
            d[ver][ver-1]=1;
            ver++;
        }
    }
    for(k=0;k<ver;k++) {
        for(i=0;i<ver;i++)  {
            for(j=0;j<ver;j++) {
                if((d[i][k]+d[k][j])<d[i][j])
                d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
    
    for(i=0;i<v;i++) {
        for(j=0;j<v;j++) {
            if(i!=j)
            vec1[i].push_back(j);
        }
    }
    dfs(0,0,1);
    if(min1==100000)
    printf("-1\n");
    else
    printf("%d\n",min1);
    return 0;
}

void dfs(int v,int sum,int ct) {
    int i,x1;
    if(ct==num) {
        if(min1>sum)
        min1=sum;
        return;
    }
    visited[v]=1;
    for(i=0;i<vec1[v].size();i++) {
        x1=vec1[v][i];
        if(visited[x1]==0) {
            dfs(x1,sum+d[arr[v].x*w+arr[v].y][arr[x1].x*w+arr[x1].y],ct+1);
            visited[x1]=0;
        }
    }
}