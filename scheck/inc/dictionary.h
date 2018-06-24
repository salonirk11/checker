#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H

#include <string>
#include <set>
#include <fstream>

class Dictionary {

  std::set <std::string> mWords;

  public:
    Dictionary( const std::string & fname ){
      std::ifstream wlist( fname.c_str() );
      std::string word;
      while( std::getline( wlist, word ) ) {
        mWords.insert( word );
      }
    }

    bool Check( const std::string & word  ) const{
      return mWords.find( word ) != mWords.end();
    }

};

#endif
