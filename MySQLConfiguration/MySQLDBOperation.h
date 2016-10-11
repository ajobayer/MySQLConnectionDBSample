#if !defined MySQLDBOperation_H
#define MySQLDBOperation_H

#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class MySQLDBOperation
{
private:
	string				mServerIPAddress;
	string				mDBUserName;
	string				mDBUserPassword;
	string				mTargetDatabase;

public:
	sql::Driver			*m_Driver;
	sql::Connection		*m_Connection;

private:
	int ConnectToDB();

public:
	sql::ResultSet* fetchingResultsOfExecuteQuery(string aQueryStatement);
	int executeUpdateQuery(string aQueryString);
	bool executesOfPreparedQuery(string aQueryString);

public:
	MySQLDBOperation(string aServerIPAddress,string aDBUserName,string aDBUserPassword,string aTargetDatabase);
	~MySQLDBOperation(void);
};

#endif