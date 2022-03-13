#include<bits/stdc++.h>
#define N 101
using namespace std;

int arr[N][N], I[N][N] = {0};

void mul(int A[][N], int B[][N], int dim)
{
	int res[dim+1][dim+1];
	
	//multiplication of two matrices
	for(int i = 1;i <= dim;i++)
		for(int j = 1;j <= dim;j++)
		{
			res[i][j] = 0;
			for(int k = 1;k <= dim;k++)
				res[i][j] += A[i][k]*B[k][j];
		}
	//copy elements of res into A		
	for(int i = 1;i <= dim;i++)
		for(int j = 1;j <= dim;j++)
			A[i][j]	 = res[i][j];		
}

void printMat(int A[][N], int dim)
{
	for(int i = 1;i <= dim;i++)
	{
		for(int j = 1;j <= dim;j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}
void power(int A[][N],int dim,int n)
{
	// create an Identity Matrix of dimenstion dim
	for(int i = 1;i <= dim;i++)
		I[i][i] = 1;
	
//	for(int i = 0;i < n;i++)  // linear exponentiation code
//		mul(I,A,dim);
	
	// matrix exponentiation code
	while(n > 0)
	{
		if(n%2 == 1)
			mul(I, A, dim);
		mul(A, A, dim);
		n = n/2;
	}
			
	//copy elements of I into A	
	for(int i = 1;i <= dim;i++)
		for(int j = 1;j <= dim;j++)
			A[i][j]	 = I[i][j];	
}

int main()
{
	int dim, n; // dim = dimension of matrix and n = power to be rairsed on matrix
	cin >> 	dim >> n;
	for(int i = 1;i <= dim;i++)
		for(int j = 1;j <= dim;j++) 
			cin >> arr[i][j];
	power(arr,dim,n);
	printMat(arr,dim);		
			
}
