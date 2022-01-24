//https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1
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

char s[101];
int vowel(char c) {
    return (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');
}
int main() {
    freopen("A1.txt","r",stdin);
    freopen("A1out.txt","w",stdout);
    int i,j;
    int T,t;
    scanf("%d",&T);
    for (t = 1; t <= T; t++) {
        scanf("%s",s);

        int l = strlen(s),ans = 1e9;
        for (i = 0; i < 26; i++) {
            int x = 0;
            for (j = 0; j < l; j++) {
                if (s[j] != i+'A') {
                    if (vowel(s[j]) != vowel(i+'A')) x++;
                    else x += 2;
                }
            }
            ans = min(ans,x);
        }
        printf("Case #%d: %d\n",t,ans);
    }

    return 0;
}
