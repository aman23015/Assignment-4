# include<bits/stdc++.h>

using namespace std;

class details {
    public:
        string vehicle_number,first_name,last_name,age,gender,address;

        details(string vn, string fn, string ln, string ag, string G, string Add) {
            this->vehicle_number = vn;
            this->first_name = fn;
            this->last_name = ln;
            this->age = ag;
            this->gender = G;
            this->address = Add;
        }

    
};
class VehicleDataBase {
    public:
        int n_vehicles = 0;
        vector<details> veh_array;
        details search(string Vehicle_No);
        void remove_detail(string Vehicle_No);
        void read_details_owner(string file_name);
        void owners_details(string Vehicle_No);
        void vehical_details();  
        void New_entry();
       
};
class problem {
    public:
        string rep_typ, Vehicle_No,Report_loc;

        problem(string VN, string typ, string Loc) {
            this->Report_loc = Loc;
            this->rep_typ = typ;
            this->Vehicle_No = VN;           
    }
};

class Problem_Data {
    public:
        int n_vehicles = 0;
        vector<problem> obj_3;

        void Read(string input);
        void View_reports();
        void vehicle_reports(string vehicle_number);
        void types(string type);
        void view_location(string location);
};

class User {
    public:
        string first_name;
        string last_name;
        int age;
        string gender;
        string address;

        User(string first_name, string last_name, int age, string gender, string address) {
            this-> first_name = first_name;
            this->last_name = last_name;
            this->age = age;
            this->gender = gender;
            this->address = address;
        }
};

class UserDB {
    public:

        int n_users = 0;
        vector<User> users;

        void readUserFile(string file_name);
        void printAllUsers();
        void printUserByName(string first_name, string last_name);
        void printUserByLocation(string location);
        void printUserByGender(string gender);
        void searchUserByVehicleNumber(VehicleDB& vdb, string vechicle_number);        

};

bool isEntryPresent(vector<User> users, User user);