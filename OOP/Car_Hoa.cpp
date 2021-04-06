/**
 * * Xây dựng lớp xe gồm các thuộc tính biển số và trọng lượng của xe.
 * * Xây dựng lớp dẫn xuất từ lớp xe
 * * Lớp xe con định nghĩa thêm thuộc tính số chỗ ngồi
 * * Lớp xe tải trong đó thêm thuộc tính tải trọng
 * ! Nhập thông tin cho xe
 * ! In danh sách các xe con có trọng lượng dưới 1 tấn và ko quá 9 chỗ ngồi
 * ! in danh sách các xe tải có trọng lượng hơn 3 tấn và có tải trọng ít nhất 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Vehicle
{
protected:
    string Nametag;
    int carWeight;

public:
    Vehicle()
    {
        this->Nametag = "";
        this->carWeight = 0;
    }
    Vehicle(string, int);
    void baseSet();
    void baseGet();
    int getCarWeight();
    ~Vehicle(){};
};
Vehicle::Vehicle(string name, int weight)
{
    this->Nametag = name;
    this->carWeight = weight;
}
void Vehicle::baseSet()
{
    cout << "Nhap bien so xe: ";
    cin >> this->Nametag;
    cout << "Nhap trong luong xe (Don vi do: Kg): ";
    cin >> this->carWeight;
}
void Vehicle::baseGet()
{
    cout << "Bien so xe: " << this->Nametag << endl;
    cout << "Trong luong xe (Don vi do: Kg): " << this->carWeight << endl;
}
int Vehicle::getCarWeight()
{
    return this->carWeight;
}
class Car : public Vehicle
{
private:
    int seats;

public:
    Car()
    {
        Vehicle();
        this->seats = 0;
    }
    Car(string, int, int);
    void setInfo();
    void showInfo();
    int getSeat();
    ~Car(){};
};
Car::Car(string name, int seat, int weight)
{
    Vehicle(name, weight);
    this->seats = seats;
}
void Car::setInfo()
{
    baseSet();
    cout << "Nhap so luong cho ngoi: ";
    cin >> this->seats;
}
void Car::showInfo()
{
    baseGet();
    cout << "So cho ngoi cua xe: " << this->seats << endl;
}
int Car::getSeat()
{
    return this->seats;
}
class Truck : public Vehicle
{
private:
    int weight;

public:
    Truck()
    {
        Vehicle();
        this->weight = 0;
    }
    Truck(string, int, int);
    void setInfo();
    void showInfo();
    int getWeight();
    ~Truck(){};
};
Truck::Truck(string name, int carweight, int weight)
{
    Vehicle(name, carweight);
    this->weight = weight;
}
void Truck::setInfo()
{
    baseSet();
    cout << "Nhap tai trong cua xe (Don vi do: Kg): ";
    cin >> this->weight;
}
void Truck::showInfo()
{
    baseGet();
    cout << "Tai trong cua xe (Don vi do: Kg): " << this->weight << endl;
}
int Truck::getWeight()
{
    return this->weight;
}
template <class Type>
void setList(vector<Type> &list, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        Type element;
        element.setInfo();
        list.push_back(element);
    }
}
void setListCar(vector<Car> &lcar)
{
    int nums;
    cout << "Ban muon them bao nhiu xe con: ";
    cin >> nums;
    setList(lcar, nums);
}
void setlistTruck(vector<Truck> &trucks)
{
    int nums;
    cout << "Ban muon them bao nhiu xe tai: ";
    cin >> nums;
    setList(trucks, nums);
}
Truck findMinWeight(vector<Truck> &trucks)
{
    Truck temp[100];
    size_t length = 0;
    for (size_t i = 0; i < trucks.size(); i++)
    {
        if (trucks.at(i).getCarWeight() >= 3000)
        {
            temp[length] = trucks.at(i);
            length++;
        }
    }
    if (length == 0)
    {
        exit(1);
    }
    Truck min = temp[0];
    for (size_t i = 0; i < length; i++)
    {
        if (min.getWeight() > temp[i].getWeight())
        {
            min = temp[i];
        }
    }
    return min;
}
void searchCar(vector<Car> &car)
{
    for (size_t i = 0; i < car.size(); i++)
    {
        if (car.at(i).getCarWeight() < 1000)
        {
            if (car.at(i).getSeat() <= 9)
            {
                car.at(i).showInfo();
            }
        }
    }
}
void showResult(vector<Car> &cars, vector<Truck> &trucks)
{
    cout << "Xe Con co trong luong duoi 1 tan va khong qua 9 cho ngoi: " << endl;
    searchCar(cars);
    cout << "Xe Tai co trong luong hon 3 tan va co tai trong thap nhat: " << endl;
    Truck searchTruck = findMinWeight(trucks);
    searchTruck.showInfo();
}
int main(int argc, char const *argv[])
{
    vector<Car> listCar;
    vector<Truck> listTruck;
    while (1)
    {
        system("cls");
        cout << "1. Them xe con " << endl;
        cout << "2. Them xe tai " << endl;
        cout << "9. Hien ket qua " << endl;
        int key;
        cout << "nhap lua chon:";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            setListCar(listCar);
            break;
        case 2:
            system("cls");
            setlistTruck(listTruck);
            break;
        case 9:
            system("cls");
            showResult(listCar, listTruck);
            system("pause");
            break;
        }
    }
    system("pause");
    return 0;
}
