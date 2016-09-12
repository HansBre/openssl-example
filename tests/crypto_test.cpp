#include "crypto.hpp"
#include <cassert>

using namespace std;

int main() {
  // Results copied from https://caligatio.github.io/jsSHA/
  assert(Crypto::hex(Crypto::sha1("Test")) == "640ab2bae07bedc4c163f679a746f7ab7fb5d1fa");
  assert(Crypto::hex(Crypto::sha1("Test", 2)) == "af31c6cbdecd88726d0a9b3798c71ef41f1624d5");

  // Results copied from http://www.freecodeformat.com/pbkdf2.php
  assert(Crypto::hex(Crypto::pbkdf2("Password", "Salt", 4096, 128 / 8)) == "f66df50f8aaa11e4d9721e1312ff2e66");
  assert(Crypto::hex(Crypto::pbkdf2("Password", "Salt", 8192, 512 / 8)) == "a941ccbc34d1ee8ebbd1d34824a419c3dc4eac9cbc7c36ae6c7ca8725e2b618a6ad22241e787af937b0960cf85aa8ea3a258f243e05d3cc9b08af5dd93be046c");
  
  assert(Crypto::hex(Crypto::md5("hey")) == "d0eedb799584d850fdd802fd3c27ae34");
  assert(Crypto::hex(Crypto::sha256("Tester")) == "9e7cd9cb5a63a3591e16f4d835f32a1c4a84ab66e39ae27aa448c03b66bf63e7");
  assert(Crypto::hex(Crypto::sha512("Ole er kul")) == "ab8c10e45a103a969cac7a9a3bcc23471c2c30f0777edc30b4110f419499128a");
}
