/*
ID: musarra1
TASK: transform
LANG: C++
*/

#include <ext/rope>
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define ios ios::sync_with_stdio(false); cin.tie(NULL);

using namespace __gnu_cxx;
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int n;
char a[11][11],b[11][11],c[11][11],d[11][11];

void read()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
}

void deg90()
{
    for(int i=0;i<n/2;++i)
    {
        for(int j=i;j<n-i-1;++j)
        {
            char temp=a[i][j];
            a[i][j]=a[n-j-1][i];
            a[n-j-1][i]=a[n-i-1][n-j-1];
            a[n-i-1][n-j-1] = a[j][n-i-1];
            a[j][n-i-1]=temp;
        }
    }

}

bool check()
{
    int ok=1;
     for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j]!=c[i][j])
            {
                ok=0;
                break;
            }
        }
        if(ok==0)
            break;
    }
    if(ok) return 1;
    return 0;
}

void reflect()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=b[i][n-j-1];
        }
    }
}


void solve()
{
    read();
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j];
            b[i][j]=a[i][j];
            d[i][j]=a[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>c[i][j];
        }
    }
    deg90();
    if(check())
    {
        cout<<1<<endl;
    }
    else
    {
        deg90();
        if(check())
        {
            cout<<2<<endl;
        }
        else
        {
            deg90();
            if(check())
                cout<<3<<endl;
            else
            {
                 for(int i=0;i<n;++i)
                {
                    for(int j=0;j<n;++j)
                    {
                        a[i][j]=d[i][j];
                    }
                }
                reflect();
                if(check())
                    cout<<4<<endl;
                else
                {
                    deg90();
                    if(check()) cout<<5<<endl;
                    else
                    {
                        deg90();
                        if(check()) cout<<5<<endl;
                        else
                        {
                            deg90();
                            if(check()) cout<<5<<endl;
                            else
                            {
                                int ok = 1;
                                for(int i=0;i<n;++i)
                                {
                                    for(int j=0;j<n;++j)
                                    {
                                        if(d[i][j]!=c[i][j])
                                        {
                                            ok=0;
                                            break;
                                        }
                                        if(ok==0) break;
                                    }
                                }
                                if(ok)
                                    cout<<6<<endl;
                                else
                                    cout<<7<<endl;
                            }
                        }
                    }
                }


            }
        }
    }

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
