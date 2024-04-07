#pragma once


#include "n.hpp"
namespace zms {
  enum class parser_type {
    text = 0,
  };
  enum class instructions{
    creat_unit = 0,
    other,
  };
class parser {
    friend class core;
    protected:
//      std::unordered_map<std::string, unit_id> m_map;    
      typedef const char * words;
      virtual bool parse(words script) = 0;
      ~parser() {}

  };
}
