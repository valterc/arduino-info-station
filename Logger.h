#ifndef Logger_h
#define Logger_h

#define ENABLE_DEBUG_LOG 
#define ENABLE_INFO_LOG 

#define setUpLogger() Serial.begin(9600); 

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#ifdef DISABLE_DEBUG_LOG
  #define logDebug(message) (void)message;
#else
  #define logDebug(message) \
    {\
      Serial.print("[");\
      Serial.print((const char*)__FILENAME__);\
      Serial.print(",");\
      Serial.print((unsigned int)__LINE__);\
      Serial.print(",");\
      Serial.print((const char*)__FUNCTION__);\
      Serial.print("] ");\
      Serial.println(message);\
    }
#endif

#ifdef DISABLE_INFO_LOG
  #define logInfo(message)
  #define logInfoLine(message) 
#else 
  #define logInfo(message) Serial.print("["); Serial.print((const char*)__FILENAME__); Serial.print("] "); Serial.print(message);
  #define logInfoLine(message) Serial.print("["); Serial.print((const char*)__FILENAME__); Serial.print("] "); Serial.println(message);
  #define appendLogInfo(message) Serial.print(message);
  #define appendLogInfoLine(message) Serial.println(message);
#endif
    
#endif
