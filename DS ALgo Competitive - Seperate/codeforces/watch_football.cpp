#include <iostream>
using namespace std;

int main() {
    int reqSpeed, curSpeed, length;
    cin>>reqSpeed>>curSpeed>>length;
    int bdv = curSpeed * length;
    int rSize = (reqSpeed * length) - bdv;
    int ans = rSize % curSpeed;
    if(ans>0)
        cout<<(rSize/curSpeed)+1<<endl;
    else
        cout<<(rSize/curSpeed)<<endl;
    return 0;
}