/*
ID: musarra1
TASK: beads
LANG: C++
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back
#define ios ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void read()
{
    freopen("beads.in","r",stdin);
	  freopen("beads.out","w",stdout);
}

ll lcm(ll a,ll b)
{
    return (a/__gcd(a,b))*b;
}

ll binToDec(string s)
{
    ll decimal=0,p=0,n=s.size();
    for(ll i=n-1;i>=0;i--)
    {
        if(s[i]=='1')decimal+=(1<<p);
        p++;
    }
    return decimal;
}

ll digit_sum(ll i)
{
    string s=to_string(i);
    ll sm=0;
    for(ll i=0;i<s.size();++i)
    {
        sm+=s[i]-'0';
    }
    return sm;
}


void solve()
{
    read();
    int n; cin>>n; string s; cin>>s;
    s=" "+s+s+" ";
    int From_left[2*n+1][2];
    From_left[0][1]=From_left[0][0]=0;
    memset(From_left,0,sizeof From_left);
    for(int i=1;i<2*n+1;++i)
    {
        if(s[i]=='r')
        {
            From_left[i][0]=From_left[i-1][0]+1;
            From_left[i][1]=0;
        }
        else if(s[i]=='w')
        {
            From_left[i][0]=From_left[i-1][0]+1;
            From_left[i][1]=From_left[i-1][1]+1;
        }
        else if(s[i]=='b')
        {
            From_left[i][0]=0;
            From_left[i][1]=From_left[i-1][1]+1;
        }
    }
    int From_right[2*n+1][2];
    From_right[2*n+1][1]=From_right[2*n+1][0]=0;
    memset(From_right,0,sizeof From_right);
    for(int i=2*n;i>=1;--i)
    {
        if(s[i]=='r')
        {
            From_right[i][0]=From_right[i+1][0]+1;
            From_right[i][1]=0;
        }
        else if(s[i]=='w')
        {
            From_right[i][0]=From_right[i+1][0]+1;
            From_right[i][1]=From_right[i+1][1]+1;
        }
        else if(s[i]=='b')
        {
            From_right[i][0]=0;
            From_right[i][1]=From_right[i+1][1]+1;
        }
    }
    int mx=-1;
    for(int i=1;i<2*n+1;++i)
    {
        mx=max(mx,max(From_left[i][0],From_left[i][1])+max(From_right[i+1][0],From_right[i+1][1]));
    }
    cout<<min(mx,n)<<endl;

}


int main()
{
    ios
    ll t=1;
    //cin>>t;
    for(ll tc=1;tc<=t;++tc)
    {
       // cout<<"Case "<<tc<<": "<<endl;
        solve();

    }
    return 0;
}
