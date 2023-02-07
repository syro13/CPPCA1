#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>

using namespace  std;


struct ShippingData {

    int id{};
    string Warehouse_block;
    string Mode_of_Shipment;
    int Customer_care_calls{};
    int Customer_rating{};
    int Cost_of_the_Product{};
    int Prior_purchases{};
    string Product_importance;
    string Gender;
    int Discount_offered{};
    int Weight_in_gms{};
    int Reached_on_Time_Y_N{};
};

struct T
{
    T(const char* cstr) : str(cstr){ }
    string str;
};
void linkedList(list<ShippingData> list1);

ShippingData extractData(const string& basicString, ShippingData data);

void displayHeader(){
    cout << "ID | " << "Warehouse | "  << "Shipment | " << "Calls | " << "Rating | "
         << "Cost | " << "Purchases | " << "Importance | " << "Gender | " << "Discount | "
         << "Weight(gms) | " << "On Time | ";
}
void display(const ShippingData& stud){

    cout << setw(2) << stud.id
         << setw(8) << stud.Warehouse_block
         << setw(14)<< stud.Mode_of_Shipment
         << setw(8)<< stud.Customer_care_calls
         << setw(8)<< stud.Customer_rating
         << setw(9)<< stud.Cost_of_the_Product
         << setw(8)<< stud.Prior_purchases
         << setw(15)<< stud.Product_importance
         << setw(9)<< stud.Gender
         << setw(10)<< stud.Discount_offered
         << setw(13)<< stud.Weight_in_gms
         << setw(11)<< stud.Reached_on_Time_Y_N << endl;
}
ShippingData parseLine(const string& line, ShippingData &stud) {
    string temp;

    char tempChar;
    stringstream ss(line);

    //id
    getline(ss, temp, ',');
    stud.id = stoi(temp);
    //warehouse block
    getline(ss,stud.Warehouse_block,',');
    //mode of shipment
    getline(ss,stud.Mode_of_Shipment,',');
    //customer care calls
    getline(ss, temp, ',');
    stud.Customer_care_calls= stoi(temp);

    getline(ss, temp, ',');
    stud.Customer_rating= stoi(temp);

    getline(ss, temp, ',');
    stud.Cost_of_the_Product= stoi(temp);

    getline(ss, temp, ',');
    stud.Prior_purchases= stoi(temp);

    getline(ss,stud.Product_importance,',');

    getline(ss,stud.Gender,',');

    getline(ss, temp, ',');
    stud.Discount_offered= stoi(temp);

    getline(ss, temp, ',');
    stud.Weight_in_gms= stoi(temp);

    getline(ss, temp, ',');
//    tempChar = temp[0];
//    if(tempChar == '1'){
    stud.Reached_on_Time_Y_N = stoi(temp);
//    }else{
//        stud.Reached_on_Time_Y_N = false;
//    }

    return stud;
}
void load(const string& fName, list<ShippingData> &list){
    ifstream fin(fName);
    if(fin){
        string line;
        getline(fin,line);
        while(getline(fin,line)){
            ShippingData data;
            parseLine(line, data);
            list.push_back(data);
//            display(data);
        }
    }

}
int main(){
    list<ShippingData> list;
    vector<ShippingData> vec;
    load("shipping-data-small.csv",list);
    for(const ShippingData& data : list){
        vec.push_back(data);
    }
    int choice;
    cout << "------------Welcome------------" << endl;
    cout << "1.Linked-List Features" << endl;
    cout << "2.Vector Features" << endl;
    cout << "3.Set Features" << endl;
    cout << "4.Map Features" << endl;
    cin >> choice;
    switch(choice){
        case 1:linkedList(list); break;
        case 2:break;
        case 3:break;
        case 4:break;
        default:cout << "Menu item does not exist" << endl;
    }

//    for(const ShippingData& data: vec){
//        display(data);
//    }

    return 0;
}
bool lessThan2(int i)
{
    if (i < 2)
        return true;
    else
        return false;
}
void linkedList(list<ShippingData> list) {
    auto l_front = list.begin();
    bool menuOn = true;
    ShippingData tempDetails;
    while(menuOn) {
    int choice;
    int idChoice;
    string details;
    cout << "1.Display all elements" << endl;
    cout << "2.Display first element" << endl;
    cout << "3.Display last element" << endl;
    cout << "4.Display chosen element" << endl;
    cout << "5.Delete first element" << endl;
    cout << "6.Delete Last element" << endl;
    cout << "7.Delete chosen element" << endl;
    cout << "8.Add element at any position" << endl;
    cout << "9.Count ratings" << endl;
    cout << "10.Exit" << endl;

    cin >> choice;

        switch (choice) {
            case 1:
                displayHeader();
                for (const ShippingData &data: list) {
                    display(data);
                }
                break;
            case 2:
                displayHeader();
                display(list.front());
                break;
            case 3:
                displayHeader();
                display(list.back());
                break;
            case 4:
                cout << "Enter ID:" << endl;
                cin >> idChoice;
                if (idChoice == 1) {
                    displayHeader();
                    display(*l_front);
                } else {
                    advance(l_front, idChoice - 1);
                    displayHeader();
                    display(*l_front);
                }
                break;
            case 5:
                list.pop_front();
                cout << "!!!-First element Deleted-!!!" << endl;
                l_front = list.begin();
                break;
            case 6:
                list.pop_back();
                cout << "!!!-Last element Deleted-!!!" << endl;
                l_front = list.begin();
                break;
            case 7:
                cout << "Enter ID:" << endl;
                cin >> idChoice;
                if (idChoice == 1) {
                    list.erase(l_front);
                } else {
                    advance(l_front, idChoice - 1);
                    list.erase(l_front);
                }
                l_front = list.begin();
                cout << "!!!- Element " << idChoice << " Deleted-!!!" << endl;
                break;
            case 8:

                int position;
                int temp;
                cout<< "Enter position in which you would like a new entry to go into" << endl;
                cin >> position;
                cout << "Enter details below(make sure to add ',' after each detail)" << endl;
                cin.ignore();
                getline(cin, details);
                advance(l_front,position-1);
                list.insert(l_front, extractData(details, tempDetails));
                break;
            case 9:
                cout << "Number of ratings less than 2" << count_if(list.begin(),list.end(), lessThan2(l_front->Customer_rating))<< endl;
                break;
            case 10:menuOn = false; break;
            default:
                cout << "Menu item does not exist" << endl;
        }

    }


}

ShippingData extractData(const string& details, ShippingData data) {
    string temp;

    char tempChar;
    stringstream ss(details);

    //id
    getline(ss, temp, ',');
    data.id = stoi(temp);
    //warehouse block
    getline(ss,data.Warehouse_block,',');
    //mode of shipment
    getline(ss,data.Mode_of_Shipment,',');
    //customer care calls
    getline(ss, temp, ',');
    data.Customer_care_calls= stoi(temp);

    getline(ss, temp, ',');
    data.Customer_rating= stoi(temp);

    getline(ss, temp, ',');
    data.Cost_of_the_Product= stoi(temp);

    getline(ss, temp, ',');
    data.Prior_purchases= stoi(temp);

    getline(ss,data.Product_importance,',');

    getline(ss,data.Gender,',');

    getline(ss, temp, ',');
    data.Discount_offered= stoi(temp);

    getline(ss, temp, ',');
    data.Weight_in_gms= stoi(temp);

    getline(ss, temp, ',');
//    tempChar = temp[0];
//    if(tempChar == '1'){
    data.Reached_on_Time_Y_N = stoi(temp);
    return data;
}




