/*
ID: musarra1
TASK: friday
LANG: C++
*/
#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define endl '\n'
#define ll long long
#define pb push_back
#define ios ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void read()
{
    freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
}

bool leapYear(int year)
{
    return (year%400==0 or (year%4==0 and year%100));
}


void solve()
{
    read();
    int n; cin>>n;
    int endyear=1900+n-1,totalDays=0;
    n=1900;
    int freq[7]={0,0,0,0,0,0,0};
    while(n<=endyear)
    {
        for(int i=1;i<=12;++i)
        {
            if(i==2)
            {
                if(leapYear(n))
                    freq[(totalDays+14)%7]++,totalDays+=29;
                else
                    freq[(totalDays+14)%7]++,totalDays+=28;
            }
            else if(i==4 or i==6 or i==9 or i==11)
                freq[(totalDays+14)%7]++,totalDays+=30;
            else
                freq[(totalDays+14)%7]++,totalDays+=31;
        }
        ++n;
    }
    for(int i=0;i<6;++i)
    {
        cout<<freq[i]<<" ";
    }
    cout<<freq[6]<<endl;
}


int main()
{
    ios
    ll t=1;
    //cin>>t;
    while(t--)
    {
        //cout<<"Case "<<tc<<": "<<endl;
        solve();

    }
    return 0;
}
