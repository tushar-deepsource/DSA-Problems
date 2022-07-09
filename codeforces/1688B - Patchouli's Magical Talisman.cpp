#include <iostream>
#include <cmath>
using namespace std;
 
int rsb(int a){
    int c=0;
    while(!(a&1)){
        c++;
        a=a>>1;
    }
    return c;
}
 
int main()
{
    int t;
    cin>>t;
    while (t--){
       int n;
       cin>>n;
       int A[n];
       int no=0,ne=0;
       for(int i=0;i<=n-1;i++){
           cin>>A[i];
           if(A[i]%2!=0)
                no++;
           else
                ne++;
       }
       int ans,l,m;
       if(ne==n)
       {
       int b=rsb(A[0]);
       for(int i=1;i<=n-1;i++){
           int d=rsb(A[i]);
           b=min(b,d);
       }
        ans= b + ne - 1;
       }
       else
       {
           ans=ne;
           
       }
       cout << ans<< endl;
       
    }
}
