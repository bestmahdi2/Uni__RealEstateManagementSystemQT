#include "property.h"

// ============= Property =============

Property::Property() {
}

Property::~Property() {
}

Property::Property(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
             string price, string address, string description, string pic, bool has_deed) {
    setName(name);
    setType(type);
    setCategory(category);
    setPropertyType(property_type);
    setLand(land);
    setBuilding(building);
    setDeposit(deposit);
    setRent(rent);
    setPrice(price);
    setAddress(address);
    setDescription(description);
    setPic(pic);
    setHasDeed(has_deed);
}

void Property::setName(string name) {
    this->name = name;
}

void Property::setType(string type) {
    this->type = type;
}

void Property::setCategory(string category) {
    this->category = category;
}

void Property::setPropertyType(string property_type) {
    this->property_type = property_type;
}

void Property::setLand(string land) {
    this->land = land;
}

void Property::setBuilding(string building) {
    this->building = building;
}

void Property::setDeposit(string deposit) {
    this->deposit = deposit;
}

void Property::setRent(string rent) {
    this->rent = rent;
}

void Property::setPrice(string price) {
    this->price = price;
}

void Property::setAddress(string address) {
    this->address = address;
}

void Property::setDescription(string description) {
    this->description = description;
}

void Property::setPic(string pic) {
    this->pic = pic;
}

void Property::setHasDeed(bool has_deed) {
    this->has_deed = has_deed;
}

string Property::getName() {
    return this->name;
}

string Property::getType() {
    return this->type;
}

string Property::getCategory() {
    return this->category;
}

string Property::getPropertyType() {
    return this->property_type;
}

string Property::getLand() {
    return this->land;
}

string Property::getBuilding() {
    return this->building;
}

string Property::getDeposit() {
    return this->deposit;
}

string Property::getRent() {
    return this->rent;
}

string Property::getPrice() {
    return this->price;
}

string Property::getAddress() {
    return this->address;
}

string Property::getDescription() {
    return this->description;
}

string Property::getPic() {
    return this->pic;
}

bool Property::getHasDeed() {
    return this->has_deed;
}

// ============= Non Residential =============

Non_Residential::Non_Residential() {
}

Non_Residential::Non_Residential(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
                                 string price, string address, string description, string pic, bool has_deed): Property(name, type, category, property_type, land, building, deposit, rent,
                                                                                                                       price, address, description, pic, has_deed) {
}

// ============= Residential =============

Residential::Residential() {
}

Residential::Residential(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
                         string price, string address, string description, string pic, bool has_deed): Property(name, type, category, property_type, land, building, deposit, rent,
                                                                                                               price, address, description, pic, has_deed) {
}

// ============= Office =============

Office::Office() {
}

Office::Office(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
         string price, string address, string description, string pic, bool has_deed): Property(name, type, category, property_type, land, building, deposit, rent,
                                                                                               price, address, description, pic, has_deed) {
}

// ============= Commercial =============

Commercial::Commercial() {
}

Commercial::Commercial(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
                       string price, string address, string description, string pic, bool has_deed): Property(name, type, category, property_type, land, building, deposit, rent,
                                                                                                             price, address, description, pic, has_deed) {
}

// ============= Land =============

Land::Land() {
}

Land::~Land() {
}

Land::Land(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
             string price, string address, string description, string pic, bool has_deed) : Non_Residential(name, type, category, property_type, land, building, deposit, rent,
                                                                                                    price, address, description, pic, has_deed) {
}

// ============= Kolangi =============

Kolangi::Kolangi() {
}

Kolangi::Kolangi(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
                 string price, string address, string description, string pic, bool has_deed,
                 bool has_storage, string rooms) : Non_Residential(name, type, category, property_type, land, building, deposit, rent,
                                                                    price, address, description, pic, has_deed) {
    setHasStorage(has_storage);
    setRooms(rooms);
}

void Kolangi::setHasStorage(bool has_storage) {
    this->has_storage = has_storage;
}

void Kolangi::setRooms(string rooms) {
    this->rooms = rooms;
}

bool Kolangi::getHasStorage() {
    return has_storage;
}

string Kolangi::getRooms() {
    return rooms;
}

// ============= Garden =============

Garden::Garden() {
}

