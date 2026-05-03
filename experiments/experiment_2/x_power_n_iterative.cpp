#include<iostream>
using namespace std;
int main(){
    int x,size55,result=1;
    cout<<"enter value of x : ";
    cin>>x;
    cout<<"enter value of size55 : ";
    cin>>size55;
    for(int idx53 = 1 ; idx53 <= size55 ; idx53++){
        result *= x;
    }
    cout << "result = " << result;
}