#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> //find_if
#include <string>
#include <ctime>    //time
#include <cstring> //string
#include <cstdlib>
#include <sstream>
#include <functional>
#include <ctype.h>
#include < stdio.h >
#include <cmath>
#include <cctype> //cin. 
#include <limits> //

using namespace std;

class Gift {
public:

    Gift() { GiftID = ""; GiftDescription = ""; GiftPrice = 0; GiftPoint = 0; }

    void setGift(string _id, string _name, int _price, int _point) {
        GiftID = _id;
        GiftDescription = _name;
        GiftPrice = _price;
        GiftPoint = _point;
    }

    string getGiftID() {
        return GiftID;
    }

    string getGiftDescription() {
        return GiftDescription;
    }

    int getGiftPrice() {
        return GiftPrice;
    }

    int getGiftPoint() {
        return GiftPoint;
    }

private:
    string GiftID;
    string GiftDescription;
    int GiftPrice;
    int GiftPoint;

};

class Customer {
public:
    int Points;
    Customer() { CustomerID = ""; Rank = ""; Points = 0; }

    void setCustomer(string _id, string _rank, int _points) {

        CustomerID = _id;
        Rank = _rank;
        Points = _points;
    }

    string getCustomerID() const{
        return CustomerID;
    }

    string getRank() {
        return Rank;
    }

    int getPoints() {
        return Points;
    }

private:
    string CustomerID;
    string Rank;
};

//Sorted in alphabetical order
bool compareCustomerID(const Customer& a, const Customer& b) {
    return a.getCustomerID() < b.getCustomerID();
}

//Sorted in Point -- R4
bool compareGiftPoint(Gift& a, Gift& b) {
    return a.getGiftPoint() < b.getGiftPoint();
}

//Add Transaction Class -- R5
class addTransaction {
public:
    string customerID;
    int points;
    float moneySpent;
    addTransaction() { customerID = ""; points = 0; moneySpent = 0; }

    void setaddTransaction(string _id, int _points, float _moneySpent) {

        customerID = _id;
        points = _points;
        moneySpent = _moneySpent;
    }

    string getcustomerID() {
        return customerID;
    }
    int getpoint() {
        return points;
    }
    float getmoneySpent() {
        return moneySpent;
    }
};

//Redeem Transaction Class -- R5
class redeemTransaction {
public:
    string customerID;
    string rgiftid;
    string giftd;
    double extramoney;
    int ccpointsr;
    redeemTransaction() { customerID = ""; rgiftid = ""; giftd = ""; extramoney = 0.0; ccpointsr = 0; }

    void setredeemTransaction(string _id, string _rgiftid, string _giftd, double _extramoney, int _ccpointsr) {

        customerID = _id;
        rgiftid = _rgiftid;
        giftd = _giftd;
        extramoney = _extramoney;
        ccpointsr = _ccpointsr;
    }

    string getcustomerID() {
        return customerID;
    }
    string getrgiftid() {
        return rgiftid;
    }
    string getgiftd() {
        return giftd;
    }
    double getextramoney() {
        return extramoney;
    }
    int getccpointsr() {
        return ccpointsr;
    }
};

//Modify Transaction Class -- R5
class modifyTransaction {
public:
    string customerID;
    string type;
    int mchange;
    modifyTransaction() { customerID = ""; type = ""; mchange = 0; }

    void setmodifyTransaction(string _id, string _type, int _mchange) {

        customerID = _id;
        type = _type;
        mchange = _mchange;
    }

    string getcustomerID() {
        return customerID;
    }
    string gettype() {
        return type;
    }
    int getmchange() {
        return mchange;
    }
};

//Original Point Class -- R5
class oiriginalPoint {
public:
    int Points;
    oiriginalPoint() { CustomerID = ""; Points = 0; }

    void setoiriginalPoint(string _id, int _points) {

        CustomerID = _id;
        Points = _points;
    }

    string getCustomerID() {
        return CustomerID;
    }

    int getPoints() {
        return Points;
    }

private:
    string CustomerID;
};

// //Add Add Point Record -- R5
void recordadd(string customerID, int change, float money, vector<addTransaction>& vaddTransaction) {
    addTransaction addtransaction;

    addtransaction.setaddTransaction(customerID, change, money);
    vaddTransaction.push_back(addtransaction);
}

// //Add Redeem Record -- R5
void recordredeem(string customerID, string rgiftid, double extramoney, int ccpointsr, vector<redeemTransaction>& vredeemTransaction, vector<Gift>& vGift) {
    redeemTransaction redeemtransaction;
    string giftd;
    for (int i = 0; i < vGift.size(); i++) {
        if (vGift[i].getGiftID() == rgiftid)
            giftd = vGift[i].getGiftDescription();
    }
    redeemtransaction.setredeemTransaction(customerID, rgiftid, giftd, extramoney, ccpointsr);
    vredeemTransaction.push_back(redeemtransaction);
}

