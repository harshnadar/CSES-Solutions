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

int dp[1000002];

vector<int> dig(int n){
    set<int> s;
    while(n){
        int r=n%10;
        s.insert(r);
        n/=10;
    }

    vector<int> v;
    for(auto it: s) if(it!=0) v.push_back(it);

    return v;
}

int func(int num){
    if(num==0) return 0;

    if(dp[num]!=-1) return dp[num];

    int ans=1e9;

    vector<int> d = dig(num);

    for(auto it: d){
        ans = min(ans, 1+func(num-it));
    }

    return dp[num]=ans;
}

void solve() {
    int n; cin>>n; 

    memset(dp,-1,sizeof dp);

    cout<<func(n);
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