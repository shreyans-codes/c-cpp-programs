#include<iostream>

using namespace std;

int main()
{
	int n, start, interval;
	
	cout<<"Enter the N : ";
	cin>>n;
	
	cout<<"Enter the start : ";
	cin>>start;
	
	cout<<"Enter the interval : ";
	cin>>interval;
	
	double x[n];
	double f[n];
	double sum = 0;
	double sum2 = 0;
	double cf[n];
	
	cout<<"Enter fi values : ";
	for(int i = 0; i < n; i++)
	{
		cin>>f[i];
		sum += f[i];
		cf[0] = f[0];
		if(i > 0)
		cf[i] = f[i] + cf[i - 1];
	}
	
	sum2 = sum/2;
	
	int index = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(cf[i] < sum2)
		{
			index++;
		}
		else
		{
			break;
		}
	}
	
	double h = interval;
	double l = start + (interval * (index));
	double c = cf[index-1];
	double F = f[index];
	
	cout<<"\nl = "<<l;
	cout<<"\nh = "<<h;
	cout<<"\nc = "<<c;
	cout<<"\nf = "<<F;
	cout<<"\nn/2 = "<<sum2;
	
	double mediun = l + h * ((sum2 - c)/F);
	
	cout<<"\n\nMediun : "<<mediun;
}