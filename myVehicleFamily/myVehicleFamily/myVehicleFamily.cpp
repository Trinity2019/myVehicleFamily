// myVehicleFamily.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

class Vehicle
{
public:

    // basic constructor
    Vehicle();

    virtual ~Vehicle() = default;

    virtual void ShowFeatures() = 0;

    // This is just example
    // Can return "Vehicle *" or other smart pointer type pointing to Vehicle
    static std::unique_ptr<Vehicle> getVehicle(std::string vehicleLocation);

protected:
    // Can only be seen by child classes
    std::string get_common_feature(void) { return basic_feature; }

private:
    std::string basic_feature;
};

class Sedan : public Vehicle
{
private:
    std::string my_feature;
public:
    Sedan();
    virtual ~Sedan() = default;
    void ShowFeatures()
    {
        printf("%s\n", (get_common_feature() + my_feature).c_str());
    }
};

class Truck : public Vehicle
{
private:
    std::string my_feature;

public:
    Truck();
    virtual ~Truck() = default;

    void ShowFeatures()
    {
        printf("%s\n", (get_common_feature() + my_feature).c_str());
    }
};

class SUV : public Vehicle
{
private:
    std::string my_feature;

public:
    SUV();
    virtual ~SUV() = default;
    void ShowFeatures()
    {
        printf("%s\n", (get_common_feature() + my_feature).c_str());
    }
};

Vehicle::Vehicle() : basic_feature("I have 4 wheels. ")
{
}

// If there's new vehicle type added, all you need to do is add another vehicle class and then add an "else if" case in this function
std::unique_ptr<Vehicle> Vehicle::getVehicle(std::string vehicleLocation)
{
    std::unique_ptr<Vehicle> p = nullptr;

    if (vehicleLocation == R"(CALIFORNIA)")
    {
        p = std::make_unique<Sedan>();
    }
    else if (vehicleLocation == R"(TEXAS)")
    {
        p = std::make_unique<Truck>();
    }
    else if (vehicleLocation == R"(VIRGINIA)")
    {
        p = std::make_unique<SUV>();
    }

    return p;
}

Sedan::Sedan() : my_feature("Sedan is small, lightweight, fuel economic cars for daily driving needs.")
{
}

SUV::SUV() : my_feature("SUV is for driving over rough terrains. They usually offer all-wheel drive which is beneficial in difficult weathers.")
{
}

Truck::Truck() : my_feature("Truck is larger, usually for tow and haul, as well as flexible.")
{
}


int main()
{
    auto vehicle1 = Vehicle::getVehicle("VIRGINIA");
    auto vehicle2 = Vehicle::getVehicle("CALIFORNIA");
    auto vehicle3 = Vehicle::getVehicle("TEXAS");

    vehicle1->ShowFeatures();
    vehicle2->ShowFeatures();
    vehicle3->ShowFeatures();
    return 0;
}
