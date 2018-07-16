#include "parser.h"
#include "error.h"

using std::istream;
using std::string;

Parser :: Parser(istream & is)
 :mSubmission(is) , mLineNo(0), mPos(0), mState(stInSpace){
}

char Parser :: NextChar() {
  if ( mPos >= mLine.size() ) {
     if ( ! ReadLine() )
      return 0;
  }
  return mLine[ mPos++ ];
}

string Parser :: NextWord() {
  string word;
  while( char c = NextChar() ) {
    switch( mState ) {

      case stInSpace:
            if(std::isalpha(c)){
              word += c;
              mState = stInWord;
            }
            else if(std::isdigit(c))
              mState = stInNum;
            break;

      case stInWord:
            if(std::isalpha(c)||c=='\'')
              word += c;
            else if(std::isdigit(c))
              mState = stInNum;
            else{
              mState = stInSpace;
              return word;
            }
            break;

      case stInNum:
            if(std::isalnum(c)||c=='\'')
              word += c;
            else{
              mState = stInSpace;
              word = "";
            }
            break;

      default:
            throw ScheckError( "bad state" );
    }
  }
  return word;
}

unsigned int Parser :: LineNo() const {
  return mLineNo;
}

string Parser :: Context() const {
  return mLine;
}

bool Parser :: ReadLine() {
  if ( getline( mSubmission, mLine ) ) {
    mPos = 0;
    mLineNo++;
    mLine += ' ';
    return true;
  }
  else if ( mSubmission.eof() )
    return false;
  else
    throw ScheckError( "file read error" );
}
