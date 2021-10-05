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
 
int dp[502][502];
 
int func(int a, int b){
    if(a>b) swap(a,b);
    if(a==b) return 0;
 
    if(dp[a][b]!=-1) return dp[a][b];

    int ans=1e9;

    f(1,a,i){
        ans = min(ans, func(i,b)+func(a-i, b)+1);
    }
    f(1,b,i){
        ans = min(ans, func(a,i)+func(a,b-i)+1);
    }

    return dp[a][b]=ans;
}
 
void solve() {
    int a, b;
    cin>>a>>b;
 
    memset(dp,-1,sizeof dp);
 
    cout<<func(min(a,b), max(a,b));
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