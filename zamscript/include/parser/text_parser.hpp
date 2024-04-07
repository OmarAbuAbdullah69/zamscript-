#pragma once


#include "core.hpp"
#include "parser/parser.hpp"
#include "n.hpp"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace zms {
  class text_parser: parser {
    friend class core;
    private:
      unit_id m_selected_unit;

      instructions translate(const std::string &word) {
        if(word == "unit") {
          return instructions::creat_unit;
        }else {
          return instructions::other;
        }
      }
      text_parser() {}
      virtual bool parse(words script) override {
        bool status = true;
        std::vector<instructions> inst;
        std::vector<std::string> words;
        std::istringstream iss(script);
        std::string word;
        while(iss >> word) {
          words.push_back(word);
        }
        inst.resize(words.size());
        for(unsigned i=0; i < words.size(); i++) {
          inst[i] = translate(words[i]);
        }

        unsigned size = inst.size();
        for(unsigned i =0; i < size; i++) {
          instructions s = inst[i];
          switch (s) {
            case instructions::creat_unit: {
              m_selected_unit = core::instance().creat_unit();
              if (i == size-1) {
                throw std::runtime_error("zms::error::height: named diclreations can't be the last word\n");
              }
              if (inst[i+1] != instructions::other) {
                throw std::runtime_error("zms::error::height: invalid namming\n");
              }
              i++;
              //m_map.emplace(words[i], m_selected_unit);
            }case instructions::other: {

            }
          }
        }
        return status;
      }
  };
}
