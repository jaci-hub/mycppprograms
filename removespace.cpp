#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
  string name;
  cout << "Enter name: ";
  getline(cin, name);
  for (int i = 0; i < name.length(); i++) {
      if (name[i] == ' ') 
        name.erase(remove(name.begin(), name.end(), ' '), name.end());
  }
  cout << name << endl;
  cout << "Your name has " << name.length() << " letters!" << endl;

  return 0;
}