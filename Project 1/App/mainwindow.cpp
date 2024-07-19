#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "itemwidget.h"
#include "MainProgram.h"

#include <QPixmap>
#include <QPainter>
#include <QtWidgets>
#include <QStyleOptionViewItem>

#include <string>
#include <vector>
#include <locale>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <unordered_map>

bool SIGNED_IN = false;
int Property::ID = 0;

std::unordered_map<string, int> sell_detail_1;
std::unordered_map<string, string> sell_detail_2;
std::unordered_map<int, string> deals {{0, "فروش"}, {1, "اجاره"}, {2, "معاوضه"}};
std::unordered_map<int, string> categories {{0, "مسکونی"}, {1, "اداری و تجاری"}};
typedef std::array<string, 3> subs;
std::map<string, subs> subcategories;

std::vector<Apartment> apartments;
std::vector<HouseVilla> houses_villas;
std::vector<LandOldProperty> lands_old_properties;
std::vector<OfficeAdminClinic> offices_admins_clinics;
std::vector<ShopBooth> shops_boothes;
std::vector<IndustrialAgriCommercial> industrials_agris_commercials;

string strToman = " تومان";
string strMonth = " تومان ماهانه";
string strPrice;
QString strPriceFinal;

// Function to check if a string contains only digits
bool is_digits(const string &str) {
    // std::all_of returns true if all elements in the range satisfy the condition
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

// Function to convert a number string into a string with commas separating thousands
string convertNumberToString(string s) {
    string result = "";
    string tempResult = "";
    int j = 0;

    // Loop through the string from the end to the beginning
    for (int i=s.size()-1; i>=0; i--) {
        // Insert a comma after every three digits
        if (j%3 == 0)
            result.append(",");

        // Append the current digit to the result
        result.append(s, i, 1);
        j++;
    }

     // Remove the leading comma
    result = result.substr(1, result.size()-1);

    // Reverse the result to get the final formatted string
    for (int i=result.size()-1; i>=0; i--)
        tempResult.append(result, i, 1);

    return tempResult;
}

// Function to remove the first word from a string
string removeFirstWord(const string& str) {
    // Find the position of the first space
    size_t pos = str.find(' ');

    // If there is no space, return the original string
    if (pos == string::npos)
        return str;

    // Create a substring starting from the character after the first space
    return str.substr(pos + 1);
}

// Function to get the first word from a string
string getFirstWord(const string& str) {
    // Find the position of the first space
    size_t pos = str.find(' ');

    // If there is no space, return the original string
    if (pos == string::npos)
        return str;

    // Create a substring from the beginning to the first space
    return str.substr(0, pos);
}

// Function to get the current path
std::wstring ExePath() {
    TCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName( NULL, buffer, MAX_PATH );
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    return std::wstring(buffer).substr(0, pos);
}

// Function to save users to a file
void save_users() {
    std::vector<string> users;
    wstring path_wstring = ExePath();
    string path(path_wstring.begin(), path_wstring.end());
    path.append("\\users.txt");

    // Iterate over the users and get their save string representation
    for (auto user: Tools::users)
        users.push_back(user.save_string());

    // Open an output file stream
    std::ofstream output_file(path);

    // Use an ostream iterator to write the user strings to the file
    std::ostream_iterator<string> output_iterator(output_file, "\n");
    std::copy(std::begin(users), std::end(users), output_iterator);
}

// Function to load users from a file
void load_users() {
    wstring path_wstring = ExePath();
    string path(path_wstring.begin(), path_wstring.end());
    path.append("\\users.txt");

    std::ifstream input_file(path);
    string line;

    Tools::users.clear(); // Clear the existing users
    User::USER = User(); // Initialize the global USER object
    User::ID = 1; // Reset the user ID

    string user_str = "";
    string key;
    string value;
    std::unordered_map<string, string> values;

    // Read the file line by line
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        if (line == "------"){
            // Create a new User object with the read values and add to the users list
            User user = User(values["username"], values["password"], values["name"], values["fname"], values["phone"], values["email"]);
            Tools::users.push_back(user);
        } else {
            // Parse the key and value from the line and store them in the map
            key = getFirstWord(line);
            value = removeFirstWord(line);
            values[key] = value;
        }
    }

    input_file.close(); // Close the input file stream
}

// Function to find and concatenate the facilities of a property based on provided boolean flags
string find_facilities(bool hasElevator, bool hasParking, bool hasStorage, bool hasBalcony, bool hasBathroom, bool hasCooling, bool hasHeating)
{
    string str = "";
    string sep = "، "; // Separator used to separate facilities in the string

    // Append facility names to the string if the corresponding flag is true
    if (hasElevator){
        str.append("آسانسور");
        str.append(sep);
    }
    if (hasParking) {
        str.append("پارکینگ");
        str.append(sep);
    }
    if (hasStorage) {
        str.append("انباری");
        str.append(sep);
    }
    if (hasBalcony) {
        str.append("بالکن");
        str.append(sep);
    }
    if (hasBathroom) {
        str.append("سرویس بهداشتی");
        str.append(sep);
    }
    if (hasCooling) {
        str.append("سرمایش");
        str.append(sep);
    }
    if (hasHeating) {
        str.append("گرمایش");
        str.append(sep);
    }

    // Return the concatenated facilities string
    return str;
}

// Function to find an Apartment object by its ID
Apartment find_apartment(int id){
    // Iterate through the list of apartments
    for (auto ap: apartments)
        // Return the apartment if the ID matches
        if (ap.id == id)
            return ap;

    // Return a default Apartment object if not found
    return Apartment();
}

// Function to find a HouseVilla object by its ID
HouseVilla find_house_villa(int id){
    // Iterate through the list of houses and villas
    for (auto ap: houses_villas)
        // Return the house or villa if the ID matches
        if (ap.id == id)
            return ap;

    // Return a default HouseVilla object if not found
    return HouseVilla();
}

// Function to find a LandOldProperty object by its ID
LandOldProperty find_land_old_property(int id){
    // Iterate through the list of lands and old properties
    for (auto ap: lands_old_properties)
        // Return the land or old property if the ID matches
        if (ap.id == id)
            return ap;

    // Return a default LandOldProperty object if not found
    return LandOldProperty();
}

// Function to find an OfficeAdminClinic object by its ID
OfficeAdminClinic find_office_admin_clinic(int id){
    // Iterate through the list of offices, admin spaces, and clinics
    for (auto ap: offices_admins_clinics)
        // Return the office, admin space, or clinic if the ID matches
        if (ap.id == id)
            return ap;

    // Return a default OfficeAdminClinic object if not found
    return OfficeAdminClinic();
}

// Function to find a ShopBooth object by its ID
ShopBooth find_shop_booth(int id){
    // Iterate through the list of shops and booths
    for (auto ap: shops_boothes)
        // Return the shop or booth if the ID matches
        if (ap.id == id)
            return ap;

    // Return a default ShopBooth object if not found
    return ShopBooth();
}

// Function to find an IndustrialAgriCommercial object by its ID
IndustrialAgriCommercial find_industrial_agri_commercial(int id){
    // Iterate through the list of industrial, agricultural, and commercial properties
    for (auto ap: industrials_agris_commercials)
        // Return the industrial, agricultural, or commercial property if the ID matches
        if (ap.id == id)
            return ap;

    // Return a default IndustrialAgriCommercial object if not found
    return IndustrialAgriCommercial();
}

// Function to find a user by their ID
int find_user_by_id(int id) {
    // Iterate over the list of users
    for (size_t i = 0; i < Tools::users.size(); ++i)
        // Check if the current user's ID matches the given ID
        if (Tools::users[i].id == id)
            return i; // If a match is found, return the index of the user

    // If no match is found, return -1
    return -1;
}

// Custom item delegate class for drawing a separator line between items
class ItemDelegate : public QStyledItemDelegate {
public:
    // Constructor that initializes the parent object
    ItemDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

protected:
    // Overridden paint function to customize item drawing
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        // Call the base class paint method
        QStyledItemDelegate::paint(painter, option, index);

