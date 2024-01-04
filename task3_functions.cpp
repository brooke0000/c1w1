#include "task3_functions.h"

using namespace std;


string findCorners(std::string filePath)
{
    string result;

    // ************************
    // WRITE YOUR SOLUTION HERE
    // ************************
    ifstream fileStream(filePath);

    int topRow = -1, leftCol = -1, bottomRow = -1, rightCol = -1, row = 0;
    string line;

    while (getline(fileStream, line)) {
        istringstream iss(line);
        int col = 0;
        char cell;

        while (iss >> cell) {
            if (cell == '*') {
                if (topRow == -1) {
                    topRow = row;
                    leftCol = col;
                    bottomRow = row;
                    rightCol = col;
                }
                else {
                    leftCol = min(leftCol, col);
                    rightCol = max(rightCol, col);
                    bottomRow = row;
                }
            }
            col++;
        }        

        if (topRow != -1) {
            if (bottomRow == -1) {
                bottomRow = row;
            }            
        }
        row++;

    }

    fileStream.close();
    if (topRow == -1) {
        return "no rectangle :(";
    }


    stringstream resultStream;
    resultStream << "{\n  \"topLeft\" : [" << topRow << ", " << leftCol << "],\n";
    resultStream << "  \"bottomRight\" : [" << bottomRow << ", " << rightCol << "]\n}";

    return resultStream.str();

}

