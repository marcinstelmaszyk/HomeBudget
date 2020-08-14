#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

namespace handlers {

// Shortnames
typedef std::vector<std::string> CsvRecord;

class CsvHandler {
 public:
  CsvHandler() = delete;

  // Initialize with a path to the file
  explicit CsvHandler(std::string aFilePath);

  ~CsvHandler();

  std::vector<CsvRecord> read();

 private:
  CsvRecord readHeader(const char del);

  CsvRecord splitLine(const std::string& line, const char del) const;

 private:
  const std::string theFilePath;
  std::fstream file;
};

}  // namespace handlers
