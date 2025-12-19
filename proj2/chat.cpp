/****
Name: Zita Huang
SI 221
Works Cited:
cplusplus.com
EI with Lt Gentile
****/
#include <iostream>
#include <string>
#include <iomanip>
#include "list.h" 
using namespace std;

const double shortTermRate = 0.25;
const double longTermRate = 0.15;

class Date {
public:
    int day, month, year;

    Date() {
        month = day = year = 0;
    }

    Date(string x) {
        int i = 0, num = 0, part = 0;
        month = day = year = 0;
        while (i < (int)x.length()) {
            if (x[i] == '/') {
                if (part == 0)
                    month = num;
                else if (part == 1)
                    day = num;
                part++;
                num = 0;
            } else {
                num = num * 10 + (x[i] - '0');
            }
            i++;
        }
        year = num;
    }

    //function to see if it is long term or short term
    bool longTerm(Date sell) {
        if (sell.year - year > 1)
            return true;
        else if (sell.year - year < 1)
            return false;
        else {
            if (sell.month > month)
                return true;
            else if (sell.month < month)
                return false;
            else
                return sell.day > day;
        }
    }
    //function to determine whether or not it is less than a year
    bool lessThan(Date other) {
        if (year < other.year)
            return true;
        else if (year > other.year)
            return false;
        else {
            if (month < other.month)
                return true;
            else if (month > other.month)
                return false;
            else
                return day < other.day;
        }
    }

    void print() const {
        cout << month << "/" << day << "/" << year;
    }
};

struct Share {
    double qty;
    double price;
    Date date;

    Share() {
        qty = price = 0;
    }

    Share(double q, double p, string d) {
        qty = q;
        price = p;
        date = Date(d);
    }
};

class Portfolio {
private:
    List<Share> purchase;      // FIFO
    List<Share> avgPurchases;   // Average
    List<Share> hifoPurchases;  // Most Expensive
    double FIFO;
    double avgTax;
    double hifoTax;
    double totalShare;
    double totalCost;
    double avgCostBasis;

public:
    Portfolio() {
        FIFO = 0;
        avgTax = 0;
        hifoTax = 0;
        totalShare = 0;
        totalCost = 0;
        avgCostBasis = 0;
    }

    void buy(double qty, string name, double price, string date) {
        cout << fixed << setprecision(2);
        Date d(date);
        cout << "You purchased " << qty << " shares of " << name
             << " at $" << price << " on ";
        d.print();
        cout << endl;

        purchase.add2back(Share(qty, price, date));
        avgPurchases.add2back(Share(qty, price, date));
        hifoPurchases.add2back(Share(qty, price, date));

        double newValue = qty * price;
        totalShare += qty;
        totalCost += newValue;
        
        // Calculate average cost basis after every buy
        if (totalShare > 0) {
            avgCostBasis = totalCost / totalShare;
        }
    }

