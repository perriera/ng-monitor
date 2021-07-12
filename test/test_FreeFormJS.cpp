#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string

#include "../extra/include/Directory.hpp"
#include "../extra/include/ansi_colors.hpp"
#include "../extra/include/crc32_support.hpp"
#include "../extra/include/crc64_support.hpp"
#include "../extra/include/string_support.hpp"
#include "../include/Imploder/Linux/FreeFormJS.hpp"
#include "../include/Imploder/Linux/Imploder.hpp"
#include "catch.hpp"

using namespace std;

static string fn = "perry-anderson";
static string wf = "data/homesite/" + fn + ".webflow.zip";
static string src = "data/homesite/src.zip";
static string freeformjs = "data/homesite/" + fn + ".freeformjs.imploded.zip";

SCENARIO("Verify FreeFormJSExploder (construct)", "[FreeFormJS]") {

  LinuxImploder imploder1(wf);
  imploder1.execute();
  REQUIRE(!Directory("/tmp/" + fn + ".webflow.zip").fileExists());
  REQUIRE(!Directory("/tmp/" + fn + ".webflow.imploded.zip").fileExists());
  REQUIRE(!Directory("/tmp/" + fn + ".webflow.implosion.zip").fileExists());
  REQUIRE(Directory(wf).fileExists());
  REQUIRE(Directory(replace_all(wf, ".zip", ".imploded.zip")).fileExists());
  REQUIRE(Directory(replace_all(wf, ".zip", ".implosion.zip")).fileExists());

  LinuxImploder imploder2(src);
  imploder2.execute();
  REQUIRE(!Directory("/tmp/src.zip").fileExists());
  REQUIRE(!Directory("/tmp/src.imploded.zip").fileExists());
  REQUIRE(!Directory("/tmp/src.implosion.zip").fileExists());
  REQUIRE(Directory(src).fileExists());
  REQUIRE(Directory(replace_all(src, ".zip", ".imploded.zip")).fileExists());
  REQUIRE(Directory(replace_all(src, ".zip", ".implosion.zip")).fileExists());
}

SCENARIO("Verify FreeFormJSExploder (exploder)", "[FreeFormJSX]") {

  REQUIRE(Directory(wf).fileExists());
  REQUIRE(Directory(replace_all(wf, ".zip", ".imploded.zip")).fileExists());
  REQUIRE(Directory(replace_all(wf, ".zip", ".implosion.zip")).fileExists());
  REQUIRE(Directory(src).fileExists());
  REQUIRE(Directory(replace_all(src, ".zip", ".imploded.zip")).fileExists());
  REQUIRE(Directory(replace_all(src, ".zip", ".implosion.zip")).fileExists());

  REQUIRE(Directory(freeformjs).fileExists());
  FreeFormJSExploder exploder(freeformjs);
  exploder.execute();
  REQUIRE(!Directory("/tmp/src.upgrades.zip").fileExists());
  REQUIRE(!Directory("/tmp/src.zip").fileExists());
  REQUIRE(!Directory("/tmp/src.imploded.zip").fileExists());
  REQUIRE(!Directory("/tmp/src.implosion.zip").fileExists());
  REQUIRE(Directory(src).fileExists());
  REQUIRE(Directory(replace_all(src, ".zip", ".upgrades.zip")).fileExists());
  REQUIRE(Directory(freeformjs).fileExists());
}
