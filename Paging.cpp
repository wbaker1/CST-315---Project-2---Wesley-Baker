//Simulated Page Table Made by Wesley Baker and Adam Ringwell
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    vector<string> logicalMem = {"taco", "crab", "slot", "frog"}; //Our 4 byte words held on pages to store in our physicalMem which each index represents a frame.
    vector<string> physicalMem = {"", "", "", "", "", "", "", ""}; //Page frames
    vector<int> pageTable;
    srand(time(NULL)); //Ensures the page table will have unique values.
    unordered_set<int> rand_nums; //Create a set of ints.
    while (rand_nums.size() < 4) { //Loop through the number of pages (4).
        rand_nums.insert(rand() % 8); //Assign an index in our pageTable to a random number within our physicalMem.
    }
    pageTable.reserve(rand_nums.size());//Copy the random number set to the pageTable vector.
    copy(rand_nums.begin(), rand_nums.end(), back_inserter(pageTable));
    for (int j = 0; j < logicalMem.size(); j++) {//The word / page in logicalMem index j, is the set to the index j of the pageTable, which serves as the index for the physicalMem.
    	physicalMem[pageTable[j]] = logicalMem[j];
    }
	ofstream myFile;//Output the elements of the physicalMem to a file called text.
	
	myFile.open("text");
	
	for(int i = 0; i < 8; i++){
	myFile << physicalMem[i] << "\n";
	}
	myFile.close();
	return 0;
	
}