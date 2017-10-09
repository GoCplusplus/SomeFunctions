#include "csignalhandle.h"
#include <iostream>

CSignalHandle::CSignalHandle()
{

}

CSignalHandle::~CSignalHandle()
{

}

void* thread_func(void * arg)
{
    CSignalHandle* pHandle = (CSignalHandle*)arg;
    if (pHandle)
        pHandle->HandleSignal();
    return nullptr;
}

void CSignalHandle::HandleSignal()
{
    int signo = 0;
    while (true)
    {
        sigwait(&m_sigmask, &signo);
        switch (signo)
        {
        case SIGINT:
            std::cout << "catch SIGINT" << std::endl;
            continue;
        case SIGQUIT:
            std::cout << "catch SIGQUIT, terminate" << std::endl;
            m_nFlag = 1;
            pthread_cond_signal(&m_cond);
            return;
        }
    }
}

void CSignalHandle::Run()
{
    sigset_t oldMask;
    m_cond = PTHREAD_COND_INITIALIZER;
    m_mutex = PTHREAD_MUTEX_INITIALIZER;
    m_nFlag = 0;

    sigemptyset(&m_sigmask);
    sigaddset(&m_sigmask, SIGINT); // register signal
    sigaddset(&m_sigmask, SIGQUIT); // terminate thread

    pthread_sigmask(SIG_BLOCK, &m_sigmask, &oldMask); // block signal
    pthread_create(&m_th, NULL, thread_func, this); // thread handle signal

    pthread_mutex_lock(&m_mutex);
    while (!m_nFlag)
        pthread_cond_wait(&m_cond, &m_mutex);
    pthread_mutex_unlock(&m_mutex);

    pthread_join(m_th, NULL);

    return;
}
