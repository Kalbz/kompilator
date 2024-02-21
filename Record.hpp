#ifndef RECORD_HPP
#define RECORD_HPP

#include <iostream>
#include <string>

class Record
{
private:
    std::string id;
    std::string type;

public:
    Record(std::string id, std::string type)
    {
        this->id = id;
        this->type = type;
    }
    Record()
    {
        this->id = "uninitialised";
        this->type = "uninitialised";
    }

    std::string getId()
    {
        return this->id;
    }

    std::string getType()
    {
        return this->type;
    }

    void setId(std::string id)
    {
        this->id = id;
    }

    void setType(std::string type)
    {
        this->type = type;
    }

    void printRecord()
    {
        std::cout << "ID: " << this->id << " Type: " << this->type << std::endl;
    }
};
#endif