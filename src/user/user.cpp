#include "src/user/user.h"

User::User(const int id, const std::string name) {
    std::cout << "Initializing " << name << std::endl;
    
    this->id = id;
    this->name = name;

    //Makes sure that nextId is greater than id. Will be modified once a smarter id format is implemented.
    if(nextId > id) {
        std::cout << this->name << " initialized" << std::endl;
    }
    else if (User::nextId <= id) {
        User::nextId = id + 1;
        std::cout << this->name << " initialized" << std::endl;
    }
}

User::User(const std::string name) {
    std::cout << "Creating " << name << std::endl;

    this->name = name;
    //This is a dumb way to make ids. This will not stay as it is.
    this->id = User::nextId;
    User::nextId++;
}

User::User(const int id, const std::string name, const std::vector<int> preferences, const std::map<int, Particp> locks) {
    std::cout << "Loading " << name << std::endl;

    this->name = name;
    this->id = id;
    this->preferences = preferences;
    this->locks = locks;

    //Makes sure that nextId is greater than id. Will be modified once a smarter id format is implemented.
    if(nextId > id) {
        std::cout << name << " initialized" << std::endl;
    }
    else if (User::nextId <= id) {
        User::nextId = id + 1;
    }

    std::cout << this->name << " loaded" << std::endl;
}

User& User::operator=(const User& source) {
    std::cout << "Copying " << this->name << std::endl;
    
    this->name = source.name;
    this->id = source.id;
    this->preferences = source.preferences;
    this->locks = source.locks;

    std::cout << this->name << " copied" << std::endl;
}

User::User(const User& source) {
    std::cout << "Creating new copy of " << source.name << std::endl;

    this->name = source.name;
    this->id = source.id;
    this->preferences = source.preferences;
    this->locks = source.locks;

    std::cout << this->name << " copied" << std::endl;
}

User::~User() {
    std::cout << "Deleting " << this->name << std::endl;
}

User& User::operator+(Lock& lock) {
    //Finds out if the user is the keyholder or lockee for the lock being added
    Particp partisp;
    if(lock.Keyholder()->ID() == this->id) {
        partisp = KEYHOLDER;
    }
    else if(lock.Lockee()->ID() == this->id) {
        partisp = LOCKEE;
    }
    else {
        return; //Simply refuses to add the lock if the user is not part of it or the lock is not yet fulled defined.
    }

    //Adds the lock to the list of locks
    this->locks.insert(std::pair<int, Particp>(lock.ID(), partisp));

    //Passes the user along for other useses
    return *this;
}

User& User::operator-(Lock& lock) {
    //Removes the lock for the users list
    this->locks.erase(lock.ID());

    //Passes the user along for other uses
    return *this;
}

std::ostream& operator<<(std::ostream &os, const User& user) {
    os << user.Name() << " " << user.ID() << std::endl;
    for (auto iter = user.Locks().begin(); iter != user.Locks().end(); ++iter) {
        os << iter->first << " " << iter->second << std::endl;
    }
    return os;
}
