#include <iostream>

#include "accountrecords.h"
#include "csvhandler.h"

int main() {
  handlers::CsvHandler handler("input/expenses.csv");
  auto accountRecords = handler.read();

  dataobjects::AccountRecords ar;
  ar.load(accountRecords);

  return 0;
}
