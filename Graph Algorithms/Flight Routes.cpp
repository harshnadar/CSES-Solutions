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

vector<pi> adj[100002];

void solve() {
    int n,m,k;
    cin>>n>>m>>k;

    f(0,m,i){
        int a,b,c;
        cin>>a>>b>>c;

        adj[a].push_back({b,c});
    }

    vector<int> ans;
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    vector<vector<int > > dist(n+1,vector<int>(k,1e18));

    dist[1][0]=0;
    // int j=0;
    pq.push({0,1});

    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_d = pq.top().first;

        pq.pop();

        if(cur_d>dist[cur][k-1]) continue;

        for(auto it: adj[cur]){
            int x = cur_d + it.second;
            int y = it.first;

            if(dist[y][k-1]>x){
                dist[y][k-1] = x;
                pq.push({dist[y][k-1],y});
                sort(dist[y].begin(), dist[y].end());
            }
        }
    }

    for(auto it: dist[n]){
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