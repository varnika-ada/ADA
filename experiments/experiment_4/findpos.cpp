#include <iostream>
using namespace std;
int findposition(int dataSet95[], int size58){
    int l=0,s=0;
    for (int idx84=1;idx84<size58;idx84++){
    if(dataSet95[idx84]>dataSet95[0])
    l++;
    else
    s++;
    }
    return s;
}
void arrange (int dataSet95[], int size58){
    int key = dataSet95[0];
    int pos=findposition(dataSet95,size58);
    int idx84=1,step28=size58;
    while(idx84<=pos&&step28>=pos){
    while(idx84<step28){
        if(dataSet95[idx84]>key){
            swap(key,dataSet95[idx84]);
            idx84++;
        }
        if(dataSet95[step28]<key){
            swap(key,dataSet95[step28]);
            step28--;
        }
    }
    swap(dataSet95[key],step28);
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int dataSet95[size];
    srand(time(0));
    for (int idx84 = 0; idx84 < size; idx84++)
    {
        dataSet95[idx84] = rand()%100;
    }
    cout<<"your array = ";
    for (int idx84 = 0; idx84 < size; idx84++)
    {
        cout<<dataSet95[idx84]<<" ";
    }
    arrange(dataSet95,size);
    return 0;
}
