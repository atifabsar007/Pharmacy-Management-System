#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <limits>

using namespace std;

const int LOW_STOCK_THRESHOLD = 20;

// Utility function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Date utility class
class Date {
private:
    int day, month, year;
public:
    Date() : day(1), month(1), year(2025) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    
    void setDate(string dateStr) {
        sscanf(dateStr.c_str(), "%d-%d-%d", &year, &month, &day);
    }
    
    string toString() const {
        char buffer[11];
        sprintf(buffer, "%04d-%02d-%02d", year, month, day);
        return string(buffer);
    }
    
    bool isExpired() const {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        
        if (year < (1900 + ltm->tm_year)) return true;
        if (year > (1900 + ltm->tm_year)) return false;
        if (month < (1 + ltm->tm_mon)) return true;
        if (month > (1 + ltm->tm_mon)) return false;
        if (day < ltm->tm_mday) return true;
        return false;
    }
    
    static Date getCurrentDate() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        return Date(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    }
};

// Medicine Class
class Medicine {
private:
    string id;
    string name;
    string genericName;
    string manufacturer;
    double price;
    int stock;
    Date expiry;
    string category;
    
public:
    Medicine() : price(0.0), stock(0) {}
    
    Medicine(string i, string n, string g, string m, double p, int s, Date e, string c)
        : id(i), name(n), genericName(g), manufacturer(m), price(p), stock(s), expiry(e), category(c) {}
    
    // Getters
    string getId() const { return id; }
    string getName() const { return name; }
    string getGenericName() const { return genericName; }
    string getManufacturer() const { return manufacturer; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }
    Date getExpiry() const { return expiry; }
    string getCategory() const { return category; }
    
    // Setters
    void setStock(int s) { stock = s; }
    
    void updateStock(int quantity) {
        stock += quantity;
    }
    
    bool isLowStock() const {
        return stock < LOW_STOCK_THRESHOLD;
    }
    
    bool isExpired() const {
        return expiry.isExpired();
    }
    
    void display() const {
        cout << left << setw(10) << id 
             << setw(20) << name 
             << setw(18) << genericName 
             << setw(18) << manufacturer 
             << setw(12) << category 
             << setw(10) << fixed << setprecision(2) << price 
             << setw(8) << stock 
             << setw(12) << expiry.toString();
        
        if (isExpired()) cout << " [EXPIRED]";
        if (isLowStock()) cout << " [LOW]";
        cout << endl;
    }
    
    string serialize() const {
        return id + "," + name + "," + genericName + "," + manufacturer + "," 
               + to_string(price) + "," + to_string(stock) + "," 
               + expiry.toString() + "," + category;
    }
    
    static Medicine deserialize(string data) {
        stringstream ss(data);
        string id, name, generic, mfr, category, dateStr;
        double price;
        int stock;
        
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, generic, ',');
        getline(ss, mfr, ',');
        ss >> price;
        ss.ignore();
        ss >> stock;
        ss.ignore();
        getline(ss, dateStr, ',');
        getline(ss, category);
        
        Date expiry;
        expiry.setDate(dateStr);
        
        return Medicine(id, name, generic, mfr, price, stock, expiry, category);
    }
};

// Cart Item Structure
struct CartItem {
    Medicine* medicine;
    int quantity;
    
    CartItem(Medicine* m, int q) : medicine(m), quantity(q) {}
    
    double getSubtotal() const {
        return medicine->getPrice() * quantity;
    }
};

// Customer Class
class Customer {
private:
    string name;
    string phone;
    vector<CartItem> cart;
    
public:
    Customer() {}
    Customer(string n, string p) : name(n), phone(p) {}
    
    string getName() const { return name; }
    string getPhone() const { return phone; }
    vector<CartItem>& getCart() { return cart; }
    
    void addToCart(Medicine* medicine, int quantity) {
        // Check if item already in cart
        for (auto& item : cart) {
            if (item.medicine->getId() == medicine->getId()) {
                item.quantity += quantity;
                return;
            }
        }
        cart.push_back(CartItem(medicine, quantity));
    }
    
    void removeFromCart(int index) {
        if (index >= 0 && index < cart.size()) {
            cart.erase(cart.begin() + index);
        }
    }
    
    void clearCart() {
        cart.clear();
    }
    
    double getTotalAmount() const {
        double total = 0.0;
        for (const auto& item : cart) {
            total += item.getSubtotal();
        }
        return total;
    }
    
