#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Define a structure to represent a row in the CSV table
struct CSVRow {
    std::vector<std::string> data;
};

// Function to read CSV file into a vector of CSVRows
std::vector<CSVRow> readCSV(const std::string& filename) {
    std::vector<CSVRow> rows;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        return rows;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        CSVRow row;

        while (std::getline(ss, cell, ',')) {
            row.data.push_back(cell);
        }

        rows.push_back(row);
    }

    file.close();
    return rows;
}

int main() {
    std::vector<CSVRow> data = readCSV("data.csv");

    // Print the CSV data
    for (const auto& row : data) {
        for (const auto& cell : row.data) {
            std::cout << cell << " | ";
        }
        std::cout << std::endl;
    }

    return 0;
}
