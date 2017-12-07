
#include "use_logger2.h"

#include <string>
#include "externs.h"

void fun2(){
	std::string s = "hello from use_logger2";
	LOG.log(s);
}


