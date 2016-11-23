#include <iostream>
#include <cstring>
using namespace std;
char a[256];
int i,n,k=0;
bool vocala(char x){
    if(x>='a' and x<='z' and strchr("aeiou",x))
        return true;
    else return false;
}
int main()
{
    cin.get(a,256);
    n=strlen(a);
    for(i=1;i<n-1;i++)
        if(a[i]>='a' and a[i]<='z' and strchr("aeiou",a[i]))
        if(not vocala(a[i-1]) and not vocala(a[i+1]))
          if (a[i-1]>='a' and a[i-1]<='z' and a[i+1]>='a' and a[i+1]<='z')
            k++;
        cout<<k;
    return 0;
}
