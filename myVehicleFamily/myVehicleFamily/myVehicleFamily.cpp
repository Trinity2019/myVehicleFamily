// myVehicleFamily.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

class Vehicle
{
public:
    // no default ctor
    // good programming habit in case of confusing defined ctor with default ctor
    Vehicle() = delete;

    // basic constructor.
    Vehicle(const std::string& vehicleLocation, const std::string& vehicleName);

    virtual ~Vehicle() = default;

    virtual void ShowFeatures() = 0;

    // This is just example
    // Can return "Vehicle *" or other smart pointer type pointing to Vehicle
    static std::unique_ptr<Vehicle> GetVehicle(const std::string& vehicleLocation);

protected:
    // Can only be accessed by child classes
    std::string GetCommonFeature(void) { return m_commonFeature; }
    std::string GetVehicleLocation(void) { return m_vehicleLocation; }
    std::string GetVehicleName(void) { return m_vehicleName; }

private:
    // common fields for all vehicles.
    std::string m_commonFeature;
    std::string m_vehicleLocation;
    std::string m_vehicleName;
};

class Sedan : public Vehicle
{
private:
    std::string m_myFeature;
public:
    // no default ctor
    Sedan() = delete;

    Sedan(const std::string& vehicleLocation);
    virtual ~Sedan() = default;
    void ShowFeatures()
    {
        printf("%s\n", ("I am " + GetVehicleName() + " in " + GetVehicleLocation() + ". " + GetCommonFeature() + m_myFeature).c_str());
    }
};

class Truck : public Vehicle
{
private:
    std::string m_myFeature;

public:
    // no default ctor
    Truck() = delete;

    Truck(const std::string& vehicleLocation);
    virtual ~Truck() = default;

    void ShowFeatures()
    {
        printf("%s\n", ("I am " + GetVehicleName() + " in " + GetVehicleLocation() + ". " + GetCommonFeature() + m_myFeature).c_str());
    }
};

class SUV : public Vehicle
{
private:
    std::string m_myFeature;

public:
    // no default ctor
    SUV() = delete;

    SUV(const std::string& vehicleLocation);
    virtual ~SUV() = default;
    void ShowFeatures()
    {
        printf("%s\n", ("I am " + GetVehicleName() + " in " + GetVehicleLocation() + ". " + GetCommonFeature() + m_myFeature).c_str());
    }
};

Vehicle::Vehicle(const std::string& vehicleLocation, const std::string& vehicleName) : m_vehicleLocation(vehicleLocation), m_vehicleName(vehicleName), m_commonFeature("I have 4 wheels. ")
{
}

// If there's new vehicle type added, all you need to do is add another vehicle class and then add an "else if" case in this function
std::unique_ptr<Vehicle> Vehicle::GetVehicle(const std::string& vehicleLocation)
{
    std::unique_ptr<Vehicle> p = nullptr;

    if (vehicleLocation == R"(CALIFORNIA)")
    {
        p = std::make_unique<Sedan>(vehicleLocation);
    }
    else if (vehicleLocation == R"(TEXAS)")
    {
        p = std::make_unique<Truck>(vehicleLocation);
    }
    else if (vehicleLocation == R"(VIRGINIA)")
    {
        p = std::make_unique<SUV>(vehicleLocation);
    }

    return p;
}

Sedan::Sedan(const std::string& vehicleLocation) : Vehicle(vehicleLocation, "Sedan"), m_myFeature("Sedan is small, lightweight, fuel economic cars for daily driving needs.")
{
}

SUV::SUV(const std::string& vehicleLocation) : Vehicle(vehicleLocation, "SUV"), m_myFeature("SUV is for driving over rough terrains. They usually offer all-wheel drive which is beneficial in difficult weathers.")
{
}

Truck::Truck(const std::string& vehicleLocation) : Vehicle(vehicleLocation, "Truck"), m_myFeature("Truck is larger, usually for tow and haul, as well as flexible.")
{
}


int main()
{
    auto vehicle1 = Vehicle::GetVehicle("VIRGINIA");
    auto vehicle2 = Vehicle::GetVehicle("CALIFORNIA");
    auto vehicle3 = Vehicle::GetVehicle("TEXAS");

    vehicle1->ShowFeatures();
    vehicle2->ShowFeatures();
    vehicle3->ShowFeatures();
    return 0;
}
