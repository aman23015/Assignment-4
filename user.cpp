# include "read.h"

bool isEntryPresent(vector<owner> users, owner user) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].first_name == user.first_name && users[i].last_name == user.last_name && users[i].age == user.age && users[i].gender == user.gender && users[i].address == user.address) {
            return true;
        }
    }
    return false;
}

void owner_data::readUserFile(string file_name) {
    vector<string> row;
    string line, word;

    fstream file(file_name, ios::in);
    if (file.is_open()) {
        getline(file, line); 

        while (getline(file, line)) {
            row.clear();
            stringstream str(line);
            while (getline(str, word, ',')) {
                row.push_back(word);
            }

            this->n_users += 1;

            string first_name = row[0];
            string last_name = row[1];
            int age = stoi(row[2]);
            string gender = row[3];
            string address = row[4];

            owner user(first_name, last_name, age, gender, address);
            if ( !isEntryPresent(this->users, user) ) {
                this->users.push_back(user);
            }
        }
    } else {
        cout << "\tCouldn't open the file." << endl;
    }
}

void owner_data::printAllUsers() {
    cout << endl;
    cout << "\tFirst Name, Last Name, Age, Gender, Address" << endl;
    for (int i = 0; i < this->users.size(); i++) {
        cout << "\t" << this->users[i].first_name << ", "
             << this->users[i].last_name << ", "
             << this->users[i].age << ", "
             << this->users[i].gender << ", "
             << this->users[i].address << endl;
    }

    cout << endl;
}

void owner_data::printUserByName(string first_name, string last_name) {
    bool found = false;

    cout << endl;
    cout << "\tFirst Name, Last Name, Age, Gender, Address" << endl;
    for (int i = 0; i < this->users.size(); i++) {
        if (this->users[i].first_name == first_name && this->users[i].last_name == last_name) {
            found = true;
            cout << "\t" << this->users[i].first_name << ", "
                 << this->users[i].last_name << ", "
                 << this->users[i].age << ", "
                 << this->users[i].gender << ", "
                 << this->users[i].address << endl;
        }
    }

    if (!found) {
        cout << "\tUser not found." << endl;
    }

    cout << endl;
}

void owner_data::printUserByLocation(string location) {
    bool found = false;

    cout << endl;
    cout << "\tFirst Name, Last Name, Age, Gender, Address" << endl;
    for (int i = 0; i < this->users.size(); i++) {
        if (this->users[i].address == location) {
            found = true;
            cout << "\t" << this->users[i].first_name << ", "
                 << this->users[i].last_name << ", "
                 << this->users[i].age << ", "
                 << this->users[i].gender << ", "
                 << this->users[i].address << endl;
        }
    }

    if (!found) {
        cout << "\tNo users found in the specified location." << endl;
    }

    cout << endl;
}

void owner_data::printUserByGender(string gender) {
    bool found = false;
    cout << endl;
    cout << "\tFirst Name, Last Name, Age, Gender, Address" << endl;
    for (int i = 0; i < this->users.size(); i++) {
        if (this->users[i].gender == gender) {
            found = true;
            cout << "\t" << this->users[i].first_name << ", "
                 << this->users[i].last_name << ", "
                 << this->users[i].age << ", "
                 << this->users[i].gender << ", "
                 << this->users[i].address << endl;
        }
    }

    if (!found) {
        cout << "\tNo users found with the specified gender." << endl;
    }

    cout << endl;
}

void owner_data::searchUserByVehicleNumber(VehicleDataBase& vdb, string vechicle_number) {
    details vehicle_entry = vdb.search(vechicle_number);
    if (vehicle_entry.vehicle_number != "") {
        int i = 0;
        string updated_address = vehicle_entry.address;
        string update;
        for (; i < this->users.size(); i++ ) {
            if (this->users[i].first_name == vehicle_entry.first_name && this->users[i].last_name == vehicle_entry.last_name && to_string(this->users[i].age) == vehicle_entry.age && this->users[i].address != vehicle_entry.address) {
                cout << endl;
                cout << "\tPrevious address: " << vehicle_entry.address << endl;
                cout << "\tUpdated address: " <<  this->users[i].address << endl;
                cout << "\tAddress Successfully Updated!" << endl;
                updated_address = this->users[i].address;
                update = "Updated ";
            }
            else {
                update = "";
            }
        }
        cout << endl;
        cout << "\t" << update << "User Details:" << endl;
        cout << "\tFirst Name: " << vehicle_entry.first_name << endl;
        cout << "\tLast Name: " << vehicle_entry.last_name << endl;
        cout << "\tAge: " << vehicle_entry.age << endl;
        cout << "\tGender: " << vehicle_entry.gender << endl;
        cout << "\tAddress: " << updated_address << endl;
        cout << endl;
        vehicle_entry.address = updated_address;
    } else {
        cout << "\tVehicle not found." << endl;
    }
}