// //Add Add Modify Record -- R5
void recordmodify(string customerID, string type, int mchange, vector<modifyTransaction>& vmodifyTransaction) {
    modifyTransaction modifytransaction;

    modifytransaction.setmodifyTransaction(customerID, type, mchange);
    vmodifyTransaction.push_back(modifytransaction);
}

// //Add Original Point Record -- R5
void recordoiriginalpoint(string CustomerID, int points, vector<oiriginalPoint>& voiriginalPoint) {
    oiriginalPoint oiriginalpoint;

    oiriginalpoint.setoiriginalPoint(CustomerID, points);
    voiriginalPoint.push_back(oiriginalpoint);
}

//Display Main Menu -- R0
void displayMainMenu() {
    cout << "\n\n"
        << "*** Main Menu ***\n"
        << "[1] Load Starting Data\n"
        << "[2] Show Records\n"
        << "[3] Edit Customers\n"
        << "[4] Enter Customer View\n"
        << "[5] Show Transaction History\n"
        << "[6] Credits and Exit\n"
        << "*****************\n"
        << "Option (1 - 6): ";
}

//load starting data -- R1
void loadStartingData(vector<Gift>& vGift, vector<Customer>& vCustomer) {
    Gift gift;
    Customer customer;

    //Gift data
    gift.setGift("A01", "LG Internet TV", 3900, 19000);
    vGift.push_back(gift);
    gift.setGift("A02", "Poinerr Hifi Set", 2400, 11500);
    vGift.push_back(gift);
    gift.setGift("A03", "Sony DVD Player", 400, 2000);
    vGift.push_back(gift);
    gift.setGift("B01", "Healthy Air Fryer", 1500, 7300);
    vGift.push_back(gift);
    gift.setGift("B02", "Tefal Microware Oven", 480, 2400);
    vGift.push_back(gift);
    gift.setGift("B03", "Famous Coffee Maker", 1800, 8800);
    vGift.push_back(gift);
    gift.setGift("B04", "Smart Rice Cooker", 600, 2900);
    vGift.push_back(gift);
    gift.setGift("B05", "TechCook Toaster Oven", 450, 2250);
    vGift.push_back(gift);
    gift.setGift("C01", "Wellcome $50 Coupon", 50, 250);
    vGift.push_back(gift);
    gift.setGift("C02", "Mannings $50 Coupon", 50, 250);
    vGift.push_back(gift);
    gift.setGift("C03", "Carol Restaurant $100 Coupon", 100, 500);
    vGift.push_back(gift);
    gift.setGift("C04", "Shell $200 Coupon", 100, 500);
    vGift.push_back(gift);
    gift.setGift("D01", "Clever Headset", 350, 1750);
    vGift.push_back(gift);
    gift.setGift("D02", "HP Optic Mouse", 250, 1250);
    vGift.push_back(gift);
    gift.setGift("D03", "Stylish Bluetooth Speaker", 800, 3900);
    vGift.push_back(gift);

    //customer data
    customer.setCustomer("Tommy2015", "B", 8500);
    vCustomer.push_back(customer);
    customer.setCustomer("DavidChan", "B", 22800);
    vCustomer.push_back(customer);
    customer.setCustomer("Luna123", "B", 650);
    vCustomer.push_back(customer);
    customer.setCustomer("TigerMan", "B", 14000);
    vCustomer.push_back(customer);
    customer.setCustomer("Max5678", "S", 2580);
    vCustomer.push_back(customer);
    customer.setCustomer("Neo2000", "S", 8000);
    vCustomer.push_back(customer);
    customer.setCustomer("CCTang", "S", 33554);
    vCustomer.push_back(customer);
    customer.setCustomer("EchoWong", "G", 8650);
    vCustomer.push_back(customer);
    customer.setCustomer("Rubychow", "G", 28000);
    vCustomer.push_back(customer);
    customer.setCustomer("Ivy2023", "G", 12340);
    vCustomer.push_back(customer);
}

