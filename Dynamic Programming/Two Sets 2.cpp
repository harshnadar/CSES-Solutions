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
vector<int> nums;

int dp[502][250*501];
int n;

int func(int i, int sum){
    if(sum<0) return 0;
    if(sum==0) return 1;

    if(i>n) return 0;
    if(i==n) return 0;

    if(dp[i][sum]!=-1) return dp[i][sum];

    int ans=0;

    ans+=func(i+1,sum-nums[i]);
    ans+=func(i+1,sum);
    ans%=mod;

    return dp[i][sum]=ans;
}

void solve() {
    
    cin>>n;

    f(1,n+1,i){
        nums.pb(i);
    }

    int sum = accumulate(all(nums),(int)0);

    memset(dp,-1,sizeof dp);

    if(sum%2){
        cout<<0<<endl;
        return;
    }
    int ans = func(0,sum/2);

    ans = (ans*(mod+1)/2)%mod;
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