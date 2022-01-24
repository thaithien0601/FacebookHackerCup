//https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B
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

char grid[50][50];
set<vpii> S;
int main() {
    freopen("B.txt","r",stdin);
    freopen("Bout.txt","w",stdout);
    int i,j;
    int t,T,N;
    scanf("%d",&T);
    for (t = 1; t <= T; t++) {
        scanf("%d",&N);
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) scanf(" %c",&grid[i][j]);
        }

        int best = 1e9;
        S.clear();
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (grid[i][j] == 'O') break;
            }
            if (j < N) continue;
            vpii v;
            for (j = 0; j < N; j++) {
                if (grid[i][j] == '.') v.pb(mp(i,j));
            }
            if (v.size() < best) best = v.size(),S.clear();
            if (v.size() == best) S.insert(v);
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (grid[j][i] == 'O') break;
            }
            if (j < N) continue;
            vpii v;
            for (j = 0; j < N; j++) {
                if (grid[j][i] == '.') v.pb(mp(j,i));
            }
            if (v.size() < best) best = v.size(),S.clear();
            if (v.size() == best) S.insert(v);
        }
        if (best == 1e9) printf("Case #%d: Impossible\n",t);
        else printf("Case #%d: %d %d\n",t,best,S.size());
    }

    return 0;
}
