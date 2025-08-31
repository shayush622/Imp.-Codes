//[author: ayush :)]
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

//Macros
#define int long long
#define f(i, a, n) for (int i = a; i < n; i++)
#define revv(i, n, a) for (int i = n-1; i >=a; i--)
#define pi pair<int, int>
#define vi vector<int>
#define vpi vector<pi>
#define vii vector<vector<int>>
#define mapp map<int,int>
#define INF LLONG_MAX
#define nl '\n'
#define pb push_back
#define ppb pop_back
#define mpr make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define nlflush '\n'<<flush
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define Num_of_Bits(n) ((int)log2(n) + 1)
#define all(x) x.begin(),x.end()
#define rev(x) x.rbegin(),x.rend()
#define c(x) cout<<x<<nl
#define sz(x) ((int)(x).size())
#define ps(x,y) fixed<<setprecision(y)<<x

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/************************************************************************************************************************************************************************************************************/
//debugging
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

// void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/************************************************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************************************************/
//template
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T, typename V> // cout << <pair<T,V>>
ostream& operator<<(ostream &ostream, const pair<T,V> &c) {cout << c.first << " " << c.second; return ostream; }
template<typename T> // cout << set<T>
ostream& operator<<(ostream &ostream, const set<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T> // cout << multiset<T>
ostream& operator<<(ostream &ostream, const multiset<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T, typename V> // cout << map<T,V>
ostream& operator<<(ostream &ostream, const map<T,V> &c) { for (auto &it : c) cout << it.first << " " << it.second<<nl; return ostream; }
template<typename T, typename V> // cout << vector<pair<T,V>>
ostream& operator<<(ostream &ostream, const vector<pair<T,V>> &c) { for (auto &it : c) cout << it.first << " " << it.second<<nl; return ostream; }

/************************************************************************************************************************************************************************************************************/


void solve(int testcase)
{
   int n, m;
   cin >> n >> m;
   vector<vi> adj(n + 1);
   f(i, 0, m)
   {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   vi par(n + 1, 0), in(n + 1, -1), low(n + 1, 0);
   int timer = -1;
   stack<pi> st;
   auto dfs = [&](int u, int par, auto &&dfs) -> void
   {
      in[u] = low[u] = ++timer;
      int child = 0;
      for (auto v : adj[u])
      {
         if (in[v] == -1) // not visited
         {
            child++;
            st.push({u, v});
            dfs(v, u, dfs);
            low[u] = min(low[v], low[u]);
            if (low[v] > in[u])
            {
               // bridge detected
            }
            if ((par == -1 && child > 1) || (par != -1 && low[v] >= in[u]))
            {
               // articulation pt detected here
            }
         }
         else if (in[v] < in[u] && v != par) // visited
         {
            low[u] = min(low[u], in[v]);
            st.push({u, v});
         }
      }
   };
}


signed main()
{
   // create();
   // insert();
   // gen_pows();

    // fact_series = factorial_generator(20000);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("debug.txt","w",stderr);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t=1;
    cin>>t;
    while(t--)
    solve(t);

    return 0;
}