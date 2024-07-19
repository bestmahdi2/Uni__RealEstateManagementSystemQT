#include "user.h"

#include <string>
#include <vector>

using namespace std;

// Static member initialization
bool User::logged_in = false;  // Indicates if any user is currently logged in
User User::logged;             // Represents the currently logged-in user
vector<User> User::users;      // Vector to store all user instances

// Default constructor (not used explicitly in your current implementation)
User::User() {
    // Default constructor body (empty in this case)
}

// Parameterized constructor to initialize user with details
User::User(string full_name, string username, string password, string email) {
    this->email = email;
    this->full_name = full_name;
    this->username = username;
    this->password = password;
    // You might want to assign a unique ID here if needed
}

// Getter method to retrieve the user's ID
int User::getId() {
    return this->id;  // Assuming id is initialized elsewhere in your application
}

// Getter method to retrieve the user's full name
string User::getFullName() {
    return this->full_name;
}

// Getter method to retrieve the user's username
string User::getUsername() {
    return this->username;
}

// Getter method to retrieve the user's password
string User::getPassword() {
    return this->password;
}

// Getter method to retrieve the user's email address
string User::getEmail() {
    return this->email;
}

// Method to generate and return user details as a string
string User::getDetails() {
    string str1 = "نام فروشنده: ";     // Label for full name
    string str2 = "ایمیل فروشنده: ";  // Label for email

    // Concatenate full name and email with appropriate labels
    str1.append(getFullName()).append(" - ").append(str2).append(getEmail());

    return str1;  // Return the concatenated string
}
