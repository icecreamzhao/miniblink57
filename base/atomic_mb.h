
#ifndef base_atomic_mb_h
#define base_atomic_mb_h

extern "C" long MB_InterlockedIncrement(long volatile* _Target);
extern "C" long MB_InterlockedExchange(long volatile* _Target, long _Value);
extern "C" long MB_InterlockedExchangeAdd(long volatile* _Addend, long _Value);
extern "C" long MB_InterlockedDecrement(long volatile*);
extern "C" long MB_InterlockedCompareExchange(long volatile* _Destination, long _Exchange, long _Comparand);

#endif // base_atomic_mb_h