Garden::Garden(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
               string price, string address, string description, string pic, bool has_deed,
               bool is_renew, bool has_storage, string build, string rooms) : Non_Residential(name, type, category, property_type, land, building, deposit, rent,
                                                                                                price, address, description, pic, has_deed) {
    setIsRenew(is_renew);
    setHasStorage(has_storage);
    setBuild(build);
    setRooms(rooms);
}
void Garden::setIsRenew(bool is_renew) {
    this->is_renew = is_renew;
}

void Garden::setHasStorage(bool has_storage) {
    this->has_storage = has_storage;
}

void Garden::setBuild(string build) {
    this->build = build;
}

void Garden::setRooms(string rooms) {
    this->rooms = rooms;
}

bool Garden::getIsRenew() {
    return this->is_renew;
}

bool Garden::getHasStorage() {
    return this->has_storage;
}

string Garden::getBuild() {
    return this->build;
}

string Garden::getRooms() {
    return this->rooms;
}

// ============= Apartment =============

Apartment::Apartment() {
}

Apartment::Apartment(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
                     string price, string address, string description, string pic, bool has_deed,
                     bool is_furnished, bool is_renew, bool has_parking, bool has_elevator, bool has_storage, bool has_balcony,
                     bool has_wallpaper, string build, string floor, string rooms) : Residential(name, type, category, property_type, land, building, deposit, rent,
                                                                                           price, address, description, pic, has_deed) {
    setIsFurnished(is_furnished);
    setIsRenew(is_renew);
    setHasParking(has_parking);
    setHasElevator(has_elevator);
    setHasStorage(has_storage);
    setHasBalcony(has_balcony);
    setHasWallpaper(has_wallpaper);
    setBuild(build);
    setFloor(floor);
    setRooms(rooms);
}

void Apartment::setIsFurnished(bool is_furnished) {
    this->is_furnished = is_furnished;
}

void Apartment::setIsRenew(bool is_renew) {
    this->is_renew = is_renew;
}

void Apartment::setHasParking(bool has_parking) {
    this->has_parking = has_parking;
}

void Apartment::setHasElevator(bool has_elevator) {
    this->has_elevator = has_elevator;
}

void Apartment::setHasStorage(bool has_storage) {
    this->has_storage = has_storage;
}

void Apartment::setHasBalcony(bool has_balcony) {
    this->has_balcony = has_balcony;
}

void Apartment::setHasWallpaper(bool has_wallpaper) {
    this->has_wallpaper = has_wallpaper;
}

void Apartment::setBuild(string build) {
    this->build = build;
}

void Apartment::setFloor(string floor) {
    this->floor = floor;
}

void Apartment::setRooms(string rooms) {
    this->rooms = rooms;
}

bool Apartment::getIsFurnished() {
    return this->is_furnished;
}

bool Apartment::getIsRenew() {
    return this->is_renew;
}

bool Apartment::getHasParking() {
    return this->has_parking;
}

bool Apartment::getHasElevator() {
    return this->has_elevator;
}

bool Apartment::getHasStorage() {
    return this->has_storage;
}

bool Apartment::getHasBalcony() {
    return this->has_balcony;
}

bool Apartment::getHasWallpaper() {
    return this->has_wallpaper;
}

string Apartment::getBuild() {
    return this->build;
}

string Apartment::getFloor() {
    return this->floor;
}

string Apartment::getRooms() {
    return this->rooms;
}

// ============= Villa =============

Villa::Villa() {
}

Villa::Villa(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_furnished, bool is_renew, bool has_parking, bool has_storage, bool has_wallpaper, string build, string rooms) : Residential(name, type, category, property_type, land, building, deposit, rent,
                                                                                                                                                  price, address, description, pic, has_deed) {
        setIsFurnished(is_furnished);
        setIsRenew(is_renew);
        setHasParking(has_parking);
        setHasStorage(has_storage);
        setHasWallpaper(has_wallpaper);
        setBuild(build);
        setRooms(rooms);
}

void Villa::setIsFurnished(bool is_furnished) {
    this->is_furnished = is_furnished;
}

void Villa::setIsRenew(bool is_renew) {
    this->is_renew = is_renew;
}

void Villa::setHasParking(bool has_parking) {
    this->has_parking = has_parking;
}

void Villa::setHasStorage(bool has_storage) {
    this->has_storage = has_storage;
}

