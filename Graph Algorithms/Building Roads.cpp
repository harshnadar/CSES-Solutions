#include <bits/stdc++.h>
 
#define f(a,b,i) for(int i=a;i<b;i++)
#define g(a,b,i) for(int i=b-1;i>=a;i--)
// #define int long long
#define pb push_back
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define mp make_pair
#define CIN(a,x,y) for(int i=x;i<y;i++) cin>>a[i];
#define float double
#define M 1000000007
#define MAX INT_MAX
#define MIN INT_MIN
#define all(a) (a).begin(), (a).end()
//#define N 1010
// #define mp make_pair
using namespace std;
#define fi first
#define sp(n) setprecision(n)
#define se second
#define in insert
#define lb lower_bound
#define ub upper_bound
#define pi pair<int,int>
#define bp(n) __builtin_popcount(n)
#define MAXN 200005
const int N=1e6;
const int mod=1000000007;

vector<int> adj[100002];
int par[100002];

vector<bool> vis;

int find(int a){
    if(par[a]==a) return a;

    return par[a]=find(par[a]);
}

void uni(int a, int b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    par[b]=a;
}

void dfs(int node){
    vis[node]=true;

    for(auto it: adj[node]){
        if(!vis[it])
            dfs(it);
    }
}

void solve() {
    int n,m; cin>>n>>m;
    f(0,n+1,i) par[i]=i;

    f(0,m,i){
        int a,b; cin>>a>>b;
        uni(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis.resize(n+1, false);

    int c=0;
    f(1,n+1,i){
        if(vis[i]!=true){
            dfs(i);
            vis[i]=true;
            c++;
        }
    }

    cout<<c-1<<endl;

    set<int> s;
    f(1,n+1,i){
        s.insert(find(par[i]));
    }

    vector<int> v(all(s));

    int x=v.size();
    f(0,x-1,i){
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
}
 
signed main(){
    FAST_IO
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
    int t; t=1;
    
    // cin>>t;
    while(t--){
        //solve();
        solve();
        //if(flag) return 0;
    }
}