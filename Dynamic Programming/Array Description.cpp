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
const int N=1e5+10;
const int mod=1000000007;

void solve() {
    int n,m; cin>>n>>m;
    int a[n]; CIN(a,0,n)

    int dp[n+1][m+1];
    memset(dp,0,sizeof dp);

    if(a[0]){
        dp[1][a[0]]=1;
    }
    else{
        f(1,m+1,i){
            dp[1][i]=1;
        }
    }

    f(2,n+1,i){
        f(1,m+1,j){
            dp[i][j]=dp[i-1][j];

            if(j!=1) dp[i][j]+=dp[i-1][j-1];
            if(j!=m) dp[i][j]+=dp[i-1][j+1];
            dp[i][j]%=mod;
        }

        if(a[i-1]){
            f(0,m+1,j){
                if(j!=a[i-1]){
                    dp[i][j]=0;
                }
            }
        }
    }

    int ans=0;
    f(1,m+1,i) ans = (ans+dp[n][i])%mod;
    cout<<ans;
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