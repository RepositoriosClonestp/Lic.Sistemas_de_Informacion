#include<stdio.h> 
int main () { 
	int aux,i,j,k; 
	int n=10,A[n]; 
	for (i=0; i<n; i++) {		 
		printf("dame el dato %d ",i+1); 
		scanf("%d",&A[i]); 
		} 
	for (i=1;i<n;i++) { 
		for (j=0;j<n-i;j++) 
		{ 
		if (A[j]>=A[j+1]) 
		{ 
			aux=A[j]; 
			A[j]=A[j+1]; 
			A[j+1]=aux; 
		}	 
		}		 
		}	
	for (i=0;i<n;i++) { 
	printf(" %d", A[i]); 
	} 
return 0; 
} 