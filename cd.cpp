#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

// Structure to store crop details
struct Crop {
    int id;
    string name;
    string season;
    double price;
};

// Structure to store farmer details
struct Farmer {
    int id;
    string name;
    string address;
    string phoneNumber;
};

// Structure to store land details
struct Land {
    int id,fid;
    string address;
    double size;
    string soilType;
};

// Structure to store harvest details
struct Harvest {
    int id,cid,fid,lid;
    string date;
    double quantity;
};

// Structure to store sales details
struct Sales {
    int id,cid,fid;
    string date;
    double quantity;
    double price;
};

void insertCrop(const string& filename) {
    ofstream outputFile(filename, ios::app);

    if (!outputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    Crop crop;

    cout << "Enter crop ID: ";
    cin >> crop.id;

    cout << "Enter crop name: ";
    cin.ignore();
    getline(cin, crop.name);

    cout << "Enter planting season: ";
    getline(cin, crop.season);

    cout << "Enter crop price: ";
    cin >> crop.price;
    outputFile << crop.id << " " << crop.name << " " << crop.season << " " << crop.price << endl;

    outputFile.close();

    cout << "Crop details stored in the file successfully." << endl;
}

void insertFarmer(const string& filename) {
    ofstream outputFile(filename, ios::app);

    if (!outputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    Farmer farmer;

    cout << "Enter farmer ID: ";
    cin >> farmer.id;

    cout << "Enter farmer name: ";
    cin.ignore();
    getline(cin, farmer.name);

    cout << "Enter farmer address: ";
    getline(cin, farmer.address);

    cout << "Enter farmer phone number: ";
    getline(cin, farmer.phoneNumber);

    outputFile << farmer.id << " " << farmer.name << " " << farmer.address << " " << farmer.phoneNumber << endl;

    outputFile.close();

    cout << "Farmer details stored in the file successfully." << endl;
}

void insertLand(const string& filename) {
    ofstream outputFile(filename, ios::app);

    if (!outputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    Land land;
    Farmer farm;

    cout << "Enter land ID: ";
    cin >> land.id;

     cout << "Enter Farmer ID: ";
    cin >> farm.id;

    cout << "Enter land address: ";
    cin.ignore();
    getline(cin, land.address);

    cout << "Enter land size (in acres): ";
    cin >> land.size;

    cout << "Enter soil type: ";
    cin.ignore();
    getline(cin, land.soilType);

    outputFile << land.id << " " << farm.id << " " << land.address << " " << land.size << " " << land.soilType << endl;

    outputFile.close();

    cout << "Land details stored in the file successfully." << endl;
}

void insertHarvest(const string& filename) {
    ofstream outputFile(filename, ios::app);

    if (!outputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    Harvest harvest;
    Crop c1;
    Farmer f1;
    Land l1;

    cout << "Enter harvest ID: ";
    cin >> harvest.id;

    cout << "Enter Crop ID: ";
    cin >> c1.id;

    cout << "Enter Farmer ID: ";
    cin >> f1.id;

    cout << "Enter Land ID: ";
    cin >> l1.id;

    cout << "Enter harvest date: ";
    cin.ignore();
    getline(cin, harvest.date);

    cout << "Enter harvest quantity i Kg: ";
    cin >> harvest.quantity;

    outputFile << harvest.id << " " << c1.id << " " << f1.id << " " << l1.id << " " << harvest.date << " " << harvest.quantity << endl;

    outputFile.close();

    cout << "Harvest details stored in the file successfully." << endl;
}

void insertSales(const string& filename) {
    ofstream outputFile(filename, ios::app);

    if (!outputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    Sales sales;
    Crop c2;
    Farmer f2;

    cout << "Enter sales ID: ";
    cin >> sales.id;

    cout << "Enter crop ID: ";
    cin >> c2.id;

    cout << "Enter farmer ID: ";
    cin >> f2.id;

    cout << "Enter sales date: ";
    cin.ignore();
    getline(cin, sales.date);

    cout << "Enter sales quantity in Kg: ";
    cin >> sales.quantity;

    cout << "Enter sales price per Kg: ";
    cin >> sales.price;

    outputFile << sales.id << " " << c2.id << " " << f2.id << " " << sales.date << " " << sales.quantity << " " << sales.price << endl;

    outputFile.close();

    cout << "Sales details stored in the file successfully." << endl;
}

void displayCrop(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        // Extract fields from the line
        int id;
        string name, season;
        double price;

        // Use stringstream for extraction
        stringstream ss(line);
        string field;

        // Extract ID
        getline(ss, field, ' ');
        id = stoi(field);

        // Extract name
        getline(ss, name, ' ');

        // Extract season
        getline(ss, season, ' ');

        // Extract price
        getline(ss, field, ' ');
        price = stod(field);

        // Print the extracted crop data
        cout << "-------------------------" << endl;
        cout << "Crop ID: " << id << endl;
        cout << "Crop Name: " << name << endl;
        cout << "Planting Season: " << season << endl;
        cout << "Crop Price: " << price << endl;
        cout << "-------------------------" << endl;
    }

    inputFile.close();
}

void displayFarmer(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        // Extract fields from the line
        int id;
        string name, address, phoneNumber;

        // Use stringstream for extraction
        stringstream ss(line);
        string field;

        // Extract ID
        getline(ss, field, ' ');
        id = stoi(field);

        // Extract name
        getline(ss, name, ' ');

        // Extract address
        getline(ss, address, ' ');

        // Extract phone number
        getline(ss, phoneNumber, ' ');

        // Print the extracted farmer data
        cout << "-------------------------" << endl;
        cout << "Farmer ID: " << id << endl;
        cout << "Farmer Name: " << name << endl;
        cout << "Farmer Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "-------------------------" << endl;
    }

    inputFile.close();
}

void displayLand(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        // Extract fields from the line
        int id,fid;
        string address, soilType;
        double size;

        // Use stringstream for extraction
        stringstream ss(line);
        string field;

        // Extract ID
        getline(ss, field, ' ');
        id = stoi(field);

        getline(ss, field, ' ');
        fid = stoi(field);


        // Extract address
        getline(ss, address, ' ');

        // Extract size
        getline(ss, field, ' ');
        size = stod(field);

        // Extract soil type
        getline(ss, soilType, ' ');

        // Print the extracted land data
        cout << "-------------------------" << endl;
        cout << "Land ID: " << id << endl;
        cout << "Farmer ID: " << fid << endl;
        cout << "Land Address: " << address << endl;
        cout << "Land Size (acres): " << size << endl;
        cout << "Soil Type: " << soilType << endl;
        cout << "-------------------------" << endl;
    }

    inputFile.close();
}

void displayHarvest(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        // Extract fields from the line
        int id,cid,fid,lid;
        string date;
        double quantity;

        // Use stringstream for extraction
        stringstream ss(line);
        string field;

        // Extract ID
        getline(ss, field, ' ');
        id = stoi(field);

        getline(ss, field, ' ');
        cid = stoi(field);

        getline(ss, field, ' ');
        fid = stoi(field);

        getline(ss, field, ' ');
        lid = stoi(field);


        // Extract date
        getline(ss, date, ' ');

        // Extract quantity
        getline(ss, field, ' ');
        quantity = stod(field);

        // Print the extracted harvest data
        cout << "-------------------------" << endl;
        cout << "Harvest ID: " << id << endl;
        cout << "Crop ID: " << cid << endl;
        cout << "Farmer ID: " << fid << endl;
        cout << "Land ID: " << lid << endl;
        cout << "Harvest Date: " << date << endl;
        cout << "Harvest Quantity in Kg: " << quantity << endl;
        cout << "-------------------------" << endl;
    }

    inputFile.close();
}

void displaySales(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        // Extract fields from the line
        int id,cid,fid;
        string date;
        double quantity, price;

        // Use stringstream for extraction
        stringstream ss(line);
        string field;

        // Extract ID
        getline(ss, field, ' ');
        id = stoi(field);

        getline(ss, field, ' ');
        cid = stoi(field);

        getline(ss, field, ' ');
        fid = stoi(field);

        // Extract date
        getline(ss, date, ' ');

        // Extract quantity
        getline(ss, field, ' ');
        quantity = stod(field);

        // Extract price
        getline(ss, field, ' ');
        price = stod(field);

        // Print the extracted sales data
        cout << "-------------------------" << endl;
        cout << "Sales ID: " << id << endl;
        cout << "Crop ID: " << cid << endl;
        cout << "Farmer ID: " << fid << endl;
        cout << "Sales Date: " << date << endl;
        cout << "Sales Quantity in Kg: " << quantity << endl;
        cout << "Sales Price per kg: " << price << endl;
        cout << "-------------------------" << endl;
    }

    inputFile.close();
}