        // Draw a gray line below each item except the last one
        if (index.row() < index.model()->rowCount() - 1) {
            painter->setPen(QPen(Qt::gray, 1));
            painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
        }
    }
};

// Destructor for the MainWindow class
MainWindow::~MainWindow()
{
    // Delete the user interface object
    delete ui;
}

// Constructor for the MainWindow class
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Setup the user interface

    // Create an instance of ItemDelegate
    ItemDelegate *delegate = new ItemDelegate(this);
    // Set the delegate for the QListWidget
    ui->listWidget->setItemDelegate(delegate);
    // Connect the itemClicked signal to the onItemClicked slot
    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::onItemClicked);

    // Load the users from the file
    load_users();

    // Initialize subcategories for the categories
    subcategories[categories[0]] = {"آپارتمان", "خانه و ویلا", "زمین و کلنگی"};
    subcategories[categories[1]] = {"دفترکار، اتاق اداری و مطب", "مغازه و غرفه", "صنعتی، کشاورزی و تجاری"};

    // Create and initialize sample Apartment objects
    Apartment apartment1 = Apartment(&Tools::users[0], "آپارتمان دو خوابه 90 متری", "7000000000", "", "", ":/images/apartment1.jpg",
               subcategories[categories[0]][0], deals[0], "اصفهان، بزرگمهر",
               true, 0, 90, "",
                1392, 2, 1, true, false, false, false, false, true, true, true);

    Apartment apartment2 = Apartment(&Tools::users[0], "آپارتمان شیک تک خواب ۷۵ متر", "5500000000", "", "", ":/images/apartment2.jpg",
               subcategories[categories[0]][0], "معاوضه", "اصفهان، چهارباغ",
               true, 0, 75, "تماس بگیرید.",
               1395, 1, 0, true, true, true, false, false, true, true, true);

    // Create and initialize sample HouseVilla objects
    HouseVilla hv1 = HouseVilla(&Tools::users[0], "ویلایی با یک اتاق", "", "300000000", "7000000",  ":/images/house1.jpg",
               subcategories[categories[0]][1], deals[1], "تهران، آزادی",
               true, 40, 90, "",
               1400, 1, true, true, true, true, true, true, true);

    HouseVilla hv2 = HouseVilla(&Tools::users[0], "خانه حیاط دار 90 متری", "9200000000", "", "", ":/images/default.jpg",
               subcategories[categories[0]][1], deals[0], "تهران، پردیس",
               false, 30, 60, "",
               1389, 1, false, false, false, false, true, true, true);

    // Create and initialize sample OfficeAdminClinic objects
    OfficeAdminClinic oac1 = OfficeAdminClinic(&Tools::users[1], "آفیس شیک و نو ساز 100 متر", "", "500000000", "50000000", ":/images/oac1.jpg",
               subcategories[categories[1]][0], deals[1], "تهران، ولیعصر",
               true, 0, 100, "برای بازدید تماس بگیرید.",
               1399, 2, 3, true, false, false, false);

    OfficeAdminClinic oac2 = OfficeAdminClinic(&Tools::users[1], "فروش مطب خیابان عظیمیه", "15000000000", "", "", ":/images/oac2.jpg",
               subcategories[categories[1]][0], deals[0], "خیابان عظیمیه",
               true, 0, 105, "", 1400, 2, 2, true, false, false, false);

    // Create and initialize sample ShopBooth objects
    ShopBooth sbiac1 = ShopBooth(&Tools::users[2], "مغازه 50 متر", "9400000000", "", "", ":/images/sbiac1.jpg",
                   subcategories[categories[1]][1], deals[0], sell_detail_2["full_address"],
                   true, 0, 50, "", 1380, 1, true);

    ShopBooth sbiac2 = ShopBooth(&Tools::users[2], "مغازه کنار بازار", "", "400000000", "55000000", ":/images/sbiac2.jpg",
                   subcategories[categories[1]][1], deals[1], "شهرکرد، خیابان شریعتی",
                   true, 0, 60, "", 1385, 1, true);

    // Create and initialize sample IndustrialAgriCommercial objects
    IndustrialAgriCommercial sbiac3 = IndustrialAgriCommercial(&Tools::users[3], "کارگاه سنگبری", "", "700000000", "60000000", ":/images/sbiac3.jpg",
                   subcategories[categories[1]][2], deals[1], "شهرکرد، شهرک صعنتی",
                   true, 50, 200, "", 1390, 2, true);

    IndustrialAgriCommercial sbiac4 = IndustrialAgriCommercial(&Tools::users[3], "کارگاه صعنتی شهرک سلامت", "100000000000", "", "", ":/images/sbiac4.jpg",
                   subcategories[categories[1]][2], deals[0], "حوالی شهرک سلامت",
                   true, 100, 250, "", 1391, 1, true);

    // Add apartments to the relevant vectors and the Tools::properties vector
    apartments.push_back(apartment1);
    apartments.push_back(apartment2);
    Tools::properties.push_back(apartment1);
    Tools::properties.push_back(apartment2);

    // Add houses and villas to the relevant vectors and the Tools::properties vector
    houses_villas.push_back(hv1);
    houses_villas.push_back(hv2);
    Tools::properties.push_back(hv1);
    Tools::properties.push_back(hv2);

    // Add offices, admins, and clinics to the relevant vectors and the Tools::properties vector
    offices_admins_clinics.push_back(oac1);
    offices_admins_clinics.push_back(oac2);
    Tools::properties.push_back(oac1);
    Tools::properties.push_back(oac2);

    // Add shops and booths to the relevant vectors and the Tools::properties vector
    shops_boothes.push_back(sbiac1);
    shops_boothes.push_back(sbiac2);
    Tools::properties.push_back(sbiac1);
    Tools::properties.push_back(sbiac2);

    // Add industrial, agricultural, and commercial properties to the relevant vectors and the Tools::properties vector
    industrials_agris_commercials.push_back(sbiac3);
    industrials_agris_commercials.push_back(sbiac4);
    Tools::properties.push_back(sbiac3);
    Tools::properties.push_back(sbiac4);

    // Iterate through the properties and add them to the UI list widget
    for(auto property : Tools::properties) {
        // Convert the total price or monthly rent to a formatted string
        strPrice = property.totalPrice != "" ? convertNumberToString(property.totalPrice).append(strToman) : convertNumberToString(property.monthlyRent).append(strMonth);
        strPriceFinal = QString::fromStdString(strPrice);

        // Add the item to the UI list widget
        addItem(property.id, QString::fromStdString(property.photoPath), strPriceFinal,
                QString::fromStdString(property.title), QString::fromStdString(property.full_address));
    }
}

// Function to clear all items from the QListWidget
void MainWindow::empty_list_widget(){
    // Remove items one by one until the list is empty
    while(ui->listWidget->count() > 0)
        ui->listWidget->takeItem(0);
}

// Function to add an item to the QListWidget
void MainWindow::addItem(const int id, const QString &imagePath, const QString &price, const QString &name, const QString &location)
{
    // Create a new QListWidgetItem
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    // Create a custom ItemWidget with the provided details
    ItemWidget *widget = new ItemWidget(id, imagePath, price, name, location);
    // Set the size hint for the item based on the custom widget
    item->setSizeHint(widget->sizeHint());

    // Store the ID in the item using the UserRole
    item->setData(Qt::UserRole, id);

    // Add the item to the QListWidget
    ui->listWidget->addItem(item);
    // Set the custom widget to be displayed for the item
    ui->listWidget->setItemWidget(item, widget);
}

