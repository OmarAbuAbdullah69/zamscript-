#include "core.hpp"
#include "parser/parser.hpp"
#include "parser/text_parser.hpp"

namespace zms {
  core::core() {

  }
  unit_id core::creat_unit(unit_id parent) {
    m_units.push_back(unit(parent));
    return m_units.size();
  }
  void core::add_command(std::unique_ptr<command> cmd) {
    unit_id u = cmd->m_parent;
    if(u == 0 || u > m_units.size())
      throw std::runtime_error("zms::error::low: command couldn't be add, invalid unit_id");
    m_units[u-1].add_command(cmd.release());  
  }
  void core::execute(unit_id u) {
    if (u > m_units.size())
      throw std::runtime_error("zms::error::low: attempting to execute none existing units");
    m_units[u-1].execute();
  }
  vh_id core::add_vh(value_type vhg, unit_id u) {
    vh v(vhg);
    if(!u) {
      m_vhs.push_back(v);
      return vh_id(0, m_vhs.size()-1);
    } else if(u > m_units.size())
      throw std::runtime_error("zms::error::low: attempting to execute none existing units");
    return vh_id(u, m_units[u-1].add_vh(v));
  }
  value &core::get_value(vh_id vid) {
    if(!vid.m_points)
      throw std::runtime_error("zms::error::low: invalid access vh_id don't point at a vh");
    if(!vid.m_unit)
      return m_vhs[vid.m_index].get_value();

    return m_units[vid.m_unit-1].m_vhs[vid.m_index].get_value();

  }
  void core::set_value(vh_id vid, const value &v) {
    if(!vid.m_points)
      throw std::runtime_error("zms::error::low: invalid access vh_id don't point at a vh");
    if(!vid.m_unit) {
      m_vhs[vid.m_index].set_value(v);
      return;
    }
    m_units[vid.m_unit-1].m_vhs[vid.m_index].set_value(v);

  }

  void core::set_parser(parser_type p) {
    switch (p) {
      case parser_type::text: {
                                m_parser = new text_parser;
                              }
    }
  }
  void core::load(const char *script) {
    check_parser();
    m_parser->parse(script);
  }

}
