#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "src/lock/lock.h"

enum Particp {KEYHOLDER, LOCKEE, SELF_LOCK}; //May implement lock viewers at some point. Not part of core design.

class User {
    public:
        User(const int, const std::string);
        User(const std::string);
        User(const int, const std::string, const std::vector<int>, const std::map<std::shared_ptr<Lock>, Particp>); //Loading constructor
        User& operator=(const User&);
        User(const User&);

        void ID(const int id) { this->id = id; }
        int ID(bool validate) { return this->id; }
        void Name(const std::string name) { this->name = name; }
        std::string Name(bool validate) { return this->name; }
        std::map<std::shared_ptr<Lock>, Particp>& Locks() { return this->locks; }

        //Operator overloading. + will add a new lock and - will remove an unneeded one
        User& operator+(Lock);

    private:
        int id;
        std::string name;
        std::vector<int> preferences; //Will be added. Eventually...
        std::map<std::shared_ptr<Lock>, Particp> locks; //Keeps track of locks by id. Particp defines how the user interacts with the lock itself.
        static int nextId;
};

#endif