#include <bits/stdc++.h>
using namespace std;

const int D = 1005, S = 55;
struct hello {
    int p, m, t;
} a[D];  // for all 0 <= i < d, person a[i].p drank milk a[i].m at time a[i].t
struct world {
    int p, t;  // for all 0 <= i < s, person b[i].p became sick at time b[i].t
} b[S];
int n, m, d, s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    cin >> n >> m >> d >> s;
    for(int i = 0; i < d; ++i)
        cin >> a[i].p >> a[i].m >> a[i].t;
    for(int i = 0; i < s; ++i)
        cin >> b[i].p >> b[i].t;

    set<int> sick;  // everyone who drank the bad milk i
    for(int i = 1; i <= m; ++i){
        // maybe milk i is the culprit?

        // check that, for everyone who got sick, they drank milk i before becoming sick
        for(int j = 0; j < s; ++j){
            // did person b[j].p get sick after drinking milk i before time b[j].t?
            for(int k = 0; k < d; ++k)
                // person a[k].p drank milk a[k].m at time a[k].t
                if(a[k].p == b[j].p && i == a[k].m && a[k].t < b[j].t)
                    goto good;

            // when we reach this line, it means that person s[j].p did not drink milk i
            // before time s[j].t (when they became sick)
            // thus, we check the next type of milk
            goto bad;

good:;
        }

        // the culprit is milk i!
        // notice how variable "sick" is declared outside the for loop?
        // it's because you cannot declare it here.
        for(int j = 0; j < d; ++j)
            // person a[j].p drank milk a[j].m
            if(a[j].m == i)
                sick.insert(a[j].p);
        cout << sick.size();
        return 0;  // exit the program

bad:;
    }

    // it's not possible for us to have reached here.
    assert(false);
}
