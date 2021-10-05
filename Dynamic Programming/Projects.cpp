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
 
int n;
vector<vector<int> > v;
vector<int> z;
 
int dp[200002];
 
int check(int i, int val){
 
    int lo=i+1;
    int hi = z.size()-1;
 
    while(lo<hi){
        int mid = (lo+hi)/2;
        if(z[mid]>val) hi=mid;
        else lo=mid+1;
    }
    return lo;
}
 
int func(int i){
    if(i>=n) return 0;
 
    if(dp[i]!=-1) return dp[i];
 
    int ind;
    ind = check(i,v[i][1]);
    
    if(ind<n && v[i][1]>=v[ind][0]) ind++;
 
    return dp[i]=max(v[i][2]+func(ind), func(i+1));
}
 
void solve() {
    cin>>n;
    f(0,n,i){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
 
    sort(all(v));
 
    for(auto it: v) z.pb(it[0]);
 
    memset(dp,-1,sizeof dp);
 
    cout<<func(0);
}
 
signed main(){
    FAST_IO
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t; t=1;
    
    // cin>>t;
    while(t--){
        //solve();
        solve();
        //if(flag) return 0;
    }
}