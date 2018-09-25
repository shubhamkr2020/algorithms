
// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/setting-the-alarm/editorial/
// use hPlus, hMinus, mPlus and mMinnus to solve different questions...

#include <bits/stdc++.h>
using namespace std;

int visit[13][62][3], level[13][62][3];
queue< pair< pair<int, int>, int> > Q;

void hPlus(int hh, int mm, int f)
{
    hh++;

    if(hh==12)
        f ^= 1;
    if(hh>12)
        hh = 1;

    if(!visit[hh][mm][f])
        Q.push(make_pair(make_pair(hh, mm), f));
}

void hMinus(int hh, int mm, int f)
{
    hh--;

    if(hh==11)
        f ^= 1;
    if(hh<1)
        hh = 12;

    if(!visit[hh][mm][f])
        Q.push(make_pair(make_pair(hh, mm), f));
}

void mPlus(int hh, int mm, int f)
{
    mm++;

    if(mm<=59)
    {
        if(!visit[hh][mm][f])
            Q.push(make_pair(make_pair(hh, mm), f));
    }
    else
    {
        mm = 0;
        hPlus(hh, mm, f);
    }
}

void mMinus(int hh, int mm, int f)
{
    mm--;

    if(mm>=0)
    {
        if(!visit[hh][mm][f])
            Q.push(make_pair(make_pair(hh, mm), f));
    }
    else
    {
        mm = 59;
        hMinus(hh, mm, f);
    }
}

void hashx(int hh, int mm, int f)
{
    f ^= 1;

    if(!visit[hh][mm][f])
        Q.push(make_pair(make_pair(hh, mm), f));
}

int solve(int hh1, int mm1, int f1, int hh2, int mm2, int f2)
{
    memset(visit, 0, sizeof(visit));

    int step = 0;
    Q.push(make_pair(make_pair(hh1, mm1), f1));

    while(!Q.empty())
    {
        int k = Q.size();

        for(int i=1; i<=k; i++)
        {
            pair< pair<int, int>, int > x = Q.front();
            Q.pop();
            int hh = x.first.first, mm = x.first.second, f = x.second;

            if(visit[hh][mm][f])
                continue;

            visit[hh][mm][f] = 1;
            level[hh][mm][f] = step;

            hPlus(hh, mm, f);
            hMinus(hh, mm, f);
            mPlus(hh, mm, f);
            mMinus(hh, mm, f);
            hashx(hh, mm, f);
        }

        step++;
    }

    return level[hh2][mm2][f2];
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        char m1[5], m2[5];
        int hh1, mm1, hh2, mm2;
        scanf("%d:%d %s %d:%d %s", &hh1, &mm1, m1, &hh2, &mm2, m2);

        int f1 = 0, f2 = 0;

        if(strcmp(m1, "pm")==0)
            f1  = 1;
        if(strcmp(m2, "pm")==0)
            f2 = 1;

        cout << solve(hh1, mm1, f1, hh2, mm2, f2) << endl;
    }

    return 0;
}