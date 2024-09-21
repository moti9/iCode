#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


class Mutex
{
public:
    Mutex()
    {
        isLocked = UNLOCKED_VAL;
    }

    void lock() {
        while(__sync_lock_test_and_set(&isLocked, LOCKED_VAL) == LOCKED_VAL);
    }

    void unlock() {
        __sync_lock_release(&isLocked);
    }

    bool try_lock() {
        return __sync_lock_test_and_set(&isLocked, LOCKED_VAL) != LOCKED_VAL;
    }

private:
    int LOCKED_VAL = 1;
    int UNLOCKED_VAL = 0;
    volatile int isLocked;
};

int main()
{

    return 0;
}
/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/