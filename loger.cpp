#include <loger.h>
#include <sys/inotify.h>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>

log_loger::log_loger(std::string FileName) {
  LogFileName = FileName;
  LogFile.open(LogFileName, std::ifstream::in);
}

log_loger::~log_loger() { LogFile.close(); }

void log_loger::ReadWholeLog() {
  if (LogFile.good()) {
    LogContent.clear();
    LogFile.seekg(0, std::ios::end);
    LogContent.reserve(LogFile.tellg());
    LogFile.seekg(0, std::ios::beg);
    LogContent.assign((std::istreambuf_iterator<char>(LogFile)),
                      std::istreambuf_iterator<char>());
  }
}

std::string log_loger::ReadNewData() {
  if (LogContent.length() > LogContentOld.length()) {
    return EraseOldContent(LogContent, LogContentOld);
  }
  return " ";
}

void log_loger::UpdateData() {
  LogContentOld.clear();
  LogContentOld = LogContent;
  ReadWholeLog();
}

std::string log_loger::ReadLog() { return LogContent; }

std::string log_loger::EraseOldContent(std::string& ActualData,
                                       const std::string& OldContent) {
  std::string temporary = ActualData;
  if (OldContent == ActualData) {
    return " ";
  }

  size_t position = temporary.find(OldContent);
  if (position != std::string::npos) {
    temporary.erase(position, OldContent.length());
  }
  return temporary;
}

std::string log_loger::GetFileName() { return LogFileName; }
