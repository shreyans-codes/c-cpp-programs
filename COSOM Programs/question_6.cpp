#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout<<"Enter n : ";
	cin>>n;
	
	double x[n];
	double f[n];
	double temp[n];
	int sum = 0, sum2 = 0;
	int start, interval;
	
	cout<<"Enter start : ";
	cin>>start;
	
	cout<<"Enter the interval : ";
	cin>>interval;
	
	int l, u;
	l = start;
	u = start + interval;
	
	for(int i = 0; i < n; i++)
	{
		x[i] = (l + u) / 2;
		l += interval;
		u += interval;
	}
	
	cout<<"Enter fi : ";
	for(int i = 0; i < n; i++)
	{
		cin>>f[i];
		sum += f[i];
	}
	
	int a;
	a = x[n/2];
	
	for(int i = 0; i < n; i++)
	{
		temp[i] = x[i] - a;
		temp[i] *= f[i];
		sum2 += temp[i];
	}
	
	double mean;
	mean = a + (sum2/sum);
	
	cout<<"\n\na = "<<a;
	cout<<"\nsum fidi = "<<sum2;
	cout<<"\nsum fi = "<<sum;
	cout<<"\n\nMean = "<<mean;
}