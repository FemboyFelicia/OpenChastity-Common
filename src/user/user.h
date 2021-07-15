#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include "src/lock/lock.h"

enum Particp {KEYHOLDER, LOCKEE, SELF_LOCK}; //May implement lock viewers at some point. Not part of core design.

class User {
    public:
        //All the constructors and destructos. Most of these are probably not needed.
        User(const int, const std::string);
        User(const std::string);
        User(const int, const std::string, const std::vector<int>, const std::map<int, Particp>); //Loading constructor
        User& operator=(const User&);
        User(const User&);
        ~User();

        //Accessors and mutators. Accessors and mutators have the same key, but are distinguished by their arguments.
        void ID(const int id) { this->id = id; }
        int ID() const { return this->id; }
        void Name(const std::string name) { this->name = name; }
        std::string Name() const { return this->name; }
        std::map<int, Particp> Locks() const { return this->locks; }

        //Operator overloading. + will add a new lock and - will remove an unneeded one
        User& operator+(Lock&); //Adds a lock to the list of locks. Lock must be defined with keyholder or lockee before adding it.
        User& operator-(Lock&); //Removes a lock from the list of locks.
        friend std::ostream& operator<<(std::ostream &os, const User& user); //Object print thyself

    private:
        int id;
        std::string name;
        std::vector<int> preferences; //Will be added. Eventually...
        std::map<int, Particp> locks; //Keeps track of locks by id. Particp defines how the user interacts with the lock itself.
        static int nextId;
};

#endif