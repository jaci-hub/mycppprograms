#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin;
    fin.open("hughesinterviewdata.txt");
    string myline, mystring;
    getline(fin, myline);
    int age;
    string name, state, school;
    for(int i=0; i<myline.size(); i++){
        if(myline[i]!='-')
            mystring+=myline[i];
        if(myline[i]=='-' || i==myline.size()-1){
            //check if it is age
            if(isdigit(mystring[0])){
                if(stoi(mystring)>0)
                    age=stoi(mystring);
            }
            //check if it is state accronym
            else if(mystring.size()==2)
                state=mystring;
            //check if it is school
            else if(mystring.find("College")>=0 && mystring.find("College")<=250 || mystring.find("University")>=0 && mystring.find("University")<=250 || mystring.find("Institute")>=0 && mystring.find("Institute")<=250){
                school=mystring;
            }
            //if none of the above, store in name
            else name=mystring;
            
            mystring.clear();
        }
    }
    fin.close();
    cout<<name<<"-"<<age<<"-"<<school<<"-"<<state<<"\n";
    return 0;
}