//Show Records -- R2
void displayData(vector<Gift>& vGift, vector<Customer>& vCustomer) {
    //show gift record
    cout << noshowpos << left;
    cout << "Gift records: " << endl;
    cout << setw(10) << "Gift ID" << setw(35) << "Gift Descriptiont" << setw(15) << "Price(HKD)" << setw(10) << "Points Required" << endl;
    for (auto it = vGift.begin(); it != vGift.end(); ++it) {
        cout << setw(10) << it->getGiftID() << setw(35) << it->getGiftDescription() << setw(15) << it->getGiftPrice() << setw(10) << it->getGiftPoint() << endl;
    }

    cout << "\n\n";

    //sorted in alphabetical order based on the ID values
    sort(vCustomer.begin(), vCustomer.end(), compareCustomerID);

    //show customer record
    cout << "Customer records: " << endl;
    cout << setw(15) << "Customer ID" << setw(10) << "Rank" << setw(10) << "Points Balance\n";
    for (auto it = vCustomer.begin(); it != vCustomer.end(); ++it) {
        cout << setw(15) << it->getCustomerID() << setw(10) << it->getRank() << setw(10) << it->getPoints() << endl;
    }
    cout << "\n\n\n";
}


//Displays the information of the delete customer -- R3
void displayCustomerInfo(Customer& vCustomer) {
    cout << "\n\n";
    cout << noshowpos << left;
    cout << "Customer records: " << endl;
    cout << setw(15) << "Customer ID" << setw(10) << "Rank" << setw(10) << "Points Balance\n";
    cout << setw(15) << vCustomer.getCustomerID() << setw(10) << vCustomer.getRank() << setw(10) << vCustomer.getPoints() << endl;
    cout << "\n";
}

//Function of delete customer -- R3
void deleteCustomer(vector<Customer>& vCustomer, const string& customerID, vector<oiriginalPoint>& voiriginalPoint) {
    string choice;

    while (true) {
        //confirmation on the delete operation
        cout << "Are you sure you want to delete this customer? (Yes/No): ";
        cin >> choice;

        //if yes delete, no don't delete
        if (choice == "Yes" || choice == "yes") {
            //find the customer
            auto it = find_if(vCustomer.begin(), vCustomer.end(), [&](const Customer& c) {
                return c.getCustomerID() == customerID;
                });

            //delete it
            if (it != vCustomer.end()) {
                vCustomer.erase(it);
            }

            cout << "Customer deleted.";
            break;
        }
        else if (choice == "No" || choice == "no") {

            cout << "Customer deletion canceled.\n";
            break;
        }
        else {
            cout << "Input error! Please enter 'Yes' or 'No'.\n";
        }
    }
}

//Check the date format -- R3
bool isValidDateFormat(const string& inputDate) {
    // Check if the date has the format DD/MM/YYYY
    if (inputDate.length() != 10)
        return false;

    if (inputDate[2] != '/' || inputDate[5] != '/')
        return false;

    // Check if the day, month, and year components are numeric
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5)
            continue;

        if (!isdigit(inputDate[i]))
            return false;
    }

    return true;
}

//check the date is it correct -- R3
bool isValidDate2(const string& inputDate) {
    //Find the input day month year
    int inputDay = 0, inputMonth = 0, inputYear = 0;
    if (sscanf(inputDate.c_str(), "%d/%d/%d", &inputDay, &inputMonth, &inputYear) != 3) {
        return false;
    }

    //Cheak the day, month, year are resonable
    bool leap, valid;
    leap = (inputYear % 4 == 0 && inputYear % 100 != 0) || inputYear % 400 == 0;

    if (leap && inputMonth == 2)
        valid = inputDay <= 29 && inputDay > 0 && inputMonth <= 12 && inputMonth > 0;
    else if (!leap && inputMonth == 2)
        valid = inputDay <= 28 && inputDay > 0 && inputMonth <= 12 && inputMonth > 0;
    else if (inputMonth != 2 && inputMonth == 1 || inputMonth == 3 || inputMonth == 5 || inputMonth == 7 || inputMonth == 8 || inputMonth == 10 || inputMonth == 12)
        valid = inputDay <= 31 && inputDay > 0 && inputMonth <= 12 && inputMonth > 0;
    else if (inputMonth != 2 && inputMonth == 4 || inputMonth == 6 || inputMonth == 9 || inputMonth == 11)
        valid = inputDay <= 30 && inputDay > 0 && inputMonth <= 12 && inputMonth > 0;
    else valid = 0;

    if (valid)
        return true;
    else
        return false;

}

// Cheak date -- R3
bool isValidDate(const string& inputDate) {
    //Find current date
    time_t currentTime = time(nullptr);
    tm* currentDate = localtime(&currentTime);
    int currentDay = currentDate->tm_mday;
    int currentMonth = currentDate->tm_mon + 1;
    int currentYear = currentDate->tm_year + 1900;

    //Find the input day month year
    int inputDay = 0, inputMonth = 0, inputYear = 0;
    if (sscanf(inputDate.c_str(), "%d/%d/%d", &inputDay, &inputMonth, &inputYear) != 3) {
        return false;
    }

    //check the date
    if (inputYear > currentYear)
        return false;
    else if (inputYear < currentYear)
        return true; // Enter date is earlier than today
    else {
        if (inputMonth > currentMonth)
            return false;
        else if (inputMonth < currentMonth)
            return true; // Enter date is earlier than today
        else {
            if (inputDay > currentDay)
                return false;
            else
                return true; // Enter date is earlier than or equal to today
        }
    }
}

