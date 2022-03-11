#include "logClass.hpp"

namespace Log
{
	CLog::CLog()
		:m_isPrint(false)
		,m_isNeedTimestamp(true)
		,m_isInit(false)
	{}

	CLog::CLog(string logName, bool isPrint, bool isNeedTimestamp)
		:m_isPrint(isPrint)
		,m_logName(logName)
		,m_isNeedTimestamp(isNeedTimestamp)
		,m_isInit(false)
	{
		init();
	}

	void CLog::init()
	{
		Time t;
		getDateTimeString(t);

		string localDir = "./";
		if(m_isInit)
		{
			cout << "[" << t.Date << " " << t.TimeS << " " << "] " << "Log Has Inited! " << endl;
			return;
		}

		char date[12];
		struct tm timeNow = localTime();
		sprintf(date, "%d%02d%02d", timeNow.tm_year + 1900, timeNow.tm_mon + 1, timeNow.tm_mday);

	#ifdef _WIN32
		int createLogsFlag = _mkdir((localDir +  LOGSNAME).c_str());
	#else
		int createLogsFlag = mkdir((localDir + LOGSNAME).c_str() , S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	#endif

		if(-1 == createLogsFlag)
		{
			Time t;
			getDateTimeString(t);
			cout << "[" << t.Date << " " << t.TimeS << " " << "] " << "CreateLogs Failed!" << endl;
		}

		//string logName = localDir + LOGSNAME + "/" + m_logName + "_" + date + ".log";
		//m_log.first.open(logName, ios::app|ios::out);

		m_isInit = true;
	}

	CLog::~CLog()
	{
		quit();
	}

	CLog::CLog(const CLog& log)
	{
		m_isPrint = log.m_isPrint;
		m_logName = log.m_logName;
	}

	struct tm CLog::localTime()
	{
		time_t	timeNow = time(NULL);
		struct tm timeInfo;

	#ifdef _WIN32
		localtime_s(&timeInfo, &timeNow);
		return timeInfo;
	#else
		return *localtime(&timeNow);
	#endif
	}

#ifdef _WIN32
#else	
	struct timespec CLog::localTimeNs()
	{
		struct timespec timeNow;
		clock_gettime(CLOCK_REALTIME, &timeNow);
		return	timeNow;
	}
#endif

	void CLog::writeLog(const string& logStream, int LogLevel)
	{
		if(_LOG_NONE_ == LogLevel)
		{
			writeLog(logStream);
		}
		else
		{
			writeLogs(logStream, LogLevel);
		}
	}

	void CLog::operator<<(const string& logStream)
	{
		writeLog(logStream);
	}


	void CLog::writeLog(const string& logTxt)
	{
		Time dateTime;
		getDateTimeString(dateTime);
		string dataTimeString;
		if(m_isNeedTimestamp)
		{
			dataTimeString = "[" + dateTime.Date + " " + dateTime.TimeS + " " + dateTime.Ns + "] ";
		}

		m_log.first << dataTimeString << logTxt << endl;
		//m_log.second += logTxt.size();

		if(m_isPrint)
		{
			cout << dataTimeString << logTxt << endl;
		}
	}

	void CLog::writeLogs(const string& logTxt, int LogLevel)
	{
		Time dateTime;
		getDateTimeString(dateTime);
		string dataTimeString;
		if(m_isNeedTimestamp)
		{
			dataTimeString = "[" + dateTime.Date + " " + dateTime.TimeS + " " + dateTime.Ns + "] ";
		}

		m_log.first << dataTimeString << logTxt << endl;

		if(m_isPrint)
		{
			cout << dataTimeString << logTxt << endl;
		}
	}

	void CLog::quit()
	{
		m_log.first.close();
	}

	void CLog::getDateTimeString(Time& dateTime)
	{
		char dateString[12];
		char timeString[12];
		char nsString[10];
		struct tm timeNow;

	#ifdef _WIN32
		timeNow = localTime();
		memset(nsString, 0, 10);
	#else
		struct timespec timeClock = localTimeNs();
		sprintf(nsString, "%09d", timeClock.tv_nsec);

		time_t localTime = (time_t)timeClock.tv_sec;
		timeNow = *localtime(&localTime);				 // timspec格式转换为time_t
	#endif

		sprintf(dateString, "%d-%02d-%02d", timeNow.tm_year + 1900, timeNow.tm_mon + 1, timeNow.tm_mday);
		sprintf(timeString, "%02d:%02d:%02d", timeNow.tm_hour, timeNow.tm_min, timeNow.tm_sec);

		dateTime.Date = dateString;
		dateTime.TimeS = timeString;
		dateTime.Ns = nsString;
	}

	string CLog::getDateTimeString()
	{
		Time t;
		getDateTimeString(t);
		return ("[" + t.Date + " " + t.TimeS + " " + t.Ns + "] ");
	}

	void CLog::calcLogSize()
	{}

}


