#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <algorithm>
#include <memory>

class House{
private:
    std::string address;
    double area;
    int price;
public:
    House() : address(""), area(0.0), price(0) {};
    House(const std::string &addr, double ar, int pri) : address(addr), area(ar), price(pri) {}

    void setAddress(const std::string &addr) {address = addr;}
    void setArea(double ar) {area = ar;}
    void setPrice(int pr) {price = pr;}

    friend std::ostream& operator<<(std::ostream& os, const House& hs) {
        os << "Address: " << hs.address << " Size in m²: " << hs.area << " Price: " << hs.price;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, House& hs) {
        std::string line;
        if (std::getline(is, line)) { 
            std::istringstream iss(line);  
            iss >> hs.address >> hs.area >> hs.price;
        }
        return is;
    }

    bool operator<(const House& other) const {
        return (price / area) < (other.price / other.area);
    }

    std::string printAddress() const {
        return address;
    }
};

class Apartment {
private:
    std::shared_ptr<House> housePtr;
    int num;
    int size;
    int rent;

public:
    Apartment(std::shared_ptr<House> house, int num, int size, int rent) : housePtr(house), num(num), size(size), rent(rent) {};

    void printHouseAddrAndNr() const {
        std::cout << "The address of apartment no." << num << " is " << housePtr->printAddress() << std::endl;
    }

    void printAptInfo() const {
        std:: << "Address: " << housePtr->printAddress << std:
    }

    void operator<(const Apartment& other) const {
        if (rent < other.rent) {
            std::cout << "The rent of apartment 1 is lower that the rent of apartment 2." << std::endl;
        } else if (rent == other.rent) {
            std::cout << "The rents are the same." << std::endl;
        } else {
            std::cout << "The rent of 1 is higher than the rent of apartment 2." << std::endl;
        }
    }
};

int main() {
    std::shared_ptr<House> myHouse = std::make_shared<House>("Kuusamakuja 4", 100, 1200);

    Apartment myApartment1(myHouse, 54, 600, 1200);
    myApartment1.printHouseAddrAndNr();

    Apartment myApartment2(myHouse, 54, 600, 1200);
    myApartment2.printHouseAddrAndNr();

    myApartment1 < myApartment2;
    return 0;
}