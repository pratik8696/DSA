#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
 int gcd(int a,int b)
 {
     if(b==0)
     {
         return a;
     }
     else{
         return gcd(b,a%b);
     }
 }
 int reduce(int a,string b)
 {
     int sum=0;
     for(int i=0;i<b.length();i++)
     {
         sum=(sum*10+b[i]-'0')%a;
     }
     return sum;
 }
void solve()
{ 
    ll a;
    string b;
    cin>>a>>b;
    ll newb=reduce(a,b);
    if(newb>a)
    {
        cout<<gcd(newb,a)<<endl;
    }
    else{
        cout<<gcd(a,newb)<<endl;
    }
}
int main()
{
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
 solve();
 }
 return 0;
}