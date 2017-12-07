/*
 * Log.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: keith
 */
#include <iostream>
#include "Log.h"

using namespace std;
Log::Log(){
	
}

Log::Log(std::string &s) {
	Log::log(s);	//call static method to log s
}

Log::~Log() {
	
}

void Log::log(std::string s){
	std::lock_guard<std::mutex> m1(m);
	//std::cout<<"AA"<<"BB"<<"CC"<<"DD"<<"EE"<< s <<std::endl;	//stress test cout
	std::cout<< s <<std::endl;
}

//define the static mutex (required)
std::mutex Log::m;