void MainWindow::onItemClicked(QListWidgetItem *item)
{
    // Retrieve the ID from the item
    int id = item->data(Qt::UserRole).toInt();

    Property property;
    // Find the property with the given ID
    for (auto p: Tools::properties)
        if (p.id == id)
            property = p;

     // Initialize string constants for use in UI labels
    string has = "دارد";
    string not_have = "ندارد";
    string yes = "بله";
    string no = "خیر";
    string ground = "همکف";
    string description = "توضیحات: ";
    string address = "آدرس: ";
    string facilities_str = "امکانات: ";

    // Check the category of the property and update UI accordingly
    if (property.category == subcategories[categories[0]][0]) { // apartment
        Apartment ap = find_apartment(property.id);

        // Set visibility of UI elements based on ownership
        ui->pushButton_detail_apartment_chat->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_apartment_report->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_apartment_delete->setVisible(User::USER.id == property.owner->id);

        // Update UI labels with apartment details
        change_label_text(ui->label_detail_apartment_title, ap.title);
        change_label_text(ui->label_detail_apartment_land_area, to_string(ap.landArea));
        change_label_text(ui->label_detail_apartment_build_area, to_string(ap.builtArea));
        change_label_text(ui->label_detail_apartment_deed, ap.hasDeed ? has : not_have);
        change_label_text(ui->label_detail_apartment_renovated, ap.isRenovated ? yes : no);
        change_label_text(ui->label_detail_apartment_year, to_string(ap.buildYear));
        change_label_text(ui->label_detail_apartment_floor, ap.floor == 0 ? ground : to_string(ap.floor));
        change_label_text(ui->label_detail_apartment_room,  ap.numRooms == 0 ? not_have : to_string(ap.numRooms));

         // Update facilities label
        change_label_text(ui->label_detail_apartment_facilities, facilities_str.append(find_facilities(ap.hasElevator,
                                                                                                       ap.hasParking,
                                                                                                       ap.hasStorage,
                                                                                                       ap.hasBalcony,
                                                                                                       ap.hasBathroom,
                                                                                                       ap.hasCooling,
                                                                                                       ap.hasHeating)));

        // Update price labels based on the availability of total price
        if (ap.totalPrice != "") {
            ui->label_detail_apartment_deposit->setVisible(false);
            ui->label_detail_apartment_deposit_text->setVisible(false);
            ui->label_detail_apartment_monthly_rent->setVisible(false);
            ui->label_detail_apartment_monthly_rent_text->setVisible(false);
            ui->label_detail_apartment_total_price->setVisible(true);
            ui->label_detail_apartment_total_price_text->setVisible(true);
            change_label_text(ui->label_detail_apartment_total_price, convertNumberToString(ap.totalPrice));
        } else {
            ui->label_detail_apartment_deposit->setVisible(true);
            ui->label_detail_apartment_deposit_text->setVisible(true);
            ui->label_detail_apartment_monthly_rent->setVisible(true);
            ui->label_detail_apartment_monthly_rent_text->setVisible(true);
            ui->label_detail_apartment_total_price->setVisible(false);
            ui->label_detail_apartment_total_price_text->setVisible(false);
            change_label_text(ui->label_detail_apartment_deposit, convertNumberToString(ap.deposit));
            change_label_text(ui->label_detail_apartment_monthly_rent, convertNumberToString(ap.monthlyRent));
        }

        // Update address and description labels
        change_label_text(ui->label_detail_apartment_full_address, ap.full_address);
        change_label_text(ui->label_detail_apartment_description, ap.description);
        change_label_text(ui->label_detail_apartment_phone, ap.owner->phone);
        change_label_text(ui->label_detail_apartment_email, ap.owner->email);

        // Update the photo label
        QPixmap mypix(QString::fromStdString(ap.photoPath));
        ui->label_detail_apartment_photo->setPixmap(mypix);
        // Change the page to the apartment details page
        change_page("ads", 13);

    } else if (property.category == subcategories[categories[0]][1]) { // house villa
        HouseVilla hv = find_house_villa(property.id);

        // Set visibility of UI elements based on ownership
        ui->pushButton_detail_hv_chat->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_hv_report->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_hv_delete->setVisible(User::USER.id == property.owner->id);

        // Update UI labels with house villa details
        change_label_text(ui->label_detail_hv_title, hv.title);
        change_label_text(ui->label_detail_hv_land_area, to_string(hv.landArea));
        change_label_text(ui->label_detail_hv_build_area, to_string(hv.builtArea));
        change_label_text(ui->label_detail_hv_deed, hv.hasDeed ? has : not_have);
        change_label_text(ui->label_detail_hv_renovated, hv.isRenovated ? yes : no);
        change_label_text(ui->label_detail_hv_year, to_string(hv.buildYear));
        change_label_text(ui->label_detail_hv_room, hv.numRooms == 0 ? not_have : to_string(hv.numRooms));

        // Update facilities label
        change_label_text(ui->label_detail_hv_facilities, facilities_str.append(find_facilities(false, hv.hasParking,
                                                                                                hv.hasStorage,
                                                                                                hv.hasBalcony,
                                                                                                hv.hasBathroom,
                                                                                                hv.hasCooling,
                                                                                                hv.hasHeating)));

        // Update price labels based on the availability of total price
        if (hv.totalPrice != "") {
            ui->label_detail_hv_deposit->setVisible(false);
            ui->label_detail_hv_deposit_text->setVisible(false);
            ui->label_detail_hv_monthly_rent->setVisible(false);
            ui->label_detail_hv_monthly_rent_text->setVisible(false);
            ui->label_detail_hv_total_price->setVisible(true);
            ui->label_detail_hv_total_price_text->setVisible(true);
            change_label_text(ui->label_detail_hv_total_price, convertNumberToString(hv.totalPrice));
        } else {
            ui->label_detail_hv_deposit->setVisible(true);
            ui->label_detail_hv_deposit_text->setVisible(true);
            ui->label_detail_hv_monthly_rent->setVisible(true);
            ui->label_detail_hv_monthly_rent_text->setVisible(true);
            ui->label_detail_hv_total_price->setVisible(false);
            ui->label_detail_hv_total_price_text->setVisible(false);
            change_label_text(ui->label_detail_hv_deposit, convertNumberToString(hv.deposit));
            change_label_text(ui->label_detail_hv_monthly_rent, convertNumberToString(hv.monthlyRent));
        }

        // Update address and description labels
        change_label_text(ui->label_detail_hv_full_address, address.append(hv.full_address));
        change_label_text(ui->label_detail_hv_description, description.append(hv.description));
        change_label_text(ui->label_detail_hv_phone, hv.owner->phone);
        change_label_text(ui->label_detail_hv_email, hv.owner->email);

        // Update the photo label
        QPixmap mypix(QString::fromStdString(hv.photoPath));
        ui->label_detail_hv_photo->setPixmap(mypix);

        // Change the page to the house villa details page
        change_page("ads", 14);

    } else if (property.category == subcategories[categories[0]][2]) { // land old property
        LandOldProperty lop = find_land_old_property(property.id);

        // Set visibility of UI elements based on ownership
        ui->pushButton_detail_lop_chat->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_lop_report->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_lop_delete->setVisible(User::USER.id == property.owner->id);

        // Update UI labels with land old property details
        change_label_text(ui->label_detail_lop_title, lop.title);
        change_label_text(ui->label_detail_lop_land_area, to_string(lop.landArea));
        change_label_text(ui->label_detail_lop_build_area, to_string(lop.builtArea));
        change_label_text(ui->label_detail_lop_deed, lop.hasDeed ? has : not_have);
        change_label_text(ui->label_detail_lop_total_price, convertNumberToString(lop.totalPrice));

        // Update address and description labels
        change_label_text(ui->label_detail_lop_full_address, address.append(lop.full_address));
        change_label_text(ui->label_detail_lop_description, description.append(lop.description));
        change_label_text(ui->label_detail_lop_phone, description.append(lop.owner->phone));
        change_label_text(ui->label_detail_lop_email, description.append(lop.owner->email));

        // Update the photo label
        QPixmap mypix(QString::fromStdString(lop.photoPath));
        ui->label_detail_lop_photo->setPixmap(mypix);

        // Change the page to the land old property details page
        change_page("ads", 15);

    } else if (property.category == subcategories[categories[1]][0]) { // office admin clinic
        OfficeAdminClinic oac = find_office_admin_clinic(property.id);

        // Set visibility of UI elements based on ownership
        ui->pushButton_detail_oac_chat->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_oac_report->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_oac_delete->setVisible(User::USER.id == property.owner->id);

        // Update UI labels with commercial office details
        change_label_text(ui->label_detail_oac_title, oac.title);
        change_label_text(ui->label_detail_oac_land_area, to_string(oac.landArea));
        change_label_text(ui->label_detail_oac_build_area, to_string(oac.builtArea));
        change_label_text(ui->label_detail_oac_deed, oac.hasDeed ? has : not_have);
        change_label_text(ui->label_detail_oac_year, to_string(oac.buildYear));
        change_label_text(ui->label_detail_oac_floor, oac.floor == 0 ? ground : to_string(oac.floor));
        change_label_text(ui->label_detail_oac_room, oac.numRooms == 0 ? not_have : to_string(oac.numRooms));

        // Update facilities label
        change_label_text(ui->label_detail_oac_facilities, facilities_str.append(find_facilities(oac.hasElevator,
                                                                                                 oac.hasParking,
                                                                                                 oac.hasStorage,
                                                                                                 false, false, false,
                                                                                                 false)));

        // Update price labels based on the availability of total price
        if (oac.totalPrice != "") {
            ui->label_detail_oac_deposit->setVisible(false);
            ui->label_detail_oac_deposit_text->setVisible(false);
            ui->label_detail_oac_monthly_rent->setVisible(false);
            ui->label_detail_oac_monthly_rent_text->setVisible(false);
            ui->label_detail_oac_total_price->setVisible(true);
            ui->label_detail_oac_total_price_text->setVisible(true);
            change_label_text(ui->label_detail_oac_total_price, convertNumberToString(oac.totalPrice));
        } else {
            ui->label_detail_oac_deposit->setVisible(true);
            ui->label_detail_oac_deposit_text->setVisible(true);
            ui->label_detail_oac_monthly_rent->setVisible(true);
            ui->label_detail_oac_monthly_rent_text->setVisible(true);
            ui->label_detail_oac_total_price->setVisible(false);
            ui->label_detail_oac_total_price_text->setVisible(false);
            change_label_text(ui->label_detail_oac_deposit, convertNumberToString(oac.deposit));
            change_label_text(ui->label_detail_oac_monthly_rent, convertNumberToString(oac.monthlyRent));
        }

        // Update address and description labels
        change_label_text(ui->label_detail_oac_full_address, address.append(oac.full_address));
        change_label_text(ui->label_detail_oac_description, description.append(oac.description));
        change_label_text(ui->label_detail_oac_phone, description.append(oac.owner->phone));
        change_label_text(ui->label_detail_oac_email, description.append(oac.owner->email));

        // Update the photo label
        QPixmap mypix(QString::fromStdString(oac.photoPath));
        ui->label_detail_oac_photo->setPixmap(mypix);

        // Change the page to the commercial office details page
        change_page("ads", 16);

    } else if (property.category == subcategories[categories[1]][1]) { // shop booth
        ShopBooth sbiac = find_shop_booth(property.id);

        // Set visibility of UI elements based on ownership
        ui->pushButton_detail_sbiac_chat->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_sbiac_report->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_sbiac_delete->setVisible(User::USER.id == property.owner->id);

        // Update UI labels with shop booth details
        change_label_text(ui->label_detail_sbiac_title, sbiac.title);
        change_label_text(ui->label_detail_sbiac_land_area, to_string(sbiac.landArea));
        change_label_text(ui->label_detail_sbiac_build_area, to_string(sbiac.builtArea));
        change_label_text(ui->label_detail_sbiac_deed, sbiac.hasDeed ? has : not_have);
        change_label_text(ui->label_detail_sbiac_year, to_string(sbiac.buildYear));
        change_label_text(ui->label_detail_sbiac_room, sbiac.numRooms == 0 ? not_have : to_string(sbiac.numRooms));

        // Update price labels based on the availability of total price
        if (sbiac.totalPrice != "") {
            ui->label_detail_sbiac_deposit->setVisible(false);
            ui->label_detail_sbiac_deposit_text->setVisible(false);
            ui->label_detail_sbiac_monthly_rent->setVisible(false);
            ui->label_detail_sbiac_monthly_rent_text->setVisible(false);
            ui->label_detail_sbiac_total_price->setVisible(true);
            ui->label_detail_sbiac_total_price_text->setVisible(true);
            change_label_text(ui->label_detail_sbiac_total_price, convertNumberToString(sbiac.totalPrice));
        } else {
            ui->label_detail_sbiac_deposit->setVisible(true);
            ui->label_detail_sbiac_deposit_text->setVisible(true);
            ui->label_detail_sbiac_monthly_rent->setVisible(true);
            ui->label_detail_sbiac_monthly_rent_text->setVisible(true);
            ui->label_detail_sbiac_total_price->setVisible(false);
            ui->label_detail_sbiac_total_price_text->setVisible(false);
            change_label_text(ui->label_detail_sbiac_deposit, convertNumberToString(sbiac.deposit));
            change_label_text(ui->label_detail_sbiac_monthly_rent, convertNumberToString(sbiac.monthlyRent));
        }

        // Update address and description labels
        change_label_text(ui->label_detail_sbiac_full_address, address.append(sbiac.full_address));
        change_label_text(ui->label_detail_sbiac_description, description.append(sbiac.description));
        change_label_text(ui->label_detail_sbiac_phone, sbiac.owner->phone);
        change_label_text(ui->label_detail_sbiac_email, sbiac.owner->email);

        // Update the photo label
        QPixmap mypix(QString::fromStdString(sbiac.photoPath));
        ui->label_detail_sbiac_photo->setPixmap(mypix);

        // Change the page to the shop booth details page
        change_page("ads", 17);

    } else { //industrial agri commercial
        IndustrialAgriCommercial sbiac = find_industrial_agri_commercial(property.id);

        // Set visibility of UI elements based on ownership
        ui->pushButton_detail_sbiac_chat->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_sbiac_report->setVisible(User::USER.id != property.owner->id);
        ui->pushButton_detail_sbiac_delete->setVisible(User::USER.id == property.owner->id);

        // Update UI labels with industrial agri commercial details
        change_label_text(ui->label_detail_sbiac_title, sbiac.title);
        change_label_text(ui->label_detail_sbiac_land_area, to_string(sbiac.landArea));
        change_label_text(ui->label_detail_sbiac_build_area, to_string(sbiac.builtArea));
        change_label_text(ui->label_detail_sbiac_deed, sbiac.hasDeed ? has : not_have);
        change_label_text(ui->label_detail_sbiac_year, to_string(sbiac.buildYear));
        change_label_text(ui->label_detail_sbiac_room, sbiac.numRooms == 0 ? not_have : to_string(sbiac.numRooms));

        // Update price labels based on the availability of total price
        if (sbiac.totalPrice != "") {
            ui->label_detail_sbiac_deposit->setVisible(false);
            ui->label_detail_sbiac_deposit_text->setVisible(false);
            ui->label_detail_sbiac_monthly_rent->setVisible(false);
            ui->label_detail_sbiac_monthly_rent_text->setVisible(false);
            ui->label_detail_sbiac_total_price->setVisible(true);
            ui->label_detail_sbiac_total_price_text->setVisible(true);
            change_label_text(ui->label_detail_sbiac_total_price, convertNumberToString(sbiac.totalPrice));
        } else {
            ui->label_detail_sbiac_deposit->setVisible(true);
            ui->label_detail_sbiac_deposit_text->setVisible(true);
            ui->label_detail_sbiac_monthly_rent->setVisible(true);
            ui->label_detail_sbiac_monthly_rent_text->setVisible(true);
            ui->label_detail_sbiac_total_price->setVisible(false);
            ui->label_detail_sbiac_total_price_text->setVisible(false);
            change_label_text(ui->label_detail_sbiac_deposit, convertNumberToString(sbiac.deposit));
            change_label_text(ui->label_detail_sbiac_monthly_rent, convertNumberToString(sbiac.monthlyRent));
        }

        // Update address and description labels
        change_label_text(ui->label_detail_sbiac_full_address, address.append(sbiac.full_address));
        change_label_text(ui->label_detail_sbiac_description, description.append(sbiac.description));
        change_label_text(ui->label_detail_sbiac_phone, sbiac.owner->phone);
        change_label_text(ui->label_detail_sbiac_email, sbiac.owner->email);

        // Update the photo label
        QPixmap mypix(QString::fromStdString(sbiac.photoPath));
        ui->label_detail_sbiac_photo->setPixmap(mypix);

        // Change the page to the industrial agri commercial details page
        change_page("ads", 17);
    }
}

