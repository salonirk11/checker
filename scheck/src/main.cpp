#include <iostream>
#include <string>
#include "dictionary.h"
#include "parser.h"

using namespace std;

int main(){

  try{
    cout<<"scheck v0.4"<<endl;

    Dictionary d("../data/mydict.dat");
    ifstream sub( "../data/sub1.txt" );

    if ( ! sub.is_open() )
        throw ScheckError( "cannot open data/sub1.txt" );

    Parser p( sub );
    string word;
    while(( word = p.NextWord() ) != ""){
      if ( d.Check( word ) )
        cout << word << " is OK\n";
      else
        cout << word << " is misspelt at line " << p.LineNo() << "\n";
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
