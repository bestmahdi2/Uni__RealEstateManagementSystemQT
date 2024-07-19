#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ad.h"
#include "login.h"
#include "register.h"
#include "errorbox.h"
#include "successbox.h"
#include "itemwidget.h"

#include <QPixmap>
#include <QtWidgets>
#include <QFileDialog>
#include <QHeaderView>
#include <QApplication>
#include <locale>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

// Global variables
vector<Ad> Ad::ads;
User MainWindow::THIS_USER;
string MainWindow::state = "login";

// Function declarations
void save_users();
void load_users();
string remove_first_word(const string& str);
string get_first_word(const string& str);
bool is_number(const string& s);
void create_some_default_ads();

// Custom ItemDelegate for painting items in QListWidget
class ItemDelegate : public QStyledItemDelegate {
public:
    ItemDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyledItemDelegate::paint(painter, option, index);

        if (index.row() < index.model()->rowCount() - 1) {
            painter->setPen(QPen(Qt::gray, 1));
            painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
        }
    }
};

// Constructor for MainWindow
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), loginWindow(new LoginBox(this)), registerWindow(new RegisterBox(this)) {
    ui->setupUi(this);

    // Set window icon
    setWindowIcon(QIcon(":/icon.png"));

    // Setup item delegates for QListWidget
    ItemDelegate *delegate1 = new ItemDelegate(this);
    ItemDelegate *delegate2 = new ItemDelegate(this);
    ui->listWidget_all->setItemDelegate(delegate1);
    ui->listWidget_search->setItemDelegate(delegate2);

    // Connect itemClicked signals to slots
    connect(ui->listWidget_all, &QListWidget::itemClicked, this, &MainWindow::item_click_all);
    connect(ui->listWidget_search, &QListWidget::itemClicked, this, &MainWindow::item_click_search);

    // Load users from file
    load_users();

    create_some_default_ads();

    // Connect signals and slots for login and registration windows
    connect(loginWindow, &LoginBox::loginClosed, this, &MainWindow::handleLoginClose);
    connect(registerWindow, &RegisterBox::registerClosed, this, &MainWindow::handleRegisterClose);
    connect(loginWindow, &LoginBox::showRegister, this, &MainWindow::showRegisterWindow);
    connect(registerWindow, &RegisterBox::showLogin, this, &MainWindow::showLoginWindow);
    connect(loginWindow, &LoginBox::loginSuccessful, this, &MainWindow::handleLoginSuccessful);

    // Show the login window by default
    showLoginWindow();
}

// Destructor for MainWindow
MainWindow::~MainWindow() {
    delete ui;
    delete loginWindow;
    delete registerWindow;
}

void MainWindow::handleLoginClose(bool success) {
    if (success) {
        // Handle login success
        MainWindow::THIS_USER = User::logged;
        this->show();
        on_pushButton_page_create_ad_clicked();
        save_users();  // Save user data after successful login
    } else {
        // Handle login failure
        // QMessageBox::critical(this, "Login Failed", "Invalid username or password");
    }
}

void MainWindow::handleRegisterClose(bool allowClose) {
    if (!allowClose) {
        // Handle the case where closing is not allowed
        // QMessageBox::information(this, "Registration Incomplete", "Please complete all fields");
    }
}

void MainWindow::showRegisterWindow() {
    loginWindow->hide();  // Hide the login window if it's open
    QEventLoop loop;
    connect(registerWindow, &QDialog::finished, &loop, &QEventLoop::quit);
    registerWindow->setModal(true);
    registerWindow->show();
    loop.exec();
}

void MainWindow::showLoginWindow() {
    registerWindow->hide();  // Hide the register window if it's open
    QEventLoop loop;
    connect(loginWindow, &QDialog::finished, &loop, &QEventLoop::quit);
    loginWindow->setModal(true);
    loginWindow->show();
    loop.exec();
}

void MainWindow::handleLoginSuccessful() {
    this->show(); // Show the main window upon successful login
    on_pushButton_page_create_ad_clicked();
}

void MainWindow::item_click_all(QListWidgetItem *item){
    // Retrieve the ID from the item
    int id = item->data(Qt::UserRole).toInt();

    // Show detailed page for the selected advertisement
    show_page_detail_ad(id);
}

void MainWindow::item_click_search(QListWidgetItem *item){
    // Retrieve the ID from the item
    int id = item->data(Qt::UserRole).toInt();

    // Show detailed page for the selected advertisement
    show_page_detail_ad(id);
}

void MainWindow::create_item(const int id, const QString &name, const QString &address, const QString &type, const QString &image, QListWidget *list) {
    // Create a new item for the list widget
    QListWidgetItem *item = new QListWidgetItem(list);

    // Create a custom widget for displaying item details
    ItemWidget *widget = new ItemWidget(id, image, type, name, address);

    // Set the size hint for the list widget item
    item->setSizeHint(widget->sizeHint());

    // Set custom data (ID) to the list widget item
    item->setData(Qt::UserRole, id);

    // Add the item and its widget to the list widget
    list->addItem(item);
    list->setItemWidget(item, widget);
}

void MainWindow::update_item_list(string category) {
    // Clear all items from the list widget
    while(ui->listWidget_all->count() > 0)
        ui->listWidget_all->takeItem(0);

    // Populate the list widget based on the selected category or all ads if no category specified
    if (category.empty()) {
        for(auto ad: Ad::ads)
            create_item(ad.getId(), QString::fromStdString(ad.getProperty().getName()), QString::fromStdString(ad.getProperty().getAddress()),
                        QString::fromStdString(ad.getProperty().getType()), QString::fromStdString(ad.getProperty().getPic()), ui->listWidget_all);

    } else {
        for(auto ad: Ad::ads)
            if (ad.getProperty().getCategory() == category)
                create_item(ad.getId(), QString::fromStdString(ad.getProperty().getName()), QString::fromStdString(ad.getProperty().getAddress()),
                            QString::fromStdString(ad.getProperty().getType()), QString::fromStdString(ad.getProperty().getPic()), ui->listWidget_all);
    }
}

void MainWindow::update_table() {
    // Clear all rows from the table widget
    ui->tableWidget->setRowCount(0);

    // Ensure the horizontal header is shown
    ui->tableWidget->horizontalHeader()->show();

    // Populate the table with ads owned by the current user
    size_t x = 0;
    int y = 0;
    while (x < Ad::ads.size()) {
        if (Ad::ads[x].getOwner()->getUsername() == THIS_USER.getUsername()){
            // Insert a new row at position y
            ui->tableWidget->insertRow(y);

            // Populate table cells with advertisement details
            ui->tableWidget->setItem(y, 0, new QTableWidgetItem(tr(to_string(Ad::ads[x].getId()).c_str())));
            ui->tableWidget->setItem(y, 1, new QTableWidgetItem(tr(Ad::ads[x].getProperty().getName().c_str())));
            ui->tableWidget->setItem(y, 2, new QTableWidgetItem(tr(Ad::ads[x].getProperty().getType().c_str())));
            ui->tableWidget->setItem(y, 3, new QTableWidgetItem(tr(Ad::ads[x].getProperty().getPropertyType().c_str())));
            ui->tableWidget->setItem(y, 4, new QTableWidgetItem(tr(Ad::ads[x].getProperty().getAddress().c_str())));
            ui->tableWidget->setItem(y, 5, new QTableWidgetItem(tr(Ad::ads[x].getProperty().getPrice().c_str())));
            y++;
        }
        x++;
    }
}

void MainWindow::clear_create_page(){
    // Clear all text fields on the create page
    ui->lineEdit_ad_name->setText("");
    ui->lineEdit_address->setText("");
    ui->lineEdit_land->setText("");
    ui->lineEdit_building->setText("");
    ui->lineEdit_deposit->setText("");
    ui->lineEdit_rent->setText("");
    ui->lineEdit_price->setText("");
    ui->lineEdit_description->setText("");
    ui->lineEdit_deposit->setEnabled(false);
    ui->lineEdit_rent->setEnabled(false);
    ui->lineEdit_price->setEnabled(false);

    // Clear labels and paths
    ui->label_pic->setText("");
    ui->label_ad_id_hidden->setText("");
    ui->label_pic_path->setText("");

    // Reset radio button groups and disable options
    QButtonGroup* group1 = new QButtonGroup(this);
    group1->addButton(ui->radioButton_type_sell);
    group1->addButton(ui->radioButton_type_exchange);
    group1->addButton(ui->radioButton_type_rent);
    QAbstractButton* checked1 = group1->checkedButton();
    if (checked1) {
        group1->setExclusive(false);
        checked1->setChecked(false);
        group1->setExclusive(true);
    }

    QButtonGroup* group2 = new QButtonGroup(this);
    group2->addButton(ui->radioButton_category_non_residential);
    group2->addButton(ui->radioButton_category_residential);
    group2->addButton(ui->radioButton_category_office);
    group2->addButton(ui->radioButton_category_commercial);
    QAbstractButton* checked2 = group2->checkedButton();
    if (checked2) {
        group2->setExclusive(false);
        checked2->setChecked(false);
        group2->setExclusive(true);
    }

    QButtonGroup* group3 = new QButtonGroup(this);
    group3->addButton(ui->radioButton_type_land);
    group3->addButton(ui->radioButton_type_kolangi);
    group3->addButton(ui->radioButton_type_garden);
    group3->addButton(ui->radioButton_type_apartment);
    group3->addButton(ui->radioButton_type_villa);
    group3->addButton(ui->radioButton_type_office);
    group3->addButton(ui->radioButton_type_clinic);
    group3->addButton(ui->radioButton_type_shop);
    group3->addButton(ui->radioButton_type_storage);
    group3->addButton(ui->radioButton_type_workshop);
    QAbstractButton* checked3 = group3->checkedButton();
    if (checked3) {
        group3->setExclusive(false);
        checked3->setChecked(false);
        group3->setExclusive(true);
    }

    // Clear and disable radio buttons and checkboxes
    ui->radioButton_type_sell->setChecked(false);
    ui->radioButton_type_exchange->setChecked(false);
    ui->radioButton_type_rent->setChecked(false);
    ui->radioButton_category_non_residential->setChecked(false);
    ui->radioButton_category_residential->setChecked(false);
    ui->radioButton_category_office->setChecked(false);
    ui->radioButton_category_commercial->setChecked(false);
    ui->radioButton_category_non_residential->setEnabled(true);
    ui->radioButton_category_residential->setEnabled(true);
    ui->radioButton_category_office->setEnabled(true);
    ui->radioButton_category_commercial->setEnabled(true);

    ui->radioButton_type_land->setChecked(false);
    ui->radioButton_type_kolangi->setChecked(false);
    ui->radioButton_type_garden->setChecked(false);
    ui->radioButton_type_apartment->setChecked(false);
    ui->radioButton_type_villa->setChecked(false);
    ui->radioButton_type_office->setChecked(false);
    ui->radioButton_type_clinic->setChecked(false);
    ui->radioButton_type_shop->setChecked(false);
    ui->radioButton_type_storage->setChecked(false);
    ui->radioButton_type_workshop->setChecked(false);
    ui->radioButton_type_land->setEnabled(false);
    ui->radioButton_type_kolangi->setEnabled(false);
    ui->radioButton_type_garden->setEnabled(false);
    ui->radioButton_type_apartment->setEnabled(false);
    ui->radioButton_type_villa->setEnabled(false);
    ui->radioButton_type_office->setEnabled(false);
    ui->radioButton_type_clinic->setEnabled(false);
    ui->radioButton_type_shop->setEnabled(false);
    ui->radioButton_type_storage->setEnabled(false);
    ui->radioButton_type_workshop->setEnabled(false);

    ui->checkBox_deed->setChecked(false);
    ui->checkBox_furnished->setChecked(false);
    ui->checkBox_renew->setChecked(false);
    ui->checkBox_parking->setChecked(false);
    ui->checkBox_elevator->setChecked(false);
    ui->checkBox_storage->setChecked(false);
    ui->checkBox_balcony->setChecked(false);
    ui->checkBox_wallpaper->setChecked(false);
    ui->checkBox_deed->setEnabled(false);
    ui->checkBox_furnished->setEnabled(false);
    ui->checkBox_renew->setEnabled(false);
    ui->checkBox_parking->setEnabled(false);
    ui->checkBox_elevator->setEnabled(false);
    ui->checkBox_storage->setEnabled(false);
    ui->checkBox_balcony->setEnabled(false);
    ui->checkBox_wallpaper->setEnabled(false);

    // Reset and disable combo box selections
    ui->comboBox_build->setCurrentIndex(53);
    ui->comboBox_floor->setCurrentIndex(1);
    ui->comboBox_room->setCurrentIndex(0);
    ui->comboBox_build->setEnabled(false);
    ui->comboBox_floor->setEnabled(false);
    ui->comboBox_room->setEnabled(false);
}