// Function to change the color of buttons, except the specified one
void MainWindow::change_button_colors(const string &except)
{
    // Default style for buttons
    QString defaultStyle = "QPushButton { color: white; } QPushButton:hover { color: #50C878; }";
    // Style for the selected button
    QString selectedStyle = "QPushButton { color: #C74375; } QPushButton:hover { color: #50C878; }";

    // Apply default style to all buttons
    ui->pushButton_Ads->setStyleSheet(defaultStyle);
    ui->pushButton_Categories->setStyleSheet(defaultStyle);
    ui->pushButton_Add_Ad->setStyleSheet(defaultStyle);
    ui->pushButton_Chat->setStyleSheet(defaultStyle);
    ui->pushButton_My_Account->setStyleSheet(defaultStyle);

    // Apply selected style to the specified button
    if (except == "ads")
        ui->pushButton_Ads->setStyleSheet(selectedStyle);
    else if (except == "categories")
        ui->pushButton_Categories->setStyleSheet(selectedStyle);
    else if (except == "add_ad")
        ui->pushButton_Add_Ad->setStyleSheet(selectedStyle);
    else if (except == "chat")
        ui->pushButton_Chat->setStyleSheet(selectedStyle);
    else if (except == "account")
        ui->pushButton_My_Account->setStyleSheet(selectedStyle);
}

