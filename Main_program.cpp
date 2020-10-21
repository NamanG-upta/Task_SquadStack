#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<vector>
#include<unordered_map>
#include <unordered_set>
#include "Parking_Header_files.h"
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string Task;
    ParkingLot parkingLot;
    while(cin>>Task){
        if(Task=="Create_parking_lot"){
            int Count_of_Lot;
            cin>>Count_of_Lot;
            parkingLot.createParkingLot(Count_of_Lot);
        }
        else if(Task=="Park"){
            string regno;
            string Num_2;
            int age;
            cin>>regno>>Num_2>>age;
            parkingLot.park(regno,age);
        }
        
        else if(Task=="Slot_numbers_for_driver_of_age"){
            int age;
            cin>>age;
            parkingLot.getSlotNumbersFromAge(age);
        }
        else if(Task=="Slot_number_for_car_with_number"){
            string regno;
            cin>>regno;
            parkingLot.getSlotNumberFromRegNo(regno);
        }
        
        else if(Task=="Vehicle_registration_number_for_driver_of_age"){
            int age;
            cin>>age;
            parkingLot.getRegistrationNumbersFromAge(age);
        }
    }
    return 0;
}