void MainWindow::on_pushButton_page_create_ad_clicked() {
    // Clear all fields on the create page
    clear_create_page();

    // Set visibility of buttons for creating and editing ads
    ui->pushButton_edit_ad->setVisible(false);
    ui->pushButton_create_ad->setVisible(true);

    // Set the current page of the stacked widget to the create ad page (index 0)
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_page_show_my_ads_clicked() {
    // Set the current page of the stacked widget to show my ads (index 1)
    ui->stackedWidget->setCurrentIndex(1);

    // Update the table with ads owned by the current user
    update_table();
}

void MainWindow::on_pushButton_page_show_all_ads_clicked() {
    // Update the list widget to show all ads (empty category parameter)
    update_item_list("");

    // Set the current page of the stacked widget to show all ads (index 2)
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_page_search_ads_clicked() {
    // Set the current page of the stacked widget to the search ads page (index 4)
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::show_page_detail_ad(int ad_id) {
    // Initialize variables
    bool mine = false;
    size_t x = 0;

    // Search for the ad with the given id in the Ad::ads list
    while (x < Ad::ads.size()) {
        if (Ad::ads[x].getId() == ad_id) {
            // Check if the ad belongs to the current user
            if (Ad::ads[x].getOwner()->getUsername() == THIS_USER.getUsername())
                mine = true;
            break;
        }
        x++;
    }

    // Retrieve ad details
    int id = Ad::ads[x].getId();
    Property property = Ad::ads[x].getProperty();
    User *owner = Ad::ads[x].getOwner();

    // Set UI elements with ad details
    ui->label_ad_name->setText(QString::fromStdString(property.getName()));
    ui->label_mine->setText(mine ? "✅" : "❌");
    ui->label_mine->setToolTip(mine ? "این آگهی شماست" : "این آگهی شما نیست");
    ui->label_ad_owner->setText(QString::fromStdString(owner->getDetails()));
    ui->label_ad_id->setText(QString::fromStdString(to_string(id)));
    ui->label_ad_type->setText(QString::fromStdString(property.getType()));
    ui->label_ad_category->setText(QString::fromStdString(property.getCategory()));
    ui->label_ad_property_type->setText(QString::fromStdString(property.getPropertyType()));
    ui->label_ad_address->setText(QString::fromStdString(property.getAddress()));

    // Set price information based on property type
    if (!property.getPrice().empty()) {
        double price = property.getPrice() != "" ? std::stod(property.getPrice()) : 0;
        double land = property.getLand() != "" ? std::stod(property.getLand()) : 0;
        double build = property.getBuilding() != "" ? std::stod(property.getBuilding()) : 0;

        double price_per_meter = price / (land + build);
        ui->label_ad_price->setText(QString::fromStdString(property.getPrice()));
        ui->label_ad_price_per_meter->setText(QString::fromStdString(to_string((int) price_per_meter)));
    }
    else {
        // Combine deposit and rent for properties without a fixed price
        string deposit = "ودیعه: ";
        string rent = " اجاره: ";
        deposit.append(property.getDeposit());
        rent.append(property.getRent());
        ui->label_ad_price->setText(QString::fromStdString(deposit.append(rent)));
    }

    // Set property image
    QPixmap pixmap(QString::fromStdString(property.getPic()));
    ui->label_ad_pic->setPixmap(pixmap);

    // Set detailed information based on property type
    string details;
    if (property.getHasDeed())
        details.append("سند - ");

    string str1 = "زمین: ";
    string str2 = "ساختمان: ";
    size_t y;
    if (property.getPropertyType() == "زمین") {
        ui->label_ad_detail->setText(QString::fromStdString(details));

        ui->label_ad_build->setText("");
        ui->label_ad_floor->setText("");
        ui->label_ad_room->setText("");
        ui->label_ad_meter->setText(QString::fromStdString(str1.append(property.getLand())));

    } else if (property.getPropertyType() == "کلنگی") {
        // Search for the corresponding Kolangi property
        y = 0;
        while (y < Ad::kolangies.size()) {
            if (Ad::kolangies[y].getName() == property.getName() && Ad::kolangies[y].getAddress() == property.getAddress() && Ad::kolangies[y].getType() == property.getType() && Ad::kolangies[y].getPropertyType() == property.getPropertyType() && Ad::kolangies[y].getCategory() == property.getCategory()){
                break;
            }
            y++;
        }

        Kolangi kolangi = Ad::kolangies[y];

        if (kolangi.getHasStorage())
            details.append("انباری - ");
        ui->label_ad_detail->setText(QString::fromStdString(details));

        ui->label_ad_build->setText("");
        ui->label_ad_floor->setText("");
        ui->label_ad_room->setText(QString::fromStdString(kolangi.getRooms()));
        ui->label_ad_meter->setText(QString::fromStdString(str1.append(property.getLand()).append(" - ").append(str2).append(property.getBuilding())));

    } else if (property.getPropertyType() == "باغ") {
        // Search for the corresponding Garden property
        y = 0;
        while (y < Ad::gardens.size()) {
            if (Ad::gardens[y].getName() == property.getName() && Ad::gardens[y].getAddress() == property.getAddress() && Ad::gardens[y].getType() == property.getType() && Ad::gardens[y].getPropertyType() == property.getPropertyType() && Ad::gardens[y].getCategory() == property.getCategory()){
                break;
            }
            y++;
        }
        Garden garden = Ad::gardens[y];

        if (garden.getIsRenew())
            details.append("نوساز - ");
        if (garden.getHasStorage())
            details.append("انباری - ");
        ui->label_ad_detail->setText(QString::fromStdString(details));

        ui->label_ad_build->setText(QString::fromStdString(garden.getBuild()));
        ui->label_ad_floor->setText("");
        ui->label_ad_room->setText(QString::fromStdString(garden.getRooms()));
        ui->label_ad_meter->setText(QString::fromStdString(str1.append(property.getLand()).append(" - ").append(str2).append(property.getBuilding())));

    } else if (property.getPropertyType() == "آپارتمان") {
         // Search for the corresponding Apartment property
        y = 0;
        while (y < Ad::apartments.size()) {
            if (Ad::apartments[y].getName() == property.getName() && Ad::apartments[y].getAddress() == property.getAddress() && Ad::apartments[y].getType() == property.getType() && Ad::apartments[y].getPropertyType() == property.getPropertyType() && Ad::apartments[y].getCategory() == property.getCategory()){
                break;
            }
            y++;
        }

        Apartment apartment = Ad::apartments[y];

        if (apartment.getIsFurnished())
            details.append("مبله - ");
        if (apartment.getIsRenew())
            details.append("نوساز - ");
        if (apartment.getHasParking())
            details.append("پارکینگ - ");
        if (apartment.getHasElevator())
            details.append("آسانسور - ");
        if (apartment.getHasStorage())
            details.append("انباری - ");
        if (apartment.getHasBalcony())
            details.append("بالکن/تراس - ");
        if (apartment.getHasWallpaper())
            details.append("کاغذ دیواری - ");

        ui->label_ad_detail->setText(QString::fromStdString(details));

        ui->label_ad_build->setText(QString::fromStdString(apartment.getBuild()));
        ui->label_ad_floor->setText(QString::fromStdString(apartment.getFloor()));
        ui->label_ad_room->setText(QString::fromStdString(apartment.getRooms()));
        ui->label_ad_meter->setText(QString::fromStdString(str2.append(property.getBuilding())));

    } else if (property.getPropertyType() == "ویلایی") {
        // Search for the corresponding Villa property
        y = 0;
        while (y < Ad::villas.size()) {
            if (Ad::villas[y].getName() == property.getName() && Ad::villas[y].getAddress() == property.getAddress() && Ad::villas[y].getType() == property.getType() && Ad::villas[y].getPropertyType() == property.getPropertyType() && Ad::villas[y].getCategory() == property.getCategory()){
                break;
            }
            y++;
        }
        Villa villa = Ad::villas[y];

        if (villa.getIsFurnished())
            details.append("مبله - ");
        if (villa.getIsRenew())
            details.append("نوساز - ");
        if (villa.getHasParking())
            details.append("پارکینگ - ");
        if (villa.getHasStorage())
            details.append("انباری - ");
        if (villa.getHasWallpaper())
            details.append("کاغذ دیواری - ");

        ui->label_ad_detail->setText(QString::fromStdString(details));

        ui->label_ad_build->setText(QString::fromStdString(villa.getBuild()));
        ui->label_ad_floor->setText("");
        ui->label_ad_room->setText(QString::fromStdString(villa.getRooms()));
        ui->label_ad_meter->setText(QString::fromStdString(str1.append(property.getLand()).append(" - ").append(str2).append(property.getBuilding())));

    } else if (property.getPropertyType() == "دفترکار") {
        // Search for the corresponding Workplace property
        y = 0;
        while (y < Ad::workplaces.size()) {
            if (Ad::workplaces[y].getName() == property.getName() && Ad::workplaces[y].getAddress() == property.getAddress() && Ad::workplaces[y].getType() == property.getType() && Ad::workplaces[y].getPropertyType() == property.getPropertyType() && Ad::workplaces[y].getCategory() == property.getCategory()){
                break;
            }
            y++;
        }
        Workplace workplace = Ad::workplaces[y];

        if (workplace.getIsRenew())
            details.append("نوساز - ");
        if (workplace.getHasParking())
            details.append("پارکینگ - ");
        if (workplace.getHasElevator())
            details.append("آسانسور - ");
        if (workplace.getHasStorage())
            details.append("انباری - ");
        if (workplace.getHasWallpaper())
            details.append("کاغذ دیواری - ");

        ui->label_ad_detail->setText(QString::fromStdString(details));

        ui->label_ad_build->setText(QString::fromStdString(workplace.getBuild()));
        ui->label_ad_floor->setText(QString::fromStdString(workplace.getFloor()));
        ui->label_ad_room->setText(QString::fromStdString(workplace.getRooms()));
        ui->label_ad_meter->setText(QString::fromStdString(str2.append(property.getBuilding())));

    } else if (property.getPropertyType() == "مطب") {
        // Search for the corresponding Clinic property
        y = 0;
        while (y < Ad::clinics.size()) {
            if (Ad::clinics[y].getName() == property.getName() && Ad::clinics[y].getAddress() == property.getAddress() && Ad::clinics[y].getType() == property.getType() && Ad::clinics[y].getPropertyType() == property.getPropertyType() && Ad::clinics[y].getCategory() == property.getCategory()){
                break;
            }
            y++;
        }
        Clinic clinic = Ad::clinics[y];

        if (clinic.getIsRenew())
            details.append("نوساز - ");
        if (clinic.getHasParking())
            details.append("پارکینگ - ");
        if (clinic.getHasElevator())
            details.append("آسانسور - ");
        if (clinic.getHasStorage())
            details.append("انباری - ");
        if (clinic.getHasWallpaper())
            details.append("کاغذ دیواری - ");

        ui->label_ad_detail->setText(QString::fromStdString(details));

        ui->label_ad_build->setText(QString::fromStdString(clinic.getBuild()));
        ui->label_ad_floor->setText(QString::fromStdString(clinic.getFloor()));
        ui->label_ad_room->setText(QString::fromStdString(clinic.getRooms()));
        ui->label_ad_meter->setText(QString::fromStdString(str2.append(property.getBuilding())));

    } else if (property.getPropertyType() == "مغازه") {
        // Search for the corresponding Shop property
        y = 0;
        while (y < Ad::shops.size()) {
            if (Ad::shops[y].getName() == property.getName() && Ad::shops[y].getAddress() == property.getAddress() && Ad::shops[y].getType() == property.getType() && Ad::shops[y].getPropertyType() == property.getPropertyType() && Ad::shops[y].getCategory() == property.getCategory()){
                break;
            }
            y++;
        }
        Shop shop = Ad::shops[y];

        if (shop.getIsRenew())
            details.append("پارکینگ - ");
        if (shop.getHasElevator())
            details.append("آسانسور - ");
        if (shop.getHasStorage())
            details.append("بالکن/تراس - ");
        if (shop.getHasWallpaper())
            details.append("کاغذ دیواری - ");

        ui->label_ad_detail->setText(QString::fromStdString(details));

        ui->label_ad_build->setText(QString::fromStdString(shop.getBuild()));
        ui->label_ad_floor->setText(QString::fromStdString(shop.getFloor()));
        ui->label_ad_room->setText(QString::fromStdString(shop.getRooms()));
        ui->label_ad_meter->setText(QString::fromStdString(str2.append(property.getBuilding())));

    } else if (property.getPropertyType() == "کارگاه") {
        // Search for the corresponding Workshop property
        y = 0;
        while (y < Ad::workshops.size()) {
            if (Ad::workshops[y].getName() == property.getName() && Ad::workshops[y].getAddress() == property.getAddress() && Ad::workshops[y].getType() == property.getType() && Ad::workshops[y].getPropertyType() == property.getPropertyType() && Ad::workshops[y].getCategory() == property.getCategory()){
                break;
            }
            y++;
        }
        Workshop workshop = Ad::workshops[y];

        if (workshop.getIsRenew())
            details.append("نوساز - ");
        if (workshop.getHasStorage())
            details.append("انباری - ");

        ui->label_ad_detail->setText(QString::fromStdString(details));

        ui->label_ad_build->setText(QString::fromStdString(workshop.getBuild()));
        ui->label_ad_floor->setText("");
        ui->label_ad_room->setText(QString::fromStdString(workshop.getRooms()));
        ui->label_ad_meter->setText(QString::fromStdString(str2.append(property.getBuilding())));

    } else { // انبار
        // Search for the corresponding Storage property
        y = 0;
        while (y < Ad::storages.size()) {
            if (Ad::storages[y].getName() == property.getName() && Ad::storages[y].getAddress() == property.getAddress() && Ad::storages[y].getType() == property.getType() && Ad::storages[y].getPropertyType() == property.getPropertyType() && Ad::storages[y].getCategory() == property.getCategory()){
                break;
            }
            y++;
        }
        Storage storage = Ad::storages[y];

        if (storage.getIsRenew())
            details.append("نوساز - ");
        if (storage.getHasStorage())
            details.append("انباری - ");

        ui->label_ad_detail->setText(QString::fromStdString(details));

        ui->label_ad_build->setText(QString::fromStdString(storage.getBuild()));
        ui->label_ad_floor->setText("");
        ui->label_ad_room->setText(QString::fromStdString(storage.getRooms()));
        ui->label_ad_meter->setText(QString::fromStdString(str2.append(property.getBuilding())));
    }

    // Set the current page of the stacked widget to show ad details (index 3)
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_see_my_ad_clicked() {
    // Get the index of the currently selected row in the tableWidget
    int row = ui->tableWidget->currentRow();

    // Check if a row is selected (-1 means no row is selected)
    if (row == -1) {
        // If no row is selected, show an error message
        show_error_box("لطفا یک مورد را انتخاب کنید.");
    } else {
        // Retrieve the text from the first column (index 0) of the selected row
        QString index_str = ui->tableWidget->item(row, 0)->text();

        // Convert the QString to string and then to integer
        int ad_id = std::stoi(index_str.toStdString());

        // Call the function to show detailed information about the selected ad
        show_page_detail_ad(ad_id);
    }
}

void MainWindow::show_edit_section() {
    // Retrieve the ad ID from the hidden label and convert it to integer
    int ad_id = std::stoi(ui->label_ad_id_hidden->text().toStdString());

    // Find the ad in the appropriate container based on its ID
    size_t x = 0;
    while (x < Ad::ads.size()) {
        if (Ad::ads[x].getId() == ad_id){
            break;
        }
        x++;
    }

    // Retrieve the property associated with the ad
    Property property = Ad::ads[x].getProperty();

    // Set UI elements with property details
    ui->lineEdit_ad_name->setText(QString::fromStdString(property.getName()));
    ui->lineEdit_address->setText(QString::fromStdString(property.getAddress()));

    // Set type radio buttons based on property type
    string type = property.getType();
    if (type == "فروش")
        ui->radioButton_type_sell->setChecked(true);

    else if (type == "معاوضه")
        ui->radioButton_type_exchange->setChecked(true);

    else
        ui->radioButton_type_rent->setChecked(true);

    // Set category radio buttons based on property category
    string category = property.getCategory();
    if (category == "غیرمسکونی")
        ui->radioButton_category_non_residential->setChecked(true);

    else if (category == "مسکونی")
        ui->radioButton_category_residential->setChecked(true);

    else if (category == "اداری")
        ui->radioButton_category_office->setChecked(true);

    else
        ui->radioButton_category_non_residential->setChecked(true);

    // Set property type radio buttons based on property type
    string property_type = property.getPropertyType();
    if (property_type == "زمین")
         ui->radioButton_type_land->setChecked(true);

    else if (property_type == "کلنگی")
        ui->radioButton_type_kolangi->setChecked(true);

    else if (property_type == "باغ")
        ui->radioButton_type_garden->setChecked(true);

    else if (property_type == "آپارتمان")
        ui->radioButton_type_apartment->setChecked(true);

    else if (property_type == "ویلایی")
        ui->radioButton_type_villa->setChecked(true);

    else if (property_type == "دفترکار")
        ui->radioButton_type_office->setChecked(true);

    else if (property_type == "مطب")
        ui->radioButton_type_clinic->setChecked(true);

    else if (property_type == "مغازه")
        ui->radioButton_type_shop->setChecked(true);

    else if (property_type == "انبار")
        ui->radioButton_type_storage->setChecked(true);

    else
        ui->radioButton_type_workshop->setChecked(true);

    // Set specific property details based on type
    ui->lineEdit_land->setText(QString::fromStdString(property.getLand()));
    ui->lineEdit_building->setText(QString::fromStdString(property.getBuilding()));

    // Enable/disable price/deposit/rent based on property type
    if (!property.getPrice().empty()){
        ui->lineEdit_price->setEnabled(true);
        ui->lineEdit_deposit->setEnabled(false);
        ui->lineEdit_rent->setEnabled(false);
    } else {
        ui->lineEdit_price->setEnabled(false);
        ui->lineEdit_deposit->setEnabled(true);
        ui->lineEdit_rent->setEnabled(true);
    }
    ui->lineEdit_price->setText(QString::fromStdString(property.getPrice()));
    ui->lineEdit_deposit->setText(QString::fromStdString(property.getDeposit()));
    ui->lineEdit_rent->setText(QString::fromStdString(property.getRent()));

     // Set description and picture path
    ui->lineEdit_description->setText(QString::fromStdString(property.getDescription()));
    ui->label_pic_path->setText(QString::fromStdString(property.getPic()));

    // Set picture display if available, otherwise set a default picture
    if (!property.getPic().empty()){
        QPixmap pixmap(QString::fromStdString(property.getPic()));
        ui->label_pic->setPixmap(pixmap.scaled(141, 141, Qt::KeepAspectRatio));
    } else {
        QPixmap pixmap(":/no_pic.jpg");
        ui->label_pic->setPixmap(pixmap.scaled(141, 141, Qt::KeepAspectRatio));
    }

     // Set additional features based on property type
    if (property.getHasDeed())
        ui->checkBox_deed->setChecked(true);

    // Additional settings based on specific property types
    string build = ui->comboBox_build->currentText().toStdString();
    string floor = ui->comboBox_floor->currentText().toStdString();
    string rooms = ui->comboBox_room->currentText().toStdString();

    x = 0;
    if (property_type == "زمین"){
        while (x < Ad::lands.size()) {
            if (Ad::lands[x].getName() == property.getName() && Ad::lands[x].getAddress() == property.getAddress()
                    && Ad::lands[x].getType() == property.getType() && Ad::lands[x].getCategory() == property.getCategory()
                    && Ad::lands[x].getPropertyType() == property.getPropertyType()){
                break;
            }
            x++;
        }

        Land property = Ad::lands[x];

    } else if (property_type == "کلنگی") {
        while (x < Ad::kolangies.size()) {
            if (Ad::kolangies[x].getName() == property.getName() && Ad::kolangies[x].getAddress() == property.getAddress()
                    && Ad::kolangies[x].getType() == property.getType() && Ad::kolangies[x].getCategory() == property.getCategory()
                    && Ad::kolangies[x].getPropertyType() == property.getPropertyType()){
                break;
            }
            x++;
        }

        Kolangi property = Ad::kolangies[x];

        if (property.getHasStorage())
            ui->checkBox_storage->setChecked(true);

        if (!property.getRooms().empty())
            ui->comboBox_room->setCurrentText(QString::fromStdString(property.getRooms()));

    } else if (property_type == "باغ") {
        while (x < Ad::gardens.size()) {
            if (Ad::gardens[x].getName() == property.getName() && Ad::gardens[x].getAddress() == property.getAddress()
                    && Ad::gardens[x].getType() == property.getType() && Ad::gardens[x].getCategory() == property.getCategory()
                    && Ad::gardens[x].getPropertyType() == property.getPropertyType()){
                break;
            }
            x++;
        }

        Garden property = Ad::gardens[x];

        if (property.getIsRenew())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasStorage())
            ui->checkBox_storage->setChecked(true);

        if (!property.getBuild().empty())
            ui->comboBox_build->setCurrentText(QString::fromStdString(property.getBuild()));

        if (!property.getRooms().empty())
            ui->comboBox_room->setCurrentText(QString::fromStdString(property.getRooms()));

    } else if (property_type == "آپارتمان") {
        while (x < Ad::apartments.size()) {
            if (Ad::apartments[x].getName() == property.getName() && Ad::apartments[x].getAddress() == property.getAddress()
                    && Ad::apartments[x].getType() == property.getType() && Ad::apartments[x].getCategory() == property.getCategory()
                    && Ad::apartments[x].getPropertyType() == property.getPropertyType()){
                break;
            }
            x++;
        }

        Apartment property = Ad::apartments[x];

        if (property.getIsFurnished())
            ui->checkBox_storage->setChecked(true);

        if (property.getIsRenew())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasParking())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasElevator())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasStorage())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasBalcony())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasWallpaper())
            ui->checkBox_storage->setChecked(true);

        if (!property.getBuild().empty())
            ui->comboBox_build->setCurrentText(QString::fromStdString(property.getBuild()));

        if (!property.getFloor().empty())
            ui->comboBox_floor->setCurrentText(QString::fromStdString(property.getFloor()));

        if (!property.getRooms().empty())
            ui->comboBox_room->setCurrentText(QString::fromStdString(property.getRooms()));

    } else if (property_type == "ویلایی"){
        while (x < Ad::villas.size()) {
            if (Ad::villas[x].getName() == property.getName() && Ad::villas[x].getAddress() == property.getAddress()
                    && Ad::villas[x].getType() == property.getType() && Ad::villas[x].getCategory() == property.getCategory()
                    && Ad::villas[x].getPropertyType() == property.getPropertyType()){
                break;
            }
            x++;
        }

        Villa property = Ad::villas[x];

        if (property.getIsFurnished())
            ui->checkBox_storage->setChecked(true);

        if (property.getIsRenew())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasParking())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasStorage())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasWallpaper())
            ui->checkBox_storage->setChecked(true);

        if (!property.getBuild().empty())
            ui->comboBox_build->setCurrentText(QString::fromStdString(property.getBuild()));

        if (!property.getRooms().empty())
            ui->comboBox_room->setCurrentText(QString::fromStdString(property.getRooms()));

    } else if (property_type == "دفترکار"){
        while (x < Ad::workplaces.size()) {
            if (Ad::workplaces[x].getName() == property.getName() && Ad::workplaces[x].getAddress() == property.getAddress()
                    && Ad::workplaces[x].getType() == property.getType() && Ad::workplaces[x].getCategory() == property.getCategory()
                    && Ad::workplaces[x].getPropertyType() == property.getPropertyType()){
                break;
            }
            x++;
        }

        Workplace property = Ad::workplaces[x];

        if (property.getIsRenew())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasParking())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasElevator())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasStorage())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasWallpaper())
            ui->checkBox_storage->setChecked(true);

        if (!property.getBuild().empty())
            ui->comboBox_build->setCurrentText(QString::fromStdString(property.getBuild()));

        if (!property.getFloor().empty())
            ui->comboBox_floor->setCurrentText(QString::fromStdString(property.getFloor()));

        if (!property.getRooms().empty())
            ui->comboBox_room->setCurrentText(QString::fromStdString(property.getRooms()));

    } else if (property_type == "مطب") {
        while (x < Ad::clinics.size()) {
            if (Ad::clinics[x].getName() == property.getName() && Ad::clinics[x].getAddress() == property.getAddress()
                    && Ad::clinics[x].getType() == property.getType() && Ad::clinics[x].getCategory() == property.getCategory()
                    && Ad::clinics[x].getPropertyType() == property.getPropertyType()){
                break;
            }
            x++;
        }

        Clinic property = Ad::clinics[x];

        if (property.getIsRenew())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasParking())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasElevator())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasStorage())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasWallpaper())
            ui->checkBox_storage->setChecked(true);

        if (!property.getBuild().empty())
            ui->comboBox_build->setCurrentText(QString::fromStdString(property.getBuild()));

        if (!property.getFloor().empty())
            ui->comboBox_floor->setCurrentText(QString::fromStdString(property.getFloor()));

        if (!property.getRooms().empty())
            ui->comboBox_room->setCurrentText(QString::fromStdString(property.getRooms()));

    } else if (property_type == "مغازه") {
        while (x < Ad::shops.size()) {
            if (Ad::shops[x].getName() == property.getName() && Ad::shops[x].getAddress() == property.getAddress()
                    && Ad::shops[x].getType() == property.getType() && Ad::shops[x].getCategory() == property.getCategory()
                    && Ad::shops[x].getPropertyType() == property.getPropertyType()){
                break;
            }
            x++;
        }

        Shop property = Ad::shops[x];

        if (property.getIsRenew())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasElevator())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasStorage())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasWallpaper())
            ui->checkBox_storage->setChecked(true);

        if (!property.getBuild().empty())
            ui->comboBox_build->setCurrentText(QString::fromStdString(property.getBuild()));

        if (!property.getFloor().empty())
            ui->comboBox_floor->setCurrentText(QString::fromStdString(property.getFloor()));

        if (!property.getRooms().empty())
            ui->comboBox_room->setCurrentText(QString::fromStdString(property.getRooms()));

    } else if (property_type == "انبار") {
        while (x < Ad::storages.size()) {
            if (Ad::storages[x].getName() == property.getName() && Ad::storages[x].getAddress() == property.getAddress()
                    && Ad::storages[x].getType() == property.getType() && Ad::storages[x].getCategory() == property.getCategory()
                    && Ad::storages[x].getPropertyType() == property.getPropertyType()){
                break;
            }
            x++;
        }

        Storage property = Ad::storages[x];

        if (property.getIsRenew())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasStorage())
            ui->checkBox_storage->setChecked(true);

        if (!property.getBuild().empty())
            ui->comboBox_build->setCurrentText(QString::fromStdString(property.getBuild()));

        if (!property.getRooms().empty())
            ui->comboBox_room->setCurrentText(QString::fromStdString(property.getRooms()));

    } else { // کارگاه
        while (x < Ad::workshops.size()) {
            if (Ad::workshops[x].getName() == property.getName() && Ad::workshops[x].getAddress() == property.getAddress()
                    && Ad::workshops[x].getType() == property.getType() && Ad::workshops[x].getCategory() == property.getCategory()
                    && Ad::workshops[x].getPropertyType() == property.getPropertyType()){
                break;
            }
            x++;
        }

        Workshop property = Ad::workshops[x];

        if (property.getIsRenew())
            ui->checkBox_storage->setChecked(true);

        if (property.getHasStorage())
            ui->checkBox_storage->setChecked(true);

        if (!property.getBuild().empty())
            ui->comboBox_build->setCurrentText(QString::fromStdString(property.getBuild()));

        if (!property.getRooms().empty())
            ui->comboBox_room->setCurrentText(QString::fromStdString(property.getRooms()));
    }

    // Disable property type and category radio buttons for editing
    ui->radioButton_category_non_residential->setEnabled(false);
    ui->radioButton_category_residential->setEnabled(false);
    ui->radioButton_category_office->setEnabled(false);
    ui->radioButton_category_commercial->setEnabled(false);

    ui->radioButton_type_land->setEnabled(false);
    ui->radioButton_type_kolangi->setEnabled(false);
    ui->radioButton_type_garden->setEnabled(false);
    ui->radioButton_type_apartment->setEnabled(false);
    ui->radioButton_type_villa->setEnabled(false);
    ui->radioButton_type_office->setEnabled(false);
    ui->radioButton_type_clinic->setEnabled(false);
    ui->radioButton_type_shop->setEnabled(false);
    ui->radioButton_type_storage->setEnabled(false);
    ui->radioButton_type_workshop->setEnabled(false);
}

