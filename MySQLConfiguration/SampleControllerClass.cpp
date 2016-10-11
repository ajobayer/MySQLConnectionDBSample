#include "../MySQLConnectionDBSample/stdafx.h"
#include "SampleControllerClass.h"

//Hard coded; This can be pass through ini/configuration/main class;
const string g_ServerIPAddress	="tcp://localhost:3306";
const string g_UserName			="root";
const string g_UserPassword		="";
const string g_Database			="feed_server_fxcm";

SampleControllerClass::SampleControllerClass(void)
{
	mMySQLDBOperation=new MySQLDBOperation(g_ServerIPAddress,g_UserName,g_UserPassword,g_Database);
}

SampleControllerClass::~SampleControllerClass(void)
{
	delete mMySQLDBOperation;
}

list<SampleModelClass> SampleControllerClass::getDataFromSymbolSpikeMappingTable(string aQueryString)
{
	list<SampleModelClass> lListOfData;
	sql::ResultSet *lReturnData= mMySQLDBOperation->fetchingResultsOfExecuteQuery(aQueryString);
	while (lReturnData->next())
	{
		SampleModelClass lSampleModelClass=SampleModelClass();

		lSampleModelClass.setAutoIncrimentID(lReturnData->getInt("pAutoIncrimentID"));
		lSampleModelClass.setSymbolID(lReturnData->getInt("fSymbolID"));
		lSampleModelClass.setTickValueChangePercent(lReturnData->getDouble("TickValueChangePercent"));
		lSampleModelClass.setTickValueCount(lReturnData->getInt("TickValueCount"));
		lSampleModelClass.setPipsValue(lReturnData->getInt("PipsValue"));

		lListOfData.push_back(lSampleModelClass);
	}
	return lListOfData;
}

list<SampleModelClass> SampleControllerClass::ImportCSVFileToDB(string lCsvFilePath)
{
	list<SampleModelClass> lListOfDataCSVFile;

	return lListOfDataCSVFile;
}

int SampleControllerClass::ExportCSVFileFromDB(string aQueryString)
{
	return mMySQLDBOperation->executesOfPreparedQuery(aQueryString);
}

