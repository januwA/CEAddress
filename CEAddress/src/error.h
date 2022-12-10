#pragma once

#include "pch.h"
#include <format>
#include "location.hh"

namespace ces
{
  using namespace std::string_literals;

  class ces_error : public std::exception
  {
  public:
    std::string geterr(std::string_view name, std::string_view source, const ces::location &loc, std::string_view msg);

    explicit ces_error(std::string_view name, std::string_view source, const ces::location& loc, std::string_view msg = "")
      : std::exception(geterr(name, source, loc, msg).data())
    {
    }
  };

  class lexer_error : public ces_error
  {
  public:
    explicit lexer_error(std::string_view source, const ces::location& loc)
      : ces_error("Lexer Error", source, loc) {}
  };

  class parser_error : public ces_error
  {
  public:
    explicit parser_error(std::string_view source, const ces::location& loc)
      : ces_error("Parser Error", source, loc) {}
  };

  class runtime_error : public ces_error
  {
  public:
    explicit runtime_error(std::string_view source, const ces::location& loc, std::string_view msg)
      : ces_error("Runtime Error", source, loc, msg) {}
  };
}
