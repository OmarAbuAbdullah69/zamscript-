#include <iostream>
#include <ostream>
#include <zamscript.hpp>

using namespace zms;

int main (int argc, char *argv[]) {
  core &c = core::instance();
  unit_id uid = c.creat_unit();
  vh_id vid = c.add_vh(vhgtype::INTGER, uid);
  type &t = c.get_value(vid);

  std::cout << INTGER::s_extract(t) << std::endl;
  c.execute(uid);
}
