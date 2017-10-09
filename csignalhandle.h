#ifndef CSIGNALHANDLE_H
#define CSIGNALHANDLE_H
#include <signal.h>
#include <pthread.h>

void* thread_func(void*);

class CSignalHandle
{
    friend void* thread_func(void *);
public:
    CSignalHandle();
    ~CSignalHandle();

    void Run();

private:
    void HandleSignal();

private:
    sigset_t m_sigmask;
    pthread_t m_th;
    pthread_cond_t m_cond;
    pthread_mutex_t m_mutex;
    int      m_nFlag;
};

#endif // CSIGNALHANDLE_H
