#pragma once


#include "core.hpp"
#include "parser/parser.hpp"
#include "n.hpp"
#include <string>

namespace zms {
  class text_parser: parser {
    friend class core;
    private:
      text_parser();
      instructions translate(const std::string &word);
      virtual bool parse(words script) override;
  };
}
