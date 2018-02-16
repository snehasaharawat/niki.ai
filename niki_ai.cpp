#include <iostream>
using namespace std;

#define MOD 1000000007            //output is modulo 10^9+7


void multiplication(long long int A[2][2], long long int B[2][2])
{
  long long int x =  ((A[0][0]*B[0][0])%MOD + (A[0][1]*B[1][0])%MOD)%MOD;
  long long int y =  ((A[0][0]*B[0][1])%MOD + (A[0][1]*B[1][1])%MOD)%MOD;
  long long int z =  ((A[1][0]*B[0][0])%MOD + (A[1][1]*B[1][0])%MOD)%MOD;
  long long int w =  ((A[1][0]*B[0][1])%MOD + (A[1][1]*B[1][1])%MOD)%MOD;
 
  A[0][0] = x;
  A[0][1] = y;
  A[1][0] = z;
  A[1][1] = w;
};



void pow(long long int A[2][2], long long int n)
{
  if( n == 0 || n == 1)
      return;
      
  long long int B[2][2] = {{1,1},{1,0}};
 
  pow(A, n/2);
  multiplication(A, A);
 
  if (n%2 != 0)
     multiplication(A, B);
};

long long int modfind(long long int n)
{
	long long int A[2][2]={{1,1},{1,0}};
	// Base cases
	if(n==0)
		return 0;
	if(n==1)
		return 2;
	if(n==2)
		return 3;
		
	pow(A,n-2);
	
	return (A[0][0]*3 + A[0][1]*2)% MOD;
	
};





int main()
{	freopen("input.txt","r",stdin);
	long long int T;
	cout<<"Enter no of test cases";
	cin >> T;
	while(T--)
	{
		long long int number;
		cout<<"Enter number";
		cin >> number;
		cout << "The no of strings without two contiguous zeroes are:"<< modfind(number) << endl;
	}
	return 0;	
	
	
}
