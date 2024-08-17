#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to append user input to the existing file
void appendToFile(const std::string& filename) {
    std::ofstream file;
    // Open the file in append mode
    file.open(filename, std::ios::app);

    if (!file) {
        std::cerr << "Unable to open file for appending." << std::endl;
        return;
    }

    std::string userInput;
    std::cout << "Enter text to append to the file: ";
    std::getline(std::cin, userInput);

    // Write the user input to the file
    file << userInput << std::endl;
    file.close();
}

// Function to reverse the content of the original file and save it to a new file
void reverseFileContent(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream file(inputFile);
    if (!file) {
        std::cerr << "Unable to open file for reading." << std::endl;
        return;
    }

    std::string content;
    std::string line;
    // Read the entire file content into a string
    while (std::getline(file, line)) {
        content += line + "\n";
    }
    file.close();

    // Reverse the content
    std::reverse(content.begin(), content.end());

    // Save the reversed content to the new file
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Unable to open file for writing." << std::endl;
        return;
    }
    outFile << content;
    outFile.close();
}

int main() {
    std::string inputFilename = "CSC450_CT5_mod5.txt";
    std::string outputFilename = "CSC450_mod5_reverse.txt";

    // Step 1: Append user input to the existing file
    appendToFile(inputFilename);

    // Step 2: Reverse the file content and save it to a new file
    reverseFileContent(inputFilename, outputFilename);

    std::cout << "Text appended and file content reversed successfully." << std::endl;
    return 0;
}