// Function to handle editing of an advertisement when "Edit My Ad" button is clicked
void MainWindow::on_pushButton_edit_my_ad_clicked() {
    int row = ui->tableWidget->currentRow();

    // Check if a row is selected in the table
    if (row == -1) {
         // Show error message if no row is selected
        show_error_box("لطفا یک مورد را انتخاب کنید.");

    } else {
         // Clear the create page, retrieve ad ID, show edit section, and switch UI buttons
        clear_create_page();

        QString index_str = ui->tableWidget->item(row, 0)->text();
        ui->label_ad_id_hidden->setText(index_str);

        show_edit_section();

        ui->pushButton_edit_ad->setVisible(true);
        ui->pushButton_create_ad->setVisible(false);
        ui->stackedWidget->setCurrentIndex(0);
    }
}

// Function to update item list for non-residential properties and switch to appropriate UI page
void MainWindow::on_pushButton_non_residential_clicked() {
    update_item_list("غیرمسکونی");
    ui->stackedWidget->setCurrentIndex(2);
}

// Function to update item list for residential properties and switch to appropriate UI page
void MainWindow::on_pushButton_residential_clicked() {
    update_item_list("مسکونی");
    ui->stackedWidget->setCurrentIndex(2);
}

// Function to update item list for office properties and switch to appropriate UI page
void MainWindow::on_pushButton_office_clicked() {
    update_item_list("اداری");
    ui->stackedWidget->setCurrentIndex(2);
}

