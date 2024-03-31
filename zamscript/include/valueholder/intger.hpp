#include "core.hpp"
#include "n.hpp"
#include "vh.hpp"
#include <stdexcept>

namespace zms {
  class INTGER: public value {
    public:
      INTGER(int value = 0)
        :m_value(value), m_pvalue(nullptr), m_p(false) {}
      INTGER(int *value) 
        :m_pvalue(value){
          if(!value) {
            m_p = false;
            m_value = 0;
          } else {
            m_p = true;
          }
      }
      virtual value_type get_type() const override{
        return s_get_type();
      }
      virtual void  copy(const value &other) override{
        value_type ovt = other.get_type();
        switch (ovt) {
          default: {
                     throw std::runtime_error("zms::error::low no conversion to intger");
                   }
          case value_type::INTGER: {
                                      INTGER &o = *((INTGER *) &other);
                                      if(o.m_p) {
                                        m_p = true;
                                        m_pvalue = o.m_pvalue;
                                        m_value = o.m_value;
                                      } else {
                                        if(m_p) {
                                          *m_pvalue = o.m_value;
                                        } else {
                                          m_value = o.m_value;
                                        }
                                      }
                                   }
        }
      }

      static int s_extract(vh_id vid) {
        value &v = core::instance().get_value(vid);
        if (value_type::INTGER == v.get_type()) {
          return (*((INTGER *) &v)).get_value();
        } else {
          throw std::runtime_error("zms::error::low: value is not an INTGER\n");
        }
        return -1;
      }
     
      inline int get_value() const{
        return m_p ? *m_pvalue:m_value;
      }

    private:
      static value_type s_get_type() {
        return value_type::INTGER;
      }

      int m_value;
      int *m_pvalue;
      bool m_p;
  };

}
