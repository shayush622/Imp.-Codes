//[author: ayush :)]
/************************************************* जय जय श्री राम **************************************************************************  */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
//PBDS

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
#define mp make_pair
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
//Typedef
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // find_by_order, order_of_key

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

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
int binaryToDecimal(string n){string num = n;int dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
 
/************************************************************************************************************************************************************************************************************/
//mathematical_fxn
const int mod=1e9+7;
int mod_expo(int a, int b) { int res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; } // (a^b)%mod
int mminv(int a) { return mod_expo(a, mod - 2); } // a^-1 wrt mod , a^-1 = a^(mod-2)
int nCr(int n, int r) { if (r == 0 || n == 0) return 1; int fac[n + 1];fac[0] = 1; for (int i = 1; i < n + 1; i++)fac[i] = (fac[i - 1] * i) % mod;return(fac[n] * mminv(fac[r]) % mod * mminv(fac[n - r]) % mod) % mod; } //nCr % mod
int factorial(int n) { vi fact(n + 1); fact[0] = 1; for (int i = 1; i < n + 1; i++) fact[i] = (fact[i - 1] * i) % mod; return fact[n]; } //fact(i)%mod
vi primeFactors(int n) { vector<int> ans; while (n % 2 == 0) { ans.push_back(2);n = n / 2; } for (int i = 3; i * i <= n; i += 2) { while (n % i == 0) { ans.push_back(i);n = n / i; } } if (n > 2) ans.push_back(n); return ans; }
int mod_add(int a, int b) { a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod; }
int mod_mul(int a, int b) { a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod; }
int mod_sub(int a, int b) { a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod; }
int mod_div(int a, int b) { a = a % mod; b = b % mod; return (mod_mul(a, mminv(b)) + mod) % mod; }  //only for prime m
int phin(int n) { int number = n; if (n % 2 == 0) { number /= 2; while (n % 2 == 0) n /= 2; } for (int i = 3; i <= sqrt(n); i += 2) { if (n % i == 0) { while (n % i == 0)n /= i; number = (number / i * (i - 1)); } } if (n > 1)number = (number / n * (n - 1)); return number; } //O(sqrt(N))
/************************************************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************************************************/
/*Factorial Series Generator*/
vi fact_series;
vi factorial_generator(int n) { vi fact(n); fact[0] = 1; for (int i = 1; i < n; ++i) fact[i] = (fact[i - 1] * i) % mod; return fact; }
int find_nCr(int n, int r) { if (r == 0 || n == 0) return 1; return(fact_series[n] * mminv(fact_series[r]) % mod * mminv(fact_series[n - r]) % mod) % mod; } // nCr in O(1) time or it helps in managing time complexity
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
int lcm(int a, int b){return (a/gcd(a,b)*b);}
int ceil_div(int a, int b){return ((a==0) ? 0 : 1+(a-1)/b);}
int moduloMultiplication(int a,int b){int res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
int powermod(int x, int y, int p){int res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
int power(int x,int n){if(n==0) return 1; int val=power(x,n/2); if(n%2) return val*val%mod*x%mod; return val*val%mod;}
//To find modulo inverse, call powermod(A,M-2,M)

/************************************************************************************************************************************************************************************************************/
//MEX(minimum_excluded_num)
int mex(vector<int> &arr, int N){sort(all(arr));int mex = 0;for (int idx = 0; idx < N; idx++){ if (arr[idx] == mex)mex += 1;}return mex;}

/************************************************************************************************************************************************************************************************************/
//ORDERED_multiset
//this function inserts one more occurrence of (x) into the set.
void Insert(ordered_multiset &s,int x){ s.insert(x);} 

//this function checks weather the value (x) exists in the set or not.
bool Exist(ordered_multiset &s,int x){ if((s.upper_bound(x))==s.end()){return 0;}return ((*s.upper_bound(x))==x);}
 
//this function erases one occurrence of the value (x).
void Erase(ordered_multiset &s,int x){if(Exist(s,x)){s.erase(s.upper_bound(x));}}
 
//this function returns the first index of the value (x)..(0 indexing).
int FirstIdx(ordered_multiset &s,int x){ if(!Exist(s,x)){return -1;}return (s.order_of_key(x));}
 
int Value(ordered_multiset &s,int idx){ //this function returns the value at the index (idx)..(0 indexing).
   return (*s.find_by_order(idx));}

//this function returns the last index of the value (x)..(0 indexing).
int LastIdx(ordered_multiset &s,int x){ if(!Exist(s,x)){return -1;}if(Value(s,(int)s.size()-1)==x){return (int)(s.size())-1;}return FirstIdx(s,*s.lower_bound(x))-1;}
 
//this function returns the number of occurrences of the value (x).
int Count(ordered_multiset &s,int x){if(!Exist(s,x)){return 0;}return LastIdx(s,x)-FirstIdx(s,x)+1;}

//this function clears all the elements from the set.
void Clear(ordered_multiset &s){ s.clear();}

//this function returns the size of the set.
int Size(ordered_multiset &s){ return (int)(s.size());}

/************************************************************************************************************************************************************************************************************/
//DSU
class UnionFind
{
    private: vector<int> p, rank,mxx;
    public:
        UnionFind(int n)
        {
            rank.assign(n+1,0); p.assign(n+1,0),mxx.assign(n+1,0);
            iota(p.begin(),p.end(),0);
            iota(mxx.begin(),mxx.end(),0);
        }

        int findSet(int i){ return (p[i] == i) ? i : p[i] = findSet(p[i]);}

        bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}

        void unionSet(int i, int j)
        {
            if(!isSameSet(i,j))
            {
                int x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]){
                    mxx[x]=max(mxx[x],mxx[y]);
                    p[y] = x;
                } 
                else 
                {
                    mxx[y]=max(mxx[y],mxx[x]);
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
        int ncomp(){
            int n=p.size()-1,cnt=0;
            for(int i=1;i<=n;i++){
                if(p[i]==i)
                cnt++;
            }
            return cnt;
        }
        int maxValue(int i){
            i=findSet(i);
            return mxx[i];
        }
};
/************************************************************************************************************************************************************************************************************/
/* SIEVE*/
const int N = (int)1e6;
vector<bool> sieve(N+1,1); // primality test
vector<int> primes; // contains first N primes
void create(){ sieve[0]=0,sieve[1]=0; for(int i=2;i*i<=N;i++){for(int j = i*i;j<=N;j+=i)sieve[j]=0;}}
void insert(){for(int i=2;i<=N;i++) if(sieve[i]) primes.push_back(i);}
/************************************************************************************************************************************************************************************************************/
//custom comparator
class comp // used for maps, sets, priority queue .... associative containers
{
   public:
      bool operator()(const pair<ll,ll> &a,const pair<ll,ll> &b) // operator overloading
      {
      ll len = a.second-a.first+1, len2 = b.second-b.first+1;
      if(len == len2)return a.first<b.first ; 
      return len>len2;
      }
};

/************************************************************************************************************************************************************************************************************/
//global variables






// //dfs-tree
void dfs(int node, int parent, vii &adj)
{
    // inside subtree of node

    for(auto &child: adj[node])
    {
        if(child != parent)
        {
            dfs(child, node, adj);
        }
    }
    // outside subtree of node

}

// // dfs - graph
void dfs(int node, int parent,  vi &vis, vii &adj)
{
    // inside subgraph of node
    vis[node] = 1;

    for(auto &neigh: adj[node])
    {
        if(!vis[neigh])
        {
            dfs(neigh, node, vis, adj);
        }
    }
    // outside subgraph of node

}




void solve(int testcase)
{
   int n   ; 
   cin>>n     ;
   vi v(n);   cin>>v;



}   

signed main()
{

auto start = std::chrono::high_resolution_clock::now();

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
    

    
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
    return 0;
}