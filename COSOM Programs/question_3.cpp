
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std; 

struct equations
{
	double x;
	double y;
	double s;
	double slope;
};

equations x_axis = {0, 1, 0, 0};
equations y_axis = {1, 0, 0, 0};
equations eq[3];

void inter(equations, equations);	
void inter_points();
void input();
void maximize();

double points[5][2];
double s1, s2;
double max_val = 0;

int X = 0;
int num = 0;

bool comp(equations eq1, equations eq2)
{
	return (eq1.slope < eq2.slope);
}

int main()
{	
	input();
	
	for(int i = 0; i < 3; i++)
	{
		eq[i].slope = eq[i].x / eq[i].y;
	}
	
	sort(eq, eq+3, comp);
	
	inter_points();	
	
	maximize();
}

void input()
{
	cout<<"Maximize Z = s1x1 + s2x2 (maximize the revenue-this is the objective function";
	cout<<"\nsubject to: x1+x2 <= A (limit on total area)";
	cout<<"\nf1x1 + f2x2 <= f (limit on fertilizer)";
	cout<<"\np1x1 + p2x2 <= p (limit on insecticide)";
	cout<<"\nx1 >= 0, x2 >= 0 (cannot plant a negative area)";
	
	cout<<"\n\nEnter value of s1 : ";
	cin>>s1;
	
	cout<<"Enter value of s2 : ";
	cin>>s2;
	
	cout<<"Enter value of f1 : ";
	cin>>eq[0].x;
	
	cout<<"Enter value of f2 : ";
	cin>>eq[0].y;
	
	cout<<"Enter value of f : ";
	cin>>eq[0].s;
	
	cout<<"Enter value of p1 : ";
	cin>>eq[1].x;
	
	cout<<"Enter value of p2 : ";
	cin>>eq[1].y;
	
	cout<<"Enter value of p : ";
	cin>>eq[1].s;
	
	cout<<"Enter value of A : ";
	cin>>eq[2].s;

	eq[2].x = 1;
	eq[2].y = 1;
	
	cout<<"\n\nMaximize Z = "<<s1<<"x1 + "<<s2<<"x2 (maximize the revenue-this is the objective function";
	cout<<"\nsubject to: x1+x2 <= "<<eq[2].s<<" (limit on total area)";
	cout<<"\n"<<eq[0].x<<"x1 + "<<eq[0].x<<"x2 <= "<<eq[0].s<<" (limit on fertilizer)";
	cout<<"\n"<<eq[1].x<<"x1 + "<<eq[1].y<<"x2 <= "<<eq[1].s<<" (limit on insecticide)";
	cout<<"\nx1 >= 0, x2 >= 0 (cannot plant a negative area)";
}

void inter_points()
{
	inter(y_axis, eq[0]);
	inter(x_axis, eq[2]);
	inter(eq[0], eq[1]);
	inter(eq[1], eq[2]);
	inter(eq[2], eq[0]);
	
	cout<<"\n\nInteresction points\n";
	
	if(points[3][0] > points[2][0])
	{
		num = 4;
		
		for(int i = 0; i < 4; i++)
		{
			cout<<"("<<setprecision(3)<<points[i][0]<<", "<<points[i][1]<<")\n";
		}
	}
	else
	{
		num = 3;
		
		for(int i = 0; i < 5; i++)
		{
			if(i == 2 || i == 3)
				continue;
				
			cout<<"("<<setprecision(3)<<points[i][0]<<", "<<points[i][1]<<")\n";
		}
	}
}

void inter(equations eq1, equations eq2)
{
	points[X][1] = (eq2.x*eq1.s - eq1.x*eq2.s)/(eq1.y*eq2.x - eq1.x*eq2.y);
	points[X][0] = (eq2.y*eq1.s - eq1.y*eq2.s)/(eq1.x*eq2.y - eq1.y*eq2.x);
	X++;
}

void maximize()
{
	int n = 0;
	
	if(num == 4)
	{
		for(int i = 0; i < 4; i++)
		{
			double sum = (points[i][0]*s1) + (points[i][1]*s2);
			
			if(sum > max_val)
			{
				max_val = sum;
				n = i;
			}
		}
	}
	else if(num == 3)
	{
		for(int i = 0; i < 5; i++)
		{
			if(i == 2 || i == 3)
				continue;
				
			double sum = (points[i][0]*s1) + (points[i][1]*s2);
			
			if(sum > max_val)
			{
				max_val = sum;
				n = i;
			}
		}
	}
	
	cout<<"\nMaximum value : "<<max_val;
	cout<<"\nMaximum point : "<<"("<<points[n][0]<<", "<<points[n][1]<<")\n";
}