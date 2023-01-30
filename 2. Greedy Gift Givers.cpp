/*
ID: musarra1
TASK: gift1
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
    freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
}

void solve()
{
    read();
    int n,give,friends,cnt; cin>>n;
    unordered_map<string,int> umap;
    unordered_map<string,int>:: iterator ip;
    string s,p;
    vector<string> v;
    for(int i=0;i<n;++i)
    cin>>s,umap.insert(make_pair(s,0)),v.push_back(s);

    while(n--)
    {
        cin>>s>>give>>cnt;
        friends=cnt;
        ip=umap.find(s);
        if(friends>0)
            ip->second+=(-give+(give%friends));
        while(cnt--)
        {
            cin>>p;
            ip=umap.find(p);
            if(friends!=0)
                ip->second+=(give/friends);
        }
    }
    for(string a:v)
    {
        ip=umap.find(a);
        cout<<ip->first<<" "<<ip->second<<endl;
    }

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
