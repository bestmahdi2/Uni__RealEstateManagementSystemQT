#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#pragma once

#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class User {
public:
    static int ID;
    static User USER;

    int id;
    string username;
    string password;
    string name;
    string fname;
    string phone;
    string email;

    string role = "user";
    bool operation_success = false;
    string note;

    User();

    User(string username, string password);

    User(string username, string password, string name, string fname, string phone, string email);

    string save_string();
};

// Base class for properties
class Property {
public:
    static int ID;

    User* owner;
    int id;
    string title;
    string totalPrice;
    string deposit;
    string monthlyRent;
    string photoPath;
    string category;
    string dealType; // Sale/Rent/Exchange
    string full_address;
    bool hasDeed;
    int landArea;
    int builtArea;
    string description;

    Property (){

    }

    // Constructor
    Property(User *owner, string title, string totalPrice, string deposit, string monthlyRent, string photoPath, string category, string dealType, string full_address, bool hasDeed, double landArea, double builtArea, string description) {
        this->id = Property::ID++;
        this->owner = owner;
        this->title = title;
        this->totalPrice = totalPrice;
        this->deposit = deposit;
        this->monthlyRent = monthlyRent;
        this->photoPath = photoPath;
        this->category = category;
        this->dealType = dealType;
        this->full_address = full_address;
        this->hasDeed = hasDeed;
        this->landArea = landArea;
        this->builtArea = builtArea;
        this->description = description;
    }

    virtual ~Property()
    {

    }
};

class Tools {
public:
    static vector<User> users;
    static vector<Property> properties;

    static bool is_valid_username(const std::string& username);

    static bool is_valid_password(const std::string& password);

    static bool is_valid_email(const std::string& email);

    static bool is_valid_phone(const std::string& phone);

    static int user_signin(string username,string password);

    static User user_signup(string username, string password1, string password2, string name, string fname, string phone, string email);

    static void user_edit(User *user, string password1, string password2, string name, string fname, string phone, string email);

    static void loadUsers();

    static void saveUsers();
};

// Subclass for apartments
class Apartment : public Property {
public:
    int buildYear;
    int numRooms;
    int floor;
    bool hasElevator;
    bool hasParking;
    bool hasStorage;
    bool isRenovated;
    bool hasBalcony;
    bool hasBathroom;
    bool hasCooling;
    bool hasHeating;

    Apartment(){

    }

    // Constructor
    Apartment(User *owner, string title, string totalPrice, string deposit, string monthlyRent, string photoPath, string category, string dealType, string full_address, bool hasDeed, double landArea, double builtArea, string description,
              int buildYear, int numRooms, int floor, bool hasElevator, bool hasParking, bool hasStorage, bool isRenovated, bool hasBalcony, bool hasBathroom,
              bool hasCooling, bool hasHeating)
        : Property(owner, title, totalPrice, deposit, monthlyRent, photoPath, category, dealType, full_address, hasDeed, landArea, builtArea, description)
    {
        this->buildYear = buildYear;
        this->numRooms = numRooms;
        this->floor = floor;
        this->hasElevator = hasElevator;
        this->hasParking = hasParking;
        this->hasStorage = hasStorage;
        this->isRenovated = isRenovated;
        this->hasBalcony = hasBalcony;
        this->hasBathroom = hasBathroom;
        this->hasCooling = hasCooling;
        this->hasHeating = hasHeating;
    }

    ~Apartment()
    {
        // Do some important cleanup
    }
};

// Subclass for houses and villas
class HouseVilla : public Property {
public:
    int buildYear;
    int numRooms;
    bool hasParking;
    bool hasStorage;
    bool hasBalcony;
    bool isRenovated;
    bool hasBathroom;
    bool hasCooling;
    bool hasHeating;

    HouseVilla () {

    }

