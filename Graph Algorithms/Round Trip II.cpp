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

int n,m;
vector<set<int> > adj;
vector<bool> flag;
vector<int> ans;
vector<int> vis;
stack<int> st;

bool dfs(int src){
    st.push(src);
    vis[src]=true;
    flag[src]=true;

    for(auto it: adj[src]){
        if(!vis[it]){
            if(dfs(it)) return true;
        }
        if(flag[it]){
            st.push(it);
            return true;
        }
    }

    st.pop();
    flag[src]=false;
    return false;
}

void solve() {
    cin>>n>>m;
    vis.resize(n+1,false);
    flag.resize(n+1,false);
    adj.resize(n+1);

    f(0,m,i){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
    }

    f(1,n+1,i){
        if(!vis[i]){
            if(dfs(i)) break;
        }
    }

    if(st.empty()){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    int tmp = st.top();

    while(!st.empty()){
        ans.pb(st.top());
        st.pop();
        if(tmp == ans.back() && ans.size()!=1){
            break;
        }
    }
    reverse(all(ans));

    cout<<ans.size()<<endl;
    for(auto it: ans){
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