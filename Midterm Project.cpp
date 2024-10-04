#include <iostream>
#include <algorithm>
#include <windows.h>
#include <vector>
#include <iomanip>
using namespace std;

class Shop{
	
	private:
		int quantity;
		double price;
		string ID, name;
	
	public:
		Shop(int tempQuantity, double tempPrice, string tempID, string tempName) : quantity(tempQuantity), price(tempPrice), ID(tempID), name(tempName){}
		
		virtual void addItem() = 0;
		virtual void display() = 0;
		
		void setName(string a){
			name = a;
		}
		void setID(string b){
			ID = b;
		}
		void setQuantity(int a){
			quantity = a;
		}
		void setPrice(double a){
			price = a;
		}
		
		string getName(){
			return name;
		}
		string getID(){
			return ID;
		}
		int getQuantity(){
			return quantity;
		}
		double getPrice(){
			return price;
		}
	
	};
		
class Clothing : public Shop{
	
	public:
		
		Clothing(int tempQuantity, double tempPrice, string tempID, string tempName) : Shop(tempQuantity, tempPrice, tempID, tempName){}
		
		void addItem() override{
				
			string inputName;	
			cout<<"\nPlease Input Name: ";
			cin>>inputName; setName(inputName);
			
			string inputID;
			cout<<"\nPlease Input ID: ";
			cin>>inputID; setID(inputID);
			
			int inputQuantity;
			cout<<"\nPlease Input Quantity: ";
			cin>>inputQuantity; setQuantity(inputQuantity);
			
			double inputPrice;
			cout<<"\nPlease Input Price: ";
			cin>>inputPrice; setPrice(inputPrice);
		
		}
		
		void display() override{
		
					cout << left << setw(15) << setfill(' ') << getID();     //ONLY FOR CLOTHING
					cout << left << setw(15) << setfill(' ') << getName();
					cout << left << setw(15) << setfill(' ') << getQuantity();
					cout << left << setw(15) << setfill(' ') << getPrice();
					cout << left << setw(15) << setfill(' ') << "Clothing" << endl;
                }
		};	
		
class Electronics : public Shop{
	
	public:
		
		Electronics(int tempQuantity, double tempPrice, string tempID, string tempName) : Shop(tempQuantity, tempPrice, tempID, tempName){}
		
		void addItem() override{
				
			string inputName;	
			cout<<"\nPlease Input Name: ";
			cin>>inputName; setName(inputName);
			
			string inputID;
			cout<<"\nPlease Input ID: ";
			cin>>inputID; setID(inputID);
			
			int inputQuantity;
			cout<<"\nPlease Input Quantity: ";
			cin>>inputQuantity; setQuantity(inputQuantity);
			
			double inputPrice;
			cout<<"\nPlease Input Price: ";
			cin>>inputPrice; setPrice(inputPrice);
		
		}
		
		void display() override{
		
					cout << left << setw(15) << setfill(' ') << getID();     //ONLY FOR ELECTRONIC
					cout << left << setw(15) << setfill(' ') << getName();
					cout << left << setw(15) << setfill(' ') << getQuantity();
					cout << left << setw(15) << setfill(' ') << getPrice();
					cout << left << setw(15) << setfill(' ') << "Electronics" << endl;
                }
		};			
		
class Entertainment : public Shop{
	
	public:
		
		Entertainment(int tempQuantity, double tempPrice, string tempID, string tempName) : Shop(tempQuantity, tempPrice, tempID, tempName){}
		
		void addItem() override{
				
			string inputName;	
			cout<<"\nPlease Input Name: ";
			cin>>inputName; setName(inputName);
			
			string inputID;
			cout<<"\nPlease Input ID: ";
			cin>>inputID; setID(inputID);
			
			int inputQuantity;
			cout<<"\nPlease Input Quantity: ";
			cin>>inputQuantity; setQuantity(inputQuantity);
			
			double inputPrice;
			cout<<"\nPlease Input Price: ";
			cin>>inputPrice; setPrice(inputPrice);
		
		}
		