void Villa::setHasWallpaper(bool has_wallpaper) {
    this->has_wallpaper = has_wallpaper;
}

void Villa::setBuild(string build) {
    this->build = build;
}

void Villa::setRooms(string rooms) {
    this->rooms = rooms;
}

bool Villa::getIsFurnished() {
    return this->is_furnished;
}

bool Villa::getIsRenew() {
    return this->is_renew;
}

bool Villa::getHasParking() {
    return this->has_parking;
}

bool Villa::getHasStorage() {
    return this->has_storage;
}

bool Villa::getHasWallpaper() {
    return this->has_wallpaper;
}

string Villa::getBuild() {
    return this->build;
}

string Villa::getRooms() {
    return this->rooms;
}

// ============= Workplace =============

Workplace::Workplace() {
}

Workplace::Workplace(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_renew, bool has_parking, bool has_storage, bool has_wallpaper, string build, string rooms) : Office(name, type, category, property_type, land, building, deposit, rent,
                                                                                                                                     price, address, description, pic, has_deed) {
    setIsRenew(is_renew);
    setHasParking(has_parking);
    setHasElevator(has_elevator);
    setHasStorage(has_storage);
    setHasBalcony(has_balcony);
    setHasWallpaper(has_wallpaper);
    setBuild(build);
    setFloor(floor);
    setRooms(rooms);
}

void Workplace::setIsRenew(bool is_renew) {
    this->is_renew = is_renew;
}

void Workplace::setHasParking(bool has_parking) {
    this->has_parking = has_parking;
}

void Workplace::setHasElevator(bool has_elevator) {
    this->has_elevator = has_elevator;
}

void Workplace::setHasStorage(bool has_storage) {
    this->has_storage = has_storage;
}

void Workplace::setHasBalcony(bool has_balcony) {
    this->has_balcony = has_balcony;
}

void Workplace::setHasWallpaper(bool has_wallpaper) {
    this->has_wallpaper = has_wallpaper;
}

void Workplace::setBuild(string build) {
    this->build = build;
}

void Workplace::setFloor(string floor) {
    this->floor = floor;
}

void Workplace::setRooms(string rooms) {
    this->rooms = rooms;
}

bool Workplace::getIsRenew() {
    return this->is_renew;
}

bool Workplace::getHasParking() {
    return this->has_parking;
}

bool Workplace::getHasElevator() {
    return this->has_elevator;
}

bool Workplace::getHasStorage() {
    return this->has_storage;
}

bool Workplace::setHasBalcony() {
    return this->has_balcony;
}

bool Workplace::getHasWallpaper() {
    return this->has_wallpaper;
}

string Workplace::getBuild() {
    return this->build;
}

string Workplace::getFloor() {
    return this->floor;
}

string Workplace::getRooms() {
    return this->rooms;
}

// ============= Clinic =============

Clinic::Clinic() {
}

Clinic::Clinic(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_renew, bool has_parking, bool has_storage, bool has_wallpaper, string build, string rooms) : Office(name, type, category, property_type, land, building, deposit, rent,
                                                                                                                         price, address, description, pic, has_deed) {
    setIsRenew(is_renew);
    setHasParking(has_parking);
    setHasElevator(has_elevator);
    setHasStorage(has_storage);
    setHasBalcony(has_balcony);
    setHasWallpaper(has_wallpaper);
    setBuild(build);
    setFloor(floor);
    setRooms(rooms);
}

void Clinic::setIsRenew(bool is_renew) {
    this->is_renew = is_renew;
}

void Clinic::setHasParking(bool has_parking) {
    this->has_parking = has_parking;
}

void Clinic::setHasElevator(bool has_elevator) {
    this->has_elevator = has_elevator;
}

void Clinic::setHasStorage(bool has_storage) {
    this->has_storage = has_storage;
}

void Clinic::setHasBalcony(bool has_balcony) {
    this->has_balcony = has_balcony;
}

void Clinic::setHasWallpaper(bool has_wallpaper) {
    this->has_wallpaper = has_wallpaper;
}

void Clinic::setBuild(string build) {
    this->build = build;
}

void Clinic::setFloor(string floor) {
    this->floor = floor;
}

void Clinic::setRooms(string rooms) {
    this->rooms = rooms;
}

bool Clinic::getIsRenew() {
    return this->is_renew;
}

