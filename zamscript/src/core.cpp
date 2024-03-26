#include "core.hpp"
#include <stdexcept>

namespace zms {
  core::core() {

  }
  unit_id core::creat_unit(unit_id parent) {
    m_units.push_back(unit(parent));
    return m_units.size();
  }

  // add command for dev not the user
  void core::add_command(std::unique_ptr<command> cmd) {
    m_units[cmd->m_parent-1].add_command(cmd.release());
  }
  void core::execute(unit_id u) {
    m_units[u-1].execute();
  }
  vh_id core::add_vh(vhgtype vhg, unit_id u) {
    if(!u) {
      m_vhs.push_back(vh(vhg));
      return vh_id(0, m_vhs.size()-1);
    }
    return vh_id(u, m_units[u-1].add_vh(vh(vhg)));
  }
  type &core::get_value(vh_id vid) {
    if(!vid.m_points)
      throw std::runtime_error("zms::error::low: invalid access vh_id don't point at a vh");
    if(!vid.m_unit)
      return m_vhs[vid.m_index].get_value();

    return m_units[vid.m_unit-1].m_vhs[vid.m_index].get_value();

  }

}
