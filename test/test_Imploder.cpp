#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string

#include "../extra/include/Directory.hpp"
#include "../extra/include/ansi_colors.hpp"
#include "../extra/include/crc32_support.hpp"
#include "../extra/include/crc64_support.hpp"
#include "../extra/include/string_support.hpp"
#include "../include/Imploder/Linux/Exploder.hpp"
#include "../include/Imploder/Linux/Imploder.hpp"
#include "catch.hpp"

using namespace std;

SCENARIO("Verify LinuxImploder (webflow.zip)", "[Imploder]") {

  string filename = "data/homesite/perry-anderson.webflow.zip";
  LinuxImploder imploder(filename);
  imploder.execute();
  REQUIRE(!Directory("/tmp/perry-anderson.webflow.zip").fileExists());
  REQUIRE(!Directory("/tmp/perry-anderson.webflow.imploded.zip").fileExists());
  REQUIRE(!Directory("/tmp/perry-anderson.webflow.implosion.zip").fileExists());
  REQUIRE(Directory("data/homesite/perry-anderson.webflow.imploded.zip")
              .fileExists());
  REQUIRE(Directory("data/homesite/perry-anderson.webflow.implosion.zip")
              .fileExists());
}

SCENARIO("Verify LinuxImploder (src.zip)", "[Imploder]") {

  string filename = "data/homesite/src.zip";
  LinuxImploder imploder(filename);
  imploder.execute();
  REQUIRE(!Directory("/tmp/src.zip").fileExists());
  REQUIRE(!Directory("/tmp/src.imploded.zip").fileExists());
  REQUIRE(!Directory("/tmp/src.implosion.zip").fileExists());
  REQUIRE(Directory("data/homesite/src.imploded.zip").fileExists());
  REQUIRE(Directory("data/homesite/src.implosion.zip").fileExists());
}
