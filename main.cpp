//#include <iostream>
//#include <list>
//
//
//using namespace std;
//
//struct ShippingData{
//    int id;
//    string Warehouse_block;
//    string Mode_of_Shipment;
//    int Customer_care_calls;
//    int Customer_rating;
//    int Cost_of_the_Product;
//    int Prior_purchases;
//    string Product_importance;
//    string Gender;
//    int Discount_offered;
//    int Weight_in_gms;
//    int Reached_on_Time_Y_N;
//};
//
//int main() {
//    list<string> myStr;
//    return 0;
//}
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//using namespace std;
//
//void display(vector<vector<string>> content);
//
//int main()
//{
//    string fname = "shipping-data-small.csv";
//
//    vector<vector<string>> content;
//    vector<string> row;
//    string line, word;
//
//
//    fstream file (fname, ios::in);
//    if(file.is_open())
//    {
//        while(getline(file, line))
//        {
//            row.clear();
//
//            stringstream str(line);
//
//            while(getline(str, word, ','))
//                row.push_back(word);
//            content.push_back(row);
//        }
//    }
//    else
//        cout<<"Could not open the file\n";
//
//
//    display(content);
//    return 0;
//}
//
//void display(vector<vector<string>> content) {
//    for(int i=0;i<content.size();i++)
//    {
//        for(int j=0;j<content[i].size();j++)
//        {
//            cout<<content[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//}
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <list>
#include <vector>

using namespace  std;


struct ShippingData{
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
void displayHeader(){
    cout << "ID | " << "Warehouse | "  << "Shipment | " << "Calls | " << "Rating | "
         << "Cost | " << "Purchases | " << "Importance | " << "Gender | " << "Discount | "
         << "Weight(gms) | " << "On Time | " << endl;
}
void display(const ShippingData& stud){

    cout
            << setw(2) << stud.id
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
void load(const string& fName, list<ShippingData> list){
    ifstream fin(fName);
    if(fin){
        string line;
        getline(fin,line);
        displayHeader();
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


    for(ShippingData data : list){
        vec.push_back(data);
    }
    for(ShippingData data : list){
        display(data);
    }
    for(ShippingData data: vec){
        display(data);
    }
    return 0;
}


