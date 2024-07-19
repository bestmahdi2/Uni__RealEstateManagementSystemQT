#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <MainProgram.h>

using namespace std;

User User::USER = User();
int User::ID = 1;

// User class constructor definitions
User::User(){
    this->id = 0;
}

User::User(string username, string password) {
    this->id = User::ID++;
    this->username = username;
    this->password = password;
}

User::User(string username, string password, string name, string fname, string phone, string email) {
    this->id = User::ID++;
    this->username = username;
    this->password = password;
    this->name = name;
    this->fname = fname;
    this->phone = phone;
    this->email = email;
}

// Save user information to a formatted string
string User::save_string(){
    string result = "";

    result.append("id ").append(to_string(this->id));
    result.append("\n");
    result.append("username ").append(this->username);
    result.append("\n");
    result.append("password ").append(this->password);
    result.append("\n");
    result.append("name ").append(this->name);
    result.append("\n");
    result.append("fname ").append(this->fname);
    result.append("\n");
    result.append("phone ").append(this->phone);
    result.append("\n");
    result.append("email ").append(this->email);
    result.append("\n");
    result.append("role ").append(this->role);
    result.append("\n");

    result.append("------");
    return result;
}

// Static member initialization
std::vector<User> Tools::users;
std::vector<Property> Tools::properties;

// Validate username format
bool Tools::is_valid_username(const std::string& username) {
    for (char c : username) {
        if (c < 0 || c > 127) {
            return false;
        }
    }
    return true;
}

// Validate password length
bool Tools::is_valid_password(const std::string& password) {
    return password.length() >= 8;
}

// Validate email format
bool Tools::is_valid_email(const std::string& email) {
    const std::regex pattern(R"((\w+)(\.{1}\w+)*@(\w+)(\.\w+)+)");
    return std::regex_match(email, pattern) or email == "";
}

// Validate phone number format
bool Tools::is_valid_phone(const std::string& phone) {
    const std::regex pattern(R"(^\+98\d{10}$)");
    return std::regex_match(phone, pattern) or phone == "";
}

// Find user index by username and password
int find_user_by_username_password(string username, string password) {
    for (size_t i = 0; i < Tools::users.size(); ++i) {
        if (Tools::users[i].username == username && Tools::users[i].password == password) {
            return i; // Return the index
        }
    }
    return -1; // Return -1 if the user is not found
}

// Sign in user and return index or -1 if not found
int Tools::user_signin(string username,string password) {
    int user_index = find_user_by_username_password(username, password);

    if (user_index > -1){
        return user_index;
    }

    User::USER.note = "نام کاربری یا رمز عبور اشتباه است.";
    return -1;
}

// Register a new user and return feedback
User Tools::user_signup(string username, string password1, string password2, string name, string fname, string phone, string email){
    User new_user =User(username, password1, name, fname, phone, email);

    for (auto &user: Tools::users) {
        if (user.username == new_user.username) {
            new_user.note = "این کاربر در سیستم وجود دارد.";
            return new_user;
        }
    }

    if (password1 != password2){
        new_user.note = "رمز عبور با تکرار آن تطابق ندارد.";
        return new_user;
    }

    if (!Tools::is_valid_username(username)){
        new_user.note = "نام کاربری غیرمجاز است.";
        return new_user;
    }

    if (!Tools::is_valid_password(password1)){
        new_user.note = "رمز عبور باید حداقل 8 کاراکتر باشد.";
        return new_user;
    }

    if (!Tools::is_valid_phone(phone)){
        new_user.note = "شماره اشتباه است. (+989xxxxxxxxx)";
        return new_user;
    }

    if (!Tools::is_valid_email(email)){
        new_user.note = "آدرس ایمیل اشتباه است.";
        return new_user;
    }

    new_user.note = "ثبت نام با موفقیت انجام شد.";
    new_user.operation_success = true;
    Tools::users.push_back(new_user);
    return new_user;
    saveUsers();
}

// Edit user profile information
void Tools::user_edit(User *user, string password1, string password2, string name, string fname, string phone, string email){
    user->operation_success = false;

    if (password1 != password2){
        user->note = "رمز عبور با تکرار آن تطابق ندارد.";
        return;
    }

    if (!Tools::is_valid_password(password1)){
        user->note = "رمز عبور باید حداقل 8 کاراکتر باشد.";
        return;
    }

    if (!Tools::is_valid_phone(phone)){
        user->note = "شماره اشتباه است. (+989xxxxxxxxx)";
        return;
    }

    if (!Tools::is_valid_email(email)){
        user->note = "آدرس ایمیل اشتباه است.";
        return;
    }

    user->password = password1;
    user->name = name;
    user->fname = fname;
    user->phone = phone;
    user->email = email;
    user->note = "ویرایش با موفقیت انجام شد.";
    user->operation_success = true;
}
