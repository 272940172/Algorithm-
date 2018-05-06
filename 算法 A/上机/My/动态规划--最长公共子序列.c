#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int c[200][200];   //��c[i][j]��¼X[i]��Y[j] ��LCS �ĳ���  
int b[200][200];   //b[i][j]��¼c[i][j]��ͨ����һ���������ֵ��õģ��Ծ��������ķ���  
int main(int argc, char *argv[]) {
	char x[] = {'a','b','c','b','d','a','b'};
	char y[] = {'b','d','c','a','b','a'};
	printf("%s\n",x);
	
	printf("%s\n",y);
	LCSLength(7,6,x,y,c,b);
	
	int m = 7,n=6;
	int i,j;
	printf("C[][]:\n");
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	printf("b[][]:\n");
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	
	LCS(7,6,x,b);
	
}

void LCSLength(int m,int n,char x[],char y[]){
	int i,j;
	
	//��c[i][j]���г�ʼ�� 
//	for(i=1;i<=m;i++)c[i][0] = 0;
//	for(i=1;i<=n;i++)c[0][i] = 0;
	
//	for(i=0;i<=m;i++){
//		for(j=0;j<=n;j++){
//			printf("%d ",c[i][j]);
//		}
//		printf("\n");
//	}
	
	for(i=1;i<=m;i++){
		
		for(j=1;j<=n;j++){
			printf("%c - %c \n",x[i-1],y[j-1]);
			if(x[i-1]==y[j-1]){
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 1;
				
			}else if(c[i-1][j]>=c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
				
			}else if(c[i-1][j]<=c[i][j-1]){
				c[i][j] = c[i][j-1];
				b[i][j] = 3; 
			}
		}
	}
}

void LCS(int i,int j,char x[]){
	//	7         6
	if(i==0 || j==0){
		return;
	}	
	if(b[i][j]==1){
		LCS(i-1,j-1,x);
		printf("%c",x[i-1]);
	}else if(b[i][j]==2){
		LCS(i-1,j,x);
	}else{
		LCS(i,j-1,x);
	}

}