// Function to change the page and update the active button's color
void MainWindow::change_page(const string active_button, int page_index){
    // Set the current page in the stacked widget
    ui->stackedWidget->setCurrentIndex(page_index);
    // Update button colors based on the active button
    change_button_colors(active_button);
}

// Function to change the text of a label, with an optional stylesheet
void MainWindow::change_label_text(QLabel *label, string text, string stylesheet) { // Pass by reference
    // Apply the provided stylesheet if it's not empty
    if (stylesheet != "")
        label->setStyleSheet(QString::fromStdString(stylesheet));

    // Set the label text
    label->setText(QString::fromStdString(text));
}

// Function to change the text of a line edit (string version)
void MainWindow::change_line_edit_text(QLineEdit *line_edit, string &text){
    // Set the line edit text
    line_edit->setText(QString::fromStdString(text));
}

// Function to change the text of a line edit (QString version)
void MainWindow::change_line_edit_text(QLineEdit *line_edit, QString text){
    // Set the line edit text
    line_edit->setText(text);
}

// Slot function for the "Ads" button click event
void MainWindow::on_pushButton_Ads_clicked()
{
    // Clear the list widget
    empty_list_widget();

    // Show related ads
    for(auto property: Tools::properties) {
        // Determine the price string based on totalPrice or monthlyRent
        strPrice = property.totalPrice != "" ? convertNumberToString(property.totalPrice).append(strToman) : convertNumberToString(property.monthlyRent).append(strMonth);
        strPriceFinal = QString::fromStdString(strPrice);

        // Add item to the list widget with property details
        addItem(property.id, QString::fromStdString(property.photoPath), strPriceFinal,
                QString::fromStdString(property.title), QString::fromStdString(property.full_address));
    }

    change_page("ads", 0);
}

// Slot function for the "Categories" button click event
void MainWindow::on_pushButton_Categories_clicked()
{
    change_page("categories", 1);
}

// Slot function for the "Add Ad" button click event
void MainWindow::on_pushButton_Add_Ad_clicked()
{
    // Check if the user is signed in
    if (!SIGNED_IN) // If not signed in, navigate to the sign-in page (index 11)
        change_page("add_ad", 11);

    else // If signed in, navigate to the add ad page (index 2)
        change_page("add_ad", 2);
}

// Slot function for the "Chat" button click event
void MainWindow::on_pushButton_Chat_clicked()
{
    // Check if the user is signed in
    if (!SIGNED_IN) // If not signed in, navigate to the sign-in page (index 11)
        change_page("chat", 11);

    else // If signed in, navigate to the chat page (index 8)
        change_page("chat", 8);
}

// Slot function for the "My Account" button click event
void MainWindow::on_pushButton_My_Account_clicked()
{
    // Check if the user is signed in
    if (!SIGNED_IN) // If not signed in, navigate to the sign-in page (index 11)
        change_page("account", 11);

     else {
        // Update user information labels
        change_label_text(ui->label_username, User::USER.username);
        change_label_text(ui->label_name, User::USER.name);
        change_label_text(ui->label_fname, User::USER.fname);
        change_label_text(ui->label_email, User::USER.email);
        change_label_text(ui->label_phone, User::USER.phone);
        change_label_text(ui->label_role, User::USER.role);

        change_page("account", 9);
    }
}

// Slot function for the "Go to Sign In" button click event
void MainWindow::on_pushButton_goto_signin_clicked()
{
    change_page("account", 11);
}

// Slot function for the "Go to Sign Up" button click event
void MainWindow::on_pushButton_goto_signup_clicked()
{
    change_page("account", 12);
}

// Handle click event for "Edit My Account" button
void MainWindow::on_pushButton_goto_edit_my_account_clicked()
{
    // Populate fields with current user's information
    change_line_edit_text(ui->lineEdit_edit_my_account_name, User::USER.name);
    change_line_edit_text(ui->lineEdit_edit_my_account_fname, User::USER.fname);
    change_line_edit_text(ui->lineEdit_edit_my_account_password1, User::USER.password);
    change_line_edit_text(ui->lineEdit_edit_my_account_password2, User::USER.password);
    change_line_edit_text(ui->lineEdit_edit_my_account_phone, User::USER.phone);
    change_line_edit_text(ui->lineEdit_edit_my_account_email, User::USER.email);

    // Clear any previous error messages
    change_label_text(ui->label_edit_my_account_error, "", "color:red;");
    change_page("account", 10);
}

// Handle sign-in button click event
void MainWindow::on_pushButton_signin_clicked()
{
    // Retrieve username and password from input fields
    QString username = ui->lineEdit_signin_username->text();
    QString password = ui->lineEdit_signin_password->text();

    // Attempt to sign in user
    int user_index = Tools::user_signin(username.toStdString(), password.toStdString());

     // If sign-in is successful
    if (user_index > -1){
        SIGNED_IN = true;
        User::USER = Tools::users[user_index];
        on_pushButton_Ads_clicked(); // Display ads after successful sign-in

        // Clear input fields and error message
        change_line_edit_text(ui->lineEdit_signin_username, "");
        change_line_edit_text(ui->lineEdit_signin_password, "");
        change_label_text(ui->label_signin_error, "");

    } else // Display sign-in error message
        change_label_text(ui->label_signin_error, User::USER.note, "color:red");
}

