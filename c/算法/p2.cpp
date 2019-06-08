#include <bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
using namespace std;
char a[1005],b[1005];
int f[1005][1005],n,m;
int main(){
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1);m=strlen(b+1);
    int w=max(n,m);
    for(int i=1;i<=w;++i)f[i][0]=f[0][i]=i;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i]==b[j])f[i][j]=f[i-1][j-1];
            else f[i][j]=min(f[i][j-1],min(f[i-1][j],f[i-1][j-1]))+1;
        }
    }
    printf("%d",f[n][m]);
    return 0;
} 