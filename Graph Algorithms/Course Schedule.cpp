#include <bits/stdc++.h>
 
#define f(a,b,i) for(int i=a;i<b;i++)
#define g(a,b,i) for(int i=b-1;i>=a;i--)
#define int long long
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
const int INF = 1e17;
const int NINF = -1*(INF);

void solve() {
    int n,m; cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> in(n+1,0);

    f(0,m,i){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }

    vector<int> res;
    
    queue<int> q;
    f(1,n+1,i){
        if(in[i]==0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        res.pb(cur);
        q.pop();

        for(auto it: adj[cur]){
            in[it]--;
            if(in[it]==0){
                q.push(it);
            }
        }
    }

    if(res.size()!=n){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    for(auto it:res){
        cout<<it<<" ";
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