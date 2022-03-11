#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

#ifdef _WIN32
#include <Windows.h>
#include <direct.h>

	#ifdef _DEBUG
	#define LOGSNAME	"Win32_Debug"
	#else
	#define LOGSNAME	"Win32_Release"
	#endif

#else
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#define LOGSNAME		"Linux64"
#endif

using namespace std;

namespace Log
{
	typedef long long int logSizeType;

	enum LogLevel
	{
		_LOG_NONE_ = 0,
		_LOG_INFO_,
		_LOG_DEBUG_,
		_LOG_WARN_,
		_LOG_USER_,
		_LOG_ERROR_
	};

	struct Time
	{
		string Date;
		string TimeS;
		string Ns;
	};

	class CLog
	{
	public:
		CLog();
		CLog(string logName, bool isPrint = false, bool isNeedTimestamp = true);
		~CLog();

	public:
		CLog(const CLog& log);
		void init();

	public:
		// 参数：日志内容 日志级别
		void writeLog(const string& logStream, int LogLevel);
		void writeLog(const string& logTxt);
		void operator<<(const string& logStream);
		void quit();

		static void getDateTimeString(Time& dataTime);
		static string getDateTimeString();
		void writeLogs(const string& logTxt, int LogLevel);

	private:
		void calcLogSize();
		static struct tm localTime();

	#ifdef _WIN32
	#else	
		static struct timespec localTimeNs();
	#endif
	
	private:
		string m_logName;
		bool m_isPrint;				// 是否打印
		bool m_isNeedTimestamp;
		bool m_isInit;

		pair<fstream, logSizeType> m_log; // 普通日志

		//pair<fstream, logSizeType> m_logError;
		//pair<fstream, logSizeType> m_logInfo; 
		//pair<fstream, logSizeType> m_logDebug;
		//pair<fstream, logSizeType> m_logWarn; 
		//pair<fstream, logSizeType> m_logUser; 
	};
}