#include "csvhandler.h"

namespace handlers {

//------------------------------------------------------------------------------
// FUNCTION: Constructor
//------------------------------------------------------------------------------
CsvHandler::CsvHandler(std::string aFilePath)
    : theFilePath{std::move(aFilePath)} {
  file.open(theFilePath);
}

//------------------------------------------------------------------------------
// FUNCTION: Destructor
//------------------------------------------------------------------------------
CsvHandler::~CsvHandler() {
  // Close the file on destruction
  if (file.is_open()) {
    file.close();
  }
}

//------------------------------------------------------------------------------
// FUNCTION: read
//------------------------------------------------------------------------------
std::vector<CsvRecord> CsvHandler::read() {
  if (!file.is_open()) exit(1);

  std::vector<CsvRecord> records;

  // Read the header line and put it as the first CsvRecord
  records.emplace_back(readHeader(';'));

  // Read remaining lines and store them in the vector
  std::string line;
  while (std::getline(file, line)) {
    records.emplace_back(splitLine(line, ';'));
  }

  return records;
}

//------------------------------------------------------------------------------
// FUNCTION: readHeader
//------------------------------------------------------------------------------
CsvRecord CsvHandler::readHeader(const char del) {
  std::string headerLine;
  std::getline(file, headerLine);
  return splitLine(headerLine, del);
}

//------------------------------------------------------------------------------
// FUNCTION: splitLine
//------------------------------------------------------------------------------
CsvRecord CsvHandler::splitLine(const std::string& line, const char del) const {
  std::istringstream ss(line);
  CsvRecord record;
  std::string field;

  while (std::getline(ss, field, del)) {
    record.push_back(field);
  }

  return record;
}

}  // namespace handlers