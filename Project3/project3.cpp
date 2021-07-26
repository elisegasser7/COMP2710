#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Declaration of functions (further dec below)
bool check_file(string);
vector<int> read_file(string);
void write_file(string, vector<int>);
vector<int> merge(vector<int>, vector<int>);
void to_string(string, vector<int>);

//main
int main() {

    //variables
    ifstream inStream1;
    string fileNameOne;
    string fileNameTwo;
    string writtenFile;
    vector<int> numbers1;
    vector<int> numbers2;
    vector<int> mergedList;
    int sizeOne;
    int sizeTwo;
     
    // Gets first file input
    do {

        cout << "*** Welcome to Elise's sorting program ***";
        cout << "\nEnter the first input file name: ";
        cin >> fileNameOne;
    } while (cin.fail() || !check_file(fileNameOne));

    // Reads fileOne
    numbers1 = read_file(fileNameOne);
    sizeOne = numbers1.size();

    // Stores numbers1 (vector) as an array
    int arr1[sizeOne];
    for (int i = 0; i < sizeOne; ++i) {
        arr1[i] = numbers1[i];
    }

    // Reurns numbers in file one
    cout << "The list of " << numbers1.size() << " numbers in the file " << fileNameOne << " is:\n";

    for (int i = 0; i < sizeOne; ++i) {
        cout << arr1[i] << "\n";
    }   

    // Gets second file input
    do {
        cout << "\nEnter the second input file name: ";
        cin >> fileNameTwo;
    } while (cin.fail() || !check_file(fileNameTwo));

    // Reads fileTwo
    numbers2 = read_file(fileNameTwo);
    sizeTwo = numbers2.size();

    // Stores numbers2 (vector) as an array
    int arr2[sizeTwo];
    for (int i = 0; i < sizeTwo; ++i) {
        arr2[i] = numbers2[i];
    }

    // Reurns numbers in file two
    cout << "The list of " << sizeTwo << " numbers in the file " << fileNameTwo << " is:\n";

    for (int i = 0; i < sizeTwo; ++i) {
        cout << arr2[i] << "\n";
    }

    // Merges two files
    mergedList = merge(numbers1, numbers2);

    // Stores mergedlist as an array
    int arr3[sizeOne + sizeTwo];
    for (int i = 0; i < (sizeOne + sizeTwo); ++i) {
        arr3[i] = mergedList[i];
    }

    // Returns merged list
    cout << "\nThe sorted list of 11 numbers is: ";
    
    for (int i = 0; i < (sizeOne + sizeTwo); ++i) {
        cout << arr3[i] << " ";
    }

    // Input prompted for output file
    do {
        cout << "\nEnter the output file name: "; 
        cin >> writtenFile;
    } while (cin.fail());

    // Output file created and returned
    write_file(writtenFile, mergedList);

    cout << "*** Please check the new file - " << writtenFile << " ***\n*** Goodbye. ***" << endl;


}

// Checks validity of file
bool check_file(string file) {

    ifstream stream;

    stream.open(file.c_str());

    if (stream.fail()) {
        cout << "File Does Not Exist. Try Again.\n";
        return false;
    }
    stream.close();

    return true;
}

// Reads file using stream and stores values in vector
vector<int> read_file(string file) {

    ifstream stream;
    vector<int> v;
    int i;
    stream.open(file.c_str());

    while (stream.good()) {

        stream >> i;
        v.push_back(i); 
    }

    stream.close();

    return v;
    
}

// Creates output file of vector (used for merged list)
void write_file(string file, vector<int> v) {

    int size = v.size();
    int arrFinal[size];

    for (int i = 0; i < size; ++i) {
        arrFinal[i] = v[i];
    }

    ofstream outputFile(file.c_str());

    for (int i = 0; i < size; ++i) {
        outputFile << arrFinal[i] << "\n";
    }

    outputFile.close();

}

// Uses merge sort to combine to vectors
vector<int> merge(vector<int> v1, vector<int> v2) {

    int ileft = 0;
    int iright = 0;
    int sizeOne = v1.size();
    int sizeTwo = v2.size();
    vector<int> mergedList;

    while (ileft < sizeOne && iright < sizeTwo) {
        if (v1[ileft] < v2[iright]) {
            mergedList.push_back(v1[ileft++]);
        }
        else {
            mergedList.push_back(v2[iright++]);    
        }
    }

    while (ileft < sizeOne) {
        mergedList.push_back(v1 [ileft++]);
    }

    while (iright < sizeTwo) {
        mergedList.push_back(v2[iright++]);
    }

    return mergedList;

}

// to string overwritten
void to_string(string file, vector<int> v) {
    unsigned short i;
}





