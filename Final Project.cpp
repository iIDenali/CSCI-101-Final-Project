#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//Global variables to be used by any functions used later in the program.

string fileName, fileLine; //String variables for handling file traversal.
int x, y; //Int variables used to initialize an ASCII character at a certain coordinate, with x handling columns and y handling rows.
int row, col; //Int variables used to navigate each row and column of the following asciiMatrix array in for loops.
string ascii; //String used to initialize a certain coordinate in the following asciiMatrix array with it's corresponding ASCII character.
string asciiMatrix[7][90]; //String 2D array that will be used to hold the ASCII art, with 7 representing the amount of rows and 90 representing the amount of columns.
int maxX = 0, maxY = 0; //Int variables that will gather the maximum values of x and y. Will also be used to determine the amount of rows and columns in AsciiPrinter.

//Void function that initializes the asciiMatrix with spaces.
void MatrixInitialization() {
    for(row = 0; row < 7; row++) {
        for(col = 0; col < 90; col++) {
            asciiMatrix[row][col] = " ";
        }
    }
}
//Int function that reads through a user inputed file and initializes an ASCII character for each x-y coordinate.
//Function will also gather the maximum x and y values to be used by AsciiPrinter.
int AsciiInitializer(string file) {
    ifstream fileReader(file); //Input file stream that opens the user inputed file.
    
    //If-else statements that will either return an error for wrong file input or go through with the rest of the function.
    if(!fileReader.is_open()) { //If statement that returns an error for a wrong file input.
        cout << file << " could not be opened. Are you sure this is the right file?" << endl;
        return 1;
    }

    else {//Else statement that uses a while loop to initialize the asciiMatrix at a x-y coordinate with the corresponding ASCII character, while also determining the values maxX and maxY.
        /*While loop that does the following:
        -Open an input string stream called fileISS that will parse through every file line.
        -Gets each line of the file and puts it in one string, fileLine.
        -Parses each new string given to fileLine into three variables, int x, string ascii and int y.
        -Assigns each x-y coordinate with an ASCII character.
        -Gathers both the maxX value and maxY value.
        */
        while(!fileReader.eof()) {
            istringstream fileISS(fileLine);
            getline(fileReader, fileLine); //Gathers each line in the file into string fileLine.

            fileISS >> x >> ascii >> y; //Parses each string into x, ascii and y.
            
            asciiMatrix[y][x] = ascii; //Puts each ASCII character into an x-y coordinate on the asciiMatrix.
            
            //If-else statement that initializes maxX or maxY if x or y are greater than the previous maxX or maxY.
            if(x > maxX) {
                maxX = x + 1;
            }
            else if(y > maxY) {
                maxY = y + 1;
            }
            
        }
    }
    return maxX, maxY;
}

//Void function that prints out the newly initialized asciiMatrix.
void AsciiPrinter(string file) {
    //For loop that prints out the asciiMatrix.
    for(row = 0; row < maxY; row++) {
        for(col = 0; col < maxX; col++) {
            cout << asciiMatrix[row][col]; //Prints each row in the asciiMatrix.
        }
        cout << endl; //Separates each row in the asciiMatrix.
    }
}

int main() {
    cin >> fileName;

    //Function calls that gather and print out the ASCII art in block annotated letters.
    AsciiInitializer(fileName);
    AsciiPrinter(fileName);

    return 0;
}
