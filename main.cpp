# include "headers.h"

int main() {

    VehicleDB vdb;
    vdb.readVehicleDetailsCSVFile("A4-Q1.csv");

    ReportDB rdb;
    rdb.readReportFile("A4-Q2.csv");

    UserDB udb;
    udb.readUserFile("A4-Q3.csv");

    bool ask_again = true;
    while(ask_again) {

        cout << "\t---TRAFFIC POLICE MANAGAMENT SYSTEM---" << endl;
        cout << "\t1. Vehicle-Driver Database" << endl;
        cout << "\t2. Vehicle-Report Database" << endl;
        cout << "\t3. User-Address Database" << endl;
        cout << "\t4. Exit" << endl;
        cout << "\tChoice: ";
        int choice;
        cin >> choice;

        switch(choice) {
            case 1: {
                bool do_break_vdb = false;
                while (!do_break_vdb) {
                    cout << "\t---Vehicle-Driver Database---" << endl;
                    cout << "\t1. Display Database" << endl;
                    cout << "\t2. Search User by Vehicle Numer" << endl;
                    cout << "\t3. Add a record" << endl;
                    cout << "\t4. Remove a record" << endl;
                    cout << "\t5. Exit" << endl;
                    cout << "\tYour choice: ";
                    int choice;
                    cin >> choice;
                    cout << endl;
                    switch(choice) {
                        case 1: {
                            vdb.printAllVehicleDB();
                        } break;
                        case 2: {
                            string vehicle_num;
                            cout << "\tVehicle Number: ";
                            cin >> vehicle_num;
                            vdb.printDriverDetailsByVehicleNumber(vehicle_num);
                        } break;
                        case 3: {
                            vdb.askAndAddEntry();
                        } break;
                        case 4: {
                            string v_num_to_delete;
                            bool is_found = false;
                            cout << "\tVehicle Number: ";
                            cin >> v_num_to_delete; 
                            vdb.removeEntry(v_num_to_delete);
                        } break;
                        case 5: {
                            do_break_vdb = true;
                        } break;

                        default: {
                            cout << "\tInvalid Choice, exiting program!" << endl;
                            exit(1);
                        } break;
                    }
                }

            } break;
            
            case 2: {
                bool do_break_rdb = false;
                while(!do_break_rdb) {
                    cout << "\t---Vehicle-Report Database---" << endl;
                    cout << "\t1. Display Database" << endl;
                    cout << "\t2. Print Report By Vehicle Number" << endl;
                    cout << "\t3. Print Report By Type" << endl;
                    cout << "\t4. Print Report By Location" << endl;
                    cout << "\t5. Exit" << endl;

                    cout << "\tChoice: ";
                    int choice;
                    cin >> choice;

                    switch(choice) {
                        case 1: {
                            rdb.printAllReports();
                        } break;

                        case 2: {
                            cout << "\tVehicle Number: ";
                            string v_number_rdb;
                            cin.ignore();
                            getline(cin, v_number_rdb);

                            rdb.printReportByVehicleNumber(v_number_rdb);
                        } break;

                        case 3: {
                            cout << "\tReport Type: ";
                            string type;
                            cin.ignore();
                            getline(cin, type);

                            rdb.printReportByType(type);
                        } break;

                        case 4: {
                            cout << "\tLocation: ";
                            string location;
                            cin.ignore();
                            getline(cin, location);

                            rdb.printAllReportsByLocation(location);
                        } break;

                        case 5: {
                            do_break_rdb = true;
                        } break;

                        default: {
                            cout << "\tInvalid Choice, exiting program!" << endl;
                            exit(1);
                        } break;

                    }
                }
            } break;

            case 3: {
                bool do_break_udb = false;
                while(!do_break_udb) {
                    cout << "\t---User-Address Database---" << endl;
                    cout << "\t1. Display Database" << endl;
                    cout << "\t2. Print All Users By User Name" << endl;
                    cout << "\t3. Print All Users By Location" << endl;
                    cout << "\t4. Print All Users By Gender" << endl;
                    cout << "\t5. Print User By Vehicle Number" << endl;
                    cout << "\t6. Exit" << endl;

                    cout << "\tChoice: ";
                    int choice;
                    cin >> choice;

                    switch(choice) {
                        case 1: {
                            udb.printAllUsers();
                        } break;

                        case 2: {
                            cout << "\tFirst Name: ";
                            string first_name;
                            cin >> first_name;
                            cout << "\tLast Name: ";
                            string last_name;
                            cin >> last_name;

                            udb.printUserByName(first_name, last_name);
                        } break;

                        case 3: {
                            cout << "\tLocation: ";
                            string location;
                            cin.ignore();
                            getline(cin, location);

                            udb.printUserByLocation(location);
                        } break;

                        case 4: {
                            cout << "\tGender: ";
                            string gender;
                            cin >> gender;

                            udb.printUserByGender(gender);
                        } break;

                        case 5: {
                            cout << "\tVehicle Number: ";
                            string vehicle_number;
                            cin >> vehicle_number;

                            udb.searchUserByVehicleNumber(vdb, vehicle_number);
                        } break;

                        case 6: {
                            do_break_udb = true;
                        } break;

                        default: {
                            cout << "\tInvalid Choice, exiting program!" << endl;
                            exit(1);
                        } break;

                    }
                }
            } break;

            case 4: {
                cout << "\tGoodBye!" << endl;
                ask_again = false;
            } break;

            default: {
                cout << "Invalid choice, exiting program!" << endl;
                exit(1);
            } break;
        }
    }
    return 0;
}