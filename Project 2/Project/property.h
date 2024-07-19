#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include <string>

using namespace std;

// Base class representing a generic property
class Property {
private:
    string name;
    string type;
    string category;
    string property_type;

    string land;
    string building;

    string deposit;
    string rent;
    string price;

    string address;
    string description;
    string pic;

    bool has_deed;
public:
    Property();  // Default constructor
        virtual ~Property();  // Virtual destructor
    Property(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
             string price, string address, string description, string pic, bool has_deed);

    // Setter methods
    void setName(string name);
    void setType(string type);
    void setCategory(string category);
    void setPropertyType(string property_type);
    void setLand(string land);
    void setBuilding(string building);
    void setDeposit(string deposit);
    void setRent(string rent);
    void setPrice(string price);
    void setAddress(string address);
    void setDescription(string description);
    void setPic(string pic);
    void setHasDeed(bool has_deed);

    // Getter methods
    string getName();
    string getType();
    string getCategory();
    string getPropertyType();
    string getLand();
    string getBuilding();
    string getDeposit();
    string getRent();
    string getPrice();
    string getAddress();
    string getDescription();
    string getPic();
    bool getHasDeed();
};

// Derived class representing a non-residential property
class Non_Residential : public Property {
public:
    Non_Residential();  // Default constructor
    Non_Residential(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
             string price, string address, string description, string pic, bool has_deed);
};

// Derived class representing a residential property
class Residential : public Property {
public:
    Residential();  // Default constructor
    Residential(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
                string price, string address, string description, string pic, bool has_deed);
};

// Derived class representing an office property
class Office : public Property {
public:
    Office();  // Default constructor
    Office(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
                 string price, string address, string description, string pic, bool has_deed);
};

// Derived class representing a commercial property
class Commercial : public Property {
public:
    Commercial();  // Default constructor
    Commercial(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
               string price, string address, string description, string pic, bool has_deed);
};

// Derived class representing a land property (specific type of non-residential)
class Land: public Non_Residential {
public:
    Land();  // Default constructor
    virtual ~Land();  // Virtual destructor
    Land(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
             string price, string address, string description, string pic, bool has_deed);
};

// Derived class representing a "Kolangi" property (specific type of non-residential)
class Kolangi: public Non_Residential {
private:
    bool has_storage;
    string rooms;

public:
    Kolangi();  // Default constructor
    Kolangi(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
            string price, string address, string description, string pic, bool has_deed,
            bool has_storage, string rooms);

    // Setter methods for additional attributes
    void setHasStorage(bool has_storage);
    void setRooms(string rooms);

    // Getter methods for additional attributes
    bool getHasStorage();
    string getRooms();
};

// Derived class representing a garden property (specific type of non-residential)
class Garden: public Non_Residential {
private:
    bool is_renew;
    bool has_storage;
    string build;
    string rooms;

public:
    Garden();  // Default constructor
    Garden(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
            string price, string address, string description, string pic, bool has_deed,
            bool is_renew, bool has_storage, string build, string rooms);

    // Setter methods for additional attributes
    void setIsRenew(bool is_renew);
    void setHasStorage(bool has_storage);
    void setBuild(string build);
    void setRooms(string rooms);

    // Getter methods for additional attributes
    bool getIsRenew();
    bool getHasStorage();
    string getBuild();
    string getRooms();
};

// Derived class representing an apartment property
class Apartment : public Residential {
private:
    bool is_furnished;
    bool is_renew;
    bool has_parking;
    bool has_elevator;
    bool has_storage;
    bool has_balcony;
    bool has_wallpaper;
    string build;
    string floor;
    string rooms;

public:
    Apartment(); // Default constructor
    Apartment(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_furnished, bool is_renew, bool has_parking, bool has_elevator, bool has_storage, bool has_balcony,
           bool has_wallpaper, string build, string floor, string rooms);

    // Setter methods for additional attributes
    void setIsFurnished(bool is_furnished);
    void setIsRenew(bool is_renew);
    void setHasParking(bool has_parking);
    void setHasElevator(bool has_elevator);
    void setHasStorage(bool has_storage);
    void setHasBalcony(bool has_balcony);
    void setHasWallpaper(bool has_wallpaper);
    void setBuild(string build);
    void setFloor(string floor);
    void setRooms(string rooms);

    // Getter methods for additional attributes
    bool getIsFurnished();
    bool getIsRenew();
    bool getHasParking();
    bool getHasElevator();
    bool getHasStorage();
    bool getHasBalcony();
    bool getHasWallpaper();
    string getBuild();
    string getFloor();
    string getRooms();
};

// Derived class representing a villa property
class Villa : public Residential {
private:
    bool is_furnished;
    bool is_renew;
    bool has_parking;
    bool has_storage;
    bool has_wallpaper;
    string build;
    string rooms;

public:
    Villa();  // Default constructor
    Villa(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_furnished, bool is_renew, bool has_parking, bool has_storage, bool has_wallpaper, string build, string rooms);

