#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int result;

    srand(time(0));

    result=rand()%100+1;

    do{
        cout<<"guess the number between 1-100:";
        cin>>n;
        if(n>result){
            cout<<"too high ,please guess lower "<<endl;
        }
        else if(n<result){
            cout<<"too low, please guess higher"<<endl;
        }
        else{
            cout<<"Correct!! the number was"<<result<<endl;
        }
    }while(result!=n);

    return 0;
}

