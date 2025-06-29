
#ifndef USER_H
#define USER_H
#include <vector>
#include <iostream>

#include "Constants.h"
#include "Console.h"

using namespace std;

class Flight;

class User
{
protected:
    string userID;
    string userName;
    string userEmail;
    string userPassword;
    static int noOfUsers;

public:
    User(string userID, string userName, string userEmail, string userPassword);

    bool verifyCredential(const string &email, const string &password);

    virtual void userPanel(vector<Flight> &allFlights) = 0;

    void setUserName(const string &name);
    void setUserEmail(const string &email);
    void setUserPassword(const string &password);

    string getUserID() const;
    string getUserName() const;
    string getUserEmail() const;
    string getUserPassword() const;
};

class Admin : public User
{
private:
    static int noOfAdmins;

public:
    Admin();
    Admin(string userID, string userName, string userEmail, string userPassword);

    void editInformation();

    void addNewFlight(vector<Flight> &allflights);

    void removeFlight(vector<Flight> &allflights);

    void listAllFlights(vector<Flight> &allflights);

    void listAllCustomers(vector<Flight> &allFlights);

    void userPanel(vector<Flight> &allFlights) override;
};

class Customer : public User
{
private:
    static int noOfCustomers;

    vector<Flight> flightsBookedByCustomer;
    int noOfBookedFlights = flightsBookedByCustomer.size();

public:
    Customer(string userID = "", string userName = "", string userEmail = "", string userPassword = "");
    const vector<Flight> &getFlightsBooked() const;
    // Adds a booked flight to the customer's list
    void setBookedFlight(const Flight &f);

    void editInformation();

    void displayEnhancedData();

    void bookNewFlightEnhanced(vector<Flight> &allFlights);

    void removeFlightEnhanced();

    void userPanel(vector<Flight> &allFlights) override;

};

#endif // USER_H