// Function to update item list for commercial properties and switch to appropriate UI page
void MainWindow::on_pushButton_commercial_clicked() {
    update_item_list("تجاری");
    ui->stackedWidget->setCurrentIndex(2);
}

// Function to switch radio button state with specified enable and state settings
void MainWindow::switch_radio_button(QRadioButton *radio_button, bool enable, bool state) {
    radio_button->setEnabled(enable);
    radio_button->setAutoExclusive(false);
    radio_button->setChecked(state);
    radio_button->setAutoExclusive(true);
}

// Function called when "Sell" radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_sell_clicked() {
    ui->lineEdit_deposit->setEnabled(false);
    ui->lineEdit_deposit->setText("");
    ui->lineEdit_rent->setEnabled(false);
    ui->lineEdit_rent->setText("");
    ui->lineEdit_price->setEnabled(true);
    ui->lineEdit_price->setText("");

}

// Function called when "Exchange" radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_exchange_clicked() {
    ui->lineEdit_deposit->setEnabled(false);
    ui->lineEdit_deposit->setText("");
    ui->lineEdit_rent->setEnabled(false);
    ui->lineEdit_rent->setText("");
    ui->lineEdit_price->setEnabled(true);
    ui->lineEdit_price->setText("");
}

// Function called when "Rent" radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_rent_clicked() {
    ui->lineEdit_deposit->setEnabled(true);
    ui->lineEdit_deposit->setText("");
    ui->lineEdit_rent->setEnabled(true);
    ui->lineEdit_rent->setText("");
    ui->lineEdit_price->setEnabled(false);
    ui->lineEdit_price->setText("");
}

// Function called when "Non-Residential" category radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_category_non_residential_clicked() {
    reset_other_details();
    switch_radio_button(ui->radioButton_type_land, true);
    switch_radio_button(ui->radioButton_type_kolangi, true);
    switch_radio_button(ui->radioButton_type_garden, true);

    switch_radio_button(ui->radioButton_type_apartment, false);
    switch_radio_button(ui->radioButton_type_villa, false);
    switch_radio_button(ui->radioButton_type_office, false);
    switch_radio_button(ui->radioButton_type_clinic, false);
    switch_radio_button(ui->radioButton_type_shop, false);
    switch_radio_button(ui->radioButton_type_storage, false);
    switch_radio_button(ui->radioButton_type_workshop, false);
}

