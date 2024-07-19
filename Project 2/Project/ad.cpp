#include "ad.h"

// Initialize static variables
int Ad::counter = 0;
vector<Property> Ad::properties;
vector<Land> Ad::lands;
vector<Kolangi> Ad::kolangies;
vector<Garden> Ad::gardens;
vector<Apartment> Ad::apartments;
vector<Villa> Ad::villas;
vector<Workplace> Ad::workplaces;
vector<Clinic> Ad::clinics;
vector<Shop> Ad::shops;
vector<Workshop> Ad::workshops;
vector<Storage> Ad::storages;

// Constructor for Land property
Ad::Ad(User *owner, Land land) {
    this->id = 10000 + counter++; // Assign a unique ID
    this->land = land; // Assign the land property
    this->owner = owner; // Set the owner
    this->type = "زمین"; // Set the type as "زمین"
    lands.push_back(land); // Add to lands vector
    properties.push_back(land); // Add to properties vector
}

// Constructor for Kolangi property
Ad::Ad(User *owner, Kolangi kolangi) {
    this->id = 10000 + counter++; // Assign a unique ID
    this->kolangi = kolangi; // Assign the kolangi property
    this->owner = owner; // Set the owner
    this->type = "کلنگی"; // Set the type as "کلنگی"
    kolangies.push_back(kolangi); // Add to kolangies vector
    properties.push_back(kolangi); // Add to properties vector
}

// Constructor for Garden property
Ad::Ad(User *owner, Garden garden) {
    this->id = 10000 + counter++; // Assign a unique ID
    this->garden = garden; // Assign the garden property
    this->owner = owner; // Set the owner
    this->type = "باغ"; // Set the type as "باغ"
    gardens.push_back(garden); // Add to gardens vector
    properties.push_back(garden); // Add to properties vector
}

// Constructor for Apartment property
Ad::Ad(User *owner, Apartment apartment) {
    this->id = 10000 + counter++; // Assign a unique ID
    this->apartment = apartment; // Assign the apartment property
    this->owner = owner; // Set the owner
    this->type = "آپارتمان"; // Set the type as "آپارتمان"
    apartments.push_back(apartment); // Add to apartments vector
    properties.push_back(apartment); // Add to properties vector
}

// Constructor for Villa property
Ad::Ad(User *owner, Villa villa) {
    this->id = 10000 + counter++; // Assign a unique ID
    this->villa = villa; // Assign the villa property
    this->owner = owner; // Set the owner
    this->type = "ویلایی"; // Set the type as "ویلایی"
    villas.push_back(villa); // Add to villas vector
    properties.push_back(villa); // Add to properties vector
}

// Constructor for Workplace property
Ad::Ad(User *owner, Workplace workplace) {
    this->id = 10000 + counter++; // Assign a unique ID
    this->workplace = workplace; // Assign the workplace property
    this->owner = owner; // Set the owner
    this->type = "دفترکار"; // Set the type as "دفترکار"
    workplaces.push_back(workplace); // Add to workplaces vector
    properties.push_back(workplace); // Add to properties vector
}

// Constructor for Clinic property
Ad::Ad(User *owner, Clinic clinic) {
    this->id = 10000 + counter++; // Assign a unique ID
    this->clinic = clinic; // Assign the clinic property
    this->owner = owner; // Set the owner
    this->type = "مطب"; // Set the type as "مطب"
    clinics.push_back(clinic); // Add to clinics vector
    properties.push_back(clinic); // Add to properties vector
}

// Constructor for Shop property
Ad::Ad(User *owner, Shop shop) {
    this->id = 10000 + counter++; // Assign a unique ID
    this->shop = shop; // Assign the shop property
    this->owner = owner; // Set the owner
    this->type = "مغازه"; // Set the type as "مغازه"
    shops.push_back(shop); // Add to shops vector
    properties.push_back(shop); // Add to properties vector
}

// Constructor for Workshop property
Ad::Ad(User *owner, Workshop workshop) {
    this->id = 10000 + counter++; // Assign a unique ID
    this->workshop = workshop; // Assign the workshop property
    this->owner = owner; // Set the owner
    this->type = "کارگاه"; // Set the type as "کارگاه"
    workshops.push_back(workshop); // Add to workshops vector
    properties.push_back(workshop); // Add to properties vector
}

// Constructor for Storage property
Ad::Ad(User *owner, Storage storage) {
    this->id = 10000 + counter++; // Assign a unique ID
    this->storage = storage; // Assign the storage property
    this->owner = owner; // Set the owner
    this->type = "انبار"; // Set the type as "انبار"
    storages.push_back(storage); // Add to storages vector
    properties.push_back(storage); // Add to properties vector
}

// Set the owner of the Ad
void Ad::setOwner(User *owner){
    this->owner = owner;
}

// Get the property based on its type
Property Ad::getProperty() {
    if (this->type == "زمین")
        return this->land;
    else if (this->type == "کلنگی")
        return this->kolangi;
    else if (this->type == "باغ")
        return this->garden;
    else if (this->type == "آپارتمان")
        return this->apartment;
    else if (this->type == "ویلایی")
        return this->villa;
    else if (this->type == "دفترکار")
        return this->workplace;
    else if (this->type == "مطب")
        return this->clinic;
    else if (this->type == "مغازه")
        return this->shop;
    else if (this->type == "کارگاه")
        return this->workshop;
    else // storage
        return this->storage;
}

// Get the owner of the Ad
User* Ad::getOwner() {
    return this->owner;
}

// Get the ID of the Ad
int Ad::getId() {
    return this->id;
}

// Get the type of the Ad
string Ad::getType() {
    return this->type;
}
