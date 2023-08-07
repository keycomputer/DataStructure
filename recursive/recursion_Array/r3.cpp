#include<iostream>
using namespace std;
int sum(int n,int array[]){
    if(n==0){
        return 0;
    }
    return (array[n-1] + sum(n-1, array));
}
int main(){
    int array[]={1,2,3,4,5};
    int arraysize= sizeof(array)/sizeof(array[0]); // gives the array size.
    int output = sum(arraysize,array);
    cout<<output;
}