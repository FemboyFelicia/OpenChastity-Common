#ifndef TIMER_H
#define TIMER_H

#include "src/lock/lock.h"

class Timer: public Lock {
    public:
        Timer(std::shared_ptr<User>, std::shared_ptr<User>);
        Timer(std::shared_ptr<User>, std::shared_ptr<User>, time_t, time_t);
        Timer(std::shared_ptr<User>, std::shared_ptr<User>, time_t, time_t);

        void StartTime(time_t startTime) { this->startTime = startTime; }
        time_t StartTime() { return this->startTime; }
        void Length(time_t length) { this->length = length; }
        time_t Length() { return this->length; }

    private:
        time_t startTime;
        time_t length;
};

#endif