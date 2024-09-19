#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int result;
    srand(time(0));
    
    result = rand() % 100 + 1;
    
        do{
            cout<<"eneter the number between 1-100:"<<endl;
            cin>>n;
            
        if (n>result) {
            cout << "too high,guess lower!!" << endl;
        } 
        else if (n<result) {
            cout << "too low,guess higher!!" << endl;
        } 
        else {
            cout << "Correct!!the number was " << result << endl;
            break; 
        }

        }while (result!=n);


    return 0;
}

