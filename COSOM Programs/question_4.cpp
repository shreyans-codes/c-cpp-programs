#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout<<"Enter the n : ";
	cin>>n;
	
	double x[n];
	double f[n];
	double sum = 0;
	double sum2 = 0;
	double mul[n];
	
	cout<<"Enter Xi values : ";
	for(int i = 0; i < n; i++)
	{
		cin>>x[i];
	}
	
	cout<<"Enter Fi values : ";
	for(int i = 0; i < n; i++)
	{
		cin>>f[i];
		sum += f[i];
		mul[i] = f[i] * x[i];
		sum2 += mul[i];
	}

 	cout<<"Mean : "<<sum2/sum;
}