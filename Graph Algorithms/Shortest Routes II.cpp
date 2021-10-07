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
 
vector<vector<int> > graph;
int n,m,q;
 
vector<vector<int> > floyd(){
    vector<vector<int> > dist(all(graph));
 
    f(1,n+1,k){
        f(1,n+1,i){
            f(1,n+1,j){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                
            }
        }
    }
 
    return dist;
}
 
void solve() {
    cin>>n>>m>>q;
    graph.resize(n+1,vector<int>(n+1, (int)1e18));
 
    f(0,m,i){
        int a,b,c;
        cin>>a>>b>>c;
        if(graph[a][b]>c){
            graph[a][b]=c;
            graph[b][a]=c;
        }
    }
 
    f(0,n+1,i){
        f(0,n+1,j){
            if(i==j){
                graph[i][j]=0;
            }
        }
    }
 
    vector<vector<int> > dist = floyd();
 
    while(q--){
        int a,b; cin>>a>>b;
        if(dist[a][b]>1e17) {cout<<-1<<endl; continue;}
        cout<<dist[a][b]<<endl;
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