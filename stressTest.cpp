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




//----------------------------------------------------------------------------
// Utility functions (Don't modify this)

// Generates random number from 1 to range
int generate_random_number(int range){
    return (rand()%range)+1; 
}


// Generate random lowercase string of length n
string generate_random_lowercase_string_of_length_n(int n){
    string s="";

    for(int i=0; i<n; i++){
        int x=(rand()%26);
        s+=(x+97);
    }

    return s;
}


// Generate random uppercase string of length n
string generate_random_uppercase_string_of_length_n(int n){
    string s="";

    for(int i=0; i<n; i++){
        int x=(rand()%26);
        s+=(x+65);
    }

    return s;
}


// Generate random upper & lower both case string of length n
string generate_random_both_case_string_of_length_n(int n){
    string s="";

    for(int i=0; i<n; i++){
        int x=(rand()%26);
        int type=(rand()%2);
        
        if(type==0){
            s+=(x+65);
        }else{
            s+=(x+97);
        }
    }

    return s;
}


// Generate random numeric string of length n
string generate_random_numeric_string_of_length_n(int n){
    string s="";

    for(int i=0; i<n; i++){
        int x=(rand()%10);
        s+=(x+48);
    }

    return s;
}


// Generates a random vector of length n having values in between mini and maxi
vector<int> generate_vector_of_random_value_of_length_n(int n, int minimum_element, int maximum_element){
    vector<int> v;
    
    for(int i=0; i<n; i++){
        int random_value=minimum_element+rand()%(maximum_element-minimum_element+1);

        v.emplace_back(random_value);
    }

    return v;
}


// Print captured outputs and final verdicts
void print_verdict(string &output1, string &output2){  
    cout<<"Output Of Your Function"<<endl;
    cout<<"------------------------"<<endl;
    cout<<output1<<endl;

    cout<<"Output Of Bruteforce Function"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<output2<<endl;

    // Compare the outputs
    if(output1==output2){
        cout<<"Verdict - [OK]"<<endl;
    }else{
        cout<<"Verdict - [NOT OK]"<<endl;
    }

    cout<<"____________________________________________________________________________"<<endl<<endl<<endl;
}


// Final verdict judging
void get_final_verdict(string output1, string output2, streambuf* &oldCout){
    // Restore standard output
    cout.rdbuf(oldCout);

    // Print final verdict
    print_verdict(output1,output2);
}
//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
// Your working area

// Print inputs to see the generated testcase
void print_input(int n, vector<int> &v){ // Update parameters by generated inputs
    cout<<"Input"<<endl;
    cout<<"--------------------------"<<endl;

    // Update printing statements of inputs to see the generated testcases
    cout<<n<<endl;
    for(int val : v){
        cout<<val<<" ";
    }cout<<endl<<endl;
}


// Fill your function that you want to test
void your_function(int &n, vector<int> v) { // Update parameters by generated inputs
    if(v.size()<2){
        cout<<"No second smallest"<<endl;
        return;
    }

    sort(v.begin(),v.end());
    cout<<v[1]<<endl;
}


// Write the bruteforce solution
void bruteforce_function(int &n, vector<int> v) { // Update parameters by generated inputs
    int mini=1e9;
    for(int i=0; i<n; i++){
        mini=min(mini,v[i]);
    }

    int second_smallest=1e9;
    for(int i=0; i<n; i++){
        if(v[i]<second_smallest && v[i]!=mini){
            second_smallest=v[i];
        }
    }

    if(second_smallest==1e9){
        cout<<"No second smallest"<<endl;
    }else{
        cout<<second_smallest<<endl;
    }
}


// Stress testing function
void stress_testing(int &test_case, ostringstream &oss1, ostringstream &oss2, streambuf* &oldCout){
    // Generate inputs ---------------------------------------------------------------------------
    int n=generate_random_number(10);
    vector<int> v=generate_vector_of_random_value_of_length_n(n,1,3);

    // Print inputs
    print_input(n,v); // Update parameters by generated inputs
    //--------------------------------------------------------------------------------------------


    // Calling your_function() -------------------------------------------------------------------
    cout.rdbuf(oss1.rdbuf()); // Capture output of your_function() 
    
    your_function(n,v); // Update parameters by generated inputs
    //--------------------------------------------------------------------------------------------
    

    // Calling bruteforce_function() -------------------------------------------------------------
    cout.rdbuf(oss2.rdbuf()); // Capture output of bruteforce_function()

    bruteforce_function(n,v); // Update parameters by generated inputs
    //--------------------------------------------------------------------------------------------

    get_final_verdict(oss1.str(),oss2.str(),oldCout);
}
//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
// Main function 
int main(){
    int test_case=100; // Change the number of test cases according to your need.
    cin>>test_case; // Uncomment this line to take input from user
    srand(static_cast<unsigned int>(time(0)));

    for(int test=1; test<=test_case; test++){
        cout<<"-----------------------------------"<<endl;
        cout<<"|          Test Case - "<<test<<"          |"<<endl;
        cout<<"-----------------------------------"<<endl<<endl;

        // Create string streams to capture the outputs
        ostringstream oss1, oss2;

        // Redirect standard output to the string streams
        streambuf* oldCout=cout.rdbuf();

        stress_testing(test,oss1,oss2,oldCout);
    }

    return 0;
}
//----------------------------------------------------------------------------