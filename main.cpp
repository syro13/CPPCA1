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
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void display(vector<vector<string>> content);



int main()
{
    string fname = "shipping-data-small.csv";
//    cout<<"Enter the file name: ";
//    cin>>fname;

    vector<vector<string>> content;
    vector<string> row;
    string line, word;


    fstream file (fname, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";


    display(content);
    return 0;
}

void display(vector<vector<string>> content) {
    for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
            cout<<content[i][j]<<" ";
        }
        cout<<"\n";
    }
}
