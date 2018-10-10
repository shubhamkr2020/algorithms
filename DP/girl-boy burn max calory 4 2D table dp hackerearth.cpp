// https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/tutorial/
// Another variant question


// Problem Statement : You are given a 2-D matrix A of n rows and m columns where A[i][j] denotes the calories burnt. 
// Two persons, a boy and a girl, start from two corners of this matrix. The boy starts from cell (1,1) and needs to reach cell (n,m). 
// On the other hand, the girl starts from cell (n,1) and needs to reach (1,m). The boy can move right and down. The girl can move right and up. 
// As they visit a cell, the amount in the cell A[i][j] is added to their total of calories burnt. 
// You have to maximize the sum of total calories burnt by both of them under the condition that 
// they shall meet only in one cell and the cost of this cell shall not be included in either of their total.


// Solution :
// 1. Find the number of ways of meeting at i,j (here they can meet in two ways only for details see hackerearth link)
// 2. create 4 tables 
// 		1. cost for boy from 1,1 to i,j
// 		2. cost for boy from n,m to i,j
// 		3. cost for girl from n,1 to i,j
// 		4. cost for girl from i,j to 1,n
// 3. find the maximum of all the ways found in 1st step


#include <bits/stdc++.h>
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MAX 1005
int Boy1[MAX][MAX];
int Boy2[MAX][MAX];
int Girl1[MAX][MAX];
int Girl2[MAX][MAX];
using namespace std;
int main() {
    int N,M,ans,op1,op2;
    scanf("%d%d",&N,&M);
    int Workout[MAX][MAX];
    ans = 0;

    //Take input the calories burnt matrix
    F(i,1,N)
        F(j,1,M)
            scanf("%d",&Workout[i][j]);

    //Table for Boy's journey from start to meeting cell
    F(i,1,N)
        F(j,1,M)
            Boy1[i][j] = max(Boy1[i-1][j],Boy1[i][j-1]) + Workout[i][j];

    //Table for boy's journey from end to meet cell
    RF(i,N,1)
        RF(j,M,1)
            Boy2[i][j] = max(Boy2[i+1][j],Boy2[i][j+1]) + Workout[i][j];


    //Table for girl's journey from start to meeting cell
    RF(i,N,1)
        F(j,1,M)
            Girl1[i][j] = max(Girl1[i+1][j],Girl1[i][j-1]) + Workout[i][j];


    //Table for girl's journey from end to meeting cell
    F(i,1,N)
        RF(j,M,1)
            Girl2[i][j] = max(Girl2[i-1][j],Girl2[i][j+1]) + Workout[i][j];


    //Now iterate over all meeting positions (i,j)
    F(i,2,N-1)
    {
        F(j,2,M-1)
        {
            //For the option 1
            op1 = Boy1[i][j-1] + Boy2[i][j+1] + Girl1[i+1][j] + Girl2[i-1][j];

            //For the option 2
            op2 = Boy1[i-1][j] + Boy2[i+1][j] + Girl1[i][j-1] + Girl2[i][j+1];

            //Take the maximum of two options at each position
            ans = max(ans,max(op1,op2));
        }
    }

    printf("%d",ans);
    return 0;
}