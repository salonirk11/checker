#include <iostream>
#include <string>
#include "dictionary.h"

using namespace std;

int main(){
  cout<<"scheck v0.1"<<endl;

  Dictionary d("data/mydict.dat");
  string word = "dog";

  while(getline(cin, word)){
    if ( d.Check( word ) )
      cout << word << " is OK\n";
    else
      cout << word << " is misspelt \n";
  }

}
