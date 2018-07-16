#ifndef INC_SCHECK_PARSER_H
#define INC_SCHECK_PARSER_H

#include <string>
#include <iostream>
#include <sstream>

class Parser {
  public:
    Parser( std::istream & is );
    std::string NextWord();
    unsigned int LineNo() const;
    std::string Context() const;
  private:
    bool ReadLine();
    std::istream & mIn;
    std::string mLine;
    unsigned int mLineNo;
    std::istringstream mIs;
};

#endif
