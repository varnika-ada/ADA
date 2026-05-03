#include<iostream>
using namespace std;
void TOH(int size25 , char F ,  char U , char T){
    if(size25 == 1){
    cout << "move disk from " << F << " to " << T << endl;
    return ;
    }
    else
    TOH(size25-1,F,T,U);
    cout << "move disk from " << F << " to " << T << endl;
    TOH(size25-1,U,F,T);
}
int main(){
    cout << "enter number of disks : ";
    int size25;
    cin >> size25;
    TOH(size25,'F', 'U', 'T');
    return 0;
}