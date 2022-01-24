https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/C2
#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

int C[50];
vi adjList[50];
int K,dp[60][60][3];
int dp2[60][60][3];
int doDFS(int u,int p) {
    int i,j,k;
    vi c;
    for (int v: adjList[u]) {
        if (v != p) c.pb(v),doDFS(v,u);
    }
    for (i = 0; i < c.size(); i++) {
        int v = c[i];
        if (i == 0) {
            for (j = 0; j <= K; j++) {
                dp2[0][j][0] = max(dp[v][j][0],dp[v][j][2]);
                dp2[0][j][1] = C[u]+dp[v][j][1];
                dp2[0][j][2] = -1e9;
                if (dp2[i][j][0] < 0) dp2[i][j][0] = -1e9;
                if (dp2[i][j][1] < 0) dp2[i][j][1] = -1e9;
                if (dp2[i][j][2] < 0) dp2[i][j][2] = -1e9;
            }
        }
        else {
            for (j = 0; j <= K; j++) {
                dp2[i][j][0] = dp2[i][j][1] = dp2[i][j][2] = -1e9;
                for (k = 0; k <= j; k++) {
                    dp2[i][j][0] = max(dp2[i][j][0],dp2[i-1][k][0]+max(dp[v][j-k][0],dp[v][j-k][2]));
                    dp2[i][j][1] = max(dp2[i][j][1],dp2[i-1][k][1]+max(dp[v][j-k][0],dp[v][j-k][2]));
                    dp2[i][j][1] = max(dp2[i][j][1],dp2[i-1][k][0]+C[u]+dp[v][j-k][1]);
                    dp2[i][j][2] = max(dp2[i][j][2],dp2[i-1][k][2]+max(dp[v][j-k][0],dp[v][j-k][2]));
                    dp2[i][j][2] = max(dp2[i][j][2],dp2[i-1][k][1]+dp[v][j-k+1][1]);
                    dp2[i][j][1] = max(dp2[i][j][1],dp2[i-1][k][2]+dp[v][j-k][1]);
                }
                if (dp2[i][j][0] < 0) dp2[i][j][0] = -1e9;
                if (dp2[i][j][1] < 0) dp2[i][j][1] = -1e9;
                if (dp2[i][j][2] < 0) dp2[i][j][2] = -1e9;
            }
        }
    }
    if (c.empty()) {
        for (i = 0; i <= K; i++) {
            dp[u][i][0] = (i == 0) ? 0:C[u];
            dp[u][i][1] = dp[u][i][2] = (i == 0) ? -1e9:C[u];
        }
    }
    else {
        for (i = 0; i <= K; i++) {
            dp[u][i][2] = dp2[c.size()-1][i][2];
            dp[u][i][1] = dp2[c.size()-1][i][1];
            dp[u][i][0] = dp2[c.size()-1][i][0];
            dp[u][i][2] = max(dp[u][i][2],dp2[c.size()-1][i][1]);
            if (i > 0) {
                dp[u][i][2] = max(dp[u][i][2],dp2[c.size()-1][i-1][0]+C[u]);
                dp[u][i][1] = max(dp[u][i][1],dp2[c.size()-1][i-1][0]+C[u]);
            }
            dp[u][i][0] = max(dp[u][i][0],dp[u][i][2]);
        }
    }
    return 0;
}
int main() {
    freopen("C2.txt","r",stdin);
    freopen("C2out.txt","w",stdout);
    int i;
    int t,T,N;
    int u,v;
    scanf("%d",&T);
    for (t = 1; t <= T; t++) {
        scanf("%d %d",&N,&K);
        for (i = 0; i < N; i++) scanf("%d",&C[i]);
        for (i = 0; i < N-1; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        if (K == 0) printf("Case #%d: %d\n",t,C[0]);
        else {
            doDFS(0,-1);
            printf("Case #%d: %d\n",t,dp[0][K][2]);
        }

        memset(dp,0,sizeof(dp));
        for (i = 0; i < N; i++) adjList[i].clear();
    }

    return 0;
}
