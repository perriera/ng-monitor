#ifndef _IMPLODER_HPP
#define _IMPLODER_HPP

#include <iostream>

#include "../extra/include/Definitions.hpp"

interface ImploderInterface {
  virtual void prerequisites() const pure;
  virtual const std::string &Filename() const pure;
  virtual void unzip() const pure;
  virtual void execute() pure;
  virtual void rezip() const pure;
};

#endif // _IMPLODER_HPP
