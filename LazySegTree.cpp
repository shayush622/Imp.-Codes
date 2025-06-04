// ayush_sharma
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
//PBDS

//Macros
#define ll long long
#define f(i, a, n) for (ll i = a; i < n; i++)
#define revv(i, n, a) for (ll i = n-1; i >=a; i--)
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vector<pl>
#define vii vector<vector<ll>>
#define nl '\n'<<flush
#define mapp map<ll,ll>
#define umap unordered_map<ll,ll>
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define Num_of_Digits(n) ((ll)log10(n) + 1)
#define Num_of_Bits(n) ((ll)log2(n) + 1)
#define all(x) x.begin(),x.end()
#define rev(x) x.rbegin(),x.rend()
#define c(x) cout<<x<<nl
#define ps(x,y) fixed<<setprecision(y)<<x

//Typedef
typedef tree<int, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

//template
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T> // cout << set<T>
ostream& operator<<(ostream &ostream, const set<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T, typename V> // cout << map<T,V>
ostream& operator<<(ostream &ostream, const map<T,V> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }
template<typename T, typename V> // cout << vector<pair<T,V>>
ostream& operator<<(ostream &ostream, const vector<pair<T,V>> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
 
//mathematical_fxn
const ll mod=1e9+7;
ll mod_expo(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; } // (a^b)%mod
ll mminv(ll a) { return mod_expo(a, mod - 2); } // a^-1 wrt mod , a^-1 = a^(mod-2)
ll nCr(ll n, ll r) { if (r == 0 || n == 0) return 1; ll fac[n + 1];fac[0] = 1; for (int i = 1; i < n + 1; i++)fac[i] = (fac[i - 1] * i) % mod;return(fac[n] * mminv(fac[r]) % mod * mminv(fac[n - r]) % mod) % mod; } //nCr % mod
ll factorial(int n) { vi fact(n + 1); fact[0] = 1; for (int i = 1; i < n + 1; i++) fact[i] = (fact[i - 1] * i) % mod; return fact[n]; } //fact(i)%mod
vl primeFactors(ll n) { vector<ll> ans; while (n % 2 == 0) { ans.push_back(2);n = n / 2; } for (ll i = 3; i * i <= n; i += 2) { while (n % i == 0) { ans.push_back(i);n = n / i; } } if (n > 2) ans.push_back(n); return ans; }
ll mod_add(ll a, ll b) { a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod; }
ll mod_mul(ll a, ll b) { a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod; }
ll mod_sub(ll a, ll b) { a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod; }
ll mod_div(ll a, ll b) { a = a % mod; b = b % mod; return (mod_mul(a, mminv(b)) + mod) % mod; }  //only for prime m
ll phin(ll n) { ll number = n; if (n % 2 == 0) { number /= 2; while (n % 2 == 0) n /= 2; } for (ll i = 3; i <= sqrt(n); i += 2) { if (n % i == 0) { while (n % i == 0)n /= i; number = (number / i * (i - 1)); } } if (n > 1)number = (number / n * (n - 1)); return number; } //O(sqrt(N))
/*Factorial Series Generator*/
vi fact_series;
vi factorial_generator(int n) { vi fact(n); fact[0] = 1; for (int i = 1; i < n; ++i) fact[i] = (fact[i - 1] * i) % mod; return fact; }
ll find_nCr(ll n, ll r) { if (r == 0 || n == 0) return 1; return(fact_series[n] * mminv(fact_series[r]) % mod * mminv(fact_series[n - r]) % mod) % mod; } // nCr in O(1) time or it helps in managing time complexity
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
ll power(ll x,ll n){if(n==0) return 1; ll val=power(x,n/2); if(n%2) return val*val%mod*x%mod; return val*val%mod;}
//To find modulo inverse, call powermod(A,M-2,M)

//MEX(minimum_excluded_num)
ll mex(vector<ll> &arr, ll N){sort(all(arr));ll mex = 0;for (ll idx = 0; idx < N; idx++){ if (arr[idx] == mex)mex += 1;}return mex;}

/* SIEVE*/
const ll N = (ll)1e6;
vector<bool> sieve(N+1,1); // primality test
vector<ll> primes; // contains first N primes
void create(){ sieve[0]=0,sieve[1]=0; for(ll i=2;i*i<=N;i++){for(ll j = i*i;j<=N;j+=i)sieve[j]=0;}}
void insert(){for(ll i=2;i<=N;i++) if(sieve[i]) primes.push_back(i);}

/************************************************************************************************************************************************************************************************************/


//Lazy-Segment_Tree for processing range minimum queries
// type 1: add x to a range 
// typ 2: return minimum of a range
//1-based indexing for each node having index x , left child's index = 2*x, right child = 2*x+1

vector<ll> segTree,lazy;
ll merge(ll l, ll r)
{
   return (l^r);
}
void Build(vector<ll> &arr,ll start, ll end, ll index)    //time_comp: O(n)
{
   if(start==end)// leaf node
   {
      segTree[index] = arr[start];
      return;
   }
   ll mid = (start+end)/2;
   ll left = 2*index,right = 2*index+1;
   Build(arr,start,mid,left);  
   Build(arr,mid+1,end,right);
   segTree[index] = merge(segTree[left],segTree[right]);   
}
void propagate(ll start,ll end, ll index)
{
    if(start==end)//leaf node
    {
    lazy[index] = -1;
        return;
    }
    lazy[2*index] = lazy[index];
    lazy[2*index+1]=lazy[index];
    lazy[index] = -1;
}
void update(ll start, ll end, ll index, ll l, ll r, ll val) 
{
   // time_complexity: O(log n)
    if(lazy[index]!=-1)
    {
        segTree[index]=((end-start+1)&1)?lazy[index]:0;
        propagate(start,end,index);
    }
    // after this my current node is in the most updated state
    if(start>=l && end<=r ) //complete overlap
   {
         // change here for update query
        segTree[index]=((end-start+1)&1)?lazy[index]:0;
        //  segTree[index]=val; 
      lazy[index] = val;
      propagate(start,end,index);
      return;
   }
   if(start>r || end <l) // disjoint
   return ;

   ll mid = (start+end)/2;
    update(start,mid,2*index,l,r,val);
    update(mid+1,end,2*index+1,l,r,val);
   segTree[index] = merge(segTree[2*index], segTree[2* index+1]);  // segTree[index] = L + R or as may be asked in range query
}
ll query(ll start, ll end, ll index, ll l, ll r)
{
    if(lazy[index]!=-1)
    {
        segTree[index]=((end-start+1)&1)?lazy[index]:0;
        // segTree[index]+=lazy[index];
        propagate(start,end,index);
    }
   // timeComp: O(log n)
   if(l<=start && r>=end)return segTree[index]; // completeOverlap
   if(l>end || r<start) return 0;  // disjoint 
   ll mid = (start+end)/2;
   ll leftAnswer=query(start,mid,2*index,l,r);
   ll rightAnswer=query(mid+1,end,2*index +1,l,r);
   return merge(leftAnswer ,rightAnswer);
}



void solve(int testcase)
{
   ll n    ; 
   cin>>n     ;
   vl v(n);   cin>>v;
   segTree.resize(4*n,-1);
   lazy.resize(4*n,-1);
   Build(v,0,n-1,1);
   c(segTree);
    c(lazy);
    c(query(0,n-1,1,0,2));
    update(0,n-1,1,0,0,500);
    c(query(0,n-1,1,0,2));
    c(lazy);


}   

signed main()
{
// auto start = std::chrono::high_resolution_clock::now();

   // create();
   // insert();

    // fact_series = factorial_generator(20000);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t=1;
    // cin>>t;
    while(t--)
    solve(t);
    

    
   //  auto stop = std::chrono::high_resolution_clock::now(); 
   //  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
   //  cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
    return 0;
}