// Handle sign-up button click event
void MainWindow::on_pushButton_signup_clicked()
{
    // Retrieve user input from signup fields
    QString username = ui->lineEdit_signup_username->text();
    QString password1 = ui->lineEdit_signup_password1->text();
    QString password2 = ui->lineEdit_signup_password2->text();
    QString name = ui->lineEdit_signup_name->text();
    QString fname = ui->lineEdit_signup_fname->text();
    QString phone = ui->lineEdit_signup_phone->text();
    QString email = ui->lineEdit_signup_email->text();

    // Attempt to sign up user
    User user = Tools::user_signup(username.toStdString(), password1.toStdString(), password2.toStdString(), name.toStdString(), fname.toStdString(), phone.toStdString(), email.toStdString());

    // If sign-up is successful
    if (user.operation_success){
        user.operation_success = false;
        // Switch to My Account page after successful signup
        on_pushButton_My_Account_clicked();

        // Save updated user list
        save_users();

        // Clear input fields and error message
        change_line_edit_text(ui->lineEdit_signup_username, "");
        change_line_edit_text(ui->lineEdit_signup_password1, "");
        change_line_edit_text(ui->lineEdit_signup_password2, "");
        change_line_edit_text(ui->lineEdit_signup_name, "");
        change_line_edit_text(ui->lineEdit_signup_fname, "");
        change_line_edit_text(ui->lineEdit_signup_phone, "");
        change_line_edit_text(ui->lineEdit_signup_email, "");
        change_label_text(ui->label_signup_error, "");

    } else // Display sign-up error message
        change_label_text(ui->label_signup_error, user.note, "color:red");
}

// Handle edit account button click event
void MainWindow::on_pushButton_edit_my_account_clicked()
{
    // Retrieve user input from edit account fields
    QString password1 = ui->lineEdit_edit_my_account_password1->text();
    QString password2 = ui->lineEdit_edit_my_account_password2->text();
    QString name = ui->lineEdit_edit_my_account_name->text();
    QString fname = ui->lineEdit_edit_my_account_fname->text();
    QString phone = ui->lineEdit_edit_my_account_phone->text();
    QString email = ui->lineEdit_edit_my_account_email->text();

    // Find the index of the current user in the user list
    int user_index = find_user_by_id(User::USER.id);

    // Attempt to edit user account information
    Tools::users[user_index].operation_success = false;
    Tools::user_edit(&Tools::users[user_index], password1.toStdString(), password2.toStdString(),
                     name.toStdString(), fname.toStdString(), phone.toStdString(), email.toStdString());

    // If edit operation is successful
    if (Tools::users[user_index].operation_success) // Display success message
        change_label_text(ui->label_edit_my_account_error, Tools::users[user_index].note, "color: green;");

    else // Display error message
        change_label_text(ui->label_edit_my_account_error, Tools::users[user_index].note, "color: red;");

     // Update current user information
    User::USER = Tools::users[user_index];

    // Save updated user list
    save_users();
}

// Handle item selection change in treeWidget (category selection)
void MainWindow::on_treeWidget_itemSelectionChanged()
{
    // Get the selected items
    QList<QTreeWidgetItem*> selectedItems = ui->treeWidget->selectedItems();

    // If an item is selected and it has a parent
    if (!selectedItems.isEmpty() && selectedItems.first()->parent()) {
        // Empty the list widget
        empty_list_widget();

        // Get the selected item and its parent
        QTreeWidgetItem *item = selectedItems.first();
        string item_str = item->text(0).toStdString();
        QTreeWidgetItem *parent = item->parent();
        string parent_str = parent->text(0).toStdString();

        // Extract deal type and category from parent item
        string deal_type = getFirstWord(parent_str);
        parent_str = removeFirstWord(parent_str);

        // Show related ads based on selection
        if (item_str == "همه"){
            for(auto property: Tools::properties)
                for (string sub: subcategories[parent_str])
                    if (sub == property.category && property.dealType == deal_type)
                    {
                        // Determine price display format
                        strPrice = property.totalPrice != "" ? convertNumberToString(property.totalPrice).append(strToman) : convertNumberToString(property.monthlyRent).append(strMonth);
                        strPriceFinal = QString::fromStdString(strPrice);

                        // Add item to list widget
                        addItem(property.id, QString::fromStdString(property.photoPath), strPriceFinal,
                                QString::fromStdString(property.title), QString::fromStdString(property.full_address));
                        break;
                    }
        } else {
            for(auto property: Tools::properties)
                if (item_str == property.category && property.dealType == deal_type)
                {
                    // Determine price display format
                    strPrice = property.totalPrice != "" ? convertNumberToString(property.totalPrice).append(strToman) : convertNumberToString(property.monthlyRent).append(strMonth);
                    strPriceFinal = QString::fromStdString(strPrice);

                    // Add item to list widget
                    addItem(property.id, QString::fromStdString(property.photoPath), strPriceFinal,
                            QString::fromStdString(property.title), QString::fromStdString(property.full_address));
                }
        }

        change_page("ads", 0);
    }
}

// Handle category selection change in comboBox_category
void MainWindow::on_comboBox_category_currentIndexChanged(int index)
{
    // Enable subcategory comboBox and clear previous items
    ui->comboBox_subcategory->setEnabled(true);
    ui->comboBox_subcategory->clear();

    // Populate subcategory comboBox based on selected category
    switch (index) {
        case 0:
            ui->comboBox_subcategory->insertItem(0, QString::fromStdString("آپارتمان"));
            ui->comboBox_subcategory->insertItem(1, QString::fromStdString("خانه و ویلا"));
            ui->comboBox_subcategory->insertItem(2, QString::fromStdString("زمین و کلنگی"));
            break;
        case 1:
            ui->comboBox_subcategory->insertItem(0, QString::fromStdString("دفترکار، اتاق اداری و مطب"));
            ui->comboBox_subcategory->insertItem(1, QString::fromStdString("مغازه و غرفه"));
            ui->comboBox_subcategory->insertItem(2, QString::fromStdString("صنعتی، کشاورزی و تجاری"));
            break;
    }
}

// Handle continue button click in add ad process (first page)
void MainWindow::on_pushButton_goto_continue_add_ad_clicked()
{
    // Check if all required fields are selected
    if (ui->comboBox_category->currentIndex() > -1 && ui->comboBox_subcategory->currentIndex() > -1 && ui->comboBox_deal_type->currentIndex() > -1) {
        // Store selected details in sell_detail_1 map
        sell_detail_1["deal_type"] = ui->comboBox_deal_type->currentIndex();
        sell_detail_1["category"] = ui->comboBox_category->currentIndex();
        sell_detail_1["subcategory"] = ui->comboBox_subcategory->currentIndex();

        // Clear error message
        change_label_text(ui->label_add_ad_error, "");

        // Show/hide price input fields based on deal type selection
        if (sell_detail_1["deal_type"] == 1){
            ui->lineEdit_sell_total_price->setVisible(false);
            ui->lineEdit_sell_deposit->setVisible(true);
            ui->lineEdit_sell_monthly_rent->setVisible(true);
        } else {
            ui->lineEdit_sell_total_price->setVisible(true);
            ui->lineEdit_sell_deposit->setVisible(false);
            ui->lineEdit_sell_monthly_rent->setVisible(false);
        }

        change_page("add_ad", 3);

    } else // Display error message if not all fields are selected
        change_label_text(ui->label_add_ad_error, "لطفا تمامی موارد خواسته شده را انتخاب کنید.");
}

