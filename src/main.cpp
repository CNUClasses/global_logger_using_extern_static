//============================================================================
// Name        : static_logger.cpp
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include "Log.h"
#include "externs.h"
#include "use_logger1.h"
#include "use_logger2.h"
using namespace std;

void fun(int i){
	string s  = "Greetings from thread "+ std::to_string(i);
	string s2 = "Greetings local logger ";
	
	//all of the logging below is synchronized by the same static mutex in the Log class
	for (int j=0;j<1000;j++){
		
		//the following 3 logger calls use the same global log object defined in externs.cpp
		LOG.log(s);	//call global log 
		fun1();		//calls global log from use_logger1
		fun2();		//calls global log from use_logger2
		
		//creates a local instance of Log and logs strings2
		Log l(s2);	
	}
	
}
int main() {
	
	thread t1(fun,1); 	//f1 - 2 threads
	thread t2(fun,2);
	thread t3(fun,3); 	//f1 - 2 threads
	thread t4(fun,4);
		
	t1.join();
	t2.join();
	t3.join();
	t4.join();

}
