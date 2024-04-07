#include "load_files.hpp"
#include "parser/parser.hpp"
#include <iostream>
#include <zamscript.hpp>


using namespace zms;

class sayhi : public command {
  public:
    sayhi(unit_id u)
      :command(u){}
    ~sayhi() {
    }
  private:
    void execute() override {
      std::cout << "hi\n";
    }

};


int main (int argc, char *argv[]) {

  core &c = core::instance();
  c.set_parser(parser_type::text);
  c.load(load_file(argv[1]).c_str());
  //unit_id uid = c.find_unit("main");
  //c.execute(uid);
// int i = 6;
//  unit_id uid = c.creat_unit();
//  c.add_command(std::make_unique<sayhi>(uid));
//  vh_id rid = c.add_vh(value_type::INTGER, uid);
//  c.set_value(rid, INTGER(&i));
//  c.set_value(rid, INTGER(3));
//  c.execute(uid);

// std::cout << i << std::endl;

  return 0;
}