// Handle continue button click in add ad process (second page)
void MainWindow::on_pushButton_goto_continue_add_ad_2_clicked()
{
    // Retrieve user inputs from second page of add ad process
    string title = ui->lineEdit_sell_title->text().toStdString();
    int land_area = ui->spinBox_sell_land_area->value();
    int build_area = ui->spinBox_sell_build_area->value();
    string deposit = ui->lineEdit_sell_deposit->text().toStdString();
    string monthly_rent = ui->lineEdit_sell_monthly_rent->text().toStdString();
    string total_price = ui->lineEdit_sell_total_price->text().toStdString();
    string full_address = ui->lineEdit_sell_full_address->text().toStdString();
    string photo_path = ui->lineEdit_sell_photo_path->text().toStdString();
    string description = ui->lineEdit_sell_description->text().toStdString();
    int has_deed = ui->comboBox_sell_has_deed->currentIndex();

    // Validate input based on deal type selection
    if (sell_detail_1["deal_type"] == 1){
        if (deposit == "" or monthly_rent == ""){
            change_label_text(ui->label_add_ad_error_2, "لطفا همه موارد خواسته شده را تکمیل کنید.");
            return;
        }
        if (!is_digits(deposit) or !is_digits(monthly_rent)){
            change_label_text(ui->label_add_ad_error_2, "اعداد وارد شده صحیح نمیباشند.");
            return;
        }
    } else {
        if (total_price == ""){
            change_label_text(ui->label_add_ad_error_2, "لطفا همه موارد خواسته شده را تکمیل کنید.");
            return;
        }
        if (!is_digits(total_price)){
            change_label_text(ui->label_add_ad_error_2, "اعداد وارد شده صحیح نمیباشند.");
            return;
        }
    }
    if (title == "" or full_address == ""){
        change_label_text(ui->label_add_ad_error_2, "لطفا همه موارد خواسته شده را تکمیل کنید.");
        return;
    }

    // Store details in sell_detail_1 and sell_detail_2 maps
    sell_detail_1["has_deed"] = has_deed;
    sell_detail_1["build_area"] = build_area;
    sell_detail_1["land_area"] = land_area;

    sell_detail_2["deposit"] = deposit;
    sell_detail_2["monthly_rent"] = monthly_rent;
    sell_detail_2["total_price"] = total_price;
    sell_detail_2["title"] = title;
    sell_detail_2["full_address"] = full_address;
    sell_detail_2["photo_path"] = photo_path != "" ? photo_path : "default.jpg";
    sell_detail_2["description"] = description;

    // Navigate to appropriate page based on category and subcategory selection
    if (sell_detail_1["category"] == 0) {
        if (sell_detail_1["subcategory"] == 0)
            change_page("add_ad", 4); // Page for adding apartment

        else if (sell_detail_1["subcategory"] == 1)
            change_page("add_ad", 5); // Page for adding house/villa

        else { // Create and add LandOldProperty object to properties list
            LandOldProperty lop = LandOldProperty(&User::USER, sell_detail_2["title"], sell_detail_2["total_price"], sell_detail_2["deposit"], sell_detail_2["monthly_rent"], sell_detail_2["photo_path"],
                    subcategories[categories[0]][2], deals[sell_detail_1["deal_type"]], sell_detail_2["full_address"],
                    sell_detail_1["has_deed"], sell_detail_1["land_area"], sell_detail_1["build_area"], sell_detail_2["description"]);

            lands_old_properties.push_back(lop);
            Tools::properties.push_back(lop);

            change_page("add_ad", 18); // Confirmation page for land/old property
        }

    } else {
        if (sell_detail_1["subcategory"] == 0)
            change_page("add_ad", 6); // Page for adding office/admin/clinic

        else if (sell_detail_1["subcategory"] == 1)
            change_page("add_ad", 7); // Page for adding shop/booth/industrial/agri/commercial

        else
            change_page("add_ad", 7); // Page for adding shop/booth/industrial/agri/commercial
    }
}

// Register apartment button clicked handler
void MainWindow::on_pushButton_apartment_register_clicked()
{
    // Retrieve checkbox and spinbox values
    bool elevator = ui->checkBox_apartment_elevator->isChecked();
    bool parking = ui->checkBox_apartment_parking->isChecked();
    bool storage = ui->checkBox_apartment_storage->isChecked();
    bool balcony = ui->checkBox_apartment_balcony->isChecked();
    bool heating = ui->checkBox_apartment_heating->isChecked();
    bool cooling = ui->checkBox_apartment_cooling->isChecked();
    bool bathroom = ui->checkBox_apartment_bathroom->isChecked();
    bool renovated = ui->checkBox_apartment_renovated->isChecked();
    int room = ui->spinBox_apartment_room->value();
    int year = ui->spinBox_apartment_year->value();
    int floor = ui->spinBox_apartment_floor->value();

    // Create Apartment object and add to respective lists
    Apartment apartment = Apartment(&User::USER, sell_detail_2["title"], sell_detail_2["total_price"], sell_detail_2["deposit"],
                                    sell_detail_2["monthly_rent"], sell_detail_2["photo_path"],
            subcategories[categories[0]][0], deals[sell_detail_1["deal_type"]], sell_detail_2["full_address"],
            sell_detail_1["has_deed"], sell_detail_1["land_area"], sell_detail_1["build_area"], sell_detail_2["description"],
            year, room, floor, elevator, parking, storage,
            renovated, balcony, bathroom, cooling, heating);

    apartments.push_back(apartment);
    Tools::properties.push_back(apartment);

    // Navigate to confirmation page
    change_page("add_ad", 18);
}

// Register house/villa button clicked handler
void MainWindow::on_pushButton_hv_register_clicked()
{
    // Retrieve checkbox and spinbox values
    bool parking = ui->checkBox_hv_parking->isChecked();
    bool storage = ui->checkBox_hv_storage->isChecked();
    bool balcony = ui->checkBox_hv_balcony->isChecked();
    bool heating = ui->checkBox_hv_heating->isChecked();
    bool cooling = ui->checkBox_hv_cooling->isChecked();
    bool bathroom = ui->checkBox_hv_bathroom->isChecked();
    bool renovated = ui->checkBox_hv_renovated->isChecked();
    int room = ui->spinBox_hv_room->value();
    int year = ui->spinBox_hv_year->value();

    // Create HouseVilla object and add to respective lists
    HouseVilla hv = HouseVilla(&User::USER, sell_detail_2["title"], sell_detail_2["total_price"], sell_detail_2["deposit"],
                               sell_detail_2["monthly_rent"], sell_detail_2["photo_path"],
            subcategories[categories[0]][1], deals[sell_detail_1["deal_type"]], sell_detail_2["full_address"],
            sell_detail_1["has_deed"], sell_detail_1["land_area"], sell_detail_1["build_area"], sell_detail_2["description"],
            year, room, parking, storage,
            renovated, balcony, bathroom, cooling, heating);

    houses_villas.push_back(hv);
    Tools::properties.push_back(hv);

    // Navigate to confirmation page
    change_page("add_ad", 18);
}

// Register office/admin/clinic button clicked handler
void MainWindow::on_pushButton_oac_register_clicked()
{
    // Retrieve checkbox and spinbox values
    bool elevator = ui->checkBox_oac_elevator->isChecked();
    bool parking = ui->checkBox_oac_parking->isChecked();
    bool storage = ui->checkBox_oac_storage->isChecked();
    int room = ui->spinBox_oac_room->value();
    int year = ui->spinBox_oac_year->value();
    int floor = ui->spinBox_oac_floor->value();
    int has_deed = ui->comboBox_sell_has_deed->currentIndex();

    // Create OfficeAdminClinic object and add to respective lists
    OfficeAdminClinic oac = OfficeAdminClinic(&User::USER, sell_detail_2["title"], sell_detail_2["total_price"], sell_detail_2["deposit"],
                                              sell_detail_2["monthly_rent"], sell_detail_2["photo_path"],
            subcategories[categories[1]][0], deals[sell_detail_1["deal_type"]], sell_detail_2["full_address"],
            sell_detail_1["has_deed"], sell_detail_1["land_area"], sell_detail_1["build_area"], sell_detail_2["description"],
            year, room, floor, elevator, parking, storage, has_deed);

    offices_admins_clinics.push_back(oac);
    Tools::properties.push_back(oac);

    // Navigate to confirmation page
    change_page("add_ad", 18);
}

