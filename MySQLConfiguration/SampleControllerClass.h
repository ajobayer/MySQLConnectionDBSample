#if !defined SampleControllerClass_H
#define SampleControllerClass_H

#include "../MySQLConfiguration/MySQLDBOperation.h"
#include "../MySQLConfiguration/SampleModelClass.h"

class SampleControllerClass
{
private:
	MySQLDBOperation *mMySQLDBOperation;

public:
	SampleControllerClass(void);
	~SampleControllerClass(void);

public:
	list<SampleModelClass> getDataFromSymbolSpikeMappingTable(string);

	list<SampleModelClass> ImportCSVFileToDB(string lCsvFilePath);
	int ExportCSVFileFromDB(string aQueryString);

};

#endif