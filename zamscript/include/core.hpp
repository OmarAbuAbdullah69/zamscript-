#pragma once

#include "n.hpp"
#include "unit.hpp"
#include <vector>
namespace zms {
  class core {
    public:
      static core &instance() {
        static core c;
        return c;
      }
      
      unit_id creat_unit(unit_id parent = 0);
  // add command for dev not the user
      void add_command(std::unique_ptr<command> cmd);
      void execute(unit_id u);
      vh_id add_vh(value_type vhg, unit_id u=0);
      value &get_value(vh_id vid);
      void set_value(vh_id vid, const value &v);
    private:
      core();

      std::vector<unit> m_units;
      std::vector<vh> m_vhs;

  };
}
