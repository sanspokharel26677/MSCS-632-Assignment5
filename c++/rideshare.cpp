/*
===============================================================================
Program: Ride Sharing System (C++)
Author: Sandesh Pokharel
Course: Advanced Programming Languages

Description:
This program implements a Ride Sharing System in C++ that demonstrates key 
Object-Oriented Programming principles: Encapsulation, Inheritance, and Polymorphism.
The system includes base and derived ride classes, along with Driver and Rider classes. 
Each component is carefully documented, and comments are used extensively to ensure 
clarity and traceability of requirements.
===============================================================================
*/

#include <iostream>
#include <vector>
#include <memory>  // For smart pointers
using namespace std;

// ============================== Requirement 1 ===============================
// Base Ride class representing a generic ride.
class Ride {
protected:
    string rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;

public:
    // Constructor
    Ride(string id, string pickup, string dropoff, double dist)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {}

    // Virtual destructor for proper cleanup of derived objects
    virtual ~Ride() {}

    // Virtual method to calculate fare (to be overridden)
    virtual double fare() const {
        return distance * 1.0; // Base rate, overridden by derived classes
    }

    // Virtual method to display ride details
    virtual void rideDetails() const {
        cout << "Ride ID: " << rideID << endl;
        cout << "Pickup: " << pickupLocation << endl;
        cout << "Dropoff: " << dropoffLocation << endl;
        cout << "Distance: " << distance << " miles" << endl;
        cout << "Fare: $" << fare() << endl;
    }
};

// ============================== Requirement 2 ===============================
// Derived class for Standard Rides
class StandardRide : public Ride {
public:
    StandardRide(string id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    // Overriding fare method for standard ride
    double fare() const override {
        return distance * 1.5; // $1.5 per mile
    }

    // Override rideDetails to add label
    void rideDetails() const override {
        cout << "Standard Ride" << endl;
        Ride::rideDetails();
        cout << "-------------------------" << endl;
    }
};

// Derived class for Premium Rides
class PremiumRide : public Ride {
public:
    PremiumRide(string id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    // Overriding fare method for premium ride
    double fare() const override {
        return distance * 2.5; // $2.5 per mile
    }

    // Override rideDetails to add label
    void rideDetails() const override {
        cout << "Premium Ride" << endl;
        Ride::rideDetails();
        cout << "-------------------------" << endl;
    }
};

// ============================== Requirement 3 ===============================
// Class representing a Driver
class Driver {
private:
    string driverID;
    string name;
    double rating;
    vector<shared_ptr<Ride>> assignedRides; // Encapsulated ride list

public:
    // Constructor
    Driver(string id, string driverName, double driverRating)
        : driverID(id), name(driverName), rating(driverRating) {}

    // Add ride to driver's assigned ride list
    void addRide(shared_ptr<Ride> ride) {
        assignedRides.push_back(ride);
    }

    // Display driver info
    void getDriverInfo() const {
        cout << "\nDriver ID: " << driverID << ", Name: " << name << ", Rating: " << rating << endl;
        cout << "Completed Rides:" << endl;
        for (const auto& ride : assignedRides) {
            ride->rideDetails();
        }
    }
};

// ============================== Requirement 4 ===============================
// Class representing a Rider
class Rider {
private:
    string riderID;
    string name;
    vector<shared_ptr<Ride>> requestedRides; // Encapsulated ride list

public:
    // Constructor
    Rider(string id, string riderName)
        : riderID(id), name(riderName) {}

    // Request a ride
    void requestRide(shared_ptr<Ride> ride) {
        requestedRides.push_back(ride);
    }

    // View ride history
    void viewRides() const {
        cout << "\nRider ID: " << riderID << ", Name: " << name << endl;
        cout << "Requested Rides:" << endl;
        for (const auto& ride : requestedRides) {
            ride->rideDetails();
        }
    }
};

// ============================== Requirement 5 ===============================
int main() {
    // Demonstrating polymorphism by storing different ride types in a list
    vector<shared_ptr<Ride>> rideList;

    // Creating various rides (Standard and Premium)
    shared_ptr<Ride> ride1 = make_shared<StandardRide>("RIDE001", "Downtown", "Airport", 10);
    shared_ptr<Ride> ride2 = make_shared<PremiumRide>("RIDE002", "Station", "Mall", 7.5);

    rideList.push_back(ride1);
    rideList.push_back(ride2);

    // Demonstrate polymorphic behavior
    cout << "\n=== All Rides (Polymorphism Demo) ===" << endl;
    for (const auto& ride : rideList) {
        ride->rideDetails();
    }

    // Create driver and assign rides
    Driver driver1("D001", "Alice", 4.8);
    driver1.addRide(ride1);
    driver1.addRide(ride2);
    driver1.getDriverInfo();

    // Create rider and request rides
    Rider rider1("U001", "Bob");
    rider1.requestRide(ride1);
    rider1.requestRide(ride2);
    rider1.viewRides();

    return 0;
}
