#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string

#include "../extra/include/Directory.hpp"
#include "../extra/include/ansi_colors.hpp"
#include "../extra/include/crc32_support.hpp"
#include "../extra/include/crc64_support.hpp"
#include "../extra/include/string_support.hpp"
#include "catch.hpp"

using namespace std;

static string test_fullpath = "docopt/include/docopt_private.h";
static string test_filename = "docopt_private.h";
static string test_pathname = "docopt/include/";

SCENARIO("Verify Directory.filename()", "[Directory]") {

  string a = test_fullpath;
  auto b = Directory(a).filename();
  REQUIRE(a != b);
  REQUIRE(b == test_filename);
}

SCENARIO("Verify Directory.pathname()", "[Directory]") {

  string a = test_fullpath;
  auto b = Directory(a).pathname();
  REQUIRE(a != b);
  REQUIRE(b == test_pathname);
}

SCENARIO("Verify Directory.listing() 'path exists'", "[Directory]") {

  string a = test_fullpath;
  auto b = Directory(a).listing();
  REQUIRE(b.size() == 4);
}

SCENARIO("Verify Directory.listing() 'path does not exists'", "[Directory]") {

  string a = "garabage";
  auto b = Directory(a).listing();
  REQUIRE(b.size() == 0);
}

SCENARIO("Verify Directory.listing() 'only path given'", "[Directory]") {

  string a = test_pathname;
  auto b = Directory(a).listing();
  REQUIRE(b.size() == 4);
}

SCENARIO("Verify Directory.listing() 'no path given'", "[Directory]") {

  string a = "";
  auto b = Directory(a).listing();
  REQUIRE(b.size() > 0);
}

SCENARIO("Verify Directory ", "[Directory]") {

  string filename = test_fullpath;
  auto fileExists = Directory(filename).fileExists();
  REQUIRE(fileExists);
}
