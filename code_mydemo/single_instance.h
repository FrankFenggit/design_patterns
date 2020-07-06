#ifndef _SINGLE_INSTANCE_COMMON_H_
#define _SINGLE_INSTANCE_COMMON_H_

#include <mutex>

using namespace std;

#define INSTANCE_DEFINE_COM(classname)	\
public: \
    virtual ~classname();\
	static classname * GetInstance(); \
private: \
    classname(); \
	static classname * instance; \
	static mutex m_mutex; \

#define SINGLETON_IMPLEMENT(classname)	\
mutex classname::m_mutex; \
classname * classname::instance = NULL; \
classname * classname::GetInstance() \
{ \
    if(instance != NULL) \
        return instance; \
	lock_guard<mutex> guard(m_mutex); \
	if( NULL == instance) \
	{ \
		instance = new classname;  \
	} \
	return instance; \
} \
classname::~classname() { \
	delete instance; \
} \
classname::classname() { \
}

#endif
