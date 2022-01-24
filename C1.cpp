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
int dp[50];
int doDFS(int u,int p) {
    dp[u] = C[u];
    for (int v: adjList[u]) {
        if (v != p) {
            doDFS(v,u);
            dp[u] = max(dp[u],dp[v]+C[u]);
        }
    }
    return 0;
}
int main() {
    freopen("C1.txt","r",stdin);
    freopen("C1out.txt","w",stdout);
    int i;
    int t,T,N;
    int u,v;
    scanf("%d",&T);
    for (t = 1; t <= T; t++) {
        scanf("%d",&N);
        for (i = 0; i < N; i++) scanf("%d",&C[i]);
        for (i = 0; i < N-1; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        int ans = C[0];
        vi vv;
        doDFS(0,-1);
        for (int v: adjList[0]) vv.pb(dp[v]);
        sort(vv.begin(),vv.end(),greater<int>());
        for (i = 0; i < min(2,(int) vv.size()); i++) ans += vv[i];
        printf("Case #%d: %d\n",t,ans);
        for (i = 0; i < N; i++) adjList[i].clear();
    }

    return 0;
}
