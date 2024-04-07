#pragma once

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

inline std::string load_file(const char *path) {
  std::string content;
  std::ifstream file(path, std::ios::binary | std::ios::ate);
  if(!file.is_open())
    throw std::runtime_error("error opening file");
  int size = file.tellg();
  if(!size)
    return content;
  file.seekg(0, std::ios::beg);
  char buffer[size];
  file.read(buffer, size-1);
  buffer[size-1] = '\0';
  content = buffer;
  return content;
}