// Function called when "Residential" category radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_category_residential_clicked() {
    reset_other_details();
    switch_radio_button(ui->radioButton_type_land, false);
    switch_radio_button(ui->radioButton_type_kolangi, false);
    switch_radio_button(ui->radioButton_type_garden, false);

    switch_radio_button(ui->radioButton_type_apartment, true);
    switch_radio_button(ui->radioButton_type_villa, true);

    switch_radio_button(ui->radioButton_type_office, false);
    switch_radio_button(ui->radioButton_type_clinic, false);
    switch_radio_button(ui->radioButton_type_shop, false);
    switch_radio_button(ui->radioButton_type_storage, false);
    switch_radio_button(ui->radioButton_type_workshop, false);
}

// Function called when "Office" category radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_category_office_clicked() {
    // Reset details unrelated to office category
    reset_other_details();

    // Enable office and clinic type radio buttons, disable others
    switch_radio_button(ui->radioButton_type_land, false);
    switch_radio_button(ui->radioButton_type_kolangi, false);
    switch_radio_button(ui->radioButton_type_garden, false);
    switch_radio_button(ui->radioButton_type_apartment, false);
    switch_radio_button(ui->radioButton_type_villa, false);

    switch_radio_button(ui->radioButton_type_office, true);
    switch_radio_button(ui->radioButton_type_clinic, true);

    switch_radio_button(ui->radioButton_type_shop, false);
    switch_radio_button(ui->radioButton_type_storage, false);
    switch_radio_button(ui->radioButton_type_workshop, false);
}

// Function called when "Commercial" category radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_category_commercial_clicked() {
    // Reset details unrelated to commercial category
    reset_other_details();

    // Enable shop, storage, and workshop type radio buttons, disable others
    switch_radio_button(ui->radioButton_type_land, false);
    switch_radio_button(ui->radioButton_type_kolangi, false);
    switch_radio_button(ui->radioButton_type_garden, false);
    switch_radio_button(ui->radioButton_type_apartment, false);
    switch_radio_button(ui->radioButton_type_villa, false);
    switch_radio_button(ui->radioButton_type_office, false);
    switch_radio_button(ui->radioButton_type_clinic, false);

    switch_radio_button(ui->radioButton_type_shop, true);
    switch_radio_button(ui->radioButton_type_storage, true);
    switch_radio_button(ui->radioButton_type_workshop, true);
}

// Function to reset all detailed checkboxes and combo boxes to their default states
void MainWindow::reset_other_details() {
    ui->checkBox_deed->setChecked(false);
    ui->checkBox_furnished->setChecked(false);
    ui->checkBox_renew->setChecked(false);
    ui->checkBox_parking->setChecked(false);
    ui->checkBox_elevator->setChecked(false);
    ui->checkBox_storage->setChecked(false);
    ui->checkBox_balcony->setChecked(false);
    ui->checkBox_wallpaper->setChecked(false);

    ui->checkBox_deed->setEnabled(false);
    ui->checkBox_furnished->setEnabled(false);
    ui->checkBox_renew->setEnabled(false);
    ui->checkBox_parking->setEnabled(false);
    ui->checkBox_elevator->setEnabled(false);
    ui->checkBox_storage->setEnabled(false);
    ui->checkBox_balcony->setEnabled(false);
    ui->checkBox_wallpaper->setEnabled(false);

    ui->comboBox_floor->setEnabled(false);
    ui->comboBox_build->setEnabled(false);
    ui->comboBox_room->setEnabled(false);
}

// Function called when "Land" type radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_land_clicked() {
    reset_other_details();

    // Enable deed checkbox and land input, disable others
    ui->checkBox_deed->setEnabled(true);
    ui->checkBox_furnished->setEnabled(false);
    ui->checkBox_renew->setEnabled(false);
    ui->checkBox_parking->setEnabled(false);
    ui->checkBox_elevator->setEnabled(false);
    ui->checkBox_storage->setEnabled(false);
    ui->checkBox_balcony->setEnabled(false);
    ui->checkBox_wallpaper->setEnabled(false);

    ui->comboBox_floor->setEnabled(false);
    ui->comboBox_floor->setCurrentIndex(1);
    ui->comboBox_build->setEnabled(false);
    ui->comboBox_room->setEnabled(false);

    ui->lineEdit_building->setEnabled(false);
    ui->lineEdit_land->setEnabled(true);
}

// Function called when "Kolangi" type radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_kolangi_clicked() {
    reset_other_details();

    // Enable deed checkbox, storage checkbox, building input, and room combo box, disable others
    ui->checkBox_deed->setEnabled(true);
    ui->checkBox_furnished->setEnabled(false);
    ui->checkBox_renew->setEnabled(false);
    ui->checkBox_parking->setEnabled(false);
    ui->checkBox_elevator->setEnabled(false);
    ui->checkBox_storage->setEnabled(true);
    ui->checkBox_balcony->setEnabled(false);
    ui->checkBox_wallpaper->setEnabled(false);

    ui->comboBox_floor->setEnabled(false);
    ui->comboBox_floor->setCurrentIndex(1);
    ui->comboBox_build->setEnabled(false);
    ui->comboBox_room->setEnabled(true);

    ui->lineEdit_building->setEnabled(true);
    ui->lineEdit_land->setEnabled(true);
}

// Function called when "Garden" type radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_garden_clicked() {
    reset_other_details();

    // Enable deed checkbox, renewal checkbox, building input, room combo box, and garden size combo box, disable others
    ui->checkBox_deed->setEnabled(true);
    ui->checkBox_furnished->setEnabled(false);
    ui->checkBox_renew->setEnabled(true);
    ui->checkBox_parking->setEnabled(false);
    ui->checkBox_elevator->setEnabled(false);
    ui->checkBox_storage->setEnabled(true);
    ui->checkBox_balcony->setEnabled(false);
    ui->checkBox_wallpaper->setEnabled(false);

    ui->comboBox_floor->setEnabled(false);
    ui->comboBox_floor->setCurrentIndex(1);
    ui->comboBox_build->setEnabled(true);
    ui->comboBox_room->setEnabled(true);

    ui->lineEdit_building->setEnabled(true);
    ui->lineEdit_land->setEnabled(true);
}

// Function called when "Apartment" type radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_apartment_clicked() {
    reset_other_details();

    // Enable relevant checkboxes and combo boxes for apartments
    ui->checkBox_deed->setEnabled(true);
    ui->checkBox_furnished->setEnabled(true);
    ui->checkBox_renew->setEnabled(true);
    ui->checkBox_parking->setEnabled(true);
    ui->checkBox_elevator->setEnabled(true);
    ui->checkBox_storage->setEnabled(true);
    ui->checkBox_balcony->setEnabled(true);
    ui->checkBox_wallpaper->setEnabled(true);

    ui->comboBox_floor->setEnabled(true);
    ui->comboBox_build->setEnabled(true);
    ui->comboBox_room->setEnabled(true);

    ui->lineEdit_building->setEnabled(true);
    ui->lineEdit_land->setEnabled(false);
}

// Function called when "Villa" type radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_villa_clicked() {
    reset_other_details();

    // Enable relevant checkboxes and combo boxes for villas
    ui->checkBox_deed->setEnabled(true);
    ui->checkBox_furnished->setEnabled(true);
    ui->checkBox_renew->setEnabled(true);
    ui->checkBox_parking->setEnabled(true);
    ui->checkBox_elevator->setEnabled(false);
    ui->checkBox_storage->setEnabled(true);
    ui->checkBox_balcony->setEnabled(false);
    ui->checkBox_wallpaper->setEnabled(true);

    ui->comboBox_floor->setEnabled(false);
    ui->comboBox_floor->setCurrentIndex(1);
    ui->comboBox_build->setEnabled(true);
    ui->comboBox_room->setEnabled(true);

    ui->lineEdit_building->setEnabled(true);
    ui->lineEdit_land->setEnabled(true);
}

// Function called when "Office" type radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_office_clicked() {
    reset_other_details();

    // Enable relevant checkboxes and combo boxes for offices
    ui->checkBox_deed->setEnabled(true);
    ui->checkBox_furnished->setEnabled(false);
    ui->checkBox_renew->setEnabled(true);
    ui->checkBox_parking->setEnabled(true);
    ui->checkBox_elevator->setEnabled(true);
    ui->checkBox_storage->setEnabled(true);
    ui->checkBox_balcony->setEnabled(true);
    ui->checkBox_wallpaper->setEnabled(true);

    ui->comboBox_floor->setEnabled(true);
    ui->comboBox_build->setEnabled(true);
    ui->comboBox_room->setEnabled(true);

    ui->lineEdit_building->setEnabled(true);
    ui->lineEdit_land->setEnabled(false);
}

// Function called when "Clinic" type radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_clinic_clicked() {
    reset_other_details();

    // Enable relevant checkboxes and combo boxes for clinics
    ui->checkBox_deed->setEnabled(true);
    ui->checkBox_furnished->setEnabled(false);
    ui->checkBox_renew->setEnabled(true);
    ui->checkBox_parking->setEnabled(true);
    ui->checkBox_elevator->setEnabled(true);
    ui->checkBox_storage->setEnabled(true);
    ui->checkBox_balcony->setEnabled(true);
    ui->checkBox_wallpaper->setEnabled(true);

    ui->comboBox_floor->setEnabled(true);
    ui->comboBox_build->setEnabled(true);
    ui->comboBox_room->setEnabled(true);

    ui->lineEdit_building->setEnabled(true);
    ui->lineEdit_land->setEnabled(false);
}

// Function called when "Shop" type radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_shop_clicked() {
    reset_other_details();

    // Enable relevant checkboxes and combo boxes for shops
    ui->checkBox_deed->setEnabled(true);
    ui->checkBox_furnished->setEnabled(false);
    ui->checkBox_renew->setEnabled(true);
    ui->checkBox_parking->setEnabled(false);
    ui->checkBox_elevator->setEnabled(true);
    ui->checkBox_storage->setEnabled(true);
    ui->checkBox_balcony->setEnabled(false);
    ui->checkBox_wallpaper->setEnabled(true);

    ui->comboBox_floor->setEnabled(false);
    ui->comboBox_build->setEnabled(true);
    ui->comboBox_room->setEnabled(true);

    ui->lineEdit_building->setEnabled(true);
    ui->lineEdit_land->setEnabled(false);
}

// Function called when "Storage" type radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_storage_clicked() {
    reset_other_details();

    // Enable relevant checkboxes and combo boxes for storage
    ui->checkBox_deed->setEnabled(true);
    ui->checkBox_furnished->setEnabled(false);
    ui->checkBox_renew->setEnabled(true);
    ui->checkBox_parking->setEnabled(false);
    ui->checkBox_elevator->setEnabled(true);
    ui->checkBox_storage->setEnabled(false);
    ui->checkBox_balcony->setEnabled(false);
    ui->checkBox_wallpaper->setEnabled(false);

    ui->comboBox_floor->setEnabled(false);
    ui->comboBox_build->setEnabled(true);
    ui->comboBox_room->setEnabled(true);

    ui->lineEdit_building->setEnabled(true);
    ui->lineEdit_land->setEnabled(false);
}

