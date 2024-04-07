#include "unit.hpp"
#include <iostream>

namespace zms {
  unit::unit(unit_id parent) 
    :m_parent(parent){
    std::cout << "unit_created\n";    
  }
  unit::~unit() {
    for(auto cmd : m_commands) {
      delete cmd;
    }
  }
  void unit::add_command(command *cmd) {
    m_commands.push_back(cmd);
  }

  void unit::execute() {
    for(auto cmd : m_commands) {
      cmd->execute();
    }
  }
  unsigned unit::add_vh(const vh &v) {
    m_vhs.push_back(v);
    return m_vhs.size()-1;
  }
}