//Check the rank -- R3
string getMembershipLevel(const string& inputDate) {
    //Find current date
    time_t currentTime = time(nullptr);
    tm* currentDate = localtime(&currentTime);
    int currentYear = currentDate->tm_year + 1900;
    int currentMonth = currentDate->tm_mon + 1;
    int currentDay = currentDate->tm_mday;

    //Find the input day month year
    int inputDay = 0, inputMonth = 0, inputYear = 0;
    if (sscanf(inputDate.c_str(), "%d/%d/%d", &inputDay, &inputMonth, &inputYear) != 3) {
        return "";
    }

    //Calculate the number of months of membership
    int membershipMonths = (currentYear - inputYear) * 12 + currentMonth - inputMonth;

    //Find the rank and return it
    if (membershipMonths >= 12)
        return "G";
    else if (membershipMonths >= 6)
        return "S";
    else
        return "B";
}

//Check invalid points input -- R3
bool isValidPoints(int points) {
    return (points >= 0 && points <= 9999999999);
}

//Function of add customer -- R3
void addCustomer(vector<Customer>& vCustomer, const string& customerID, vector<oiriginalPoint>& voiriginalPoint) {
    string rank;
    int points;
    int retryCount = 0;

    while (retryCount < 3) {
        string memberDate;
        cout << "Enter the date the customer became a member (DD/MM/YYYY): ";
        cin >> memberDate;

        if (!isValidDateFormat(memberDate)) {
            cout << "Invalid date format. Please enter the date in the format DD/MM/YYYY.\n";
            retryCount++;
            continue;
        }

        if (!isValidDate2(memberDate)) {
            cout << "Invalid date format. Please enter the date in the format DD/MM/YYYY.\n";
            retryCount++;
            continue;
        }

        if (!isValidDate(memberDate)) {
            cout << "Invalid date. Please enter a valid past date.\n";
            retryCount++;
            continue;
        }

        rank = getMembershipLevel(memberDate);

        bool ValidPoints = false;
        while (!ValidPoints) {
            cout << "Enter the points balance for the customer: ";
            cin >> points;

            if (!isValidPoints(points)) {
                cout << "Invalid points value. Please enter again.\n";
                retryCount++;
                if (retryCount >= 3) {
                    break;
                }
            }
            else {
                ValidPoints = true;
            }
        }

        if (retryCount >= 3) {
            cout << "Exceeded the maximum number of retries. Returning to the Main Menu.\n";
            return;
        }

        Customer newCustomer;
        newCustomer.setCustomer(customerID, rank, points);
        vCustomer.push_back(newCustomer);

        cout << "Customer added successfully.\n";
        //R5 Get Original Point
        for (auto it = vCustomer.begin(); it != vCustomer.end(); ++it) {
            string CustomerID;
            int points;
            CustomerID = it->getCustomerID();
            points = it->getPoints();
            recordoiriginalpoint(CustomerID, points, voiriginalPoint);
        }
        return;
    }

    cout << "Exceeded the maximum number of retries. Returning to the Main Menu.\n";
}

//Search Customer ID Function  ---- R4
string searchCustomerID(string cid, vector<Customer>& vCustomer) {
    string target = cid;
    string customerID;
    for (int i = 0; i < vCustomer.size(); i++) {
        if (vCustomer[i].getCustomerID() == target)
            customerID = vCustomer[i].getCustomerID();
    }
    return customerID;
}

//Display gift record Function  ---- R4
void displayGift(string customerID, char categories, vector<Customer>& vCustomer, vector<Gift>& vGift) {
    string crank;
    int customerpoints = 0;
    double discount;
    string useccpoints;  // only use cc pooints to redeem - Yes/No
    int cheakcategories = 1;
    cout << setprecision(0) << fixed;
    for (int i = 0; i < vCustomer.size(); i++) {
        if (vCustomer[i].getCustomerID() == customerID)
            crank = vCustomer[i].getRank();
    }
    for (int i = 0; i < vCustomer.size(); i++) {
        if (vCustomer[i].getCustomerID() == customerID) {
            customerpoints = vCustomer[i].getPoints();
        }
    }

    if (crank == "G")
        discount = 0.9;
    else if (crank == "S")
        discount = 0.95;
    else
        discount = 1;

    cout << setw(10) << "Gift ID" << setw(35) << "Gift Descriptiont" << setw(15) << "Price(HKD)" << setw(25) << "Points Required" << setw(25) << "Only Use CC Points" << endl;
    for (auto it = vGift.begin(); it != vGift.end(); ++it) {
        if (it->getGiftID()[0] == categories && categories == 'A' || categories == 'B') {
            cheakcategories = 0;
        }
    }
    //sorted point
    sort(vGift.begin(), vGift.end(), compareGiftPoint);

    for (auto it = vGift.begin(); it != vGift.end(); ++it) {
        if (it->getGiftID()[0] == categories) {
            if (round(it->getGiftPoint() * discount) <= customerpoints) {
                useccpoints = "Yes";
            }
            else {
                useccpoints = "No";
            }
            cout << setw(10) << it->getGiftID() << setw(35) << it->getGiftDescription() << setw(15) << it->getGiftPrice() << setw(25) << round(it->getGiftPoint() * discount) << setw(25) << useccpoints << endl;
        }
    }
}

