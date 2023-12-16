#include "BST_P2.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

BST csvtoAUList(string csvfile) { //convert a csv file to a list structure
    BST BgBST;
	ifstream ReadFile(csvfile); //open the csv file for reading
    string line, curvalue;
	getline(ReadFile, line); //throw away the first line (column names)

    while (getline(ReadFile,line)) {        
        stringstream ss(line); //turn the line into a string-stream
        int fielditer=0;
        BoardGame newrec; //Allocate memory for a new BoardGame object
		while(getline(ss, curvalue, ',')){ //Separate each variable per sample from the comma separator
            switch (fielditer) { //We need to explicitly convert values to the appropriate type (stoi=integer, stod=double)
            	case 0: newrec.name = curvalue; break; // handles string (no conversion needed)
            	case 1: newrec.year=stoi(curvalue); break;
            	case 2: newrec.time=stoi(curvalue); break;
                case 3: newrec.rating = stoi(curvalue); break;
			}
            fielditer++;
        }
        BgBST.InsertBST(BgBST.GetRoot(), newrec);

    }
    return BgBST;
}

int main(int argc, char** argv) {
	BST BGData=csvtoAUList("BoardGames.csv");

    cout << "All games in BST (sorted by year oldest to newest): " << endl;
	BGData.PrintAll(); //Print the elements in the BST

    //Get user input for target year
    int targetYear;
    cout << endl << "*********************************************************" << endl << endl;
    cout << "Enter the target year to print games created in or after: ";
    cin >> targetYear;

    //Print all games made in or after the target year 
    cout << "Games made in or after " << targetYear << ":" << endl;
    BGData.AfterYear(targetYear);



    
    

    return 0;
}
    
