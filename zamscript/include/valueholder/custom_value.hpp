#pragma once 

#include "valueholder/vh.hpp"
#include <initializer_list>
#include <vector>
namespace zms {
  class custom_value: public value {
    public:
      custom_value(std::initializer_list<value_type>);
      value &access(unsigned i);

    private:
      std::vector<value *> m_valmembers;
  };
}
