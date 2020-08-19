/**
 *    author:  nakli_c0der     
**/
///   TEMPLATE STARTED   /////
 
///HEADER FILES///
 
#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<cstdlib>
#include<complex>
#include<iomanip>
#include<utility>
#include<bitset>
#include<list>
#include<assert.h>
#include<numeric>
#include<fstream>
using namespace std;
 
///DEFINES///
 
#define ll long long 
#define PP pair<ll, pair<ll, ll>>
#define MOD ((ll int)(1e9+7))
#define endl "\n"
#define MAX(a,b) ( (a) > (b) ? (a) : (b))
#define MIN(a,b) ( (a) < (b) ? (a) : (b))
#define ALL(a) a.begin(), a.end()
#define REV(a) a.rbegin(), a.rend()
#define FASTIO ios::sync_with_stdio(0); cin.tie(0)
#define check(x) cout<<"CHECK = "<<#x<<"\n";
#define jsf(arr) cout<< "--> " << #arr << ": ";for(auto xxxx: arr) {cout << xxxx <<" ";} cout <<endl;
#define cones(x) __builtin_popcount(x); // count num of ones in a number
 
///TEMPLATES///
template<class T1>void deb(T1 e)
{
    cout <<"-->"<< e << endl;
}
template<class T1, class T2> void deb(T1 e1, T2 e2)
{
    cout <<"-->"<< e1 << " " << e2 << endl;
}
template<class T1, class T2, class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    cout <<"-->"<< e1 << " " << e2 << " " << e3 << endl;
}
template<class T1, class T2, class T3, class T4> void deb(T1 e1, T2 e2, T3 e3, T4 e4)
{
    cout <<"-->"<< e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template<class T1, class T2, class T3, class T4, class T5> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
{
    cout <<"-->"<< e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template<class T1, class T2, class T3, class T4, class T5, class T6> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6)
{
    cout <<"-->"<< e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6 << endl;
}
 
template<class T1>void js(T1 arr)
{
    for(auto x: arr) {
		cout << x <<" "; 
	}
    cout <<endl;
}
 
template<class T1, class T2, class T3>void js(T1 arr,T2 start,T3 end)
{
    for(auto it=start;it!=end;it++) {
		cout << *it <<" "; 
	}
    cout <<endl;
}
 
 
void read(vector<int> &v) {
	int N = (int)v.size();
	for(int i=0; i<N; i++) {
		cin >> v[i];	
	}
}
 
void fill(vector<ll> &v, int N) {
	for(int i=0; i<N; i++) {
		v[i] = 0;	
	}
}
 
 
///  TEMPLATE   OVER   ///
 
///----------ANSWER -------------------------------///
 
const int mxn = 1e3;
 
void Answer() {
	int n;
	cin >> n;
	string s[n];
	for(int i=0; i<n; i++)
		cin >> s[i];
		
	if(s[0][0]=='*'||s[n-1][n-1]=='*') {
		cout << "0" << endl;
		return;
	}
	ll dp[mxn][mxn];
	dp[0][0] = 1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!i&&!j)
				continue;
			if(s[i][j]=='*') {
				dp[i][j] = -1;
			}
			else {
				if(i-1>=0&&j>=0&&dp[i-1][j]!=-1) {
					dp[i][j] = dp[i-1][j];
				} else {
					dp[i][j] = 0;
				}
				dp[i][j] %= MOD;
				
				if(i>=0&&j-1>=0&&dp[i][j-1]!=-1) {
					dp[i][j] += dp[i][j-1];
				}
				dp[i][j] %= MOD;
			}
		}
	}
	
	cout << dp[n-1][n-1];
}
 
int main() {
		
    FASTIO;
    
    int t = 1;
    //cin>>t;
    while(t--)
    {
        Answer();
    }
    return 0;
}