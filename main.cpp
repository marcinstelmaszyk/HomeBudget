#include <iostream>
#include <fstream>
#include <iomanip>
#include <utility>
#include <vector>

typedef std::vector<std::string> Record;

class CsvHandler {
public:
    CsvHandler() = delete;
    explicit CsvHandler(std::string aFilePath)
            : theFilePath{std::move(aFilePath)} {
        file.open(theFilePath);
    }

    ~CsvHandler() {
        if (file.is_open()) {
            file.close();
        }
    }

    std::vector<Record> read() {
        if (!file.is_open())
            exit(1);

        std::vector<Record> table;

        table.emplace_back(readHeader(';'));

        std::string line;
        while (std::getline(file, line)) {
            table.emplace_back(splitLine(line, ';'));
        }

        return table;
    }

private:
    Record readHeader(const char del) {
        std::string headerLine;
        std::getline(file, headerLine);
        return splitLine(headerLine, del);
    }

    Record splitLine(const std::string& line, const char del) {
        std::istringstream ss(line);
        Record csvRecord;
        std::string field;

        while (std::getline(ss, field, del)) {
            csvRecord.push_back(field);
        }

        return csvRecord;
    }

private:
    const std::string theFilePath;
    std::fstream file;
};




int main() {
    CsvHandler handler("input/expenses.csv");
    auto accountRecords = handler.read();
    std::cout << accountRecords[1][1];

    return 0;
}