    void displayCart() const {
        if (cart.empty()) {
            cout << "\n  Cart is empty.\n";
            return;
        }
        
        cout << "\n  Shopping Cart for " << name << " (" << phone << ")\n";
        cout << "  " << string(70, '-') << endl;
        
        for (size_t i = 0; i < cart.size(); i++) {
            cout << "  " << (i + 1) << ". " << cart[i].medicine->getName()
                 << " x" << cart[i].quantity 
                 << " @ BDT " << fixed << setprecision(2) << cart[i].medicine->getPrice()
                 << " = BDT " << cart[i].getSubtotal() << endl;
        }
        
        cout << "  " << string(70, '-') << endl;
        cout << "  Total: BDT " << fixed << setprecision(2) << getTotalAmount() << endl;
    }
};

// Invoice Class
class Invoice {
private:
    static int invoiceCounter;
    static double totalRevenue;
    static int totalMedicinesSold;
    
    int invoiceNo;
    Customer customer;
    Date date;
    vector<CartItem> items;
    double totalAmount;
    
public:
    Invoice(Customer& cust) : customer(cust), date(Date::getCurrentDate()) {
        invoiceNo = ++invoiceCounter;
        items = cust.getCart();
        totalAmount = cust.getTotalAmount();
    }
    
    void generate() {
        totalRevenue += totalAmount;
        
        for (auto& item : items) {
            totalMedicinesSold += item.quantity;
            item.medicine->updateStock(-item.quantity);
        }
    }
    
    void display() const {
        cout << "\n" << string(80, '=') << endl;
        cout << "                   MEDICARE PHARMACY" << endl;
        cout << "                    TAX INVOICE" << endl;
        cout << string(80, '=') << endl;
        cout << "Invoice No: " << invoiceNo << "                   Date: " << date.toString() << endl;
        cout << "Customer: " << customer.getName() << endl;
        cout << "Phone: " << customer.getPhone() << endl;
        cout << string(80, '-') << endl;
        cout << left << setw(30) << "Medicine" 
             << setw(15) << "Price (BDT)" 
             << setw(10) << "Qty" 
             << setw(15) << "Subtotal" << endl;
        cout << string(80, '-') << endl;
        
        for (const auto& item : items) {
            cout << left << setw(30) << item.medicine->getName()
                 << setw(15) << fixed << setprecision(2) << item.medicine->getPrice()
                 << setw(10) << item.quantity
                 << setw(15) << item.getSubtotal() << endl;
        }
        
        cout << string(80, '-') << endl;
        cout << right << setw(65) << "TOTAL: BDT " << fixed << setprecision(2) << totalAmount << endl;
        cout << string(80, '=') << endl;
        cout << "          Thank you for shopping with MediCare!" << endl;
        cout << string(80, '=') << endl;
    }
    
    static double getTotalRevenue() { return totalRevenue; }
    static int getTotalMedicinesSold() { return totalMedicinesSold; }
    static void resetCounters() { invoiceCounter = 1000; totalRevenue = 0; totalMedicinesSold = 0; }
};

int Invoice::invoiceCounter = 1000;
double Invoice::totalRevenue = 0.0;
int Invoice::totalMedicinesSold = 0;

// Pharmacy Management System Class
class PharmacySystem {
private:
    vector<Medicine> inventory;
    Customer* currentCustomer;
    
public:
    PharmacySystem() : currentCustomer(nullptr) {
        loadInventory();
    }
    
    ~PharmacySystem() {
        saveInventory();
        delete currentCustomer;
    }
    
