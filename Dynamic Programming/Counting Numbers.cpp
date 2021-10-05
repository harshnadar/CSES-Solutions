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

int dp[20][10][2][2];

int func(string& num, int n, int x, bool lead_zero, bool tight){
    if(n==0) return 1;

    if(dp[n][x][lead_zero][tight]!=-1) return dp[n][x][lead_zero][tight];

    int lb = 0;
    int ub = tight?(num[num.size()-n]-'0'):9;

    int ans=0;

    f(lb, ub+1, dig){
        if(dig==x && lead_zero==0) continue;

        ans+= func(num, n-1, dig, (lead_zero&(dig==0)), tight&(dig==ub));
    }

    return dp[n][x][lead_zero][tight] = ans;
}

void solve() {
    int a,b;
    cin>>a>>b;

    string A = to_string(a-1);
    string B = to_string(b);

    memset(dp,-1,sizeof dp);

    int ans1 = func(A, A.size(), -1, 1, 1);

    memset(dp,-1,sizeof dp);

    int ans2 = func(B, B.size(), -1, 1, 1);

    cout<<ans2-ans1<<endl;
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