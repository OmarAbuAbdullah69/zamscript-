#pragma once


namespace zms {
  typedef unsigned int unit_id;

  class vh_id {
    friend class core;
    vh_id(){}
    private:
    vh_id(unit_id u, unsigned index)
      :m_unit(u), m_index(index), m_points(true){}

    unit_id m_unit;
    unsigned m_index;
    bool m_points;
  };
}
