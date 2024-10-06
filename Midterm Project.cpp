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
		
		void updateItem(){
			
			int qty;
			double newprice;
			string update;
			
			cout << "\n(Quantity or Price)" << endl;
		    cout << "What would you like to update for this item?: ";
	        cin >> update;
		            
		   	    if(update == "quantity"){
		           	cout << "Please input the new amount of qty: ";
		           	cin >> qty;
		           	cout<<"Quantity of Item " << name << " is updated from "<< quantity << " to " << qty <<endl;
					quantity = qty;
				}
				else if(update == "price"){
		           	cout << "Please input the new price: ";
		           	cin >> newprice;
					cout<<"Quantity of Item " << name << " is updated from "<< price << " to " << newprice <<endl;
					price = newprice;
					}
			
		}
//		void deleteItem(){
//			name.clear();
//			quantity.clear();
//			price.clear();
//			ID.clear();
//		}	        

		static void sortItems(vector<Shop*>& shops, const string& sortCriteria) {
		    int n = shops.size();
		    
		    string sortMethod;
	        cout<<"Ascending ot Descending: ";
	        cin>>sortMethod;
	        
	        if(sortMethod == "ascending"){
			    if (sortCriteria == "quantity") {
			        for (int i = 0; i < n - 1; i++) {
			            for (int j = 0; j < n - i - 1; j++) {
			                if (shops[j]->getQuantity() > shops[j + 1]->getQuantity()) {

			                    Shop* temp = shops[j];
			                    shops[j] = shops[j + 1];
			                    shops[j + 1] = temp;
			                }
			            }
			        }
			    } else if (sortCriteria == "price") {
			        for (int i = 0; i < n - 1; i++) {
			            for (int j = 0; j < n - i - 1; j++) {
			                if (shops[j]->getPrice() > shops[j + 1]->getPrice()) {

			                    Shop* temp = shops[j];
			                    shops[j] = shops[j + 1];
			                    shops[j + 1] = temp;
			                }
			            }
			        }
			    }
			}
			else if(sortMethod == "descending"){
				if (sortCriteria == "quantity") {
		
			        for (int i = 0; i < n - 1; i++) {
			            for (int j = 0; j < n - i - 1; j++) {
			                if (shops[j]->getQuantity() < shops[j + 1]->getQuantity()) {
			            
			                    Shop* temp = shops[j];
			                    shops[j] = shops[j + 1];
			                    shops[j + 1] = temp;
			                }
			            }
			        }
			    } else if (sortCriteria == "price") {
	
			        for (int i = 0; i < n - 1; i++) {
			            for (int j = 0; j < n - i - 1; j++) {
			                if (shops[j]->getPrice() < shops[j + 1]->getPrice()) {
			       
			                    Shop* temp = shops[j];
			                    shops[j] = shops[j + 1];
			                    shops[j + 1] = temp;
			                }
			            }
			        }
			    }
			}
		}
	
	};
		
class Clothing : public Shop{
	
	public:
		
		Clothing(int tempQuantity, double tempPrice, string tempID, string tempName) : Shop(tempQuantity, tempPrice, tempID, tempName){}
		
		void addItem() override{
				
			string inputName;	
			cout<<"\nPlease Input Name: ";
			getline(cin, inputName); setName(inputName);
			
			string inputID;
			cout<<"\nPlease Input ID: ";
			getline(cin, inputID); setID(inputID);
			
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
			cin.ignore();
			
			string inputID;
			cout<<"\nPlease Input ID: ";
			cin>>inputID; setID(inputID);
			cin.ignore();
			
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
		
void tabs(){
			cout << left << setw(15) << setfill(' ') << "ID";
			cout << left << setw(15) << setfill(' ') << "Name";
			cout << left << setw(15) << setfill(' ') << "Quantity";
			cout << left << setw(15) << setfill(' ') << "Price";
			cout << left << setw(15) << setfill(' ') << "Category";
			cout<<"\n";
		}		
				

void Menu(){
	
	vector<Shop*> shops;					
	bool entry = true;	
	int choice;
	string category, categoryChoice, key;
	
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
			cin.ignore();
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
			cout << "Enter the ID to update: ";
		    cin >> key;
			
		    for (auto& shop : shops) {
		        if (shop->getID() == key) { 
					shop->updateItem();
		        }
		    }
			break;
		case 3:
			cout << "Enter the ID to remove: ";
		    cin >> key;
			
		    for (auto& shop : shops) {
		        if (shop->getID() == key) { 
//					shop->deleteItem();
		        }
		    }
			break;
		case 4:

			cout<<"\n(Clothing, Electronics,  Entertainment)";
			cout << "\nPlease input what category you would like to see: ";
			cin>>categoryChoice;
			transform(categoryChoice.begin(), categoryChoice.end(), categoryChoice.begin(), ::tolower);
			
			cout << "\nDisplaying all items in category:" << endl;
			tabs();
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
			tabs();
			cout<<"\n";
			for(auto& shop : shops){
			    shop->display();
			}
			break;
		case 6:
		    cout << "Enter the ID to search: ";
		    cin >> key;

		    for (auto& shop : shops) {
		        if (shop->getID() == key) { 
					cout << "\nDisplaying requested item:" << endl;
					tabs();
		            shop->display();
		        }
		        else if (shop->getID() != key){
		    	cout<<"Item not found!, going back to menu..."<<endl;
			}
		    }
			break;
		case 7:{
			
			string sortCriteria;
            cout << "\nSort by (quantity or price): ";
       		cin >> sortCriteria;
            Shop::sortItems(shops, sortCriteria);
            cout << "\nItems sorted successfully by " << sortCriteria << "!" << endl;
			cout << "\nDisplaying sorted items:" << endl;
			tabs();
			for(auto& shop : shops){
			    shop->display();
			}	
			break;		
		}
		case 8:
			cout<<"\nDisplaying Low Stock Items: "<<endl;
			tabs();
			for(auto& shop : shops){
				if(shop->getQuantity() <= 5){
					shop->display();
				}
			}
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