// Comfirm gift Function  ---- R4
void comfirmRedeem(string customerID, char categories, string giftid, vector<Customer>& vCustomer, vector<Gift>& vGift, vector<redeemTransaction>& vredeemTransaction) {
    int ccpointsr = 0; // the cc points that used for redemption
    char comfirmredeem; // comfirm redeem - Y/N
    int a = 2; // for loop
    int b = 0;//store i of customer points
    string crank;
    string rgiftid;
    double discount;
    int customerpoints = 0;
    double giftpoint = 0.00;
    int ogiftpoint = 0.00;
    double extramoney;
    cout << setprecision(0) << fixed;
    for (int i = 0; i < vCustomer.size(); i++) {
        if (vCustomer[i].getCustomerID() == customerID)
            crank = vCustomer[i].getRank();
    }
    for (int i = 0; i < vCustomer.size(); i++) {
        if (vCustomer[i].getCustomerID() == customerID) {
            customerpoints = vCustomer[i].getPoints();
            b = i;
        }
    }
    if (crank == "G")
        discount = 0.9;
    else if (crank == "S")
        discount = 0.95;
    else
        discount = 1;
    cout << "Current CC Points Balance: " << customerpoints << endl;
    cout << "Enter the Gift ID: ";
    cin >> giftid;
    for (int a = 2; a >= 0; a--) {
        for (int i = 0; i < vGift.size(); i++) {
            if (vGift[i].getGiftID()[0] == categories && vGift[i].getGiftID() == giftid) {
                cout << "Enter the CC Points Redemption: ";
                cin >> ccpointsr;
                rgiftid = vGift[i].getGiftID();
                giftpoint = vGift[i].getGiftPoint();
                ogiftpoint = round(vGift[i].getGiftPoint() * discount);
            }
        }
        if (a >= 0 && rgiftid != giftid) {
            if (a == 0) {
                cout << "The chance is zero. Please try again.";
            }
            else {
                cout << "Please enter again. You have " << a << " chance." << endl;
                cout << "Enter the Gift ID: ";
                cin >> giftid;
            }
        }
        else if (a >= 0 && ccpointsr > ogiftpoint) {
            if (a == 0) {
                cout << "The chance is zero. Please try again.";
            }
            else
                cout << "Out of CC Points for the redemption. Please enter again. You have " << a << " chance." << endl;
        }
        else if (a >= 0 && ccpointsr > customerpoints) {
            if (a == 0) {
                cout << "The chance is zero. Please try again.";
            }
            else
                cout << "Over the available CC Points. Please enter again. You have " << a << " chance." << endl;
        }
        if (rgiftid == giftid && ccpointsr <= ogiftpoint && ccpointsr <= customerpoints) {
            a = -1;
            break;
        }
    }

    if (rgiftid == giftid && ccpointsr <= ogiftpoint && ccpointsr <= customerpoints) {
        if (ccpointsr < ogiftpoint) {
            extramoney = (giftpoint * 0.2) - (ccpointsr * 0.2);
        }
        else {
            extramoney = 0;
        }
        cout << "Extra money needed = $" << extramoney << endl;
        cout << "Redeem using CC Points: " << ccpointsr << endl;
        do {
            cout << "Do you comfirm redeem " << giftid << " ? (Y/N)";
            cin >> comfirmredeem;
            switch (comfirmredeem)
            {
            case 'Y':
                vCustomer[b].Points = customerpoints - ccpointsr;
                cout << "CC Points Balance : " << customerpoints << " ----> " << vCustomer[b].getPoints() << endl;
                cout << "The change of CC Points Balance : -" << ccpointsr;
                recordredeem(customerID, rgiftid, extramoney, ccpointsr, vredeemTransaction, vGift);
                break;
            case 'N':
                break;
            default:
                cout << "Please enter again." << endl;
                break;
            }
        } while (comfirmredeem != 'Y' && comfirmredeem != 'N');
    }
}

