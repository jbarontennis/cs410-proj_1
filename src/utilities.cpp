/*
 * utilities.cpp
 *
 *  Created on: Jan 19, 2020
 *      Author: james
 */
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "utilities.h"
using namespace std;
vector<process_stats> stats;
int elementCounter = 0;
int loadData(const char* filename){
fstream myFile;
string line;


const std::string file = filename;

try{
	myFile.open(filename, ios::in);
	if(myFile.is_open()){
				while(myFile.peek() != EOF){
					getline(myFile,line);
					stringstream ss(line);
					vector<std::string> tmphold;
					while(getline(ss,line,',')){
						tmphold.push_back(line);
				}
					process_stats tmpstat;
					int i1 = stoi(tmphold[0]);
					int i2 = stoi(tmphold[1]);
					int i3 = stoi(tmphold[2]);
					tmpstat.process_number = i1;
					tmpstat.start_time = i2;
					tmpstat.cpu_time = i3;
					stats.push_back(tmpstat);
				}
				return SUCCESS;
	}
return COULD_NOT_OPEN_FILE;
}catch(exception& e){
return COULD_NOT_OPEN_FILE;
}
}
int saveData(const char* filename){

}
void sortData(SORT_ORDER mySortOrder){

}
process_stats getNext(){
process_stats tmp= stats[elementCounter];
elementCounter++;
stats.pop_back();
return tmp;
	}



