#include<iostream> 
using namespace std; 

int main()
{
	double quator(int, double[], double[], double, int, double , double);
	
	int n;
	
	double start, interval;
	
	cout<<"Enter n : ";
	cin>>n;
	
	double f[n];
	double cf[n];
	
	double sum = 0;
	
	cout<<"Enter start value : ";
	cin>>start;
	
	cout<<"Enter interval value : ";
	cin>>interval;
	
	cout<<"Enter f : ";
	for(int i = 0; i < n; i++)
	{
		cin>>f[i];
		sum += f[i];
	}
	
	cf[0] = f[0];
	
	for(int i = 1; i < n; i++)
	{
		cf[i] = cf[i - 1] + f[i];
	}
	
	double q1 = quator(1, f, cf, sum, n, start, interval);
	double q2 = quator(2, f, cf, sum, n, start, interval);
	double q3 = quator(3, f, cf, sum, n, start, interval);
	
	cout<<"\nQ1 = "<<q1;
	cout<<"\nQ2 = "<<q2;
	cout<<"\nQ3 = "<<q3;
}


double quator(int i, double f[], double cf[], double sum, int n, double start, double interval)
{
	double k = (sum * i)/4;
	
	int index = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(cf[i] < k)
		{
			index++;
		}
	}
	
    double l = start + (index * interval);
    double cf1 = cf[index - 1];
    double f1 = f[index];
    
    double q = l + (((k) - cf1 )/ (f1))  * interval;
    
    return q;
}