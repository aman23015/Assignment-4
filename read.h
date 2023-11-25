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