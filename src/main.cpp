#include "command/command.hpp"
#include <iostream>
#include <memory>
#include <zamscript.hpp>


using namespace zms;

class sayhi : public command {
  public:
    sayhi(unit_id u)
      :command(u){}
  private:
    void execute() override {
      std::cout << "hi\n";
    }
};


int main (int argc, char *argv[]) {
  core &c = core::instance();
  unit_id uid = c.creat_unit();
  vh_id vid = c.add_vh(value_type::INTGER);
  c.add_command(std::make_unique<sayhi>(uid));
  c.execute(uid);

  return 0;
}
