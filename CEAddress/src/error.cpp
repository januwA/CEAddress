#include "error.h"

namespace ces
{
  using namespace std::string_literals;

  std::string ces_error::geterr(std::string_view name, std::string_view source, const ces::location &loc, std::string_view msg)
  {
    auto charCount = loc.end.column - loc.begin.column;
    return std::format("{}:{}\n\n{}\n{}{}", name, msg, source, std::string((size_t)(loc.begin.column - 1), ' '), std::string(charCount, '~'));
  }

}