// Register shop/booth/industrial/agri/commercial button clicked handler
void MainWindow::on_pushButton_sbiac_register_clicked()
{
    // Retrieve spinbox values
    int room = ui->spinBox_sbiac_room->value();
    int year = ui->spinBox_sbiac_year->value();
    int has_deed = ui->comboBox_sbiac_deed->currentIndex();

    // Check subcategory type and create appropriate object
    if (sell_detail_1["subcategory"] == 1){ // Shop Booth
        ShopBooth sbiac = ShopBooth(&User::USER, sell_detail_2["title"], sell_detail_2["total_price"], sell_detail_2["deposit"],
                                    sell_detail_2["monthly_rent"], sell_detail_2["photo_path"],
                subcategories[categories[1]][1], deals[sell_detail_1["deal_type"]], sell_detail_2["full_address"],
                sell_detail_1["has_deed"], sell_detail_1["land_area"], sell_detail_1["build_area"], sell_detail_2["description"],
                year, room, has_deed);

        shops_boothes.push_back(sbiac);
        Tools::properties.push_back(sbiac);

    } else { // IndustrialAgriCommercial
        IndustrialAgriCommercial sbiac = IndustrialAgriCommercial(&User::USER, sell_detail_2["title"], sell_detail_2["total_price"],
                                                                  sell_detail_2["deposit"], sell_detail_2["monthly_rent"], sell_detail_2["photo_path"],
                subcategories[categories[1]][2], deals[sell_detail_1["deal_type"]], sell_detail_2["full_address"],
                sell_detail_1["has_deed"], sell_detail_1["land_area"], sell_detail_1["build_area"], sell_detail_2["description"],
                year, room, has_deed);

         industrials_agris_commercials.push_back(sbiac);
         Tools::properties.push_back(sbiac);
    }

    change_page("add_ad", 18);
}

// Search text changed handler
void MainWindow::on_lineEdit_search_textChanged(const QString &arg1)
{
    // Convert QString to std::string
    string query = arg1.toStdString();

    // Clear the list widget
    empty_list_widget();

    // Iterate through properties and filter based on query
    for(auto property: Tools::properties) {
        if (property.category.find(query) != string::npos or
                property.title.find(query) != string::npos or
                property.dealType.find(query) != string::npos or
                property.full_address.find(query) != string::npos) {

            // Format price based on type
            strPrice = property.totalPrice != "" ? convertNumberToString(property.totalPrice).append(strToman) : convertNumberToString(property.monthlyRent).append(strMonth);
            strPriceFinal = QString::fromStdString(strPrice);

            // Add item to list widget
            addItem(property.id, QString::fromStdString(property.photoPath), strPriceFinal,
                    QString::fromStdString(property.title), QString::fromStdString(property.full_address));
        }
    }
}

// My ads button clicked handler
void MainWindow::on_pushButton_my_ads_clicked()
{
    // Clear the list widget
    empty_list_widget();

    // Iterate through properties and show only user's ads
    for(auto property: Tools::properties) {
        if (property.owner->id == User::USER.id) {
            // Format price based on type
            strPrice = property.totalPrice != "" ? convertNumberToString(property.totalPrice).append(strToman) : convertNumberToString(property.monthlyRent).append(strMonth);
            strPriceFinal = QString::fromStdString(strPrice);

            // Add item to list widget
            addItem(property.id, QString::fromStdString(property.photoPath), strPriceFinal,
                    QString::fromStdString(property.title), QString::fromStdString(property.full_address));
        }
    }

    change_page("ads", 0);
}

// Logout button clicked handler
void MainWindow::on_pushButton_logout_clicked()
{
     // Perform logout actions
    SIGNED_IN = false;
    User::USER = User();

    change_page("ads", 0);
}

// Add image button clicked handler
void MainWindow::on_pushButton_add_image_clicked()
{
    // Open file dialog to select image file
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.jpg)"));

    // Update sell photo path line edit with selected filename
    change_line_edit_text(ui->lineEdit_sell_photo_path, filename);
}

// Delete apartment button clicked handler
void MainWindow::on_pushButton_detail_apartment_delete_clicked()
{
    // Get the title of the selected apartment
    string title = ui->label_detail_apartment_title->text().toStdString();

    // Remove property from Tools::properties and apartments vectors
    for(unsigned int i = 0; i < Tools::properties.size(); i++)
        if(Tools::properties[i].owner->id == User::USER.id && Tools::properties[i].title == title){
            Tools::properties.erase(Tools::properties.begin()+i);
            break;
        }

    for(unsigned int i = 0; i < apartments.size(); i++)
        if(apartments[i].owner->id == User::USER.id && apartments[i].title == title){
            apartments.erase(apartments.begin()+i);
            break;
        }

    // Refresh the ads page
    on_pushButton_Ads_clicked();
}

// Delete house/villa button clicked handler
void MainWindow::on_pushButton_detail_hv_delete_clicked()
{
    // Get the title of the selected house/villa
    string title = ui->label_detail_hv_title->text().toStdString();

    // Remove property from Tools::properties and houses_villas vectors
    for(unsigned int i = 0; i < Tools::properties.size(); i++)
        if(Tools::properties[i].owner->id == User::USER.id && Tools::properties[i].title == title){
            Tools::properties.erase(Tools::properties.begin()+i);
            break;
        }

    for(unsigned int i = 0; i < houses_villas.size(); i++)
        if(houses_villas[i].owner->id == User::USER.id && houses_villas[i].title == title){
            houses_villas.erase(houses_villas.begin()+i);
            break;
        }

    // Refresh the ads page
    on_pushButton_Ads_clicked();
}

// Delete land/old property button clicked handler
void MainWindow::on_pushButton_detail_lop_delete_clicked()
{
    // Get the title of the selected land/old property
    string title = ui->label_detail_lop_title->text().toStdString();

    // Remove property from Tools::properties and lands_old_properties vectors
    for(unsigned int i = 0; i < Tools::properties.size(); i++)
        if(Tools::properties[i].owner->id == User::USER.id && Tools::properties[i].title == title){
            Tools::properties.erase(Tools::properties.begin()+i);
            break;
        }

    for(unsigned int i = 0; i < lands_old_properties.size(); i++)
        if(lands_old_properties[i].owner->id == User::USER.id && lands_old_properties[i].title == title){
            lands_old_properties.erase(lands_old_properties.begin()+i);
            break;
        }

    // Refresh the ads page
    on_pushButton_Ads_clicked();
}

// Delete office/admin/clinic button clicked handler
void MainWindow::on_pushButton_detail_oac_delete_clicked()
{
    // Get the title of the selected office/admin/clinic
    string title = ui->label_detail_oac_title->text().toStdString();

    // Remove property from Tools::properties and offices_admins_clinics vectors
    for(unsigned int i = 0; i < Tools::properties.size(); i++)
        if(Tools::properties[i].owner->id == User::USER.id && Tools::properties[i].title == title){
            Tools::properties.erase(Tools::properties.begin()+i);
            break;
        }

    for(unsigned int i = 0; i < offices_admins_clinics.size(); i++)
        if(offices_admins_clinics[i].owner->id == User::USER.id && offices_admins_clinics[i].title == title){
            offices_admins_clinics.erase(offices_admins_clinics.begin()+i);
            break;
        }

    // Refresh the ads page
    on_pushButton_Ads_clicked();
}

// Delete shop/booth/industrial/agri/commercial button clicked handler
void MainWindow::on_pushButton_detail_sbiac_delete_clicked()
{
    // Get the title of the selected shop/booth/industrial/agri/commercial property
    string title = ui->label_detail_sbiac_title->text().toStdString();

    // Remove property from Tools::properties, shops_boothes, and industrials_agris_commercials vectors
    for(unsigned int i = 0; i < Tools::properties.size(); i++)
        if(Tools::properties[i].owner->id == User::USER.id && Tools::properties[i].title == title){
            Tools::properties.erase(Tools::properties.begin()+i);
            break;
        }

    for(unsigned int i = 0; i < shops_boothes.size(); i++)
        if(shops_boothes[i].owner->id == User::USER.id && shops_boothes[i].title == title){
            shops_boothes.erase(shops_boothes.begin()+i);
            break;
        }

    for(unsigned int i = 0; i < industrials_agris_commercials.size(); i++)
        if(industrials_agris_commercials[i].owner->id == User::USER.id && industrials_agris_commercials[i].title == title){
            industrials_agris_commercials.erase(industrials_agris_commercials.begin()+i);
            break;
        }

    // Refresh the ads page
    on_pushButton_Ads_clicked();
}