bool Clinic::getHasParking() {
    return this->has_parking;
}

bool Clinic::getHasElevator() {
    return this->has_elevator;
}

bool Clinic::getHasStorage() {
    return this->has_storage;
}

bool Clinic::setHasBalcony() {
    return this->has_balcony;
}

bool Clinic::getHasWallpaper() {
    return this->has_wallpaper;
}

string Clinic::getBuild() {
    return this->build;
}

string Clinic::getFloor() {
    return this->floor;
}

string Clinic::getRooms() {
    return this->rooms;
}

// ============= Shop =============

Shop::Shop() {
}

Shop::Shop(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_renew, bool has_elevator, bool has_storage, bool has_wallpaper, string build, string floor, string rooms) : Commercial(name, type, category, property_type, land, building, deposit, rent,
                                                                                                                                             price, address, description, pic, has_deed) {
    setIsRenew(is_renew);
    setHasElevator(has_elevator);
    setHasStorage(has_storage);
    setHasWallpaper(has_wallpaper);
    setBuild(build);
    setFloor(floor);
    setRooms(rooms);
}

void Shop::setIsRenew(bool is_renew) {
    this->is_renew = is_renew;
}

void Shop::setHasElevator(bool has_elevator) {
    this->has_elevator = has_elevator;
}

void Shop::setHasStorage(bool has_storage) {
    this->has_storage = has_storage;
}

void Shop::setHasWallpaper(bool has_wallpaper) {
    this->has_wallpaper = has_wallpaper;
}

void Shop::setBuild(string build) {
    this->build = build;
}

void Shop::setFloor(string floor) {
    this->floor = floor;
}

void Shop::setRooms(string rooms) {
    this->rooms = rooms;
}

bool Shop::getIsRenew() {
    return this->is_renew;
}

bool Shop::getHasElevator() {
    return this->has_elevator;
}

bool Shop::getHasStorage() {
    return this->has_storage;
}

bool Shop::getHasWallpaper() {
    return this->has_wallpaper;
}

string Shop::getBuild() {
    return this->build;
}

string Shop::getFloor() {
    return this->floor;
}

string Shop::getRooms() {
    return this->rooms;
}

// ============= Workshop =============

Workshop::Workshop() {
}

Workshop::Workshop(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
           string price, string address, string description, string pic, bool has_deed,
           bool is_renew, bool has_storage, string build, string rooms) : Commercial(name, type, category, property_type, land, building, deposit, rent,
                                                                                      price, address, description, pic, has_deed) {
    setIsRenew(is_renew);
    setHasStorage(has_storage);
    setBuild(build);
    setRooms(rooms);
}

void Workshop::setIsRenew(bool is_renew) {
    this->is_renew = is_renew;
}

void Workshop::setHasStorage(bool has_storage) {
    this->has_storage = has_storage;
}

void Workshop::setBuild(string build) {
    this->build = build;
}

void Workshop::setRooms(string rooms) {
    this->rooms = rooms;
}

bool Workshop::getIsRenew() {
    return this->is_renew;
}

bool Workshop::getHasStorage() {
    return this->has_storage;
}

string Workshop::getBuild() {
    return this->build;
}

string Workshop::getRooms() {
    return this->rooms;
}

// ============= Storage =============

Storage::Storage() {
}

Storage::Storage(string name, string type, string category, string property_type, string land, string building, string deposit, string rent,
            string price, string address, string description, string pic, bool has_deed,
                 bool is_renew, bool has_storage,string build, string rooms) : Commercial(name, type, category, property_type, land, building, deposit, rent,
                                                                                            price, address, description, pic, has_deed) {
    setIsRenew(is_renew);
    setHasStorage(has_storage);
    setBuild(build);
    setRooms(rooms);
}

void Storage::setIsRenew(bool is_renew) {
    this->is_renew = is_renew;
}

void Storage::setHasStorage(bool has_storage) {
    this->has_storage = has_storage;
}

void Storage::setBuild(string build) {
    this->build = build;
}

void Storage::setRooms(string rooms) {
    this->rooms = rooms;
}

bool Storage::getIsRenew() {
    return this->is_renew;
}

bool Storage::getHasStorage() {
    return this->has_storage;
}

string Storage::getBuild() {
    return this->build;
}

string Storage::getRooms() {
    return this->rooms;
}
