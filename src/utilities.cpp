/*
 * utilities.cpp
 *
 *  Created on: Jan 19, 2020
 *      Author: James Baron
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
	ofstream myFile;
		try{
		myFile.open(filename,ios::trunc);
		if(myFile.is_open()){
			for(int i = 0;i<stats.size();i++){
				process_stats tmp = stats[i];
			myFile<<tmp.process_number;
			myFile<<",";
			myFile<<tmp.start_time;
			myFile<<",";
			myFile<<tmp.cpu_time<<endl;
			}
		}else{
			return COULD_NOT_OPEN_FILE;
		}
		}catch(exception& e){
			return COULD_NOT_OPEN_FILE;
		}
		return SUCCESS;
	}

void sortData(SORT_ORDER mySortOrder){
	int size = stats.size();
	int countArray[size];
	vector<process_stats> tmp;
	for(int i = 0;i<size;i++){
		tmp.push_back(stats[i]);
		countArray[i] = 0;
	}
if(mySortOrder == START_TIME){
	for(int i = 0;i<size-1;i++){
		for(int j = i+1;j<size;j++){
			if(stats[i].start_time > stats[j].start_time){
				countArray[i]++;
			}else{
				countArray[j]++;
			}
		}
	}
}
else if(mySortOrder == CPU_TIME){
	for(int i = 0;i<size-1;i++){
		for(int j = i+1;j<size;j++){
			if(stats[i].cpu_time > stats[j].cpu_time){
				countArray[i]++;
			}else{
				countArray[j]++;
			}
		}
	}
}
else if(mySortOrder == PROCESS_NUMBER){
	for(int i = 0;i<size-1;i++){
		for(int j = i+1;j<size;j++){
			if(stats[i].process_number > stats[j].process_number){
				countArray[i]++;
			}else{
				countArray[j]++;
			}
		}
	}
}
for(int i = 0;i<size;i++){
	stats[countArray[i]] = tmp[i];
}
}
process_stats getNext(){
process_stats tmp= stats[elementCounter];
return tmp;
	}