    void sell(double qty, string name, double price, string date) {
        cout << fixed << setprecision(2);
        Date d(date);
        cout << "You sold " << qty << " shares of " << name
             << " at $" << price << " on ";
        d.print();
        cout << endl;

        Date sellDate(date);

        //FIFO
        double remainingFIFO = qty;
        
        while (remainingFIFO > 0 && !purchase.begin().equal(purchase.end())) {
            typename List<Share>::Iterator fifoItr = purchase.begin();
            Share &curr = fifoItr.get();

            double sellNow;
            if (curr.qty < remainingFIFO)
                sellNow = curr.qty;
            else
                sellNow = remainingFIFO;

            double gain = (price - curr.price) * sellNow;
            double rate = shortTermRate;
            if (curr.date.longTerm(sellDate))
                rate = longTermRate;

            FIFO += gain * rate;
            remainingFIFO -= sellNow;

            if (sellNow >= curr.qty) {
                //once used remove
                purchase.remove(fifoItr);
            } else {
                curr.qty -= sellNow;
            }
        }

        //Average - Use the current average cost basis
        double saleAvgCostBasis = avgCostBasis;
        
        cout << "DEBUG: Before sale - totalShare=" << totalShare << " totalCost=" << totalCost << " avgCostBasis=" << avgCostBasis << endl;

        double remainingToSell = qty;

        while (remainingToSell > 0 && !avgPurchases.begin().equal(avgPurchases.end())) {
            typename List<Share>::Iterator avgItr = avgPurchases.begin();
            Share &lot = avgItr.get();

            double sellNow;
            if (lot.qty < remainingToSell)
                sellNow = lot.qty;
            else
                sellNow = remainingToSell;

            // Use average cost basis for gain calculation
            double gain = (price - saleAvgCostBasis) * sellNow; 
        
            // Use the lot's date to determine tax rate
            double rate = shortTermRate;
            if (lot.date.longTerm(sellDate))
                rate = longTermRate;

            cout << "  Lot date: ";
            lot.date.print();
            cout << " qty=" << sellNow << " long-term=" << (rate == longTermRate ? "yes" : "no") 
                 << " gain=" << gain << " tax=" << (gain * rate) << endl;

            avgTax += gain * rate;
            remainingToSell -= sellNow;
        
            if (sellNow >= lot.qty) {
                // Consuming entire lot - remove it
                avgPurchases.remove(avgItr);
            } 
            else {
                // Partial sale - just reduce quantity
                lot.qty -= sellNow;
            }
        }

        // Update totals AFTER the sale
        totalShare -= qty;
        totalCost -= qty * saleAvgCostBasis;

        // Recalculate average cost basis for remaining shares
        if (totalShare > 0) {
            avgCostBasis = totalCost / totalShare;
        } else {
            totalShare = 0;
            totalCost = 0;
            avgCostBasis = 0;
        }
        
        cout << "DEBUG: After sale - totalShare=" << totalShare << " totalCost=" << totalCost << " avgCostBasis=" << avgCostBasis << endl;
        cout << "DEBUG: Running avgTax total=" << avgTax << endl << endl;
        
        //Most Expensive(HIFO)
        double remainHIFO = qty;

        while (remainHIFO > 0 && !hifoPurchases.begin().equal(hifoPurchases.end())) {
            //Find the best lot to sell (HIFO)
            typename List<Share>::Iterator bestItr = hifoPurchases.begin();
            Share *bestPtr = nullptr;
            
            if (!bestItr.equal(hifoPurchases.end())) {
                bestPtr = &bestItr.get();
                double maxPrice = bestPtr->price;

                typename List<Share>::Iterator it = hifoPurchases.begin();
                while (!it.equal(hifoPurchases.end())) {
                    Share &curr = it.get();
                    bool currLong = curr.date.longTerm(sellDate);
                    bool bestLong = bestPtr->date.longTerm(sellDate);

                    if (curr.price > maxPrice) {
                        //Highest Price
                        maxPrice = curr.price;
                        bestItr = it;
                        bestPtr = &curr;
                    } else if (curr.price == maxPrice) {
                        //Prefer Long-Term (lower tax rate)
                        if (currLong && !bestLong) {
                            bestItr = it;
                            bestPtr = &curr;
                        } else if (currLong == bestLong) {
                            //Prefer Oldest Lot
                            if (curr.date.lessThan(bestPtr->date)) {
                                bestItr = it;
                                bestPtr = &curr;
                            }
                        }
                    }
                    it.next();
                }
            }

            if (!bestPtr) break;

            //Execute the sale on the best lot
            Share &lot = *bestPtr;
            double sellNow;
            if (lot.qty < remainHIFO)
                sellNow = lot.qty;
            else
                sellNow = remainHIFO;

            double gain = (price - lot.price) * sellNow;
            double rate = shortTermRate;
            if (lot.date.longTerm(sellDate))
                rate = longTermRate;

            hifoTax += gain * rate;

            lot.qty -= sellNow;
            remainHIFO -= sellNow;

            if (lot.qty <= 0) {
                // remove once used
                hifoPurchases.remove(bestItr);
            }
        }
    }

    void printTax() {
        cout << endl << fixed << setprecision(2);
        cout << "Using FIFO accounting, you owe Uncle Sam $" << FIFO << endl;
        cout << "Using average accounting, you owe Uncle Sam $" << avgTax << endl;
        cout << "By selling most expensive shares first, you owe Uncle Sam $" << hifoTax << endl;
    }
};

int main() {
    Portfolio p;
    string date, action, name, junk;
    double price, shares, amt;

    //Read in the header but do nothing with it
    cin >> junk >> junk >> junk >> junk >> junk >> junk
        >> junk >> junk >> junk >> junk >> junk;
    //loop through until there are no more inputs
    while (cin >> date >> action >> name >> price >> shares >> amt) {
        if (action == "Buy")
            p.buy(shares, name, price, date);
        else if (action == "Sell")
            p.sell(shares, name, price, date);
    }

    p.printTax();
    return 0;
}