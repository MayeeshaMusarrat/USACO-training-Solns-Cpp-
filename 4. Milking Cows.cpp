/*
ID: musarra1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back
#define ios ios::sync_with_stdio(false); cin.tie(NULL);
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

const int MX = 1e7;
bool isPrime[MX];
vector<int> listOfPrimes;
map<int,int> factors;

void sieve()
{
    memset(isPrime,true,sizeof isPrime);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=sqrt(MX);++i)
    {
        if(isPrime[i])
        {
            for(int j=i;j<=MX;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    listOfPrimes.push_back(2);
    for(int i=3;i<=MX;i+=2)
        listOfPrimes.push_back(i);
}
void primeFactorize(int n)
{

    while(n%2==0)
    {
        n/=2;
        factors[2]++;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0)
        {
            n/=i;
            factors[i]++;
        }
    }
    if(n>2)
    {
        factors[n]++;
    }

}



void read()
{
    freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
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
    int n; cin>>n;
    int a,b;
    vector<pair<ll,ll>> v(n);
    vector<ll> max_short,max_long;

    for(int i=0;i<n;++i)
    {
        cin>>a>>b;
        v[i]={a,b};
    }
    sort(v.begin(),v.end());
    ll start=v[0].first,endd=v[0].second;
    max_long.push_back(endd-start);
    max_short.push_back(0);
    //debug(v);

    for(int i=0;i<n;++i)
    {
        if(i==n-1)
        {
            if(v[i].first>endd)
            {
                max_short.push_back(v[i].first-endd);
                max_long.push_back(v[i].second-v[i].first);
                max_long.push_back(endd-start);
            }
            else if(v[i].first<=endd)
            {
                max_long.push_back(max(v[i].second-start,endd-start));
            }
        }
        else if(v[i+1].first>endd) //no overlap
        {
            max_short.push_back(v[i+1].first-endd);
            max_long.push_back(endd-start);
            start=v[i+1].first;
            endd=v[i+1].second;
        }
        else if(v[i+1].second>endd)
        {
            endd=max(v[i+1].second,v[i].second);
        }
    }
    //debug(max_short);
    ll mx1=*max_element(max_long.begin(),max_long.end());
    ll mx2=*max_element(max_short.begin(),max_short.end());
    cout<<mx1<<" "<<mx2<<endl;

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
