#include "src/user/user.h"
#include <iostream>

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

User::User(const int id, const std::string name, const std::vector<int> preferences, const std::map<std::shared_ptr<Lock>, Particp> locks) {
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
    this->name = source.name;
    this->id = source.id;
    this->preferences = source.preferences;
    this->locks = source.locks;
}
