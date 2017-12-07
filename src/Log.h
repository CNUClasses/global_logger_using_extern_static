/*
 * Log.h
 *
 *  Created on: Dec 6, 2017
 *      Author: keith
 */

#ifndef LOG_H_
#define LOG_H_
#include <string>
#include <mutex>

class Log {
public:
	Log();					//no argument, use if you want Log to be global
	Log(std::string &s);	//use to instantiate and log all in one go
	virtual ~Log();
	static void log(std::string s);	//does the work using the below mutex
private:
	static std::mutex m;			//declaration, only 1 mutex for this class
};

#endif /* LOG_H_ */
