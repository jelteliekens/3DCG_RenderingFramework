#include "AppConfigurationFileReader.h"
#include <fstream>
#include <iostream>


AppConfiguration AppConfigurationFileReader::read(const std::string & filename){
	AppConfiguration appCfg;
	std::ifstream inf(filename.c_str());
	if (!inf) {
		std::cout << "Configuration file " << filename << " could not be opened!\n";
	    exit(1);
	}
	while(inf){
		std::string line;
	    getline(inf, line);
	    if(!line.empty()){
	    	appCfg[line.substr(0,line.find('=')-1)]=line.substr(line.find('=')+2);
	    }
	}

	return appCfg;
}
