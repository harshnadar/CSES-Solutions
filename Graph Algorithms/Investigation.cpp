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

    vector<pi> adj[n+1];

    f(0,m,i){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    priority_queue<pi, vector<pi>, greater<pi> > pq;

    vector<int> dist(n+1, INF);
    vector<int> route(n+1);
    route[1]=1;
    vector<int> min_f(n+1);
    vector<int> max_f(n+1);

    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_d = pq.top().first;

        pq.pop();

        if(cur_d > dist[cur]) continue;

        for(auto it: adj[cur]){
            int x = it.first;
            int y = it.second + cur_d;

            if(y > dist[x]) continue;

            if(y==dist[x]){
                route[x]+=route[cur];
                route[x]%=mod;
                min_f[x] = min(min_f[cur]+1, min_f[x]);
                max_f[x] = max(max_f[cur]+1, max_f[x]);
            }

            if(y<dist[x]){
                dist[x] = y;
                route[x]=route[cur];

                min_f[x] = min_f[cur]+1;
                max_f[x] = max_f[cur]+1;
                pq.push({dist[x],x});
            }
        }
    }

    cout<<dist[n]<<" "<<route[n]<<" "<<min_f[n]<<" "<<max_f[n];
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