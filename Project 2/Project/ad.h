#ifndef AD_H
#define AD_H

#include <vector>
#include <property.h>
#include <user.h>

using namespace std;


// Ad class definition
class Ad {
private:
    static int counter; // Static counter to keep track of Ad instances
    int id; // Unique identifier for each Ad
    string type; // Type of property
    User *owner; // Pointer to the User who owns the Ad
    Land land; // Land property
    Kolangi kolangi; // Kolangi property
    Garden garden; // Garden property
    Apartment apartment; // Apartment property
    Villa villa; // Villa property
    Workplace workplace; // Workplace property
    Clinic clinic; // Clinic property
    Shop shop; // Shop property
    Workshop workshop; // Workshop property
    Storage storage; // Storage property

public:
    static vector<Ad> ads; // Static vector to store all Ad instances
    static vector<Property> properties; // Static vector to store all Property instances
    static vector<Land> lands; // Static vector to store all Land instances
    static vector<Kolangi> kolangies; // Static vector to store all Kolangi instances
    static vector<Garden> gardens; // Static vector to store all Garden instances
    static vector<Apartment> apartments; // Static vector to store all Apartment instances
    static vector<Villa> villas; // Static vector to store all Villa instances
    static vector<Workplace> workplaces; // Static vector to store all Workplace instances
    static vector<Clinic> clinics; // Static vector to store all Clinic instances
    static vector<Shop> shops; // Static vector to store all Shop instances
    static vector<Workshop> workshops; // Static vector to store all Workshop instances
    static vector<Storage> storages; // Static vector to store all Storage instances


    // Constructors for different property types
    Ad(User *owner, Land land);
    Ad(User *owner, Kolangi kolangi);
    Ad(User *owner, Garden garden);
    Ad(User *owner, Apartment apartment);
    Ad(User *owner, Villa villa);
    Ad(User *owner, Workplace workplace);
    Ad(User *owner, Clinic clinic);
    Ad(User *owner, Shop shop);
    Ad(User *owner, Workshop workshop);
    Ad(User *owner, Storage storage);

    // Setter for the owner
    void setOwner(User *owner);
    // Getter for the ID
    int getId();
    // Getter for the type
    string getType();
    // Getter for the owner
    User* getOwner();
    // Getter for the property
    Property getProperty();
};
#endif // AD_H
