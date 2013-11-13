#ifndef APPCONFIGURATIONFILEREADER_H_
#define APPCONFIGURATIONFILEREADER_H_

#include <string>
#include <map>

typedef std::map<const std::string, std::string> AppConfiguration;

class AppConfigurationFileReader {
public:
	static AppConfiguration read(const std::string & filename);
};

#endif /* APPCONFIGURATIONFILEREADER_H_ */
