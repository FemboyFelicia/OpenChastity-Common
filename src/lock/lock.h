#ifndef LOCK_H
#define LOCK_H

#include "src/user/user.h"
#include <ctime> //Is needed for all kinds of locks. Not used in the root class, but definatly needed in all others
#include <memory>
#include "src/user/user.h"

class Lock {
    public:
        Lock(std::shared_ptr<User>, std::shared_ptr<User>);

        void ID(int id) { this->id = id; }
        int ID() const { return this->id; }
        void Keyholder(std::shared_ptr<User> keyholder) { this->keyholder = keyholder; }
        std::shared_ptr<User> Keyholder() const { return this->keyholder; }
        void Lockee(std::shared_ptr<User> lockee) { this->lockee = lockee; }
        std::shared_ptr<User> Lockee() const { return this->lockee; }

    protected:
        int id;
        std::shared_ptr<User> keyholder;
        std::shared_ptr<User> lockee;
};

#endif