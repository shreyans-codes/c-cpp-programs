#include <iostream>
#include <math.h>
using namespace std; 


int main()
{
	double pa, pb, pab = 0, pa_b;
	char mu;
	
	cout<<"Enter P(A) : ";
	cin>>pa;
	
	cout<<"Enter P(B) : ";
	cin>>pb;
	
	cout<<"Enter whether events mutually exclusive or not (y/n) : ";
	cin>>mu;
	
	if(mu == 'y')
	{
		while(pa < 0 || pa > 1 || pb < 0 || pb > 1)
		{
			cout<<"\nInvalid values ! Please enter again";
			
			cout<<"\n\nEnter P(A) : ";
			cin>>pa;
			
			cout<<"Enter P(B) : ";
			cin>>pb;
		}
	}
	else if (mu == 'n')
	{
		cout<<"\nEnter P(AB) : ";
		cin>>pab;
		
		while(pa < 0 || pa > 1 || pb < 0 || pb > 1 || (pa + pb) < pab)
		{
			cout<<"\nInvalid values ! Please enter again";
			
			cout<<"\n\nEnter P(A) : ";
			cin>>pa;
			
			cout<<"Enter P(B) : ";
			cin>>pb;
			
			cout<<"Enter P(AB) : ";
			cin>>pab;
		}
	}
	
	pa_b = pa + pb - pab;
	
	cout<<"\nP(A + B) = "<<pa_b;
}