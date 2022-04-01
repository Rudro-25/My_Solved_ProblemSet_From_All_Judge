//BeginCodeSnip{C++ Short Template}
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair


mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash { /// use most bits rather than just the lowest ones
    const uint64_t C = ll(2e18*acos((long double)-1))+71; // large odd number
    const int RANDOM = rng();
    ll operator()(ll x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C); }
};

template<class K,class V> using ht = gp_hash_table<K,V,chash>;

int main() {

    int n, x; cin >> n >> x;

    vi v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    ht<int, pi> hm;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i - 1; j >= 0; j--) {
            int idx = x - v[i] - v[j];
            if(hm.find(idx) != hm.end()) {
                cout << i + 1 << " " << j + 1 << " " << hm[idx].f + 1 << " " << hm[idx].s + 1;
                return 0;
            }
        }

        for(int j = i + 1; j < n; j++) hm[v[i] + v[j]] = {i, j};
    }

    cout << "IMPOSSIBLE\n";
}
