// MySQLConnectionDBSample.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <string>

#include "../MySQLConfiguration/SampleControllerClass.h"
#include "../MySQLConfiguration/SampleModelClass.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	string lQueryString="SELECT pAutoIncrimentID, fSymbolID, TickValueChangePercent, TickValueCount, PipsValue FROM tbl_symbol_spike_mapping";
	SampleControllerClass *lSampleControllerClass = new SampleControllerClass();
	list<SampleModelClass> lListOfData = lSampleControllerClass->getDataFromSymbolSpikeMappingTable(lQueryString);

	for(list<SampleModelClass>::iterator lIterator = lListOfData.begin();  lIterator != lListOfData.end(); lIterator++)
	{
		SampleModelClass lSampleModelClass=(SampleModelClass)*lIterator;

		cout<<lSampleModelClass.getAutoIncrimentID()<<" | ";
		cout<<lSampleModelClass.getSymbolID()<<" | ";
		cout<<lSampleModelClass.getTickValueChangePercent()<<" | ";
		cout<<lSampleModelClass.getTickValueCount()<<" | ";
		cout<<lSampleModelClass.getPipsValue()<<" | ";

		cout<<endl;
	}

	string lCsvFilePath = "record11.csv";
	string lQueryImportCSVFile = "SELECT * from tbl_symbol_spike_mapping INTO OUTFILE '"+lCsvFilePath+"' FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n'";
	lSampleControllerClass->ExportCSVFileFromDB(lQueryImportCSVFile);

	getchar();
	return 0;
}

