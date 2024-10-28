#include <bits/stdc++.h>
using namespace std;

/* 
    File Handling in C++
    ==================== 
    Files are used to store information permanently on a storage device like a disk.

    In C++, file I/O is implemented through the <fstream> header file.

    Various Data Types for File Handling
    ------------------------------------

        fstream : used for both input & output
        ifstream: used for input (reading from a file)
        ofstream: used for output (writing to a file)

    Streams in File Handling
    ------------------------
                  (write data to file)         (read data from file)            (input data to program)
    o/p stream  ----------------->  Disk file -------------------> i/p stream ---------------> C++ Program
    (receives data from program)                                (sends data to program)

    Text File vs Binary File
    ------------------------

        Text File  : Stores information as ASCII characters.
        Binary File: Stores information in the same format as it is in memory.
        
        Text File  : Each line is terminated by a special character (EOL).
        Binary File: No such delimiter exists.
        
        Text File  : Involves internal translation (e.g., converting text to binary).
        Binary File: No translation is performed.

        Text File  : Slower to operate.
        Binary File: Faster in comparison.
                        
    Example: Writing to a File
    --------------------------

    ofstream fout;
    fout.open("file_name.txt", ios::out);  // Open file in write mode.

    Common File Modes
    -----------------

    ios::out    -> Open for writing (if the file doesn't exist, it is created; if it does exist, it is overwritten).
    ios::in     -> Open for reading.
    ios::app    -> Append to the end of the file.
    ios::trunc  -> Truncate the file (clear all contents).
    ios::ate    -> Set the pointer at the end of the file (for reading and writing).
    ios::binary -> Open in binary mode.

    Error Checking
    --------------

    file.bad()   -> Returns true if a read/write error occurs.
    file.fail()  -> Returns true if a logical error occurs (e.g., reading a string into an integer).
    file.good()  -> Returns true if no errors have occurred.
    file.eof()   -> Returns true if the end of the file is reached.

    File Pointers
    -------------
    
    seekp(offset, direction) -> Move the put pointer for output.
    seekg(offset, direction) -> Move the get pointer for input.

    Direction can be:
        ios::beg -> Beginning of the file
        ios::end -> End of the file
        ios::cur -> Current position in the file

    Example: Reading from a File
    ----------------------------

    #include <string>
    ifstream MyFile("test.txt");
    string text;
    while (getline(MyFile, text)) {
        cout << text << endl;
    }
    MyFile.close();

    Creating & Writing to a File in C++
    -----------------------------------

    #include <fstream>
    #include <iostream>

    int main() {
        ofstream MyFile("example.txt");
        if (MyFile.is_open()) {
            MyFile << "This is an example text file.\n";
            MyFile << "You can write multiple lines.\n";
            MyFile.close();
        } else {
            cout << "Unable to open file";
        }
        return 0;
    }
*/



void writeToFile() {
    ofstream fout;
    fout.open("example.txt", ios::out);  // Open file in write mode

    if (fout.is_open()) {
        fout << "This is the first line in the file.\n";
        fout << "File handling in C++ is simple.\n";
        fout.close();  // Close the file after writing
    } else {
        cout << "Unable to open file for writing!" << endl;
    }
}

/*
    Example: Reading from a File
    ----------------------------
*/

void readFromFile() {
    ifstream fin;
    fin.open("example.txt", ios::in);  // Open file in read mode

    if (fin.is_open()) {
        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();  // Close the file after reading
    } else {
        cout << "Unable to open file for reading!" << endl;
    }
}

/*
    Example: Appending to a File
    ----------------------------
*/

void appendToFile() {
    ofstream fout;
    fout.open("example.txt", ios::app);  // Open file in append mode

    if (fout.is_open()) {
        fout << "This line is appended to the file.\n";
        fout.close();  // Close the file after appending
    } else {
        cout << "Unable to open file for appending!" << endl;
    }
}

/*
    Example: Checking for Errors
    ----------------------------
*/

void errorHandlingExample() {
    ifstream fin;
    fin.open("nonexistentfile.txt", ios::in);  // Try to open a non-existing file

    if (fin.fail()) {
        cout << "Error: File could not be opened!" << endl;
    } else {
        cout << "File opened successfully." << endl;
        fin.close();
    }
}

int main() {
    // Write to a file
    writeToFile();

    // Read from the file
    readFromFile();

    // Append to the file
    appendToFile();

    // Read again to check if append worked
    readFromFile();

    // Demonstrate error handling
    errorHandlingExample();

    return 0;
}