    // Constructor
    HouseVilla(User *owner, string title, string totalPrice, string deposit, string monthlyRent, string photoPath, string category, string dealType, string full_address, bool hasDeed, double landArea, double builtArea, string description,
               int buildYear, int numRooms, bool hasParking, bool hasStorage, bool isRenovated, bool hasBalcony, bool hasBathroom, bool hasCooling, bool hasHeating)
    : Property(owner, title, totalPrice, deposit, monthlyRent, photoPath, category, dealType, full_address, hasDeed, landArea, builtArea, description)
    {
        this->buildYear=buildYear;
        this->numRooms=numRooms;
        this->hasParking=hasParking;
        this->hasStorage=hasStorage;
        this->hasBalcony=hasBalcony;
        this->isRenovated=isRenovated;
        this->hasBathroom=hasBathroom;
        this->hasCooling=hasCooling;
        this->hasHeating=hasHeating;
    }
};

// Subclass for land and old properties
class LandOldProperty : public Property {
public:

    LandOldProperty () {

    }

    // Constructor
    LandOldProperty(User *owner, string title, string totalPrice, string deposit, string monthlyRent, string photoPath, string category, string dealType, string full_address, bool hasDeed, double landArea, double builtArea, string description)
    : Property(owner, title, totalPrice, deposit, monthlyRent, photoPath, category, dealType, full_address, hasDeed, landArea, builtArea, description) {}
};

// Subclass for offices, administrative rooms, and clinics
class OfficeAdminClinic : public Property {
public:
    int numRooms;
    int buildYear;
    int floor;
    bool hasAdminDeed;
    bool hasElevator;
    bool hasParking;
    bool hasStorage;

    OfficeAdminClinic () {

    }

    // Constructor
    OfficeAdminClinic(User *owner, string title, string totalPrice, string deposit, string monthlyRent, string photoPath, string category, string dealType, string full_address, bool hasDeed, double landArea, double builtArea, string description,
                      int buildYear, int numRooms, int floor, bool hasElevator, bool hasParking, bool hasStorage, bool hasAdminDeed)
    : Property(owner, title, totalPrice, deposit, monthlyRent, photoPath, category, dealType, full_address, hasDeed, landArea, builtArea, description)
    {
        this->numRooms = numRooms;
        this->buildYear = buildYear;
        this->floor = floor;
        this->hasAdminDeed = hasAdminDeed;
        this->hasElevator = hasElevator;
        this->hasParking = hasParking;
        this->hasStorage = hasStorage;
    }
};

// Subclass for shops and booths
class ShopBooth : public Property {
public:
    int numRooms;
    int buildYear;
    bool hasAdminDeed;

    ShopBooth(){

    }

    // Constructor
    ShopBooth(User *owner, string title, string totalPrice, string deposit, string monthlyRent, string photoPath, string category, string dealType, string full_address, bool hasDeed, double landArea, double builtArea, string description,
              int buildYear, int numRooms, bool hasAdminDeed)
    : Property(owner, title, totalPrice, deposit, monthlyRent, photoPath, category, dealType, full_address, hasDeed, landArea, builtArea, description)
    {
        this->numRooms = numRooms;
        this->buildYear = buildYear;
        this->hasAdminDeed = hasAdminDeed;
    }
};

// Subclass for industrial, agricultural, and commercial properties
class IndustrialAgriCommercial : public Property {
public:
    int numRooms;
    int buildYear;
    bool hasAdminDeed;

    IndustrialAgriCommercial(){

    }

    // Constructor
    IndustrialAgriCommercial(User *owner, string title, string totalPrice, string deposit, string monthlyRent, string photoPath, string category, string dealType, string full_address, bool hasDeed, double landArea, double builtArea, string description,
                             int buildYear, int numRooms, bool hasAdminDeed)
    : Property(owner, title, totalPrice, deposit, monthlyRent, photoPath, category, dealType, full_address, hasDeed, landArea, builtArea, description)
    {
        this->numRooms = numRooms;
        this->buildYear = buildYear;
        this->hasAdminDeed = hasAdminDeed;
    }
};

#endif