//Earn CC Points ------ R4 Option 1
void B1(vector<Customer>& vCustomer, const string& customerID, vector<addTransaction>& vaddTransaction)
{
    int a = 0;
    float money;
    int cpoint; // cpoint ---- convert point
    int change;
    cout << endl;
    cout << "Please enter the amount of money spent for converting to CC points : $";
    cin >> money;
    if (money >= 250)
        cpoint = (int)money / 250;
    else if (money < 250)
        cpoint = 0;
    int opoint = 0; // opoint ---- original point
    for (int i = 0; i < vCustomer.size(); i++) {
        if (vCustomer[i].getCustomerID() == customerID) {
            opoint = vCustomer[i].getPoints();
            a = i;
        }
    }
    int bpoint; // bpoint ---- Before point change
    bpoint = opoint;
    opoint = opoint + cpoint;
    vCustomer[a].Points = opoint;
    cout << "Convert CC Points : " << cpoint << endl;
    cout << "CC Points Balance : " << bpoint << " ----> " << vCustomer[a].getPoints() << endl;
    cout << "The change of CC Points Balance : +" << cpoint;
    change = vCustomer[a].getPoints() - bpoint;
    recordadd(customerID, change, money, vaddTransaction);
}

//Redeem Gifts ------ R4 Option 2
void B2(vector<Customer>& vCustomer, vector<Gift>& vGift, const string& customerID, vector<redeemTransaction>& vredeemTransaction)
{
    string giftid;
    char categories;
    do {
        cout << "Please choose the Gift Categories(A,B,C,D)(Go back press 'Q'): ";
        cin >> categories;
        switch (categories)
        {
        case 'A':
            cout << endl;
            cout << "Audio & Video:" << endl;
            displayGift(customerID, categories, vCustomer, vGift);
            comfirmRedeem(customerID, categories, giftid, vCustomer, vGift, vredeemTransaction);
            break;
        case 'B':
            cout << endl;
            cout << "Kitchenware:" << endl;
            displayGift(customerID, categories, vCustomer, vGift);
            comfirmRedeem(customerID, categories, giftid, vCustomer, vGift, vredeemTransaction);
            break;
        case 'C':
            cout << endl;
            cout << "Coupons:" << endl;
            displayGift(customerID, categories, vCustomer, vGift);
            comfirmRedeem(customerID, categories, giftid, vCustomer, vGift, vredeemTransaction);
            break;
        case 'D':
            cout << endl;
            cout << "Computer Accessories:" << endl;
            displayGift(customerID, categories, vCustomer, vGift);
            comfirmRedeem(customerID, categories, giftid, vCustomer, vGift, vredeemTransaction);
            break;
        default:
            cout << "Invalid category. Please try again." << endl;
            break;
        }
    } while (categories != 'A' && categories != 'B' && categories != 'C' && categories != 'D' && categories != 'Q');


}

//Mofidy CC Point ------ R4 Option 3
void B3(vector<Customer>& vCustomer, const string& customerID, vector<modifyTransaction>& vmodifyTransaction)
{
    cout << endl;
    int a = 0;
    string type;
    int currentpoint = 0;
    int newpoint;
    int mchange;
    bool validInput = false;
    for (int i = 0; i < vCustomer.size(); i++) {
        if (vCustomer[i].getCustomerID() == customerID) {
            currentpoint = vCustomer[i].getPoints();
            a = i;
        }
    }
    cout << "Current CC Points Balance: " << currentpoint << endl;
    cout << "Please enter a new CC Points Balance(Positive Integer): ";
    cin >> newpoint;

    while (!validInput) {
        if (cin.fail()) {
            cin.clear(); // Reset error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Please enter again !" << endl;
            cout << "Please enter a new CC Points Balance(Positive Integer): ";
            cin >> newpoint;
        }
        else {
            validInput = true;
        }
    }
    validInput = false;

    if (newpoint < 0) {
        do {
            cout << "Please enter again !" << endl;
            cout << "Please enter a new CC Points Balance(Positive Integer): ";
            cin >> newpoint;
        } while (newpoint < 0);
    }

    vCustomer[a].Points = newpoint;
    cout << "CC Points Balance : " << currentpoint << " ----> " << vCustomer[a].getPoints() << endl;
    mchange = vCustomer[a].getPoints() - currentpoint;
    if (vCustomer[a].getPoints() > currentpoint) {
        cout << "The change of CC Points Balance : +" << mchange;
        type = "Increase";
    }
    else {
        cout << "The change of CC Points Balance : " << mchange;
        type = "Decrease";
    }
    recordmodify(customerID, type, mchange, vmodifyTransaction);
}

