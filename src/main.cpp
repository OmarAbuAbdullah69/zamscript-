#include <iostream>
#include <zamscript.hpp>

using namespace zms;

int main (int argc, char *argv[]) {
  core &c = core::instance();
  unit_id uid = c.creat_unit();
  vh_id vid = c.add_vh(value_type::INTGER);
  INTGER i;
  INTGER i1;
  c.set_value(vid, INTGER(4));
  std::cout << INTGER::s_extract(vid) << std::endl;

  c.execute(uid);
}
