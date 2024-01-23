
//********************************************************************************************
//*******************           STUDENT NAME: MUHAMMED UYAN                  *****************
//*******************           STUDENT NUMBER: B231302376                   *****************
//*******************          ASSIGNMENT # : ASSIGMENT#2 (Project)          *****************
//*******************               - HONOR CODE -                           *****************
//*************         I pledge my honor to avoid behaviors that                *************
//************* do not comply with the student code of conduct such as cheating, *************
//*************     deception, and misleading during my whole student life.      *************
//********************************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Method that writes to a file
void writeToFile() {
    
    // Open file.
    ofstream writeData("data.txt");

    // Checking if there is an error opening the file.
    if (!writeData.is_open()) {
        cerr << "File not opened!" << endl;
        return;
    }

    // Creating the input matrix. Between [5x5] and [20x20].
    const int inputRow = rand() % 16 + 5;
    int** inputArray = new int* [inputRow];

    for (int i = 0; i < inputRow; i++) {

        inputArray[i] = new int[inputRow];
    }
    // Filling the input matrix with random values. Include numbers between [10-20]. 
    for (int i = 0; i < inputRow; i++) {
        for (int j = 0; j < inputRow; j++) {
            inputArray[i][j] = rand() % 11 + 10;
        }
    }

    // Print input matrix.
    writeData << "Input Matrix:" << endl;
    writeData << "------------" << endl;
    for (int i = 0; i < inputRow; i++) {
        for (int j = 0; j < inputRow; j++) {
            writeData << setw(2) << inputArray[i][j] << " ";
        }
        writeData << endl;
    }

    writeData << endl;

    // Calculating the number of Rows of the Core matrix and creating the Core matrix.
    int** coreArray;
    const int coreRow = rand() % 4 + 2;
    coreArray = new int* [coreRow];
    for (int i = 0; i < coreRow; i++) {
        coreArray[i] = new int[coreRow];
    }

    // Fill the Core matrix with random values.
    for (int i = 0; i < coreRow; i++) {
        for (int j = 0; j < coreRow; j++) {
            coreArray[i][j] = rand() % 11;
        }
    }

    // Print Core matrix.
    writeData << "Core Matrix:" << endl;
    writeData << "-----------" << endl;
    for (int i = 0; i < coreRow; i++) {
        for (int j = 0; j < coreRow; j++) {
            writeData << setw(2) << coreArray[i][j] << " ";
        }
        writeData << endl;
    }

    writeData << endl;

    // Calculating the number of Rows of the output matrix. (Rows = Columns).
    const int outputRow = inputRow - coreRow + 1;
    // Creating the output matrix.
    int** outputArray = new int* [outputRow];

    for (int i = 0; i < outputRow; i++) {
        outputArray[i] = new int[outputRow];
    }

    // Calculation required to create the output matrix.
    for (int i = 0; i < outputRow; i++) {
        for (int j = 0; j < outputRow; j++) {
            int x = coreArray[0][0] * inputArray[i + 1][j + 1];
            int y = coreArray[1][0] * inputArray[i][j + 1];
            int z = coreArray[0][1] * inputArray[i + 1][j];
            int t = coreArray[1][1] * inputArray[i][j];
            outputArray[i][j] = (x + y + z + t) / 4;
        }
    }

    // Print Output matrix.
    writeData << "Output Matrix:" << endl;
    writeData << "-------------" << endl;
    for (int i = 0; i < outputRow; i++) {
        for (int j = 0; j < outputRow; j++) {
            writeData << setw(5) << outputArray[i][j] << " ";
        }
        writeData << endl;
    }

    // The created matrices are released from memory.
    for (int i = 0; i < inputRow; i++) {
        delete[] inputArray[i];
    }
    delete[] inputArray;

    for (int i = 0; i < coreRow; i++) {
        delete[] coreArray[i];
    }
    delete[] coreArray;

    for (int i = 0; i < outputRow; i++) {
        delete[] outputArray[i];
    }
    delete[] outputArray;

    // The file is closed.
    writeData.close();

}

// Method that reads and prints the content of the file.
void readToFile() {
    string readLine;
    // Reading from file logic...
    ifstream readData("data.txt");

    // Checking if there is an error opening the file. 
    // If there is no file to read, it goes back to option 1, writes to the file, 
    // and then reads from the file.
    if (!readData.is_open()) {
        cerr << "File not found! Defaulting to Option 1." << endl;
        cout << endl;
        writeToFile();
        readToFile();
        return;
    }

    // Check if there is an error opening the file.
    while (getline(readData, readLine)) {
        cout << readLine << endl;
    }
    // The file is closed.
    readData.close();
}

int main() {

    int selection;
    // This loop asks the user whether they want to write to a file or 
    // read from a file and ensures that the desired action is performed.
    while (true) {
        cout << endl;
        cout << "(1) - Writing to file." << endl;
        cout << "(2) - Reading from file." << endl;
        cout << "(3) - Exit." << endl;
        cout << "Select the action you want to take: ";

        cin >> selection;
        cout << endl;

        if (selection == 1) {
            writeToFile();
            readToFile();
        }
        else if (selection == 2) {
            readToFile();
        }
        else if (selection == 3) {
            cout << "Exiting the program." << endl;
            break;// Terminates the program.
        }
        else {
            cout << "Invalid option! Please select either 1, 2, or 3." << endl;
        }
    }
    return 0;
}
