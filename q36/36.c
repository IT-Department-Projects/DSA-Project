    #include <stdio.h>
    long long int a[201][201],n,k;
    long long int solve(long long int n,long long int m){
    if(n==0)
    return 1;
    if(m==0)
    return 0;
    if(n<0)
    return 0;
    if(n<k||m<k)
    return 0;
     
    if(a[n][m]!=-1)
    return a[n][m];
     
    a[n][m]=solve(n,m-1)+solve(n-m,m);
    return a[n][m];
    }
    int main(){
    long long int t,i,j,d;
    scanf("%lld",&t);
    while(t--){
    scanf("%lld %lld",&n,&k);
    for(i=0;i<201;++i)
    for(j=0;j<201;++j)
    a[i][j]=-1;
    d=solve(n,n);
    printf("%lld\n",d);
    }
    return 0;
    }

Language: C