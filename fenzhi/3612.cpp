#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    long long n,L;
    cin>>str>>n;
    int len=str.length();
    
    
    while(len<n)
    {

        L=len;
        while(n>L){
            L*=2;
        }
        L/=2;
        
        n-=(L+1);
        if(n==0)
        {
            n=L;
        }
    }

    cout<<str[n-1];
    return 0;
}