		void display() override{
		
					cout << left << setw(15) << setfill(' ') << getID();     //ONLY FOR Entertainment
					cout << left << setw(15) << setfill(' ') << getName();
					cout << left << setw(15) << setfill(' ') << getQuantity();
					cout << left << setw(15) << setfill(' ') << getPrice();
					cout << left << setw(15) << setfill(' ') << "Entertainment" << endl;
                }
		};			

void Menu(){
			
	vector<Shop*> shops;					
	bool entry = true;	
	int choice;
	string category, categoryChoice;
	
	while(entry == true){
	
		system("Color 0A"); 
		cout<<"================================="<<endl;
		cout<<"\tMenu"<<endl;
		cout<<"[1] - Add Item"<<endl;
		cout<<"[2] - Update Item"<<endl;
		cout<<"[3] - Remove Item"<<endl;
		cout<<"[4] - Display Items by Category"<<endl;
		cout<<"[5] - Display All Items"<<endl;
		cout<<"[6] - Search Item"<<endl;
		cout<<"[7] - Sort Items"<<endl;
		cout<<"[8] - Display Low Stock Items"<<endl;
		cout<<"[9] - Exit"<<endl;
		cout<<"================================="<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
	
		system("CLS");
	switch(choice){
		case 1:
			cout<<"\nPlease input category (Clothing, Electronics,  Entertainment): ";
			cin>>categoryChoice;
			transform(categoryChoice.begin(), categoryChoice.end(), categoryChoice.begin(), ::tolower);
			
				if(categoryChoice == "clothing"){
					Shop* cloth = new Clothing(0,0," ", " ");
					cloth->addItem();
					shops.push_back(cloth);
					cout<<"\nClothing added successfully!"<<endl;
				}
				else if(categoryChoice == "electronics"){
					Shop* electronic = new Electronics(0,0," ", " ");
					electronic->addItem();
					shops.push_back(electronic);
					cout<<"\nElecronic added successfully!"<<endl;
				}
				else if(categoryChoice == "entertainment"){
					Shop* entertainment = new Entertainment(0,0," ", " ");
					entertainment->addItem();
					shops.push_back(entertainment);
					cout<<"\nEntertainment added successfully!"<<endl;
				}
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:

			cout<<"\n(Clothing, Electronics,  Entertainment)";
			cout << "\nPlease input what category you would like to see: ";
			cin>>categoryChoice;
			transform(categoryChoice.begin(), categoryChoice.end(), categoryChoice.begin(), ::tolower);
			
			cout << "\nDisplaying all items in category:" << endl;
			cout << left << setw(15) << setfill(' ') << "ID";
			cout << left << setw(15) << setfill(' ') << "Name";
			cout << left << setw(15) << setfill(' ') << "Quantity";
			cout << left << setw(15) << setfill(' ') << "Price";
			cout << left << setw(15) << setfill(' ') << "Category";
			cout<<"\n";
			
			for(auto& shop : shops){
			    if(categoryChoice == "clothing"){
			        Clothing* cloth = dynamic_cast<Clothing*>(shop);
			        if(cloth) cloth->display();
			    }
			    else if(categoryChoice == "electronics"){
			        Electronics* electronic = dynamic_cast<Electronics*>(shop);
			        if(electronic) electronic->display();
			    }
			    else if(categoryChoice == "entertainment"){
			        Entertainment* entertainment = dynamic_cast<Entertainment*>(shop);
			        if(entertainment) entertainment->display();
				}
			}
			break;
		case 5:
			cout << "\nDisplaying all items:" << endl;
			cout << left << setw(15) << setfill(' ') << "ID";
			cout << left << setw(15) << setfill(' ') << "Name";
			cout << left << setw(15) << setfill(' ') << "Quantity";
			cout << left << setw(15) << setfill(' ') << "Price";
			cout << left << setw(15) << setfill(' ') << "Category";
			cout<<"\n";
			for(auto& shop : shops){
			    shop->display();
			}
			break;
		case 6:
//			for(auto& shop : shops){
//				if(binary_search(shop.(start), shop.(end), key){
//				shop->display();
//			}
//			}
			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 9:
			cout<<"Terminating program...";
			entry = false;
			break;	
		default:
			cout<<"\nInvalid Input. Please try again."<<endl;	
		
		}
	}
	for(auto& shop : shops){
    	delete shop;
	}
}

int main(){	
		
	Menu();
	
	return 0;
}