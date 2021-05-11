#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n], b1=0, b2=0;
	    for(int i=0; i<n; i++){
	        cin>>a[i];
	    } 
	    sort(a, a+n, cmp);
	    
	    for(int i=0; i<n; i++){
            if(b1<b2){
                b1 += a[i];
                cout<<"Yo, me here. Val of B1 = "<<b1<<endl;
            }
            else{
                b2 += a[i];
                cout<<"Yo, me here. Val of B2 = "<<b2<<endl;
            }
	    }
	    cout<<max(b1,b2)<<endl;
	}
	return 0;
}