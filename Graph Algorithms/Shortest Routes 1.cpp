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

void solve() {
    int n,m; cin>>n>>m;
    vector<pair<int, int> > adj[n+1];

    f(0,m,i){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        // adj[b].push_back({a,w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    vector<int> dist(n+1, (int)1e18);

    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_d = pq.top().first;

        pq.pop();

        if(dist[cur]<cur_d) continue;

        for(auto it: adj[cur]){
            int x = it.second + cur_d;
            int y = it.first;

            if(dist[y]>=x){
                dist[y]=x;
                pq.push({dist[y],y});
            }
        }
    }

    f(1,n+1,i) cout<<dist[i]<<" ";
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