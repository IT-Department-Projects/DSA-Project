#include <stdio.h>
long long int M[205][205];

int main() {
	
	int i,j,N,K,T;
	for(i=1;i<=200;i++) {
		for(j=1;j<=i;j++) {
			if(i==j)
				M[i][j]=1;
			else {
				M[i][j]=M[i-j][j];
		}
	}
	
		for(j=i;j>=1;j--) {
			M[i][j]=M[i][j]+M[i][j+1];
		}
	}

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&K);
		printf("%lld\n",M[N][K]);
	}
	return 0;
}
