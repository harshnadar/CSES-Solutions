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

vector<int> bellman(int n, int src, vector<vector<int> >& edges){
    vector<int> dist(n+1, INF);
    dist[src]=0;
    f(0,n-1,i){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            

            if(dist[u]!=INF and dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }

    f(0,n-1,i)
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
 
        if(dist[u]!=INF and dist[u]+wt < dist[v]){
            dist[v]=NINF;
        }

    }

    return dist;
}
 
void solve() {
    int n,m; cin>>n>>m;

    vector<vector<int> > edges;
    f(0,m,i){
        int a,b,c; cin>>a>>b>>c;
        edges.push_back({a,b,-1*c});
        
    }

    vector<int> dist = bellman(n,1,edges);

    if(dist[n]==NINF){
        cout<<-1<<endl;
        return;
    }

    cout<<(-1*dist[n])<<endl;
   

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