void modifyCrop(const string& filename, int cropID) {
    ifstream inputFile(filename);
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        // Extract fields from the line
        int id;
        string name, season;
        double price;

        // Use stringstream for extraction
        stringstream ss(line);
        string field;

        // Extract ID
        getline(ss, field, ' ');
        id = stoi(field);

        // Check if the ID matches
        if (id == cropID) {
            found = true;

            // Extract name
            getline(ss, name, ' ');

            // Extract season
            getline(ss, season, ' ');

            // Extract price
            getline(ss, field, ' ');
            price = stod(field);

            // Prompt for modification
            cout << "Enter new crop name (current: " << name << "): ";
            cin >> name;

            cout << "Enter new planting season (current: " << season << "): ";
            cin >> season;

            cout << "Enter new crop price (current: " << price << "): ";
            cin >> price;

            // Write the modified data to temp file
            tempFile << id << " " << name << " " << season << " " << price << endl;
        }
        else {
            // Write unchanged data to temp file
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (!found) {
        cerr << "Crop with ID " << cropID << " not found." << endl;
        remove("temp.txt");
        return;
    }

    // Replace the original file with the modified temp file
    if (remove(filename.c_str()) != 0) {
        cerr << "Error deleting the file." << endl;
        return;
    }

    if (rename("temp.txt", filename.c_str()) != 0) {
        cerr << "Error renaming the file." << endl;
        return;
    }

    cout << "Crop with ID " << cropID << " modified successfully." << endl;
}


void modifyFarmer(const string& filename, int farmerID) {
    ifstream inputFile(filename);
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        // Extract fields from the line
        int id;
        string name, address, phoneNumber;

        // Use stringstream for extraction
        stringstream ss(line);
        string field;

        // Extract ID
        getline(ss, field, ' ');
        id = stoi(field);

        // Check if the ID matches
        if (id == farmerID) {
            found = true;

            // Extract name
            getline(ss, name, ' ');

            // Extract address
            getline(ss, address, ' ');

            // Extract phone number
            getline(ss, phoneNumber, ' ');

            // Modify farmer details
            Farmer modifiedFarmer;
            modifiedFarmer.id = farmerID;

            cout << "Enter modified farmer name: ";
            cin>> modifiedFarmer.name;

            cout << "Enter modified farmer address: ";
            cin >> modifiedFarmer.address;

            cout << "Enter modified farmer phone number: ";
            cin >> modifiedFarmer.phoneNumber;

            // Write modified details to temporary file
            tempFile << modifiedFarmer.id << " " << modifiedFarmer.name << " "
                     << modifiedFarmer.address << " " << modifiedFarmer.phoneNumber << endl;
        } else {
            // Write unchanged details to temporary file
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (found) {
        // Replace the original file with the modified file
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        cout << "Farmer details modified successfully." << endl;
    } else {
        cout << "Farmer ID not found." << endl;
    }
}

void modifyLand(const string& filename, int landID) {
    ifstream inputFile(filename);
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        // Extract fields from the line
        int id,fid;
        string address, soilType;
        double size;

        // Use stringstream for extraction
        stringstream ss(line);
        string field;

        // Extract ID
        getline(ss, field, ' ');
        id = stoi(field);

        // Check if the ID matches
        if (id == landID) {
            found = true;

            getline(ss, field, ' ');
            fid = stoi(field);

            // Extract address
            getline(ss, address, ' ');

            // Extract size
            getline(ss, field, ' ');
            size = stod(field);

            // Extract soil type
            getline(ss, soilType, ' ');

            // Modify land details
            Land modifiedLand;
            modifiedLand.id = landID;

            cout << "Enter modified Farmer id: ";
            cin >> modifiedLand.id;

            cout << "Enter modified land address: ";
            cin >> modifiedLand.address;

            cout << "Enter modified land size (in acres): ";
            cin >> modifiedLand.size;

            cout << "Enter modified soil type: ";
            cin.ignore();
            cin >> modifiedLand.soilType;

            // Write modified details to temporary file
            tempFile << modifiedLand.id << " " << modifiedLand.id << " " << modifiedLand.address << " "
                     << modifiedLand.size << " " << modifiedLand.soilType << endl;
        } else {
            // Write unchanged details to temporary file
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (found) {
        // Replace the original file with the modified file
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        cout << "Land details modified successfully." << endl;
    } else {
        cout << "Land ID not found." << endl;
    }
}

void modifyHarvest(const string& filename, int harvestID) {
    ifstream inputFile(filename);
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        // Extract fields from the line
        int id,cid,fid,lid;
        string date;
        double quantity;

        // Use stringstream for extraction
        stringstream ss(line);
        string field;

        // Extract ID
        getline(ss, field, ' ');
        id = stoi(field);

        // Check if the ID matches
        if (id == harvestID) {
            found = true;

            getline(ss, field, ' ');
            cid = stoi(field);

            getline(ss, field, ' ');
            fid = stoi(field);

            getline(ss, field, ' ');
            lid = stoi(field);

            // Extract date
            getline(ss, date, ' ');

            // Extract quantity
            getline(ss, field, ' ');
            quantity = stod(field);

            // Modify harvest details
            Harvest modifiedHarvest;
            modifiedHarvest.id = harvestID;

            cout << "Enter modified Crop id: ";
            cin >> modifiedHarvest.cid;

            cout << "Enter modified Farmer id: ";
            cin >> modifiedHarvest.fid;

            cout << "Enter modified Land id: ";
            cin >> modifiedHarvest.lid;

            cout << "Enter modified harvest date: ";
            cin >> modifiedHarvest.date;

            cout << "Enter modified harvest quantity in Kg: ";
            cin >> modifiedHarvest.quantity;

            // Write modified details to temporary file
            tempFile << modifiedHarvest.id << " " << modifiedHarvest.id << " " << modifiedHarvest.id << " " << modifiedHarvest.id << " " << modifiedHarvest.date << " "
                     << modifiedHarvest.quantity << endl;
        } else {
            // Write unchanged details to temporary file
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (found) {
        // Replace the original file with the modified file
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        cout << "Harvest details modified successfully." << endl;
    } else {
        cout << "Harvest ID not found." << endl;
    }
}

void modifySales(const string& filename, int salesID) {
    ifstream inputFile(filename);
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        // Extract fields from the line
        int id,cid,fid;
        string date;
        double quantity, price;

        // Use stringstream for extraction
        stringstream ss(line);
        string field;

        // Extract ID
        getline(ss, field, ' ');
        id = stoi(field);

        // Check if the ID matches
        if (id == salesID) {
            found = true;

            getline(ss, field, ' ');
            cid = stoi(field);

            getline(ss, field, ' ');
            fid = stoi(field);

            // Extract date
            getline(ss, date, ' ');

            // Extract quantity
            getline(ss, field, ' ');
            quantity = stod(field);

            // Extract price
            getline(ss, field, ' ');
            price = stod(field);

            // Modify sales details
            Sales modifiedSales;
            modifiedSales.id = salesID;

            cout << "Enter modified Crop id: ";
            cin >> modifiedSales.cid;

            cout << "Enter modified Farmer id: ";
            cin >> modifiedSales.fid;

            cout << "Enter modified sales date: ";
            cin >> modifiedSales.date;

            cout << "Enter modified sales quantity in Kg: ";
            cin >> modifiedSales.quantity;

            cout << "Enter modified sales price per Kg: ";
            cin >> modifiedSales.price;

            // Write modified details to temporary file
            tempFile << modifiedSales.id << " " << modifiedSales.id << " " << modifiedSales.id << " " << modifiedSales.date << " "
                     << modifiedSales.quantity << " " << modifiedSales.price << endl;
        } else {
            // Write unchanged details to temporary file
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (found) {
        // Replace the original file with the modified file
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        cout << "Sales details modified successfully." << endl;
    } else {
        cout << "Sales ID not found." << endl;
    }
}
void deleteCropRecord(const string& filename, int idToDelete) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile.is_open()) {
        cerr << "Error creating temporary file." << endl;
        inFile.close(); // Close the input file before returning
        return;
    }

    string line;
    bool recordDeleted = false;

    while (getline(inFile, line)) {
        stringstream ss(line);
        Crop crop;
        ss >> crop.id >> crop.name >> crop.season >> crop.price;

        if (crop.id != idToDelete) {
            tempFile << line << endl;
        } else {
            recordDeleted = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (recordDeleted) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
        cout << "Record with ID " << idToDelete << " deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Record with ID " << idToDelete << " not found." << endl;
    }
}
void deleteFarmerRecord(const string& filename, int farmerid) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        inFile.close();
        return;
    }

    string line;
    bool recordDeleted = false;

    while (getline(inFile, line)) {
        stringstream ss(line);
        Farmer farmer;
        ss >> farmer.id >> farmer.name >> farmer.address >> farmer.phoneNumber;

        if (farmer.id != farmerid) {
            tempFile << line << endl;
        } else {
            recordDeleted = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (recordDeleted) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
        cout << "Record with ID " << farmerid << " deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Record with ID " << farmerid << " not found." << endl;
    }
}
void deleteLandRecord(const string& filename, int landid) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        inFile.close();
        return;
    }

    string line;
    bool recordDeleted = false;

    while (getline(inFile, line)) {
        stringstream ss(line);
        Land land;
        ss >> land.id >> land.address >> land.size >> land.soilType;

        if (land.id != landid) {
            tempFile << line << endl;
        }
        else
            recordDeleted = true;
    }

    inFile.close();
    tempFile.close();

    if (recordDeleted) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
        cout << "Record with ID " << landid << " deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Record with ID " << landid << " not found." << endl;
    }
}
void deleteHarvestRecord(const string& filename, int harvid) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        inFile.close();
        return;
    }

    string line;
    bool recordDeleted = false;

    while (getline(inFile, line)) {
        stringstream ss(line);
        Harvest harvest;
        ss >> harvest.id >> harvest.date >> harvest.quantity;

        if (harvest.id != harvid) {
            tempFile << line << endl;
        } else {
            recordDeleted = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (recordDeleted) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
        cout << "Record with ID " << harvid << " deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Record with ID " << harvid << " not found." << endl;
    }
}
void deleteSalesRecord(const string& filename, int salid) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        inFile.close();
        return;
    }

    string line;
    bool recordDeleted = false;

    while (getline(inFile, line)) {
        stringstream ss(line);
        Sales salesRecord;
        ss >> salesRecord.id >> salesRecord.date >> salesRecord.quantity >> salesRecord.price;

       if (salesRecord.id != salid) {
            tempFile << line << endl;
        } else {
            recordDeleted = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (recordDeleted) {
        // Replace the original file with the modified temporary file
        remove(filename.c_str());                  // Delete the original file
        rename("temp.txt", filename.c_str());       // Rename the temporary file
        cout << "Record with ID " << salid << " deleted successfully." << endl;
    } else {
        remove("temp.txt");  // Delete the temporary file
        cout << "Record with ID " << salid << " not found." << endl;
    }
}

bool searchCropRecord(const string& filename, int searchcId, Crop& foundCrop) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        Crop cropRecord;
        if (iss >> cropRecord.id >> cropRecord.name >> cropRecord.season >> cropRecord.price) {
            if (cropRecord.id == searchcId) {
                foundCrop = cropRecord;
                inFile.close();
                return true;
            }
        }
    }

    inFile.close();
    return false;
}
bool searchFarmerRecord(const string& filename, int searchfId, Farmer& foundFarmer) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        Farmer farmerRecord;
        if (iss >> farmerRecord.id >> farmerRecord.name >> farmerRecord.address >> farmerRecord.phoneNumber) {
            if (farmerRecord.id == searchfId) {
                foundFarmer = farmerRecord;
                inFile.close();
                return true;
            }
        }
    }

    inFile.close();
    return false;
}

