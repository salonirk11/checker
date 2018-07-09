#ifndef INC_ERROR_H
#define INC_ERROR_H
#include <stdexcept> //runtime_error cass is defined here
#include <string>

/*
ScheckError class has a virtual member function what() inherited from
the std::exception base class. It returns a const char * pointing to
the error message the function contains, if the actual exception type
supports error messages.
*/

class ScheckError : public std::runtime_error {
   public:
      ScheckError( const std::string & emsg )
         : std::runtime_error( emsg ) {
           //pass error message to base class using intitalisation list
      }
};
#endif
