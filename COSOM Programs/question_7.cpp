#include <iostream>

using namespace std;

int main()
{
	int n;
	double start, interval;
	
	cout<<"Enter n : ";
	cin>>n;
	
	int f[n];
	int maximum = 0;
	int max_2;
	
	cout<<"Enter start value : ";
	cin>>start;
	
	cout<<"Enter interval value : ";
	cin>>interval;
	
	cout<<"Enter f : ";
	for(int i = 0; i < n; i++)
	{
		cin>>f[i];
	}
	
	max_2 = f[0];
	
	for(int i = 1; i < n; i++)
	{
		if(f[i] > max_2)
		{
			max_2 = f[i];
			maximum = i;
		}
	}
	
	double l = (start + interval) * maximum;
	double fm, fm1, fm2;
	
	fm = f[maximum];
    maximum == n - 1 ? fm1 = 0 : fm1 = f[maximum+1];
	maximum == 0 ? fm2 = 0 : fm2 = f[maximum-1];
	cout<<"\nl = "<<l;
	cout<<"\nf m = "<<fm;
	cout<<"\nf m+1 = "<<fm1;
	cout<<"\nf m-1 = "<<fm2;
	
	double mode = l + (((fm - fm2)/ ((fm - fm2 ) + (fm - fm1))) * interval);
	cout<<"\n\nMode = "<<mode;
    
    return 0;
}