bool searchLandRecord(const string& filename, int searchId, Land& foundLand) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        Land landRecord;
        if (iss >> landRecord.id >>landRecord.id >> landRecord.address >> landRecord.size >> landRecord.soilType) {
            if (landRecord.id == searchId) {
                foundLand = landRecord;
                inFile.close();
                return true;
            }
        }
    }

    inFile.close();
    return false;
}

bool searchHarvestRecord(const string& filename, int searchhId, Harvest& foundHarvest) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        Harvest harvestRecord;
        if (iss >> harvestRecord.id >>harvestRecord.cid >>harvestRecord.fid >>harvestRecord.lid >> harvestRecord.date >> harvestRecord.quantity) {
            if (harvestRecord.id == searchhId) {
                foundHarvest = harvestRecord;
                inFile.close();
                return true;
            }
        }
    }

    inFile.close();
    return false;
}

bool searchSalesRecord(const string& filename, int searchsId, Sales& foundSales) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        Sales salesRecord;
        if (iss >> salesRecord.id >>salesRecord.cid >> salesRecord.fid >>  salesRecord.date >> salesRecord.quantity >> salesRecord.price) {
            if (salesRecord.id == searchsId) {
                foundSales = salesRecord;
                inFile.close();
                return true;
            }
        }
    }

    inFile.close();
    return false;
}