    // Setter methods for additional attributes
    void setIsFurnished(bool is_furnished);
    void setIsRenew(bool is_renew);
    void setHasParking(bool has_parking);
    void setHasStorage(bool has_storage);
    void setHasWallpaper(bool has_wallpaper);
    void setBuild(string build);
    void setRooms(string rooms);

    // Getter methods for additional attributes
    bool getIsFurnished();
    bool getIsRenew();
    bool getHasParking();
    bool getHasStorage();
    bool getHasWallpaper();
    string getBuild();
    string getRooms();
};

// Derived class representing a workplace property
class Workplace : public Office {
private:
    bool is_renew;
    bool has_parking;
    bool has_elevator;
    bool has_storage;
    bool has_balcony;
    bool has_wallpaper;
    string build;
    string floor;
    string rooms;

public:
    Workplace(); // Default constructor
    Workplace(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_renew, bool has_parking, bool has_storage, bool has_wallpaper, string build, string rooms);

    // Setter methods for additional attributes
    void setIsRenew(bool is_renew);
    void setHasParking(bool has_parking);
    void setHasElevator(bool has_elevator);
    void setHasStorage(bool has_storage);
    void setHasBalcony(bool has_balcony);
    void setHasWallpaper(bool has_wallpaper);
    void setBuild(string build);
    void setFloor(string floor);
    void setRooms(string rooms);

    // Getter methods for additional attributes
    bool getIsRenew();
    bool getHasParking();
    bool getHasElevator();
    bool getHasStorage();
    bool setHasBalcony();
    bool getHasWallpaper();
    string getBuild();
    string getFloor();
    string getRooms();
};

// Derived class representing a clinic property
class Clinic : public Office {
private:
    bool is_renew;
    bool has_parking;
    bool has_elevator;
    bool has_storage;
    bool has_balcony;
    bool has_wallpaper;
    string build;
    string floor;
    string rooms;

public:
    Clinic(); // Default constructor
    Clinic(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_renew, bool has_parking, bool has_storage, bool has_wallpaper, string build, string rooms);

    // Setter methods for additional attributes
    void setIsRenew(bool is_renew);
    void setHasParking(bool has_parking);
    void setHasElevator(bool has_elevator);
    void setHasStorage(bool has_storage);
    void setHasBalcony(bool has_balcony);
    void setHasWallpaper(bool has_wallpaper);
    void setBuild(string build);
    void setFloor(string floor);
    void setRooms(string rooms);

    // Getter methods for additional attributes
    bool getIsRenew();
    bool getHasParking();
    bool getHasElevator();
    bool getHasStorage();
    bool setHasBalcony();
    bool getHasWallpaper();
    string getBuild();
    string getFloor();
    string getRooms();
};

// Derived class representing a shop property
class Shop : public Commercial {
private:
    bool is_renew;
    bool has_elevator;
    bool has_storage;
    bool has_wallpaper;
    string build;
    string floor;
    string rooms;

public:
    Shop(); // Default constructor
    Shop(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_renew, bool has_elevator, bool has_storage, bool has_wallpaper, string build, string floor, string rooms);

    // Setter methods for additional attributes
    void setIsRenew(bool is_renew);
    void setHasElevator(bool has_elevator);
    void setHasStorage(bool has_storage);
    void setHasWallpaper(bool has_wallpaper);
    void setBuild(string build);
    void setFloor(string floor);
    void setRooms(string rooms);

    // Getter methods for additional attributes
    bool getIsRenew();
    bool getHasElevator();
    bool getHasStorage();
    bool getHasWallpaper();
    string getBuild();
    string getFloor();
    string getRooms();
};

// Derived class representing a workshop property
class Workshop : public Commercial {
private:
    bool is_renew;
    bool has_storage;
    string build;
    string rooms;

public:
    Workshop(); // Default constructor
    Workshop(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_renew, bool has_storage, string build, string rooms);

    // Setter methods for additional attributes
    void setIsRenew(bool is_renew);
    void setHasStorage(bool has_storage);
    void setBuild(string build);
    void setRooms(string rooms);

    // Getter methods for additional attributes
    bool getIsRenew();
    bool getHasStorage();
    string getBuild();
    string getRooms();
};

// Derived class representing a storage property
class Storage : public Commercial {
private:
    bool is_renew;
    bool has_storage;
    string build;
    string rooms;

public:
    Storage(); // Default constructor
    Storage(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
            string price, string address, string description, string pic, bool has_deed,
            bool is_renew, bool has_storage,string build, string rooms);

    // Setter methods for additional attributes
    void setIsRenew(bool is_renew);
    void setHasStorage(bool has_storage);
    void setBuild(string build);
    void setRooms(string rooms);

    // Getter methods for additional attributes
    bool getIsRenew();
    bool getHasStorage();
    string getBuild();
    string getRooms();
};

#endif // PROPERTY_H
