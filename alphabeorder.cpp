#include <iostream>
#include <string>
using namespace std;

string a;
string list[5];

void ordering()
{
    for(int i=0; i<5; i++){
    cin>>list[i];
    for(int m=0; m<5; m++){
        for(int j=m+1; j<5; j++){
            if(list[m]>list[j]){
                a=list[m];
                list[m]=list[j];
                list[j]=a;
            }
        }
    }
    }
}

int main()
{
    cout<<"Enter 5 words: ";
    ordering();
    cout << "Alphebetical order: " << endl;
    for (int k = 0; k < 5; k++){
        cout << list[k] << " ";
    }
    cout << endl;

    return 0;
}

