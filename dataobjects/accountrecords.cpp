#include "accountrecords.h"

namespace dataobjects {

void AccountRecords::load(std::vector<std::vector<std::string>> csvTable) {
  parseHeader(csvTable[0]);
  for (std::size_t row = 1; row < csvTable.size(); ++row) {
    theTable[theHeaderFields[0]].push_back(csvTable[row][0]);
  }
}

void AccountRecords::parseHeader(const std::vector<std::string> &csvHeader) {
  const std::string headerFieldSymbol{'#'};

  // Store header fields in member theHeaders
  for (auto field : csvHeader) {
    // Find the position of a header field symbol and remove it
    std::size_t characterPos = field.find(headerFieldSymbol);
    field.erase(characterPos, characterPos + headerFieldSymbol.length());

    theHeaderFields.emplace_back(std::move(field));
  }
}

std::ostream &operator<<(std::ostream &os, const AccountRecords &records) {
  os << "Headers: ";
  for (const auto &field : records.theHeaderFields) os << field << " ";
  return os;
}

}  // namespace dataobjects