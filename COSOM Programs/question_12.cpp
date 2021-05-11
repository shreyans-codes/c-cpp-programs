#include <iostream>
using namespace std; 

int main()
{	
	int n, m;
	
	cout<<"Enter n : ";
	cin>>n;
	
	int a[n];
	
	cout<<"Enter values of set A : ";
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	
	cout<<"\nEnter m : ";
	cin>>m;
	
	int b[m];
	
	cout<<"Enter values of set B : ";
	for(int i = 0; i < m; i++)
	{
		cin>>b[i];
	}
	
	int c[n+m];
	
	int h = 0;
	
	for(int i = 0; i < n; i++)
	{
		c[h] = a[i];
		h++;
	}
	
	int temp;
	
	for(int i = 0; i < m; i++)
	{
		temp = 1;
		
		for(int j = 0; j < n; j++)
		{
			if(b[i] == c[j])
			{
				temp = 0;
				break;
			}
		}
		
		if(temp == 1)
		{
			c[h] = b[i];
			h++;	
		}
	}
	
	cout<<"\n(A U B) = ";
	for(int i = 0; i < h; i++)
	{
		cout<<c[i]<<" ";
	}
	
	cout<<"\nn(A U B) = "<<h;
}