// Function called when "Workshop" type radio button is clicked to set UI elements accordingly
void MainWindow::on_radioButton_type_workshop_clicked() {
    reset_other_details();

    // Enable relevant checkboxes and combo boxes for workshops
    ui->checkBox_deed->setEnabled(true);
    ui->checkBox_furnished->setEnabled(false);
    ui->checkBox_renew->setEnabled(true);
    ui->checkBox_parking->setEnabled(false);
    ui->checkBox_elevator->setEnabled(false);
    ui->checkBox_storage->setEnabled(true);
    ui->checkBox_balcony->setEnabled(false);
    ui->checkBox_wallpaper->setEnabled(false);

    ui->comboBox_floor->setEnabled(false);
    ui->comboBox_floor->setCurrentIndex(1);
    ui->comboBox_build->setEnabled(true);
    ui->comboBox_room->setEnabled(true);

    ui->lineEdit_building->setEnabled(true);
    ui->lineEdit_land->setEnabled(false);
}

// Function called when "Renew" checkbox state changes to set the combo box accordingly
void MainWindow::on_checkBox_renew_stateChanged(int arg1) {
    if (arg1) {
        // Set the combo box index and disable it when checkbox is checked
        ui->comboBox_build->setCurrentIndex(53);
        ui->comboBox_build->setEnabled(false);
    } else {
        // Reset combo box index and enable it when checkbox is unchecked
        ui->comboBox_build->setCurrentIndex(53);
        ui->comboBox_build->setEnabled(true);
    }
}

// Function called when "pic" button is clicked to open a file dialog and set an image
void MainWindow::on_pushButton_pic_clicked() {
    // Open a file dialog to select an image file
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.jpg)"));

    // Display the selected image in a QLabel and set its path
    QPixmap pixmap(filename);
    ui->label_pic->setPixmap(pixmap.scaled(141, 141, Qt::KeepAspectRatio));
    ui->label_pic_path->setText(filename);

    // Update button text based on whether an image is selected
    if (!filename.toStdString().empty())
        ui->pushButton_pic->setText("");

    else
        ui->pushButton_pic->setText("انتخاب تصویر");
}

// Function to show an error message box with the specified text
void MainWindow::show_error_box(string text) {
    ErrorBox error;
    error.change_label(text);
    error.setModal(true);
    error.exec();
}

// Function to show a success message box with the specified text
void MainWindow::show_success_box(string text) {
    SuccessBox success;
    success.change_label(text);
    success.setModal(true);
    success.exec();
}

// Function called when the "Create Ad" button is clicked to create a new advertisement
void MainWindow::on_pushButton_create_ad_clicked() {
    // Retrieve input values from UI elements
    string name = ui->lineEdit_ad_name->text().toStdString();
    string address = ui->lineEdit_address->text().toStdString();

    // Determine the selected type of advertisement (sell, exchange, rent)
    string type = "";
    if (ui->radioButton_type_sell->isChecked())
        type = ui->radioButton_type_sell->text().toStdString();

    else if (ui->radioButton_type_exchange->isChecked())
        type = ui->radioButton_type_exchange->text().toStdString();

    else
        type = ui->radioButton_type_rent->text().toStdString();

    // Determine the selected category of the property (residential, non-residential, office, commercial)
    string category = "";
    if (ui->radioButton_category_non_residential->isChecked())
        category = ui->radioButton_category_non_residential->text().toStdString();

    else if (ui->radioButton_category_residential->isChecked())
        category = ui->radioButton_category_residential->text().toStdString();

    else if (ui->radioButton_category_office->isChecked())
        category = ui->radioButton_category_office->text().toStdString();

    else
        category = ui->radioButton_category_commercial->text().toStdString();

    // Determine the specific type of property (land, kolangi, garden, apartment, villa, office, clinic, shop, storage, workshop)
    string property_type = "";
    if (ui->radioButton_type_land->isChecked())
        property_type = ui->radioButton_type_land->text().toStdString();

    else if (ui->radioButton_type_kolangi->isChecked())
        property_type = ui->radioButton_type_kolangi->text().toStdString();

    else if (ui->radioButton_type_garden->isChecked())
        property_type = ui->radioButton_type_garden->text().toStdString();

    else if (ui->radioButton_type_apartment->isChecked())
        property_type = ui->radioButton_type_apartment->text().toStdString();

    else if (ui->radioButton_type_villa->isChecked())
        property_type = ui->radioButton_type_villa->text().toStdString();

    else if (ui->radioButton_type_office->isChecked())
        property_type = ui->radioButton_type_office->text().toStdString();

    else if (ui->radioButton_type_clinic->isChecked())
        property_type = ui->radioButton_type_clinic->text().toStdString();

    else if (ui->radioButton_type_shop->isChecked())
        property_type = ui->radioButton_type_shop->text().toStdString();

    else if (ui->radioButton_type_storage->isChecked())
        property_type = ui->radioButton_type_storage->text().toStdString();

    else
        property_type = ui->radioButton_type_workshop->text().toStdString();

    // Validate mandatory fields
    if (name.empty() || address.empty() || type.empty() || category.empty() || property_type.empty()){
        show_error_box("لطفا همه موارد خواسته شده (ستاره دار) را تکمیل کنید و سپس آگهی را ثبت نمایید.");
        return;
    }

    // Validate land and building size input
    string land = ui->lineEdit_land->text().toStdString();
    string building = ui->lineEdit_building->text().toStdString();
    if (land.empty() && building.empty()){
        show_error_box("لطفا متراژ خواسته شده را تکمیل کنید و سپس آگهی را ثبت نمایید.");
        return;
    }
    if ((!land.empty() && !is_number(land)) || (!building.empty() && !is_number(building))){
        show_error_box("متراژ وارد شده اشتباه است.");
        return;
    }

    // Validate price, deposit, and rent input
    string price = ui->lineEdit_price->text().toStdString();
    string deposit = ui->lineEdit_deposit->text().toStdString();
    string rent = ui->lineEdit_rent->text().toStdString();
    if (price.empty() && deposit.empty() && rent.empty()){
        show_error_box("لطفا مبلغ خواسته شده را وارد نمایید.");
        return;
    }
    if ((!price.empty() && !is_number(price)) || (!deposit.empty() && !is_number(deposit)) || (!rent.empty() && !is_number(rent))){
        show_error_box("مبلغ وارد شده اشتباه است.");
        return;
    }

    // Retrieve additional details
    string description = ui->lineEdit_description->text().toStdString();
    string pic = ui->label_pic_path->text().toStdString();

    bool has_deed = ui->checkBox_deed->isChecked();
    bool is_furnished = ui->checkBox_furnished->isChecked();
    bool is_renew = ui->checkBox_renew->isChecked();
    bool has_parking = ui->checkBox_parking->isChecked();
    bool has_elevator = ui->checkBox_elevator->isChecked();
    bool has_storage = ui->checkBox_storage->isChecked();
    bool has_balcony = ui->checkBox_balcony->isChecked();
    bool has_wallpaper = ui->checkBox_wallpaper->isChecked();

    string build = ui->comboBox_build->currentText().toStdString();
    string floor = ui->comboBox_floor->currentText().toStdString();
    string rooms = ui->comboBox_room->currentText().toStdString();

    // Create the appropriate property object based on property type
    if (property_type == "زمین"){
        Land property = Land(name, type, category, property_type, land, building, deposit, rent,
                             price, address, description, pic, has_deed);
        Ad new_ad = Ad(&THIS_USER, property);
        Ad::ads.push_back(new_ad);

    } else if (property_type == "کلنگی") {
        Kolangi property = Kolangi(name, type, category, property_type, land, building, deposit, rent,
                price, address, description, pic, has_deed, has_storage, rooms);
        Ad new_ad = Ad(&THIS_USER, property);
        Ad::ads.push_back(new_ad);

    } else if (property_type == "باغ") {
        Garden property = Garden(name, type, category, property_type, land, building, deposit, rent,
                price, address, description, pic, has_deed, is_renew, has_storage, build, rooms);
        Ad new_ad = Ad(&THIS_USER, property);
        Ad::ads.push_back(new_ad);

    } else if (property_type == "آپارتمان") {
        Apartment property = Apartment(name, type, category, property_type, land, building, deposit, rent,
                                       price, address, description, pic, has_deed,
                                       is_furnished, is_renew, has_parking, has_elevator, has_storage, has_balcony,
                                       has_wallpaper, build, floor, rooms);
        Ad new_ad = Ad(&THIS_USER, property);
        Ad::ads.push_back(new_ad);

    } else if (property_type == "ویلایی"){
        Villa property = Villa(name, type, category, property_type, land, building, deposit, rent,
               price, address, description, pic, has_deed, is_furnished, is_renew, has_parking, has_storage, has_wallpaper, build, rooms);
        Ad new_ad = Ad(&THIS_USER, property);
        Ad::ads.push_back(new_ad);

    } else if (property_type == "دفترکار"){
        Workplace property = Workplace(name, type, category, property_type, land, building, deposit, rent,
               price, address, description, pic, has_deed, is_renew, has_parking, has_storage, has_wallpaper, build, rooms);
        Ad new_ad = Ad(&THIS_USER, property);
        Ad::ads.push_back(new_ad);

    } else if (property_type == "مطب") {
        Clinic property = Clinic(name, type, category, property_type, land, building, deposit, rent,
               price, address, description, pic, has_deed, is_renew, has_parking, has_storage, has_wallpaper, build, rooms);
        Ad new_ad = Ad(&THIS_USER, property);
        Ad::ads.push_back(new_ad);

    } else if (property_type == "مغازه") {
        Shop property = Shop(name, type, category, property_type, land, building, deposit, rent,
               price, address, description, pic, has_deed, is_renew, has_elevator, has_storage, has_wallpaper, build, floor, rooms);
        Ad new_ad = Ad(&THIS_USER, property);
        Ad::ads.push_back(new_ad);

    } else if (property_type == "انبار") {
        Storage property = Storage(name, type, category, property_type, land, building, deposit, rent,
                price, address, description, pic, has_deed, is_renew, has_storage, build, rooms);
        Ad new_ad = Ad(&THIS_USER, property);
        Ad::ads.push_back(new_ad);

    } else { // property_type == "کارگاه"
        Workshop property = Workshop(name, type, category, property_type, land, building, deposit, rent,
               price, address, description, pic, has_deed, is_renew, has_storage, build, rooms);
        Ad new_ad = Ad(&THIS_USER, property);
        Ad::ads.push_back(new_ad);
    }

    // Show success message and update UI to display user's ads
    show_success_box("آگهی شما با موفقیت به آگهی ها افزوده شد.");
    on_pushButton_page_show_my_ads_clicked();
}

// Function called when the "Delete My Ad" button is clicked to remove the selected advertisement
void MainWindow::on_pushButton_delete_my_ad_clicked() {
    int row = ui->tableWidget->currentRow();

    // Check if a row is selected
    if (row == -1){
        show_error_box("لطفا یک مورد را انتخاب کنید.");

    } else {
        QString index_str = ui->tableWidget->item(row, 0)->text();

        // Find and remove the ad from the ads vector
        for(unsigned int i = 0; i < Ad::ads.size(); i++)
            if(Ad::ads[i].getId() == std::stoi(index_str.toStdString())){
                Ad::ads.erase(Ad::ads.begin()+i);
                show_success_box("آگهی مورد نظر حذف شد.");
                break;
            }
    }

    // Update the table display
    update_table();
}

