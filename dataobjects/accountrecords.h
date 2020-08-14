#pragma once

#include <iostream>
#include <map>
#include <vector>

namespace dataobjects {

class AccountRecords {
 public:
  void load(std::vector<std::vector<std::string>> csvTable);

 private:
  void parseHeader(const std::vector<std::string> &csvHeader);

 public:
  friend std::ostream &operator<<(std::ostream &os,
                                  const AccountRecords &records);

 private:
  std::map<std::string, std::vector<std::string>> theTable;
  std::vector<std::string> theHeaderFields;
};

}  // namespace dataobjects