#include <iostream>
using namespace std; 

int main()
{
	double ne, ns, pe;
	
	cout<<"Enter number of favourable outcomes (ne) : ";
	cin>>ne;
	
	cout<<"Enter total number of outcomes (ns) : ";
	cin>>ns;
	
	while(ne > ns || ns == 0)
	{
		cout<<"\nWrong Values, Try Again";
		
		cout<<"\n\nEnter number of favourable outcomes (ne) : ";
		cin>>ne;
	
		cout<<"Enter total number of outcomes (ns) : ";
		cin>>ns;
	}
	
	pe = ne / ns;
	
	cout<<"\nProbability of event = "<<pe;
}