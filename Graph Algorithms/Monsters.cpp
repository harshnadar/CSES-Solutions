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

int mon[1002][1002];
int n,m;
string adj[1002];

int travel[]={'D','R','L','U'};
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
char hp[1002][1002];
string path;

bool human_fill(int x, int y){
    queue<pi> q;

    q.push({x,y});
    int timer=1;
    int vis[n][m];
    memset(vis,false,sizeof vis);
    vis[x][y]=true;

    while(!q.empty()){
        int u=q.size();

        while(u--){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();

            if(curx==0 || curx==n-1 || cury==0 || cury==m-1){
                int j=0;
                while(1){
                    
                    path.push_back(hp[curx][cury]);
                
                    if(path.back() == 'L') cury++;
                    if(path.back() == 'R') cury--;
                    if(path.back() == 'U') curx++;
                    if(path.back() == 'D') curx--;
                    
                    if(curx == x && cury == y)
                    break;
                    j++;
                }
                return true;
            }

            f(0,4,k){
                int nx = curx+dx[k];
                int ny = cury+dy[k];

                if(nx<0 || ny<0 || nx>=n || ny>=m || adj[nx][ny]=='#' || vis[nx][ny]==true || (mon[nx][ny]<=timer)) continue;
                
                vis[nx][ny]=true;
                q.push({nx,ny});
                hp[nx][ny]=travel[k];
            }
        }
        timer++;
    }

    return false;
}

void monster_fill(){
    queue<pi> q;

    f(0,n,i){
        f(0,m,j){
            if(adj[i][j]=='M'){ mon[i][j]=0; q.push({i,j});}
        }
    }
    int timer=1;
    while(!q.empty()){
        int count=q.size();
        while(count--){
            int curx = q.front().first;
            int cury = q.front().second;

            q.pop();

            f(0,4,k){
                int nx = curx+dx[k];
                int ny = cury+dy[k];

                if(nx<0 || ny<0 || nx>=n || ny>=m || adj[nx][ny]=='#' || mon[nx][ny]!=-1) continue;

                mon[nx][ny]=timer;
                q.push({nx, ny});
            }
        }
        timer++;
    }
}

void solve() {
    cin>>n>>m;
    f(0,n,i) cin>>adj[i];
    memset(mon, -1,sizeof mon);
    monster_fill();

    int x,y;
    f(0,n,i){
        f(0,m,j){
            if(adj[i][j]!='#' && mon[i][j]==-1) mon[i][j]=1e9;
            if(adj[i][j]=='A'){ x=i,y=j; }
        }
    }

    if(x==0 || x==n-1 || y==0 || y==m-1){
        cout<<"YES\n";
        cout<<0<<endl;
        return;
    }

    if(human_fill(x,y)){
        cout<<"YES\n";
        cout<<path.size()<<endl;
        
        reverse(all(path));
        cout<<path<<endl;
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