#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define vi vector <int>
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define hell 100000007
#define N 1000000
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

bool PRIME[N];
vector < ll > FACT(N+5),INVFACT(N+5);

void SIEVE(){
    memset(PRIME,true,sizeof(PRIME));
    PRIME[0]=PRIME[1]=false;
    for(int i=2;i<N;i++){
        if(PRIME[i]){
            for(int j=i+i;j<N;j+=i){
                PRIME[j]=false;
            }
        }
    }
}

ll PR(ll x, ll y){
    ll ans=1;
    while(y>0){
        if(y&1){
            ans*=x;
            ans%=hell;
        }
        y>>=1;
        x=x*x;
        x%=hell;
    }
    return ans%hell;
}

ll INVERSE(ll x, ll m){
    return PR(x,m-2);
}

void FACTORIAL(){
    FACT[0]=1;
    for(int i=1;i<N;i++){
        FACT[i]=i*FACT[i-1]%hell;
    }
    INVFACT[N-1]=INVERSE(FACT[N-1], hell);
    for(int i=N-2;i>=0;i--){
        INVFACT[i] = (INVFACT[i+1]*(i+1))%hell;
    }

}

ll NCR(ll n, ll r){
    if(n<r or n<0 or r<0) return 0ll;
    return (FACT[n]*INVFACT[n-r]%hell)*INVFACT[r]%hell;
}

int main(){
    ios;
    //SIEVE();
    //FACTORIAL();
    int n,r;


}