// Function called when the "Search" button is clicked to find ads based on user input
void MainWindow::on_pushButton_search_clicked() {
    string search = ui->lineEdit_search->text().toStdString();

    // Check if search field is empty
    if (search.empty()){
        show_error_box("لطفا عبارت مورد نظر خود را وارد نمایید.");
        return;
    }

    // Clear the list widget before adding new search results
    while(ui->listWidget_search->count() > 0)
        ui->listWidget_search->takeItem(0);

    int count = 0;
    if (ui->radioButton_search_name->isChecked()){
        // Search by advertisement name
        for(auto ad: Ad::ads) {
             if (ad.getProperty().getName().find(search) != string::npos){
                 count++;
             }
        }

        // Handle case when no ads match the search criteria
        if (count == 0)
            show_error_box("آگهی با این مشخصات پیدا نشد.");

        // Add matching ads to the list widget
        for(auto ad: Ad::ads) {
             if (ad.getProperty().getName().find(search) != string::npos){
                 create_item(ad.getId(), QString::fromStdString(ad.getProperty().getName()), QString::fromStdString(ad.getProperty().getAddress()),
                             QString::fromStdString(ad.getProperty().getType()), QString::fromStdString(ad.getProperty().getPic()), ui->listWidget_search);
             }
        }

    } else {
        // Search by advertisement address
        for(auto ad: Ad::ads) {
            if (ad.getProperty().getAddress().find(search) != string::npos)
                count++;
        }

        // Handle case when no ads match the search criteria
        if (count == 0)
            show_error_box("موردی پیدا نشد.");

        // Add matching ads to the list widget
        for(auto ad: Ad::ads) {
            if (ad.getProperty().getAddress().find(search) != string::npos)
                create_item(ad.getId(), QString::fromStdString(ad.getProperty().getName()), QString::fromStdString(ad.getProperty().getAddress()),
                            QString::fromStdString(ad.getProperty().getType()), QString::fromStdString(ad.getProperty().getPic()), ui->listWidget_search);
        }
    }
}

// Function called when the "Edit Ad" button is clicked to update an existing advertisement
void MainWindow::on_pushButton_edit_ad_clicked() {
    int ad_id = std::stoi(ui->label_ad_id_hidden->text().toStdString());

    // Find the index of the advertisement in the Ad::ads vector
    size_t x = 0;
    size_t w = 0;
    while (w < Ad::ads.size()) {
        if (Ad::ads[w].getId() == ad_id){
            break;
        }
        x++;
    }

    // Save the original and updated property objects
    Property propertyO = Ad::ads[w].getProperty();
    Property property = Ad::ads[w].getProperty();

     // Update the property attributes based on user input
    property.setName(ui->lineEdit_ad_name->text().toStdString());
    property.setAddress(ui->lineEdit_address->text().toStdString());

     // Set property type based on radio button selection
    if (ui->radioButton_type_sell->isChecked())
        property.setType(ui->radioButton_type_sell->text().toStdString());

    else if (ui->radioButton_type_exchange->isChecked())
        property.setType(ui->radioButton_type_exchange->text().toStdString());

    else
        property.setType(ui->radioButton_type_rent->text().toStdString());

    // Set property category based on radio button selection
    if (ui->radioButton_category_non_residential->isChecked())
        property.setCategory(ui->radioButton_category_non_residential->text().toStdString());

    else if (ui->radioButton_category_residential->isChecked())
        property.setCategory(ui->radioButton_category_residential->text().toStdString());

    else if (ui->radioButton_category_office->isChecked())
        property.setCategory(ui->radioButton_category_office->text().toStdString());

    else
        property.setCategory(ui->radioButton_category_commercial->text().toStdString());

    // Set property specific type based on radio button selection
    if (ui->radioButton_type_land->isChecked())
        property.setPropertyType(ui->radioButton_type_land->text().toStdString());

    else if (ui->radioButton_type_kolangi->isChecked())
        property.setPropertyType(ui->radioButton_type_kolangi->text().toStdString());

    else if (ui->radioButton_type_garden->isChecked())
        property.setPropertyType(ui->radioButton_type_garden->text().toStdString());

    else if (ui->radioButton_type_apartment->isChecked())
        property.setPropertyType(ui->radioButton_type_apartment->text().toStdString());

    else if (ui->radioButton_type_villa->isChecked())
        property.setPropertyType(ui->radioButton_type_villa->text().toStdString());

    else if (ui->radioButton_type_office->isChecked())
        property.setPropertyType(ui->radioButton_type_office->text().toStdString());

    else if (ui->radioButton_type_clinic->isChecked())
        property.setPropertyType(ui->radioButton_type_clinic->text().toStdString());

    else if (ui->radioButton_type_shop->isChecked())
        property.setPropertyType(ui->radioButton_type_shop->text().toStdString());

    else if (ui->radioButton_type_storage->isChecked())
        property.setPropertyType(ui->radioButton_type_storage->text().toStdString());

    else
        property.setPropertyType(ui->radioButton_type_workshop->text().toStdString());

    // Validate mandatory fields
    if (property.getName().empty() || property.getAddress().empty()){
        show_error_box("لطفا همه موارد خواسته شده (ستاره دار) را تکمیل کنید و سپس آگهی را ثبت نمایید.");
        return;
    }

    // Set land and building size
    property.setLand(ui->lineEdit_land->text().toStdString());
    property.setBuilding(ui->lineEdit_building->text().toStdString());

     // Validate land and building size inputs
    if (property.getLand().empty() && property.getBuilding().empty()){
        show_error_box("لطفا متراژ خواسته شده را تکمیل کنید و سپس آگهی را ثبت نمایید.");
        return;
    }

    // Validate numeric inputs for land and building size
    if ((!property.getLand().empty() && !is_number(property.getLand())) || (!property.getBuilding().empty() && !is_number(property.getBuilding()))){
        show_error_box("متراژ وارد شده اشتباه است.");
        return;
    }

    // Set price, deposit, and rent
    property.setPrice(ui->lineEdit_price->text().toStdString());
    property.setDeposit(ui->lineEdit_deposit->text().toStdString());
    property.setRent(ui->lineEdit_rent->text().toStdString());

    // Validate at least one of price, deposit, or rent is filled
    if (property.getPrice().empty() && property.getDeposit().empty() && property.getRent().empty()){
        show_error_box("لطفا مبلغ خواسته شده را وارد نمایید.");
        return;
    }

    // Validate numeric inputs for price, deposit, and rent
    if ((!property.getPrice().empty() && !is_number(property.getPrice())) || (!property.getDeposit().empty() && !is_number(property.getDeposit())) || (!property.getRent().empty() && !is_number(property.getRent()))){
        show_error_box("مبلغ وارد شده اشتباه است.");
        return;
    }

    // Set description, picture path, and additional features
    property.setDescription(ui->lineEdit_description->text().toStdString());
    property.setPic(ui->label_pic_path->text().toStdString());
    property.setHasDeed(ui->checkBox_deed->isChecked());

    bool is_furnished = ui->checkBox_furnished->isChecked();
    bool is_renew = ui->checkBox_renew->isChecked();
    bool has_parking = ui->checkBox_parking->isChecked();
    bool has_elevator = ui->checkBox_elevator->isChecked();
    bool has_storage = ui->checkBox_storage->isChecked();
    bool has_balcony = ui->checkBox_balcony->isChecked();
    bool has_wallpaper = ui->checkBox_wallpaper->isChecked();

    string build = ui->comboBox_build->currentText().toStdString();
    string floor = ui->comboBox_floor->currentText().toStdString();
    string rooms = ui->comboBox_room->currentText().toStdString();

     // Update specific type properties based on original type
    x = 0;
    if (propertyO.getPropertyType() == "زمین"){
        while (x < Ad::lands.size()) {
            if (Ad::lands[x].getName() == propertyO.getName() && Ad::lands[x].getAddress() == propertyO.getAddress()
                    && Ad::lands[x].getType() == propertyO.getType() && Ad::lands[x].getCategory() == propertyO.getCategory()
                    && Ad::lands[x].getPropertyType() == propertyO.getPropertyType()){
                break;
            }
            x++;
        }

        // Update Land object and associated advertisement
        Land new_property = Land(property.getName(), property.getType(), property.getCategory(), property.getPropertyType(),
                                 property.getLand(), property.getBuilding(), property.getDeposit(), property.getRent(), property.getPrice(),
                                 property.getAddress(), property.getDescription(), property.getPic(), property.getHasDeed());
        Ad::lands[x] = new_property;
        Ad::ads[w] = Ad(&THIS_USER, new_property);

    } else if (propertyO.getPropertyType() == "کلنگی") {
        // Update Kolangi object and associated advertisement
        while (x < Ad::kolangies.size()) {
            if (Ad::kolangies[x].getName() == propertyO.getName() && Ad::kolangies[x].getAddress() == propertyO.getAddress()
                    && Ad::kolangies[x].getType() == propertyO.getType() && Ad::kolangies[x].getCategory() == propertyO.getCategory()
                    && Ad::kolangies[x].getPropertyType() == propertyO.getPropertyType()){
                break;
            }
            x++;
        }

        Kolangi new_property = Kolangi(property.getName(), property.getType(), property.getCategory(), property.getPropertyType(),
                                 property.getLand(), property.getBuilding(), property.getDeposit(), property.getRent(), property.getPrice(),
                                 property.getAddress(), property.getDescription(), property.getPic(), property.getHasDeed(),
                                 has_storage, rooms);
        Ad::kolangies[x] = new_property;
        Ad::ads[w] = Ad(&THIS_USER, new_property);

    } else if (propertyO.getPropertyType() == "باغ") {
        // Update Garden object and associated advertisement
        while (x < Ad::gardens.size()) {
            if (Ad::gardens[x].getName() == propertyO.getName() && Ad::gardens[x].getAddress() == propertyO.getAddress()
                    && Ad::gardens[x].getType() == propertyO.getType() && Ad::gardens[x].getCategory() == propertyO.getCategory()
                    && Ad::gardens[x].getPropertyType() == propertyO.getPropertyType()){
                break;
            }
            x++;
        }

        Garden new_property = Garden(property.getName(), property.getType(), property.getCategory(), property.getPropertyType(),
                                 property.getLand(), property.getBuilding(), property.getDeposit(), property.getRent(), property.getPrice(),
                                 property.getAddress(), property.getDescription(), property.getPic(), property.getHasDeed(),
                                 is_renew, has_storage, build, rooms);

        Ad::gardens[x] = new_property;
        Ad::ads[w] = Ad(&THIS_USER, new_property);

    } else if (propertyO.getPropertyType() == "آپارتمان") {
        // Update Apartment object and associated advertisement
        while (x < Ad::apartments.size()) {
            if (Ad::apartments[x].getName() == propertyO.getName() && Ad::apartments[x].getAddress() == propertyO.getAddress()
                    && Ad::apartments[x].getType() == propertyO.getType() && Ad::apartments[x].getCategory() == propertyO.getCategory()
                    && Ad::apartments[x].getPropertyType() == propertyO.getPropertyType()){
                break;
            }
            x++;
        }

        Apartment new_property = Apartment(property.getName(), property.getType(), property.getCategory(), property.getPropertyType(),
                                 property.getLand(), property.getBuilding(), property.getDeposit(), property.getRent(), property.getPrice(),
                                 property.getAddress(), property.getDescription(), property.getPic(), property.getHasDeed(),
                                 is_furnished, is_renew, has_parking, has_elevator, has_storage, has_balcony, has_wallpaper, build, floor, rooms);

        Ad::apartments[x] = new_property;
        Ad::ads[w] = Ad(&THIS_USER, new_property);

    } else if (propertyO.getPropertyType() == "ویلایی"){
        // Update Villa object and associated advertisement
        while (x < Ad::villas.size()) {
            if (Ad::villas[x].getName() == propertyO.getName() && Ad::villas[x].getAddress() == propertyO.getAddress()
                    && Ad::villas[x].getType() == propertyO.getType() && Ad::villas[x].getCategory() == propertyO.getCategory()
                    && Ad::villas[x].getPropertyType() == propertyO.getPropertyType()){
                break;
            }
            x++;
        }

        Villa new_property = Villa(property.getName(), property.getType(), property.getCategory(), property.getPropertyType(),
                                 property.getLand(), property.getBuilding(), property.getDeposit(), property.getRent(), property.getPrice(),
                                 property.getAddress(), property.getDescription(), property.getPic(), property.getHasDeed(),
                                 is_furnished, is_renew, has_parking, has_storage, has_wallpaper, build, rooms);

        Ad::villas[x] = new_property;
        Ad::ads[w] = Ad(&THIS_USER, new_property);

    } else if (propertyO.getPropertyType() == "دفترکار"){
        // Update Workplace object and associated advertisement
        while (x < Ad::workplaces.size()) {
            if (Ad::workplaces[x].getName() == propertyO.getName() && Ad::workplaces[x].getAddress() == propertyO.getAddress()
                    && Ad::workplaces[x].getType() == propertyO.getType() && Ad::workplaces[x].getCategory() == propertyO.getCategory()
                    && Ad::workplaces[x].getPropertyType() == propertyO.getPropertyType()){
                break;
            }
            x++;
        }

        Workplace new_property = Workplace(property.getName(), property.getType(), property.getCategory(), property.getPropertyType(),
                                 property.getLand(), property.getBuilding(), property.getDeposit(), property.getRent(), property.getPrice(),
                                 property.getAddress(), property.getDescription(), property.getPic(), property.getHasDeed(),
                                 is_renew, has_parking, has_storage, has_wallpaper, build, rooms);

        Ad::workplaces[x] = new_property;
        Ad::ads[w] = Ad(&THIS_USER, new_property);

    } else if (propertyO.getPropertyType() == "مطب") {
        // Update Clinic object and associated advertisement
        while (x < Ad::clinics.size()) {
            if (Ad::clinics[x].getName() == propertyO.getName() && Ad::clinics[x].getAddress() == propertyO.getAddress()
                    && Ad::clinics[x].getType() == propertyO.getType() && Ad::clinics[x].getCategory() == propertyO.getCategory()
                    && Ad::clinics[x].getPropertyType() == propertyO.getPropertyType()){
                break;
            }
            x++;
        }

        Clinic new_property = Clinic(property.getName(), property.getType(), property.getCategory(), property.getPropertyType(),
                                 property.getLand(), property.getBuilding(), property.getDeposit(), property.getRent(), property.getPrice(),
                                 property.getAddress(), property.getDescription(), property.getPic(), property.getHasDeed(),
                                 is_renew, has_parking, has_storage, has_wallpaper, build, rooms);

        Ad::clinics[x] = new_property;
        Ad::ads[w] = Ad(&THIS_USER, new_property);

    } else if (propertyO.getPropertyType() == "مغازه") {
        // Update Shop object and associated advertisement
        while (x < Ad::shops.size()) {
            if (Ad::shops[x].getName() == propertyO.getName() && Ad::shops[x].getAddress() == propertyO.getAddress()
                    && Ad::shops[x].getType() == propertyO.getType() && Ad::shops[x].getCategory() == propertyO.getCategory()
                    && Ad::shops[x].getPropertyType() == propertyO.getPropertyType()){
                break;
            }
            x++;
        }

        Shop new_property = Shop(property.getName(), property.getType(), property.getCategory(), property.getPropertyType(),
                                 property.getLand(), property.getBuilding(), property.getDeposit(), property.getRent(), property.getPrice(),
                                 property.getAddress(), property.getDescription(), property.getPic(), property.getHasDeed(),
                                 is_renew, has_elevator, has_storage, has_wallpaper, build, floor, rooms);

        Ad::shops[x] = new_property;
        Ad::ads[w] = Ad(&THIS_USER, new_property);

    } else if (propertyO.getPropertyType() == "انبار") {
        // Update Storage object and associated advertisement
        while (x < Ad::storages.size()) {
            if (Ad::storages[x].getName() == propertyO.getName() && Ad::storages[x].getAddress() == propertyO.getAddress()
                    && Ad::storages[x].getType() == propertyO.getType() && Ad::storages[x].getCategory() == propertyO.getCategory()
                    && Ad::storages[x].getPropertyType() == propertyO.getPropertyType()){
                break;
            }
            x++;
        }

        Storage new_property = Storage(property.getName(), property.getType(), property.getCategory(), property.getPropertyType(),
                                 property.getLand(), property.getBuilding(), property.getDeposit(), property.getRent(), property.getPrice(),
                                 property.getAddress(), property.getDescription(), property.getPic(), property.getHasDeed(),
                                 is_renew, has_storage, build, rooms);

        Ad::storages[x] = new_property;
        Ad::ads[w] = Ad(&THIS_USER, new_property);

    } else { // کارگاه
        // Update Workshop object and associated advertisement
        while (x < Ad::workshops.size()) {
            if (Ad::workshops[x].getName() == propertyO.getName() && Ad::workshops[x].getAddress() == propertyO.getAddress()
                    && Ad::workshops[x].getType() == propertyO.getType() && Ad::workshops[x].getCategory() == propertyO.getCategory()
                    && Ad::workshops[x].getPropertyType() == propertyO.getPropertyType()){
                break;
            }
            x++;
        }

        Workshop new_property = Workshop(property.getName(), property.getType(), property.getCategory(), property.getPropertyType(),
                                 property.getLand(), property.getBuilding(), property.getDeposit(), property.getRent(), property.getPrice(),
                                 property.getAddress(), property.getDescription(), property.getPic(), property.getHasDeed(),
                                 is_renew, has_storage, build, rooms);

        Ad::workshops[x] = new_property;
        Ad::ads[w] = Ad(&THIS_USER, new_property);

    }

    // Show success message after advertisement update
    show_success_box("آگهی شما ویرایش شد.");
}

