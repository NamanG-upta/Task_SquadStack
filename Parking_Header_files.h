#include <bits/stdc++.h>
using namespace std;

// Structure of the Parking Lot , i.e. Class
class ParkingLot 
{
    int MAXIMUM_SIZE = 0;
    int CURRENT_CAR_NUMBER = 0;
private:
    // class of car containing the registration number and age.
    class Car{
    public:
        string regNo;
        int age;
        Car(const string &regNo, const int &age) {
            this->regNo = regNo;
        this->age = age;
    }
    };

    bool isEmpty(){
        if(CURRENT_CAR_NUMBER==0 and MAXIMUM_SIZE!=0)
            return true;
        else{
            return false;
        }
    }
    
    bool isFull(){
        if(CURRENT_CAR_NUMBER==MAXIMUM_SIZE)
            return true;
        else
            return false;
    }
 

public:
    // All the required containers i.e, maps and vectors for storing the required record of Car registration number, Age of the person etc.
    map<int,vector<int>> Age_To_Slot_Number;
    map<int,vector<string>> Age_To_RegistrationNumber;
    vector<int> availableSlots;
    map<int,string> Slot_To_Regis_Num;
    map<string,int> regNoToAge;
    map<string,int> carToSlot;
    
    // function to assign parking lot to the car arriving
    void createParkingLot(int lotCount) {
        try {
            if(lotCount<0)
                throw lotCount;
                this->MAXIMUM_SIZE = lotCount;
        } 
        catch (int lot) {
            cout<<"Invalid lot count"<<endl;
        }

        availableSlots.assign(MAXIMUM_SIZE+1,0);
        cout<<"Created parking lot with "<<lotCount<<" slots"<<endl;
    }

    // function to return registration numbers of the car using the Age of the persons 
    void getRegistrationNumbersFromAge(int age)  {
        if (this->MAXIMUM_SIZE == 0) {
            cout<<"Sorry, parking lot is not created"<<endl;
        } 
        else if(Age_To_RegistrationNumber[age].size()>0){
            cout<<"The following are the registration number of cars with driver of age "<<age<<endl;
            for(string no: Age_To_RegistrationNumber[age]){
                cout<<no<<endl;
            }
        }
        else 
        {
            cout<<"Not found"<<endl<<endl;
        }
    }

    // function of parking a car. If parking slots are available then the 
    // slot is assigned to the car and the number is pushed in all the required 
    // containers.
    void park(string regNo, int age) {
        if (this->MAXIMUM_SIZE == 0) {
        cout<<"Sorry, parking lot is not created"<<endl;
        } else if (isFull()) {
        cout<<"Sorry, parking lot is full"<<endl;
        } else {
        int vac;
        for(int i=1;i<=MAXIMUM_SIZE;i++){
            if(availableSlots[i]==0){
                vac = i;
                break;
            }
        }
        // here all the containers are assigned the required values.
        availableSlots[vac] = 1;
        carToSlot[regNo] = vac;
        Age_To_Slot_Number[age].push_back(vac);
        Slot_To_Regis_Num[vac] = regNo;
        regNoToAge[regNo] = age;
        Age_To_RegistrationNumber[age].push_back(regNo);
        CURRENT_CAR_NUMBER++;
        cout<<"Car with vehicle registration number \""<<regNo<<"\" has been parked at slot number "<<vac<<endl;
        }
    }

    // function to return slot number of the parking lot from the age of the person
    void getSlotNumbersFromAge(int age){
        if (this->MAXIMUM_SIZE == 0) 
        {
            cout<<"Sorry, parking lot is not created"<<endl;
        } 
        else if (Age_To_Slot_Number[age].size()>0)
        {
            cout<<"Following are the slots occupied by the drivers of age "<<age<<endl;
            for(int slot:Age_To_Slot_Number[age]){
                cout<<slot<<endl;
            }
        } 
        else 
        {
            cout<<"Not found"<<endl;
        }
    }

    // function that make the required changes whenever a car leaves the parking lot
    void leave(int slotNo) {
        if (this->MAXIMUM_SIZE == 0) 
        {
            cout<<"Sorry, parking lot is not created"<<endl;
        }
        else if(isEmpty()) {
            cout<<"Parking lot is empty"<<endl;
        }
        else if(availableSlots[slotNo]==1)
        {
            availableSlots[slotNo] = 0;
            string regNo = Slot_To_Regis_Num[slotNo];
            int age = regNoToAge[regNo];
            carToSlot.erase(regNo);
            for(auto i = Age_To_Slot_Number[age].begin(); i != Age_To_Slot_Number[age].end() ;i++){
                if(*i==slotNo){
                    Age_To_Slot_Number[age].erase(i);
                    break;
                }
            }
            CURRENT_CAR_NUMBER--;
            Slot_To_Regis_Num.erase(slotNo);
            cout<<"Slot number "<<slotNo<<" vacated, the car with vehicle registration number \""<<regNo<<"\" left the space, the driver of the car was of age "<<age<<endl;
        }
        else
        {
            cout<<"Slot number "<<slotNo<<" is already empty"<<endl;
        }
    }

    // fucntion that returns the slot number of the given car from the registration number
    void getSlotNumberFromRegNo(string regNo) {
        if (this->MAXIMUM_SIZE == 0) 
        {
            cout<<"Sorry, parking lot is not created"<<endl<<endl;
        }else if(carToSlot[regNo])
        {
            cout<<regNo<<" is parked at slot "<<carToSlot[regNo]<<endl;
        }
        else 
        {
            cout<<"Not found"<<endl;
            cout<<endl;
        }
    }
};
