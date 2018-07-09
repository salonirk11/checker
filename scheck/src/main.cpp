#include <iostream>
#include <string>
#include "dictionary.h"

using namespace std;

int main(){

  try{
    cout<<"scheck v0.1"<<endl;

    Dictionary d("data/not_there.dat");
    string word = "dog";

    while(getline(cin, word)){
      if ( d.Check( word ) )
        cout << word << " is OK\n";
      else
        cout << word << " is misspelt \n";
    }

  }
  catch( const ScheckError & e ) {
    //pass error by refernce in const always - memory management+virtual function handling
    cerr << "Error: " << e.what() << endl;
    return 1;
  }
  catch( ... ) {
    cerr << "Error: unknown exception" << endl;
    return 2;
  }

}
