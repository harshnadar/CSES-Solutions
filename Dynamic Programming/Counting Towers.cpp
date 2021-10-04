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

int dp[N+1][2];

void init(){

    dp[0][0]=dp[0][1]=1;

    f(1,N+1,i){
        int op1 = (dp[i-1][1]+ dp[i-1][0])%mod;
        int op2 = (dp[i-1][0])%mod;
        int op3 = (2*dp[i-1][0])%mod;
        int op4 = (dp[i-1][1])%mod;

        dp[i][0] = (op1+op2+op3)%mod;
        dp[i][1] = (op1 + op4)%mod;
    }
    
}

void solve() {
    int n; cin>>n;

    cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
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
    init();
    cin>>t;
    while(t--){
        //solve();
        solve();
        //if(flag) return 0;
    }
}