void MainWindow::on_pushButton_page_edit_account_clicked() {
    // Set the text of UI labels to display current user information
    ui->label_user_name->setText(QString::fromStdString(THIS_USER.getFullName()));
    ui->label_user_username->setText(QString::fromStdString(THIS_USER.getUsername()));
    ui->label_user_email->setText(QString::fromStdString(THIS_USER.getEmail()));

    // Switch the stacked widget to index 5, presumably the edit account page
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_logout_clicked() {
    // Reset THIS_USER to a default-constructed User object, effectively logging out the user
    THIS_USER = User();

    // Hide the current main window
    this->hide();
    User::logged_in = false;

    // Show the login window to allow a new user login or login again
    loginWindow->show();

    // Save user data to persist any changes made before logout
    save_users();
}

// Function to remove the first word from a string
string remove_first_word(const string& str) {
    size_t pos = str.find(' ');

    if (pos == string::npos)
        return str;

    return str.substr(pos + 1);
}

// Function to get the first word from a string
string get_first_word(const string& str) {
    size_t pos = str.find(' ');

    if (pos == string::npos)
        return str;

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
    std::vector<string> database;
    wstring path_wstring = ExePath();
    string path(path_wstring.begin(), path_wstring.end());
    path.append("\\database.txt");

    string result;
    for (auto user: User::users){
        result = "";

        result.append("username ").append(user.getUsername());
        result.append("\n");
        result.append("password ").append(user.getPassword());
        result.append("\n");
        result.append("name ").append(user.getFullName());
        result.append("\n");
        result.append("email ").append(user.getEmail());
        result.append("\n");

        result.append("END");

        database.push_back(result);
    }

    // Open an output file stream
    std::ofstream output(path);

    // Use an ostream iterator to write the user strings to the file
    std::ostream_iterator<string> output_iterator(output, "\n");
    std::copy(std::begin(database), std::end(database), output_iterator);
}

// Function to load users from a file
void load_users() {
    wstring path_wstring = ExePath();
    string path(path_wstring.begin(), path_wstring.end());
    path.append("\\database.txt");

    std::ifstream input_file(path);
    string line;

    User::users.clear();

    string user_str = "";
    string key;
    string value;
    std::unordered_map<string, string> users;

    // Read the file line by line
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        if (line == "END") {
            User user = User(users["name"], users["username"], users["password"], users["email"]);
            User::users.push_back(user);
        } else {
            key = get_first_word(line);
            value = remove_first_word(line);
            users[key] = value;
        }
    }

    input_file.close();
}

// Function to check if a string is a number
bool is_number(const string& s) {
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void create_some_default_ads() {
    Land land = Land("زمین ۱۲۰ متری", "فروش", "غیرمسکونی", "زمین", "120", "", "", "",
                         "120000000", "شهرکرد", "", "", true);
    Ad new_ad1 = Ad(&User::users[0], land);
    Ad::ads.push_back(new_ad1);

    Garden garden = Garden("باغ زیبا پر درخت", "فروش", "غیرمسکونی", "باغ", "90", "30", "", "",
            "2400000000", "چهارمحال بختیاری، سامان", "ویوی عالی", ":properties/garden.jpg", true, true, false, "1403", "یک");
    Ad new_ad2 = Ad(&User::users[1], garden);
    Ad::ads.push_back(new_ad2);

    Clinic clinic = Clinic("اجاره مطب دندان پزشکی", "اجاره", "اداری", "مطب", "", "85", "250000000", "40000000",
           "", "مشهد، خیابان زائران", "داخل مجتمع پزشکان میباشد.", ":properties/clinic.jpg", false, false, true, false, true, "1390", "سه");
    Ad new_ad3 = Ad(&User::users[1], clinic);
    Ad::ads.push_back(new_ad3);

    Villa villa = Villa("خانه ویلایی سه اتاقه", "معاوضه", "مسکونی", "ویلایی", "40", "105", "", "",
           "12400000000", "اصفهان، ملک شهر", "ملک با ملک مشابه در زرین شهر معاوضه میشود.", "", true, false, false, true, true, false, "1400", "سه");
    Ad new_ad4 = Ad(&User::users[2], villa);
    Ad::ads.push_back(new_ad4);

    Shop shop = Shop("اجاره مغازه 50 متری", "اجاره", "تجاری", "مغازه", "", "50", "352000000", "64000000",
           "", "نايين", "به تمیزکار اجاره داده میشود.", ":properties/shop.jpg", true, false, true, true, true, "1401", "اول", "یک");
    Ad new_ad5 = Ad(&User::users[2], shop);
    Ad::ads.push_back(new_ad5);
}
