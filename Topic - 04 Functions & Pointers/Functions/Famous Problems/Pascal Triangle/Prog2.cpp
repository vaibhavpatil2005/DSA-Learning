#include<iostream>
using namespace std;

// ncr+1 = ncr * (n-r/r+1)

int main(){

    int n;
    cout<<"enter n value : ";
    cin>>n;

    for(int i=0;i<=n;i++){
        int curr = 1;
        for(int j=0;j<=i;j++){
            cout<<curr<<" ";
            curr = curr*(i-j)/(j+1);
        }
        cout<<endl;
    }
    return 0;
}