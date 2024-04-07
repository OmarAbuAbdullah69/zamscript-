#pragma once

#include "command.hpp"
#include "core.hpp"
#include "n.hpp"

namespace zms {
  class creat_unit : public command {
  public:
    creat_unit(unit_id parent)
      :command(parent){}
    ~creat_unit() {
    }
  private:
    void execute() override {
      core::instance().creat_unit();
    }

};
}
