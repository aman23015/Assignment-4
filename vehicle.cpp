#include "read.h"

details VehicleDataBase :: search(string vehicle_number) {
    bool var = 0;
    int i=0;
    for(; i < this->veh_array.size(); i++) {
        if ( this->veh_array[i].vehicle_number  ==  vehicle_number ) {
            var = 1;
            break;
        }
    }
    if (!var) {
        std::cout << "\tEntry Not Found in the Database !" << endl;
        return details("", "", "", "", "", "");
    }  
    else {
        return veh_array[i];
    }
}
 
void VehicleDataBase :: read_details_owner(string file_name) {
    vector<string> row;
    string line, word;

    fstream file (file_name, ios::in);
    if (file.is_open()) {
        getline(file, line);
        while(getline(file, line)) {
            row.clear();
            stringstream str(line);
            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            this->n_vehicles += 1;

            details vehicle(row[0] + row[1], row[2], row[3], row[4], row[5], row[6]);
            this->veh_array.push_back(vehicle);
        }
    }
    else {
        std::cout << "\tCoudn't open the file." << endl;
    }
}

void VehicleDataBase :: owners_details(string vehicle_num) {
    details vehicle_obj = this->search(vehicle_num);
 
    if (vehicle_obj.vehicle_number != "") {
        string v_num = vehicle_obj.vehicle_number;
        string f_name = vehicle_obj.first_name;
        string l_name = vehicle_obj.last_name;
        string age = vehicle_obj.age;
        string gender = vehicle_obj.gender;
        string address = vehicle_obj.address;

        std::cout << "\t---Driver Details---" << endl;
        std::cout << "Ether the Vehicle Number: " << v_num << endl;
        std::cout << "Ether the Driver Name: " << f_name << " " << l_name << endl;
        std::cout << "Ether the Driver Age: " << age << endl;
        std::cout << "Ether the Driver Gender: " << gender << endl;
        std::cout << "Ether the Driver Address: " << address << endl;
        std::cout << endl;
    }
}

void VehicleDataBase :: vehical_details() {
    std::cout << "\tVehicle Number, Name, Age, Gender, location" << endl;
    std::cout << endl;
    for (int i = 0; i < this -> veh_array.size(); i++) {
        std::cout << "\t";
        std::cout << this -> veh_array[i].vehicle_number + ", ";
        std::cout << this -> veh_array[i].first_name + " " + this -> veh_array[i].last_name + ", ";
        std::cout << this -> veh_array[i].age + ", ";
        std::cout << this -> veh_array[i].gender + ", ";
        std::cout << this -> veh_array[i].address;

        std::cout << endl;
    }
    std::cout << endl;
}



void VehicleDataBase :: remove_detail(string vehicle_number) {
    details vehicle_obj = this->search(vehicle_number);
    if (vehicle_obj.vehicle_number != "") {
        auto it = this->veh_array.begin();
        for(;it != this->veh_array.end(); it++) {
            if (it->vehicle_number == vehicle_obj.vehicle_number) {
                break;
            }
        }
        this->veh_array.erase(it);
        this->n_vehicles -= 1; 
        cout << "\tEntry Successfully deleted!" << endl;
    }
}


void VehicleDataBase :: New_entry() {
    string v_num;
    string f_name;
    string l_name;
    string age;
    string gender;
    string address;

    cout << "\tEther the Vehicle Number: ";
    cin >> v_num;
    cout << "Ether the First Name: "<<endl;
    cin >> f_name;
    cout << "Ether the Last Name: "<<endl;
    cin >> l_name;
    cout << "Ether the Age: "<<endl;
    cin >> age;
    cout << "\nEther the Gender: ";
    cin >> gender;
    cout << "\nEther the Address: ";
    cin.ignore();
    getline(cin, address);

    details vehicle(v_num, f_name, l_name, age, gender, address);
    this->veh_array.push_back(vehicle);
    std::cout << endl;
    std::cout << "\tEntry added Successfully!" << endl;
}

