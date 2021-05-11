#include<iostream> 
#include<math.h>
#include<iomanip>
using namespace std; 

double mean;
int n;

int main()
{
	void moments(int, double[], double[], double);
	
	cout<<"Enter n : ";
	cin>>n;
	
	double start, interval;
	
	cout<<"Enter start value : ";
	cin>>start;
	
	cout<<"Enter interval value : ";
	cin>>interval;
	
	double x[n];
	double f[n];
	
	double sum = 0;
	double sum2 = 0;
	double sum3 = 0;
	
	double end = interval;
	
	for(int i = 0; i < n; i++)
	{
		double mid = (start + end) / 2;
		x[i] = mid;
		start += interval;
		end = start + interval;
	}
	
	cout<<"Enter values of fi : ";
	for(int i = 0; i < n; i++)
	{
		cin>>f[i];
		sum += f[i] * x[i];
		sum2 += f[i];
	}
	
	mean = sum / sum2;
	
	cout<<"\nMean = "<<mean;
	
	moments(1, f, x, sum2);
	moments(2, f, x, sum2);
	moments(3, f, x, sum2);
	moments(4, f, x, sum2);

}

void moments(int k, double f[], double x[], double sum2)
{
	double sum3 = 0;
	
	for(int i = 0; i < n; i++)
	{
		double mi = x[i] - mean;
		mi = pow(mi, k);
		mi *= f[i];
		sum3 += mi;
	}
	
	double moment = sum3 / sum2;
	
	cout<<"\n\nMoment "<<k<<" = ";
	printf("%.2f", moment);
}