//Display ---- R5
void displayRecord(string customerID, vector<Customer>& vCustomer, vector<Gift>& vGift, vector<addTransaction>& vaddTransaction, vector<redeemTransaction>& vredeemTransaction, vector<modifyTransaction>& vmodifyTransaction, vector<oiriginalPoint>& voiriginalPoint) {
    int chaekadd = 1;
    int chaekredeem = 1;
    int chaekmodify = 1;
    int originalpoints = 0;
    int finalpoints = 0;
    int pointchange = 0;
    double totalExtraMoney = 0.0;
    for (int i = 0; i < vCustomer.size(); i++) {
        if (vCustomer[i].getCustomerID() == customerID) {
            finalpoints = vCustomer[i].getPoints();
        }
    }
    for (int i = 0; i < voiriginalPoint.size(); i++) {
        if (voiriginalPoint[i].getCustomerID() == customerID) {
            originalpoints = voiriginalPoint[i].getPoints();
        }
    }
    cout << "\n\n";
    cout << "Customer ID: " << customerID << endl;
    cout << "***** CC Points Transactions *****" << endl;
    cout << endl;
    // Add 
    cout << "Add CC Points:" << endl;
    for (auto it = vaddTransaction.begin(); it != vaddTransaction.end(); ++it) {
        if (it->getcustomerID() == customerID) {
            chaekadd = 0;
        }
    }
    if (chaekadd == 1) {
        cout << "No record found !!!";
        cout << endl;
    }
    else {
        cout << left << setw(25) << "Money Spent" << "CC Points" << endl;
        for (auto it = vaddTransaction.rbegin(); it != vaddTransaction.rend(); ++it) {
            if (it->getcustomerID() == customerID) {
                cout << left;
                cout << setw(25) << it->getmoneySpent() << "+" << it->getpoint() << endl;
            }
        }
    }
    cout << endl;
    // Redeem
    cout << "Redeem Gifts:" << endl;
    for (auto it = vredeemTransaction.begin(); it != vredeemTransaction.end(); ++it) {
        if (it->getcustomerID() == customerID) {
            chaekredeem = 0;
        }
    }
    if (chaekredeem == 1) {
        cout << "No record found !!!";
        cout << endl;
    }
    else {
        cout << left << setw(10) << "Gift ID" << setw(35) << "Gift Descriptiont" << setw(25) << "Extra Money" << setw(25) << "CC Points" << endl;
        for (auto it = vredeemTransaction.rbegin(); it != vredeemTransaction.rend(); ++it) {
            if (it->getcustomerID() == customerID) {
                cout << setw(10) << it->getrgiftid() << setw(35) << it->getgiftd() << "$" << setw(25) << it->getextramoney() << "-" << setw(20) << it->getccpointsr() << endl;
                totalExtraMoney += it->getextramoney();
            }
        }
    }

    cout << endl;
    // Modify
    cout << "Modify CC Point Balace:" << endl;
    for (auto it = vmodifyTransaction.begin(); it != vmodifyTransaction.end(); ++it) {
        if (it->getcustomerID() == customerID) {
            chaekmodify = 0;
        }
    }
    if (chaekmodify == 1) {
        cout << "No record found !!!" << endl;
        cout << endl;
    }
    else {
        cout << left;
        cout << setw(10) << "Type" << setw(25) << "CC Points" << endl;
        for (auto it = vmodifyTransaction.rbegin(); it != vmodifyTransaction.rend(); ++it) {
            if (it->getcustomerID() == customerID) {
                if (it->gettype() == "Increase") {
                    cout << left;
                    cout << setw(10) << it->gettype() << "+" << it->getmchange() << endl;
                }
                else {
                    cout << left;
                    cout << setw(10) << it->gettype() << setw(25) << it->getmchange() << endl;
                }
            }
        }
    }
    cout << "**************************************************" << endl;
    cout << "Original CC Point Balace : " << originalpoints << endl;
    cout << "Final CC Point Balace : " << finalpoints << endl;
    pointchange = finalpoints - originalpoints;
    if (pointchange >= 0) {
        cout << "The change of CC Points Balance : +" << pointchange << endl;
    }
    else {
        cout << "The change of CC Points Balance : " << pointchange << endl;
    }
    cout << "Total Extra Money : $" << totalExtraMoney;
}

// Display ending -- R6
void displayCreditsAndExit() {
    char userInput;
    bool validInput = false;

    while (!validInput) {
        cout << "Are you sure you want to exit? (Y/N): ";
        cin >> userInput;

        if (userInput == 'n' || userInput == 'N') {
            validInput = true;
        }
        else if (userInput == 'y' || userInput == 'Y') {
            validInput = true;
            cout << "Group Members :\n";
            cout << "B04C_Chan Kwun Ming_23096630A\n";
            cout << "B04C_Chan Hei Pui_23092931A\n";
            cout << "B04B_Chan Ka Ming_23231380A\n";
            cout << "B04C_Cheng Chun Ho_23189243A\n";
            cout << "B04A_Cheng Tsz Hung_23149675A\n";
            cout << "B04D_Wong Chun Leung_23190727A\n";
            cout << "Thank you for using our program. Goodbye!\n";
            exit(0); // Exit the program
        }
        else {
            cout << "Invalid input, please enter 'Y' or 'N'.\n";
        }
    }
}