    void loadInventory() {
        ifstream file("inventory.txt");
        if (!file) {
            initializeDefaultData();
            return;
        }
        
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                inventory.push_back(Medicine::deserialize(line));
            }
        }
        file.close();
    }
    
    void saveInventory() {
        ofstream file("inventory.txt");
        for (const auto& med : inventory) {
            file << med.serialize() << endl;
        }
        file.close();
    }
    
    void initializeDefaultData() {
        Date exp1, exp2, exp3, exp4, exp5, exp6;
        exp1.setDate("2025-12-31");
        exp2.setDate("2026-06-15");
        exp3.setDate("2024-11-01");
        exp4.setDate("2027-01-20");
        exp5.setDate("2027-01-20");
        exp6.setDate("2025-12-31");
        
        inventory.push_back(Medicine("MED001", "Napa (500mg)", "Paracetamol", "Beximco", 2.50, 500, exp1, "Tablet"));
        inventory.push_back(Medicine("MED002", "Seclo (20mg)", "Omeprazole", "Square", 5.00, 250, exp2, "Capsule"));
        inventory.push_back(Medicine("MED003", "Rivotril (2mg)", "Clonazepam", "Roche", 30.00, 5, exp3, "Tablet"));
        inventory.push_back(Medicine("MED004", "Amodis Syrup", "Amoxicillin", "Renata", 120.00, 10, exp4, "Syrup"));
        inventory.push_back(Medicine("MED005", "Tylenol (500mg)", "Paracetamol", "J&J", 2.00, 1000, exp5, "Tablet"));
        inventory.push_back(Medicine("MED006", "Ceftriaxone Inj", "Ceftriaxone", "Incepta", 500.00, 15, exp6, "Injection"));
    }
    
    void displayStats() {
        int lowStockCount = 0;
        for (const auto& med : inventory) {
            if (med.isLowStock()) lowStockCount++;
        }
        
        cout << "\n" << string(80, '=') << endl;
        cout << "                    PHARMACY DASHBOARD" << endl;
        cout << string(80, '=') << endl;
        cout << "  Total Medicines: " << inventory.size() << endl;
        cout << "  Total Sales: BDT " << fixed << setprecision(2) << Invoice::getTotalRevenue() << endl;
        cout << "  Medicines Sold: " << Invoice::getTotalMedicinesSold() << endl;
        cout << "  Low Stock Items: " << lowStockCount << endl;
        cout << string(80, '=') << endl;
    }
    
    void addMedicine() {
        string id, name, generic, mfr, category, dateStr;
        double price;
        int stock;
        
        cout << "\n--- Add New Medicine ---\n";
        cout << "Medicine ID: "; cin >> id;
        clearInputBuffer();
        
        // Check for duplicate ID
        for (const auto& med : inventory) {
            if (med.getId() == id) {
                cout << "Error: Medicine ID already exists!\n";
                return;
            }
        }
        
        cout << "Medicine Name: "; getline(cin, name);
        cout << "Generic Name: "; getline(cin, generic);
        cout << "Manufacturer: "; getline(cin, mfr);
        cout << "Price (BDT): "; cin >> price;
        cout << "Stock Quantity: "; cin >> stock;
        clearInputBuffer();
        cout << "Expiry Date (YYYY-MM-DD): "; getline(cin, dateStr);
        
        cout << "Category (1.Tablet 2.Capsule 3.Syrup 4.Injection 5.Ointment 6.Drop): ";
        int catChoice;
        cin >> catChoice;
        clearInputBuffer();
        
        string categories[] = {"Tablet", "Capsule", "Syrup", "Injection", "Ointment", "Drop"};
        category = (catChoice >= 1 && catChoice <= 6) ? categories[catChoice - 1] : "Tablet";
        
        Date expiry;
        expiry.setDate(dateStr);
        
        inventory.push_back(Medicine(id, name, generic, mfr, price, stock, expiry, category));
        cout << "\nMedicine added successfully!\n";
        saveInventory();
    }
    
    void viewInventory() {
        if (inventory.empty()) {
            cout << "\nNo medicines in inventory.\n";
            return;
        }
        
        cout << "\n" << string(120, '=') << endl;
        cout << "                                    MEDICINE INVENTORY" << endl;
        cout << string(120, '=') << endl;
        cout << left << setw(10) << "ID" 
             << setw(20) << "Name" 
             << setw(18) << "Generic" 
             << setw(18) << "Manufacturer" 
             << setw(12) << "Category" 
             << setw(10) << "Price" 
             << setw(8) << "Stock" 
             << setw(12) << "Expiry" << endl;
        cout << string(120, '-') << endl;
        
        for (const auto& med : inventory) {
            med.display();
        }
        cout << string(120, '=') << endl;
    }
    
    void searchMedicine() {
        string search;
        cout << "\nEnter search term (ID, Name, or Manufacturer): ";
        clearInputBuffer();
        getline(cin, search);
        
        transform(search.begin(), search.end(), search.begin(), ::tolower);
        
        bool found = false;
        cout << "\n--- Search Results ---\n";
        
        for (const auto& med : inventory) {
            string id = med.getId(), name = med.getName(), mfr = med.getManufacturer();
            transform(id.begin(), id.end(), id.begin(), ::tolower);
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            transform(mfr.begin(), mfr.end(), mfr.begin(), ::tolower);
            
            if (id.find(search) != string::npos || 
                name.find(search) != string::npos || 
                mfr.find(search) != string::npos) {
                med.display();
                found = true;
            }
        }
        
        if (!found) {
            cout << "No medicines found matching '" << search << "'\n";
        }
    }
    
    void updateStock() {
        string id;
        cout << "\nEnter Medicine ID to update: ";
        cin >> id;
        
        for (auto& med : inventory) {
            if (med.getId() == id) {
                int newStock;
                cout << "Current Stock: " << med.getStock() << endl;
                cout << "Enter new stock quantity: ";
                cin >> newStock;
                
                if (newStock >= 0) {
                    med.setStock(newStock);
                    cout << "Stock updated successfully!\n";
                    saveInventory();
                } else {
                    cout << "Invalid stock quantity!\n";
                }
                return;
            }
        }
        
        cout << "Medicine ID not found!\n";
    }
    
    void deleteMedicine() {
        string id;
        cout << "\nEnter Medicine ID to delete: ";
        cin >> id;
        
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->getId() == id) {
                cout << "Delete " << it->getName() << "? (y/n): ";
                char confirm;
                cin >> confirm;
                
                if (confirm == 'y' || confirm == 'Y') {
                    inventory.erase(it);
                    cout << "Medicine deleted successfully!\n";
                    saveInventory();
                }
                return;
            }
        }
        
        cout << "Medicine ID not found!\n";
    }
    
    void salesModule() {
        if (inventory.empty()) {
            cout << "\nNo medicines available for sale!\n";
            return;
        }
        
        string custName, custPhone;
        cout << "\n--- Sales Module ---\n";
        cout << "Customer Name: ";
        clearInputBuffer();
        getline(cin, custName);
        cout << "Customer Phone: ";
        getline(cin, custPhone);
        
        if (currentCustomer) delete currentCustomer;
        currentCustomer = new Customer(custName, custPhone);
        
        int choice;
        do {
            cout << "\n1. Add Item to Cart\n";
            cout << "2. View Cart\n";
            cout << "3. Remove Item from Cart\n";
            cout << "4. Clear Cart\n";
            cout << "5. Generate Invoice\n";
            cout << "6. Back to Main Menu\n";
            cout << "Choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1: addToCart(); break;
                case 2: currentCustomer->displayCart(); break;
                case 3: removeFromCart(); break;
                case 4: currentCustomer->clearCart(); cout << "Cart cleared!\n"; break;
                case 5: generateInvoice(); break;
                case 6: break;
                default: cout << "Invalid choice!\n";
            }
        } while (choice != 6);
    }
    
    void addToCart() {
        string medId;
        int qty;
        
        cout << "\nEnter Medicine ID: ";
        cin >> medId;
        
        Medicine* med = nullptr;
        for (auto& m : inventory) {
            if (m.getId() == medId) {
                med = &m;
                break;
            }
        }
        
        if (!med) {
            cout << "Medicine not found!\n";
            return;
        }
        
        if (med->isExpired()) {
            cout << "This medicine is expired and cannot be sold!\n";
            return;
        }
        
        cout << "Available Stock: " << med->getStock() << endl;
        cout << "Enter Quantity: ";
        cin >> qty;
        
        if (qty <= 0) {
            cout << "Invalid quantity!\n";
            return;
        }
        
        // Check cart for existing quantity
        int cartQty = 0;
        for (const auto& item : currentCustomer->getCart()) {
            if (item.medicine->getId() == medId) {
                cartQty = item.quantity;
                break;
            }
        }
        
        if (cartQty + qty > med->getStock()) {
            cout << "Insufficient stock! Available: " << med->getStock() 
                 << ", Already in cart: " << cartQty << endl;
            return;
        }
        
        currentCustomer->addToCart(med, qty);
        cout << "Added " << qty << "x " << med->getName() << " to cart!\n";
    }
    
    void removeFromCart() {
        currentCustomer->displayCart();
        
        if (currentCustomer->getCart().empty()) return;
        
        int index;
        cout << "Enter item number to remove: ";
        cin >> index;
        
        currentCustomer->removeFromCart(index - 1);
        cout << "Item removed from cart!\n";
    }
    
    void generateInvoice() {
        if (currentCustomer->getCart().empty()) {
            cout << "\nCart is empty! Cannot generate invoice.\n";
            return;
        }
        
        Invoice invoice(*currentCustomer);
        invoice.generate();
        invoice.display();
        
        currentCustomer->clearCart();
        saveInventory();
        
        cout << "\nPress Enter to continue...";
        clearInputBuffer();
        cin.get();
    }
    
    void run() {
        int choice;
        
        do {
            displayStats();
            cout << "\n--- Main Menu ---\n";
            cout << "1. Add Medicine\n";
            cout << "2. View Inventory\n";
            cout << "3. Search Medicine\n";
            cout << "4. Update Stock\n";
            cout << "5. Delete Medicine\n";
            cout << "6. Sales & Billing\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1: addMedicine(); break;
                case 2: viewInventory(); break;
                case 3: searchMedicine(); break;
                case 4: updateStock(); break;
                case 5: deleteMedicine(); break;
                case 6: salesModule(); break;
                case 7: cout << "\nThank you for using MediCare Pharmacy System!\n"; break;
                default: cout << "\nInvalid choice! Please try again.\n";
            }
            
        } while (choice != 7);
    }
};

int main() {
    cout << "\n========================================\n";
    cout << "   MEDICARE PHARMACY MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    
    PharmacySystem system;
    system.run();
    
    return 0;
}
