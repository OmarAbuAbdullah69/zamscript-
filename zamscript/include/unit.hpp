#pragma once

#include "n.hpp"
#include "command/command.hpp"
#include "valueholder/vh.hpp"
#include <vector>
namespace zms {
  class unit {
    friend class core;
    public:
      ~unit();
    private:
      unit(unit_id parent);
      void execute();
      void add_command(command *cmd);
      unsigned add_vh(vh v);

      unit_id m_parent;
      std::vector<command *> m_commands;
      std::vector<vh> m_vhs;
  };
}