int main() {
    int choice;
    string filename;

     cout << "1. crops.txt\n";
            cout << "2. farmer.txt\n";
            cout << "3. land.txt\n";
            cout << "4. harvest.txt\n";
            cout << "5. sales.txt\n";
            cout << "Choose your file: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    filename="crops.txt";
                    break;
                case 2:
                    filename="farmer.txt";
                    break;
                case 3:
                    filename="land.txt";
                    break;
                case 4:
                    filename="harvest.txt";
                    break;
                case 5:
                    filename="sales.txt";
                        break;
            }

    do{
        if(filename=="crops.txt"){
            cout << "1. Insert Crop\n";
            cout << "2. Display Crop\n";
            cout << "3. Modify Crop\n";
            cout << "4. Delete Crop\n";
            cout << "5. Search Crop\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    insertCrop(filename);
                    break;
                case 2:
                    displayCrop(filename);
                    break;
                case 3:
                    int modifyID;
                    cout << "Enter the ID of the record to modify: ";
                    cin >> modifyID;
                    modifyCrop(filename, modifyID);
                    break;
                case 4:
                    int idToDelete;

                    cout << "Enter the ID of the record to delete: ";
                    cin >> idToDelete;

                    deleteCropRecord("crops.txt", idToDelete);
                    break;
                case 5:{
                    string filename = "crops.txt";
                    int searchcId;

                    cout << "Enter the ID to search: ";
                    cin >> searchcId;

                    Crop foundCrop;
                    bool recordFoundc = searchCropRecord(filename, searchcId, foundCrop);

                    if (recordFoundc) {
                        cout << "-------------------------" << endl;
                        cout << "Record found:" << endl;
                        cout << "ID: " << foundCrop.id << endl;
                        cout << "Name: " << foundCrop.name << endl;
                        cout << "Season: " << foundCrop.season << endl;
                        cout << "Price: " << foundCrop.price << endl;
                        cout << "-------------------------" << endl;
                    }
                    else {
                        cout << "Record with ID " << searchcId << " not found." << endl;
                    }
                }
                    break;
            }
    }
        else if(filename=="farmer.txt"){
            cout << "1. Insert Farmer\n";
            cout << "2. Display Farmer\n";
            cout << "3. Modify Farmer\n";
            cout << "4. Delete Farmer\n";
            cout << "5. Search Farmer\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    insertFarmer(filename);
                    break;
                case 2:
                    displayFarmer(filename);
                    break;
                case 3:
                    int modifyID;
                    cout << "Enter the ID of the record to modify: ";
                    cin >> modifyID;
                    modifyFarmer(filename, modifyID);
                    break;
                case 4:
                    int farmerid;

                    cout << "Enter the ID of the record to delete: ";
                    cin >> farmerid;

                    deleteFarmerRecord("farmer.txt", farmerid);
                    break;
                case 5:{

                    string filename = "farmer.txt";
                    int searchfId;

                    cout << "Enter the ID to search: ";
                    cin >> searchfId;

                    Farmer foundFarmer;
                    bool recordFoundf = searchFarmerRecord(filename, searchfId, foundFarmer);

                    if (recordFoundf) {
                        cout << "-------------------------" << endl;
                        cout << "Record found:" << endl;
                        cout << "ID: " << foundFarmer.id << endl;
                        cout << "Name: " << foundFarmer.name << endl;
                        cout << "Address: " << foundFarmer.address << endl;
                        cout << "Phone Number: " << foundFarmer.phoneNumber << endl;
                        cout << "-------------------------" << endl;
                    } else {
                        cout << "Record with ID " << searchfId << " not found." << endl;
                    }
                }
                    break;
            }
            }
       else if(filename=="land.txt"){
            cout << "1. Insert Land\n";
            cout << "2. Display Land\n";
            cout << "3. Modify Land\n";
            cout << "4. Delete Land\n";
            cout << "5. Search Land\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    insertLand(filename);
                    break;
                case 2:
                    displayLand(filename);
                    break;
                case 3:
                    int modifyID;
                    cout << "Enter the ID of the record to modify: ";
                    cin >> modifyID;
                    modifyLand(filename, modifyID);
                    break;
                case 4:
                    int landid,farmerid;

                    cout << "Enter the ID of the record to delete: ";
                    cin >> landid;

                    cout << "Enter the Farmer ID: ";
                    cin >> farmerid;

                    deleteLandRecord("land.txt", landid);
                    deleteFarmerRecord("farmer.txt", farmerid);
                    break;
                case 5:{
                    int searchId;

                    cout << "Enter the ID to search: ";
                    cin >> searchId;

                    Land foundLand;
                    Farmer fr;
                    bool recordFound = searchLandRecord(filename, searchId, foundLand);

                    if (recordFound) {
                        cout << "-------------------------" << endl;
                        cout << "Record found:" << endl;
                        cout << "ID: " << foundLand.id << endl;
                        cout << "Farmer ID: " <<foundLand.fid << endl;
                        cout << "Address: " << foundLand.address << endl;
                        cout << "Size: " << foundLand.size << endl;
                        cout << "Soil Type: " << foundLand.soilType << endl;
                        cout << "-------------------------" << endl;
                    } else {
                        cout << "Record with ID " << searchId << " not found." << endl;
                    }
                }
                    break;

            }
       }
       else if(filename=="harvest.txt"){
            cout << "1. Insert Harvest\n";
            cout << "2. Display Harvest\n";
            cout << "3. Modify Harvest\n";
            cout << "4. Delete Harvest\n";
            cout << "5. Search Harvest\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    insertHarvest(filename);
                    break;
                case 2:
                    displayHarvest(filename);
                    break;
                case 3:
                    int modifyID;
                    cout << "Enter the ID of the record to modify: ";
                    cin >> modifyID;
                    modifyHarvest(filename, modifyID);
                    break;
                case 4:
                    int harvid,cropid;

                    cout << "Enter the ID of the record to delete: ";
                    cin >> harvid;

                    cout << "Enter the Crop ID: ";
                    cin >> cropid;

                    deleteHarvestRecord("harvest.txt", harvid);
                    deleteCropRecord("crops.txt", cropid);
                    break;
                case 5:{
                    string filename = "harvest.txt";
                    int searchhId;

                    cout << "Enter the ID to search: ";
                    cin >> searchhId;

                    Harvest foundHarvest;
                    bool recordFoundh = searchHarvestRecord(filename, searchhId, foundHarvest);

                    if (recordFoundh) {
                        cout << "-------------------------" << endl;
                        cout << "Record found:" << endl;
                        cout << "ID: " << foundHarvest.id << endl;
                        cout << "Crop ID: " << foundHarvest.cid << endl;
                        cout << "Farmer ID: " << foundHarvest.fid << endl;
                        cout << "Land ID: " << foundHarvest.lid << endl;
                        cout << "Date: " << foundHarvest.date << endl;
                        cout << "Quantity in Kg: " << foundHarvest.quantity << endl;
                        cout << "-------------------------" << endl;
                    } else {
                        cout << "Record with ID " << searchhId << " not found." << endl;
                    }
                }
                break;
            }
       }
        else if(filename=="sales.txt"){
            cout << "1. Insert Sales\n";
            cout << "2. Display Sales\n";
            cout << "3. Modify Sales\n";
            cout << "4. Delete Sales\n";
            cout << "5. Search Sales\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    insertSales(filename);
                    break;
                case 2:
                    displaySales(filename);
                    break;
                case 3:
                    int modifyID;
                    cout << "Enter the ID of the record to modify: ";
                    cin >> modifyID;
                    modifySales(filename, modifyID);
                    break;
                case 4:
                    int salid,cropid;

                    cout << "Enter the ID of the record to delete: ";
                    cin >> salid;

                    cout << "Enter the Crop ID: ";
                    cin >> cropid;

                    deleteSalesRecord("sales.txt", salid);
                    deleteCropRecord("crops.txt", cropid);
                    break;
                case 5:{
                    string filename = "sales.txt";
                    int searchsId;

                    cout << "Enter the ID to search: ";
                    cin >> searchsId;

                    Sales foundSales;
                    bool recordFounds = searchSalesRecord(filename, searchsId, foundSales);

                    if (recordFounds) {
                        cout << "-------------------------" << endl;
                        cout << "Record found:" << endl;
                        cout << "ID: " << foundSales.id << endl;
                        cout << "Crop ID: " << foundSales.cid << endl;
                        cout << "Farmer ID: " << foundSales.fid << endl;
                        cout << "Date: " << foundSales.date << endl;
                        cout << "Quantity in Kg: " << foundSales.quantity << endl;
                        cout << "Price per Kg: " << foundSales.price << endl;
                        cout << "-------------------------" << endl;
                    } else {
                        cout << "Record with ID " << searchsId << " not found." << endl;
                    }
                }
                    break;
            }
    }
    else
        cout<<"You entered wrong file Name\n";
    }while(choice != 0);

    return 0;
}

