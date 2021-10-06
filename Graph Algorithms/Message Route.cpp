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
vector<int> par;
vector<int> ans;

void bfs(int node){
    queue<int> q;
    q.push(node);
    par[node]=0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur==n){
            while(cur!=-1 && par[cur]!=0){
                ans.pb(cur);
                cur = par[cur];
            }
            return;
        }

        for(auto it: adj[cur]){
            if(par[it]==-1){
                q.push(it);
                par[it]=cur;
            }
            
        }
    }
    return;
}

void solve() {
    
    cin>>n>>m;
    
    f(0,m,i){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    par.resize(n+10,-1);

    bfs(1);

    if(par[n]!=-1){
        cout<<ans.size()+1<<endl;
        cout<<1<<" ";
        reverse(all(ans));
        for(auto it: ans) cout<<it<<" ";
        return;
    }
    
    cout<<"IMPOSSIBLE\n";
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