#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <string>
#include <MainProgram.h>

class tools
{
public:
    static std::vector<std::string> users;
    static vector<User> users;
    static vector<Property *> properties;

    static void add_user(const std::string& user);
};

#endif // TOOLS_H

