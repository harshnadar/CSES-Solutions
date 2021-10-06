#include <bits/stdc++.h>
 
#define f(a,b,i) for(int i=a;i<b;i++)
#define g(a,b,i) for(int i=b-1;i>=a;i--)
// #define int long long
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

int n,m;
string adj[1002];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char travel[] = {'R', 'L', 'D', 'U'};
vector<vector<bool> > vis;
vector<vector<char> > br;
string path;

bool isValid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    if(adj[i][j]=='#' || vis[i][j]==true) return false;
    return true;
}

bool bfs(int x, int y){
    queue<pair<int,int> > q;
    q.push({x , y});
    vis[x][y] = true;
    
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        if(adj[a][b] == 'B'){
            while(1){
                path.push_back(br[a][b]);
            
                if(path.back() == 'L') b++;
                if(path.back() == 'R') b--;
                if(path.back() == 'U') a++;
                if(path.back() == 'D') a--;
                
                if(a == x && b == y)
                break;
            }
            return true;
        }
        
        f(0,4,k){
            int nx = a+dx[k];
            int ny = b+dy[k];
 
            if(isValid(nx,ny)){
                br[nx][ny]=travel[k];
 
                q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
        
    }
    
    return false;
}


void solve() {
    cin>>n>>m;
    f(0,n,i) cin>>adj[i];

    vis.resize(n, vector<bool>(m, false));
    br.resize(n, vector<char>(m,'*'));
    int x,y;
    f(0,n,i){
        f(0,m,j){
            if(adj[i][j]=='A') x=i,y=j;
        }
    }

    if(bfs(x,y)==true){
        cout<<"YES\n";
        cout<<path.size()<<endl;
        reverse(all(path));
        cout<<path;
        return;
    }

    cout<<"NO\n";
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