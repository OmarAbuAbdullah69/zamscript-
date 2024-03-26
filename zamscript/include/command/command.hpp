#pragma once

#include "n.hpp"

namespace zms {
  class command {
    friend class core;
    friend class unit;
    public:
      virtual ~command(){}
    protected:
      command(unit_id parent) 
        :m_parent(parent) {}
      virtual void execute() = 0;
    private:
      unit_id m_parent;
  };
}