int main() {
    vector<Gift> vGift;
    vector<Customer> vCustomer;
    vector<addTransaction> vaddTransaction;
    vector<redeemTransaction> vredeemTransaction;
    vector<modifyTransaction>vmodifyTransaction;
    vector<oiriginalPoint>voiriginalPoint;
    int option;
    bool dataLoaded = false;
    bool validInput = false;

    cout << "Welcome to our Group's Program!\n";

    while (true) {
        displayMainMenu();
        cin >> option;

        while (!validInput) {
            if (cin.fail()) {
                cin.clear(); // Reset error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid option. Please try again. ";
                displayMainMenu();
                cin >> option;
            }
            else {
                validInput = true;
            }
        }
        validInput = false;

        if (option == 1) {
            if (!dataLoaded) {
                loadStartingData(vGift, vCustomer);
                cout << "Starting data loaded successfully.\n";
                dataLoaded = true;
                //R5 Get Original Point
                for (auto it = vCustomer.begin(); it != vCustomer.end(); ++it) {
                    string CustomerID;
                    int points;
                    CustomerID = it->getCustomerID();
                    points = it->getPoints();
                    recordoiriginalpoint(CustomerID, points, voiriginalPoint);
                }
            }
            else if(dataLoaded){
                cout << "Starting data have already loaded.\n";
            }

        }
        else if (option == 2 && dataLoaded) { // R2 Code Start
            displayData(vGift, vCustomer); //display Data
        }// R2 Code End

        else if (option == 3 && dataLoaded) {   // R3 code start
            string customerID;

            //Enter customerID
            cout << "Enter a customer ID: ";
            cin >> customerID;

            //Find customers
            auto it = find_if(vCustomer.begin(), vCustomer.end(), [&](const Customer& c) {
                return c.getCustomerID() == customerID;
                });

            // If customer does not exist, add customer
            if (it == vCustomer.end()) {
                addCustomer(vCustomer, customerID, voiriginalPoint);
            }
            //If customer exist, delete customer  
            else {
                displayCustomerInfo(*it);
                deleteCustomer(vCustomer, customerID, voiriginalPoint);
            }
        }
        else if (option == 4 && dataLoaded) {   // R4 code start
            char r4_choice;
            char cid[50];
            cout << "please enter the Customer ID : ";
            cin >> cid;
            string customerID;
            customerID = searchCustomerID(cid, vCustomer);
            if (cid != customerID) {
                cout << "This Customer ID cannot be found in system";
            }
            else {
                do {
                    cout << "\n\n";
                    cout << "Action for Customer ID: " << cid << endl;
                    cout << "***** Customer View Menu *****" << endl;
                    cout << "[1] Earn CC Points" << endl;
                    cout << "[2] Redeem Gifts" << endl;
                    cout << "[3] Modify CC Points Balance" << endl;
                    cout << "[4] Return to Main Menu" << endl;
                    cout << "*************************" << endl;
                    cout << "Option (1-4)" << endl;
                    cin >> r4_choice;
                    cout << "\n\n";

                    switch (r4_choice) {
                    case '1': B1(vCustomer, customerID, vaddTransaction);
                        break;
                    case '2': B2(vCustomer, vGift, customerID, vredeemTransaction);
                        break;
                    case '3': B3(vCustomer, customerID, vmodifyTransaction);
                        break;
                    case '4': break;
                    default:
                        cout << "There is no such option, please re-enter " << endl;
                        break;
                    }
                } while (r4_choice != '4');
            }   //R4 code end
        }
        else if (option == 5 && dataLoaded) {  //R5 code start
            char cid[50];
            cout << "please enter the Customer ID : ";
            cin >> cid;
            string customerID;
            customerID = searchCustomerID(cid, vCustomer);
            if (cid != customerID) {
                cout << "This Customer ID cannot be found in system";
            }
            else {
                displayRecord(customerID, vCustomer, vGift, vaddTransaction, vredeemTransaction, vmodifyTransaction, voiriginalPoint);
            }
        } //R5 code end
        else if ((option >= 2 && option <= 5) && !dataLoaded) {
            cout << "Error: Please load starting data first.\n";
        }
        else if (option == 6) { //R6 code start
            displayCreditsAndExit();
        } //R6 code end
        else {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
