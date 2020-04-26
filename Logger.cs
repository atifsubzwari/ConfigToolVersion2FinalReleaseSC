﻿using NLog;
using NLog.Config;
using NLog.Targets;

namespace ConfigGenerator.Logging
{
  internal static class Log
  {
    public static Logger Instance { get; private set; }
    static Log()
    {
      LogManager.ReconfigExistingLoggers();

      Instance = LogManager.GetCurrentClassLogger();
    }
  }
}