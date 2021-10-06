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
int n,m;
bool vis[100002];
int par[100002];
vector<int> ans;
int s, e;

bool dfs(int node, int p){
    vis[node] = true;
    par[node] = p;
    for(auto it: adj[node]){
        if(it == p) continue;
        if(vis[it]){
            s = it;
            e = node;
            return true;
        }
        else{
            if(dfs(it, node)) return true;
        }
    }

    return false;
}

void print_func(){
    int tmp = e;
    ans.pb(e);

    while(tmp!=s){
        ans.pb(par[tmp]);
        tmp = par[tmp];
    }

    ans.pb(e);

    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it<<" ";
    }
}

void solve() {
    
    cin>>n>>m;
    
    f(0,m,i){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int l=0;

    f(1,n+1,i){
        if(vis[i]==false && dfs(i,-1)){ l=1; break;}
    }

    if(l){
        print_func();
    }
    else{
        cout<<"IMPOSSIBLE\n";
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