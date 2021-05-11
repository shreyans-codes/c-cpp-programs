
#include<iostream> 
#include<math.h>
#include<iomanip>
using namespace std; 

double mean;
int n;
double mu1, mu2, mu3, mu4;

int main()
{
	double moments(int, double[], double[], double);
	
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

	mu1 = moments(1, f, x, sum2);
	mu2 = moments(2, f, x, sum2);
	mu3 = moments(3, f, x, sum2);
	mu4 = moments(4, f, x, sum2);
	
	double beta1, beta2, gama1, gama2;
	
	beta1 = pow(mu3, 2) / pow(mu2, 3);
	beta2 = mu4 / pow(mu2, 2);
	
	gama1 = pow(beta1, 0.5);
	gama2 = beta2 -3;
	
	cout<<"\nBeta 1 = "<<beta1;  
	cout<<"\nBeta 2 = "<<beta2;  
	cout<<"\n\nGamma 1 = "<<gama1;  
	cout<<"\nGamma 2 = "<<gama2;  

}

double moments(int k, double f[], double x[], double sum2)
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
	
	return moment;
}