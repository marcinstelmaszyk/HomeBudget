#include <iostream>

#include "csvhandler.h"

int main() {
  handlers::CsvHandler handler("input/expenses.csv");
  auto accountRecords = handler.read();
  std::cout << accountRecords[1][1];

  return 0;
}
