#ifndef USER_H
#define USER_H 

#include <string>
#include <vector>

using namespace std;

// User class definition
class User {
private:
    int id;
    string full_name;
    string username;
    string password;
    string email;

public:
    // Static members of the User class
    static bool logged_in; // Indicates if any user is currently logged in
    static User logged;            // Represents the currently logged-in user
    static vector<User> users;     // Vector to store all user instances

    // Constructors
    User(); // Default constructor
    User(string full_name, string username, string password, string email); // Parameterized constructor

    // Getter methods
   int getId();             // Returns the user ID
   string getFullName();    // Returns the user's full name
   string getUsername();    // Returns the user's username
   string getPassword();    // Returns the user's password
   string getEmail();       // Returns the user's email address

   // Utility method
   string getDetails();     // Returns a string with user's details
};

#endif // USER_H
