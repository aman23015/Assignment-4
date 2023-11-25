# include "read.h"

int main() {

    VehicleDataBase obj_1;
    obj_1.read_details_owner("A4-Q1.csv");
    while (true) {
        cout << "\tVehicle-Driver Database" << endl;
        cout << "\t1. Display Database" << endl;
        cout << "\t2. Search User by Vehicle Numer" << endl;
        cout << "\t3. Remove a record" << endl;
        cout << "\t4. Add a record  " << endl;
        cout << "\t5. Exit" << endl;
        cout << "\tYour choice: ";
        int choice;
        cin >> choice;
        cout << endl;
        switch(choice) {
            case 1: {
                obj_1.vehical_details();
            } break;
            case 2: {
                string vehicle_num;
                cout << "\tVehicle Number: ";
                cin >> vehicle_num;
                obj_1.owners_details(vehicle_num);
            } break;
            case 3: {
                string v_num_to_delete;
                bool is_found = false;
                cout << "\tVehicle Number: ";
                cin >> v_num_to_delete; 
                obj_1.remove_detail(v_num_to_delete);
            } break;
            case 4: {
                obj_1.New_entry();
            } break;
            default: {
                cout << "\tGoodBye!" << endl;
                exit(1);
            } break;
        }
    }

    return 0;
}