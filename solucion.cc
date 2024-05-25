#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// create a struc to store the initial parameters

struct PaginatedParameters {
    int maxLineSize = 80;
    int maxLineCount = 25;
};

// check if the ifstream file was opened correctly

void checkError(ifstream& f) {
    if (!f) {
        cout << "Error opening input file" << endl;
        exit(1);
    }

}

// check if the ofstream file was opened correctly

void checkError(ofstream& out) {
    if (!out) {
        cout << "Error opening output file" << endl;
        exit(1);
    }
}

// Function to open the input document, checking if it was opened correctly

void openInputDocument(ifstream& f, string& inputDocumentName) {
    f.open(inputDocumentName);
    checkError(f);
}

// Function to open the output document, checkign if it was opened correctly

void openOutputDocument(ofstream& out, string& outputDocumentName) {
    out.open(outputDocumentName);
    checkError(out);
}

void paginateDocument (ifstream& f, ofstream& out, int& maxLineSize, int& maxLineCount, string& word, string& line, int& lineCount, int& pageCount) {

    // read the document.txt file word by word

    while (f >> word){
        if (line.size() + word.size() + 1 > 80){ // if the line + the next word + a space is bigger than maxLineSize characters
            out << line << endl; //print the line as it was
            line = word; // start the next one with that word
            lineCount++;
            if (lineCount == 25){ // if the line count is 25, print the page number and reset the line count
                out << "=== Page " << pageCount << " ===" << endl;
                pageCount++;
                lineCount = 0;
            }
        } else {
            line += (line.empty() ? "" : " ") + word; // if the line + the next word is smaller than 80 characters, add the word to the line, separated by a space if needed (there was a word before)
        }
    }

    if (!line.empty()) { // if there is a line left to print, print it
        out << line << endl;
        lineCount++;
    }
    if (lineCount > 0) { // if the line count is bigger than 0, print the last page number
        out << "=== Page " << pageCount << " ===" << endl; 
    }
}

int main() {
    PaginatedParameters paginatedParameters;

    ifstream f; 
    string inputDocumentName = "document.txt"; // declare a string to store the document name
    openInputDocument(f, inputDocumentName); // open the document.txt file

    ofstream out;
    string outputDocumentName = "paginated_document_cc.txt"; // declare a string to store the solution name
    openOutputDocument(out, outputDocumentName); // open / create the paginated_document.txt file where the solution will be stored

    string word = ""; // declare a strings to store each word of the document
    string line = ""; // declare a string to store each line of the document
    
    int lineCount = 0; // declare an int to count the line number
    int pageCount = 1; // declare an int to count the page number (starts at 1)


    paginateDocument(f, out, paginatedParameters.maxLineSize, paginatedParameters.maxLineCount, word, line, lineCount, pageCount); // call the solution function

    f.close();
    out.close();
    return 0;
}