#include <iostream>

using namespace std;

class Fueltank {
    private:
    int m_FueltankCapacity;
    int m_Gas_grade;
    public:
    Fueltank(int FueltankCapacity=3000,int Gas=98){
        m_FueltankCapacity=FueltankCapacity;
        m_Gas_grade=Gas;
    }
    int fuel_up(int v,int gas) {
        if(v>m_FueltankCapacity) {
            cout<<"error : FueltankCapacity: "<<m_FueltankCapacity<<" but fuel up: "<<v<<endl;
        }else if(gas!=m_Gas_grade) {
            cout<<"error : Gas_grade: "<<gas<<" Correct Gas_garde: "<<m_Gas_grade<<endl;
        }else {
            cout<<"fuel_up: "<<v<<" Gas_garde: "<<gas<<endl;
        }
    }
    int set_Gas_grade(int Gas_grade) {
        m_Gas_grade=Gas_grade;
        cout<<"Set Gas_grade: "<<Gas_grade<<endl;
    }
    int get_Gas_grade() {
        return m_Gas_grade;
    }
    int get_FueltankCapacit() {
        return m_FueltankCapacity;
    }
};

class Car {
    protected:
    string m_DriveMode;
    Fueltank m_Fueltank;
    
    public:
    string m_brand;
    string m_model;
    int m_years;
    int m_MaxSeating;
    Car(string x,string y,int z,int s) {
        m_brand=x;
        m_model=y;
        m_years=z;
        m_MaxSeating=s;
    }
    int get_m_MaxSeating(){
        return m_MaxSeating;
    }
    string get_brand() {
        return m_brand;
    }
    int set_Gas_grade(int gas) {
        m_Fueltank.set_Gas_grade(gas);
    }
    int get_Gas_grade() {
        m_Fueltank.get_Gas_grade();
    }
    int fuel_up(int v,int gas) {
        m_Fueltank.fuel_up(v,gas);
    }
};

class BMW_Car : public Car {
    public:
    BMW_Car(string y,int z,int s) : Car("BMW",y,z,s) {
        cout<<"Constructing BMW_Car\n";
        m_DriveMode="Rear-wheel";
    }
    
    string get_m_DriveMode() {
        return m_DriveMode;
    }
};

class AUDI_Car : public Car {
    public:
    AUDI_Car(string y,int z,int s) : Car("AUDI",y,z,s) {
        cout<<"Constructing AUDI_Car\n";
        m_DriveMode="Front-wheel";
    }
    
    string get_m_DriveMode() {
        return m_DriveMode;
    }
};

class BENZ_Car : public Car {
    public:
    BENZ_Car(string y,int z,int s) : Car("BENZ",y,z,s) {
        cout<<"Constructing BENZ_Car\n";
        m_DriveMode="Front-wheel";
    }
    
    string get_m_DriveMode() {
        return m_DriveMode;
    }
};

int main() {
    AUDI_Car car_2("A1",2021,2);
    cout<<car_2.get_brand()<<" : Gas_garde = "<<car_2.get_Gas_grade()<<endl;
    car_2.set_Gas_grade(95);
    cout<<car_2.get_brand()<<" : Gas_garde = "<<car_2.get_Gas_grade()<<endl;
    car_2.fuel_up(30000,95);

    return 0;
}

