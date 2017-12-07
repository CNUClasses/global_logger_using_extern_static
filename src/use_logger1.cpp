
#include "use_logger1.h"

#include <string>
#include "externs.h"

void fun1(){
	std::string s = "hello from use_logger1";
	LOG.log(s);
}

