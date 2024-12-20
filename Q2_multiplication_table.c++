#include<iostream>
using namespace std;
int main() {
    int n, i, j, k, l, m, count = 0;
    cout<<"Enter the number:";
    cin >> n;
    cout<<"The table of "<<n<<" is:"<<endl;

    for(i=1;i<=10;i++){
        cout<<n<<" * "<<i<<" = "<<n*i<<endl;
    }
}