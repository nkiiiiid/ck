#include "cmdline.h"
#include "base58.cpp"

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  cmdline::parser a;
  a.add<string>("enb58", 'e', "encode string with base58", false, "");
  a.add<string>("deb58", 'd', "decode string with base58", false, "");

  a.parse_check(argc, argv);
  
  if (a.exist("enb58")){
  std::string enstr = a.get<string>("enb58");
  int len = enstr.length();
  unsigned char encoded[len * 137 / 100];
  base58encode(enstr, len, encoded);
  cout << encoded<< endl;
  }
  
  if (a.exist("deb58")){
  std::string destr = a.get<string>("deb58");
  int len = destr.length();
  unsigned char text[len * 137 / 100];
  base58decode(destr, len, text);
  cout << text<< endl;
  }
  
  return 0;
}
