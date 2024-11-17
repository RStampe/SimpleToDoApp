#include <iostream>
#include <fstream>
#include <sstream> // For std::stringstream
#include <string>
#include <vector>
#include <filesystem> // C++17 and later
using namespace std;



int main() {


    // std::ofstream archiveFile("archive.csv");

    // if (!todoFile || !doneFile || !archiveFile) {
    //     std::cerr << "Error opening files" << std::endl;
    //     return 1;
    // }

 while (true) {
        int action;
        std::cout << "Select action: 1: todo, 2: done, 3: archive, 4: quit \n";
        std::cin >> action;

        // Check if the input is valid
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        // Clear the newline character left in the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (action == 1) {
            std::string userInput;
            std::cout << "Add task: ";
            std::getline(std::cin, userInput); // Now this will work as expected

            std::cout << "You entered: " << userInput << std::endl;

            // Writing to file
            std::ofstream todoFile("todo.txt", std::ios::app);
            if (todoFile) {
                todoFile << userInput << "\n";
                std::cout << "Task saved to todo.txt" << std::endl;
            } else {
                std::cerr << "Error opening the file for writing." << std::endl;
            }

            todoFile.close();
        } else if (action == 2) {
            std::ifstream inFile("todo.txt");
            int lineNumber;
            std::cout << "Mark task as done: ";
            std::cin >> lineNumber;

            // Check if the input is valid
            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            std::vector<std::string> lines;
            std::string line;
            std::string doneTask;
            int currentLineNumber = 1;
            while (std::getline(inFile, line)) {
                if (currentLineNumber != lineNumber) {
                    lines.push_back(line); // Keep all lines except the one to remove
                }
                else {
                    doneTask = line;
                    std::ofstream doneFile("done.txt", std::ios::app);
                    if (doneFile) {
                        doneFile << line << "\n";
                        std::cout << "Task saved to done.txt" << std::endl;
                    } else {
                        std::cerr << "Error opening the file for writing." << std::endl;
                    }
                    doneFile.close();
                }
                lines.push_back(line);
                ++currentLineNumber;
            }

            inFile.close();

            // Output the lines from the vector
            for (const auto& l : lines) {
                std::cout << l << std::endl;
            }

        } else if (action == 3) {

        } else if (action == 4) {
            std::cout << "Quiting application";

            // doneFile.close();
            // archiveFile.close();            
            return 0;
        } else {
            action = 0;
        }
    }
    return 0;
}