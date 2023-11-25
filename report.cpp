#include "read.h"

void Problem_Data::Read(string input) {
    string row, var;
    vector<string> entry;

    fstream name(input, ios::in);
    if (name.is_open()) {
        getline(name, row);
        while (getline(name, row)) {
            entry.clear();
            stringstream str(row);
            while (getline(str, var, ',')) {
                if (!var.empty()) {
                    size_t start = var.find_first_not_of("\" ");
                    size_t end = var.find_last_not_of("\" ");
                    if (start != string::npos && end != string::npos) {
                        var = var.substr(start, end - start + 1);
                    }
                }
                entry.push_back(var);
            }
            this->n_vehicles += 1;

            problem var(entry[0] + entry[1], entry[2], entry[3]);
            this->obj_3.push_back(var);
        }
    } else {
        cout << "\nError in opening file." << endl;
    }
}

void Problem_Data::View_reports() {
    cout<<endl;
    cout << "\tVehicle Number, Report type, Report Location" << endl;
    cout << endl;
    for (int i = 0; i < this->obj_3.size(); i++) {
        cout << "\t";
        cout << this->obj_3[i].Vehicle_No + ", "<< this->obj_3[i].rep_typ + ", "<< this->obj_3[i].Report_loc<<endl;
    }
    cout << endl;
}

void Problem_Data::vehicle_reports(string vehicle_number) {
    bool found = false;

    for (int i = 0; i < this->obj_3.size(); i++) {
        if (this->obj_3[i].Vehicle_No == vehicle_number) {
            found = true;
            cout << endl;
            cout << "\tReport Details is :-" << endl;
            cout << "\tEnter the Vehicle Number: " << this->obj_3[i].Vehicle_No << endl;
            cout << "\tEnter the Report Type: " << this->obj_3[i].rep_typ << endl;
            cout << "\tEnter the Location: " << this->obj_3[i].Report_loc << endl;
            cout << endl;
        }
    }

    if (!found) {
        cout << "\tNo report found for the specified vehicle number." << endl;
    }
}


void Problem_Data::types(string type) {
    bool var = 0;

    cout << endl;
    cout << "\tVehicle Number, Type of Report, Report Location" << endl;
    cout << endl;
    
    for (int i = 0; i < this->obj_3.size(); i++) {
        if (this->obj_3[i].rep_typ == type) {
            var= 1;
            cout << "\t" << this->obj_3[i].Vehicle_No << ", "
                 << this->obj_3[i].rep_typ << ", "
                 << this->obj_3[i].Report_loc << endl;
        }
    }

    if (!var) {
        cout << "\nError in finding the specified report type." << endl;
    }

    cout << endl;
}


void Problem_Data::view_location(string location) {
    bool found = false;
    cout << endl;
    cout << "\tVehicle Number, Type of Report, Report Location" << endl;
    cout << endl;

    for (int i = 0; i < this->obj_3.size(); i++) {
        if (this->obj_3[i].Report_loc == location) {
            found = true;
            cout<<endl;
            cout << "\t" << this->obj_3[i].Vehicle_No << ", "<< this->obj_3[i].rep_typ << ", " << this->obj_3[i].Report_loc << endl;         
        }
    }

    if (!found) {
        cout << "\tError in finding report." << endl;
    }

    cout << endl;
}