/***********************************************************************************************************************************
Log Test Harness
***********************************************************************************************************************************/
#ifndef TEST_COMMON_LOG_H
#define TEST_COMMON_LOG_H

/***********************************************************************************************************************************
Functions
***********************************************************************************************************************************/
#ifndef NO_LOG
void testLogInit();
void testLogResult(const char *expected);
void testLogErrResult(const char *expected);
void testLogFinal();
#endif

#endif
