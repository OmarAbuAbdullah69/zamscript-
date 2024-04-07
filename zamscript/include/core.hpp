#pragma once

#include "n.hpp"
#include "unit.hpp"
#include "parser/parser.hpp"
#include <memory>
#include <vector>

namespace zms {
  class core {
    public:
      static core &instance() {
        static core c;
        return c;
      }
      
      unit_id creat_unit(unit_id parent = 0);
      void add_command(std::unique_ptr<command> cmd);
      void execute(unit_id u);
      vh_id add_vh(value_type vhg, unit_id u=0);
      value &get_value(vh_id vid);
      void set_value(vh_id vid, const value &v);
      // only user      
      void set_parser(parser_type p);
      inline void check_parser() {
        if(!m_parser)
          throw std::runtime_error("zms::error::low: no parser selceted\n");
      }
      void load(const char *script);
      unit_id find_unit(const char *unit_name);

      // for library classes
      inline unit_id get_unit_parent(unit_id uid) {
        return m_units[uid-1].m_parent;
      }

    private:
      core();
      parser *m_parser;
      std::vector<unit> m_units;
      std::vector<vh> m_vhs;

  };
}
