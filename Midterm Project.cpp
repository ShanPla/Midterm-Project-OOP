#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

bool isOnlyDigits(const string& str) {
    for (char const &c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}
bool digitcheck(const string& str) {
    if (str.empty()) return false;

    size_t start = 0;
    bool decimalPointFound = false;

    // Check if the first character is a negative sign
    if (str[0] == '-') {
        start = 1;
    }

    for (size_t i = start; i < str.length(); ++i) {
        // Check if the current character is a decimal point
        if (str[i] == '.') {
            // Allow only one decimal point in the string
            if (decimalPointFound) return false;
            decimalPointFound = true;
        }
        // If the character is not a digit and not a decimal point, return false
        else if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}
bool isOnlyLetters(const string& str) {
    if (str.empty()) return false;

    for (char const &c : str) {
        if (!isalpha(c)) return false;
    }

    return true;
}
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
			string update, input;
			bool isUpdated = false, validInput = false, validCategory = false;
			while(!isUpdated){
			
   				while (!validCategory) {
					cout << "\n(Quantity or Price)" << endl;
				    cout << "What would you like to update for this item?: ";
			        getline(cin, update);        
			        if (isOnlyLetters(update)) {
			        	if(update == "quantity" || update == "price"){
			            validCategory = true;
						}
						else{
							cout << "Invalid input! Please enter one of the two choices.\n";
						}
			        } 
					else {
			            cout << "Numbers not allowed. Please try again.\n";
			        }
			        cin.clear();
		   		}	        		        
		        for (char& c : update) {
				    c = tolower(c);
				}
					
			    system("CLS");
			   	if(update == "quantity"){
			    	while(!validInput){
			           	cout << "Please input the new amount of qty: ";
			           	cin >> input;
			           	if (digitcheck(input)) {
				            qty = stoi(input);
				            if(qty == quantity){
				            	cout<<"This is already the current quantity for this item."<<endl;
				            	return;
							}
				            else if (qty > 0) {
				            	cout<<"Quantity of Item " << name << " is updated from "<< quantity << " to " << qty <<endl;
				            	quantity = qty;
				                validInput = true; isUpdated = true;
				            }
				            else if(qty < 1){
				  		    	cout << "Stock must be atleast 1. Please try again.\n\n";
				            }
				            }
						else {
				            cout << "Invalid input! Please enter digits only.\n\n";
				        }
				        cin.clear();
				        cin.ignore(numeric_limits<streamsize>::max(), '\n');
				        }
					}
				else if(update == "price"){
					while(!validInput){
			           	cout << "Please input the new price: ";
			           	cin >> input;
			           	if (digitcheck(input)) {
				            newprice = stoi(input);
				            if(newprice == price){
				            	cout<<"This is already the current price for this item."<<endl;
				            	return;
							}
				            else if (newprice > 0) {
				            	cout<<"Quantity of Item " << name << " is updated from "<< price << " to " << newprice <<endl;
				            	price = newprice;
				                validInput = true; isUpdated = true;
				            }
				            else if(newprice < 1){
				  		    	cout << "Price must be atleast worth 1php. Please try again.\n\n";
				            }
				            }
						else {
				            cout << "Invalid input! Please enter digits only.\n\n";
				        }
				        cin.clear();
				        cin.ignore(numeric_limits<streamsize>::max(), '\n');
				        }
				    }
				}
			}
		
		static void sortItems(vector<Shop*>& shops, const string& sortCriteria) {
		    int n = shops.size();
		    bool entry = false;
		    string sortMethod;
		    
		    while(!entry){
		        cout<<"Ascending or Descending: ";
		        cin>>sortMethod;
		        for (char& c : sortMethod) {
					    c = tolower(c);
					}  	
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
				    entry = true;
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
				    entry = true;
				}
				else {
					cout<<"\nError. Please try again."<<endl;
					entry = false;
				}
			}
		}
	};
		
class Clothing : public Shop{
	
	public:		
		Clothing(int tempQuantity, double tempPrice, string tempID, string tempName) : Shop(tempQuantity, tempPrice, tempID, tempName){}
		
		void addItem() override{
			bool validInput = false;
			string input;
				
			string inputName;	
			cout<<"\nPlease Input Name: ";
			getline(cin, inputName);
			
			string inputID;
			cout<<"\nPlease Input ID: ";
			getline(cin, inputID);
			for (char& c : inputID) {
			    c = toupper(c);
			}	

			int inputQuantity;
			while(!validInput){
				cout<<"\nPlease Input Quantity: ";
				cin>>input;
			if (digitcheck(input)) {
                inputQuantity = stoi(input);
                if (inputQuantity > 0) {
                    validInput = true;
                }
                else if(inputQuantity < 1){
                    cout << "Stock must be atleast 1. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter digits only.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        	validInput = false;
			
			double inputPrice;
			while(!validInput){
				cout<<"\nPlease Input Price: ";
				cin>>input;
			if (digitcheck(input)) {
                inputPrice = stoi(input);
                if (inputPrice > 0) {
                    validInput = true;
                }
                else if(inputPrice < 1){
                    cout << "Price must be atleast worth 1php. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter digits only.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

			setName(inputName); setID(inputID); setQuantity(inputQuantity); setPrice(inputPrice);
			
			cout<<"\nClothing added successfully!"<<endl;		
		}
		
		void display() override{			
					cout << left << setw(15) << setfill(' ') << getID();
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
			bool validInput = false;
			string input;
				
			string inputName;	
			cout<<"\nPlease Input Name: ";
			getline(cin, inputName);
			
			string inputID;
			cout<<"\nPlease Input ID: ";
			getline(cin, inputID);
			for (char& c : inputID) {
			    c = toupper(c);
			}
			
			int inputQuantity;
			while(!validInput){
				cout<<"\nPlease Input Quantity: ";
				cin>>input;
			if (digitcheck(input)) {
                inputQuantity = stoi(input);
                if (inputQuantity > 0) {
                    validInput = true;
                }
                else if(inputQuantity < 1){
                    cout << "Stock must be atleast be 1. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter digits only.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        	validInput = false;
			
			double inputPrice;
			while(!validInput){
				cout<<"\nPlease Input Price: ";
				cin>>input;
			if (digitcheck(input)) {
                inputPrice = stoi(input);
                if (inputPrice > 0) {
                    validInput = true;
                }
                else if(inputPrice < 1){
                    cout << "Price must be atleast be worth 1php. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter digits only.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
			
			setName(inputName); setID(inputID); setQuantity(inputQuantity); setPrice(inputPrice);

			cout<<"\nElecronic added successfully!"<<endl;		
		}
		
		void display() override{		
					cout << left << setw(15) << setfill(' ') << getID();
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
			bool validInput = false;
			string input;
				
			string inputName;	
			cout<<"\nPlease Input Name: ";
			getline(cin, inputName);
			
			string inputID;
			cout<<"\nPlease Input ID: ";
			getline(cin, inputID);
			for (char& c : inputID) {
			    c = toupper(c);
			}
			
			int inputQuantity;
			while(!validInput){
				cout<<"\nPlease Input Quantity: ";
				cin>>input;
			if (digitcheck(input)) {
                inputQuantity = stoi(input);
                if (inputQuantity > 0) {
                    validInput = true;
                }
                else if(inputQuantity < 1){
                    cout << "Stock must be atleast be 1. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter digits only.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        	validInput = false;
			
			double inputPrice;
			while(!validInput){
				cout<<"\nPlease Input Price: ";
				cin>>input;
			if (digitcheck(input)) {
                inputPrice = stoi(input);
                if (inputPrice > 0) {
                    validInput = true;
                }
                else if(inputPrice < 1){
                    cout << "Price must be atleast be worth 1php. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter digits only.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
					
			setName(inputName); setID(inputID); setQuantity(inputQuantity); setPrice(inputPrice);
			
			cout<<"\nEntertainment added successfully!"<<endl;
		}
		
		void display() override{
		
					cout << left << setw(15) << setfill(' ') << getID();   
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
			cout << left << setw(15) << setfill(' ') << "Category"<<endl;
		}
void categoryDisp(){
	cout<<"Displaying all items in category:"<<endl;
	tabs();
}
				
void Menu(){
	
	vector<Shop*> shops;					
	bool entry = true;	
	string category, categoryChoice, key, input;
	int choice;
	
	while(entry == true){
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
		
		bool validInput = false;
        
        while (!validInput) {
            cout << "Enter choice: ";
            cin >> input;

            if (isOnlyDigits(input)) {
                choice = stoi(input);
                if (choice >= 1 && choice <= 9) {
                    validInput = true;
                } else {
                    cout << "Invalid choice! Please enter a number between 1 and 9.\n";
                }
            } else {
                cout << "Invalid input! Please enter digits only.\n";
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
               
		system("CLS");
	switch(choice){
		case 1:
			cout<<"\nPlease input category (Clothing, Electronics, Entertainment): ";
			getline(cin, categoryChoice);
			cin.clear();
			for (char& c : categoryChoice) {
			    c = tolower(c);
			}
			
				if(categoryChoice == "clothing" || categoryChoice == "clothings"){
					Shop* cloth = new Clothing(0,0," ", " ");
					cloth->addItem();
					shops.push_back(cloth);
				}
				else if(categoryChoice == "electronics" || categoryChoice == "electronic"){
					Shop* electronic = new Electronics(0,0," ", " ");
					electronic->addItem();
					shops.push_back(electronic);
				}
				else if(categoryChoice == "entertainment"){
					Shop* entertainment = new Entertainment(0,0," ", " ");
					entertainment->addItem();
					shops.push_back(entertainment);
				}
				else{
					cout<<"\nCategory "<<categoryChoice<<" does not exist!"<<endl;
				}
			break;
		case 2:{
			bool itemFound = false, itemconfirm = false;
			char ans;
			if (shops.empty()) {
			    cout << "There is no item to update." << endl;
			    break;
			}
				cout << "Enter the ID to update: ";
			    getline(cin, key);
			    cin.clear();
				for (char& c : key) {
				    c = toupper(c);
				}
				    for (auto& shop : shops) {
				        if (shop->getID() == key) {
				        	cout<<"Item to be updated: "<<endl;
							tabs();
							shop->display();
							
							while(ans != 'n' || ans != 'N'){
					        	cout<<"\nIs this the correct item? (Y/N): ";
					        	cin>>ans;
					        	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
					        	if(ans == 'y' || ans == 'Y'){
									shop->updateItem();
							    	itemFound = true;
							    	entry = true;
							    	break;
								}
								else if(ans == 'n' || ans == 'N'){
									break;
								}
								else{
									cout<<"\nChoose either Y or N.";
								}
							}
						}
					}
					if(!itemFound){
				    	cout<<"Item not found! (Please check if ID is correct)"<<endl;
				    	break;
					}
				break;
			}
		case 3:{
			bool itemFound = false, proceed = false;
			char ans;
				
			if (shops.empty()) {
			    cout << "There is no item to remove." << endl;
			}
			else {
			    cout << "Enter the ID to remove: ";
			    getline(cin, key);
			    for (char& c : key) {
				    c = toupper(c);
				}
				    for (auto it = shops.begin(); it != shops.end(); ++it) {
				        if ((*it)->getID() == key) {
				        	
				        	cout<<"Item to be removed: "<<endl;
							tabs();
							(*it)->display();
					
							proceed = false;
							while(!proceed){
						       	cout<<"\nIs this the correct item? (Y/N): ";
						       	cin>>ans;
						       	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
						       	
						       	if(ans == 'y' || ans == 'Y'){
						        	cout<<"Item "<<(*it)->getName()<<" has been removed from the inventory!"<<endl;
						            delete *it;
						            shops.erase(it);
						            itemFound = true; proceed = true;
						            break;
						        }
						        else if(ans == 'n' || ans == 'N'){
									proceed = true;
								}
								else{
									cout<<"\nChoose either Y or N.";
								}
							}
				        }
					}
					if (!itemFound) {
				        cout << "Item not found! (Please check if ID is correct)." << endl;
				        break;
				    }
			}
		    break;
		}
		case 4:{
			bool hasCloth = false, hasElectronic = false, hasEntertainment = false, pass = false, showDisp = false;
			if (shops.empty()) {
			    cout << "There is no item available yet." << endl;
			}
			else {
				while(!pass){
					cout<<"\n(Clothing, Electronics, Entertainment)";
					cout << "\nPlease input what category you would like to see: ";
					cin>>categoryChoice; cin.ignore(numeric_limits<streamsize>::max(), '\n');
					for (char& c : categoryChoice) {
					    c = tolower(c);
					}
					showDisp = false;
					for(auto& shop : shops){
						pass = false;
					    if(categoryChoice == "clothing"){
					        Clothing* cloth = dynamic_cast<Clothing*>(shop);
							if(cloth) {
								if(!showDisp){
									categoryDisp(); showDisp = true;
								}
							cloth->display();		        
							hasCloth = true;
							}
							pass = true;
					    }
					    else if(categoryChoice == "electronics" || categoryChoice == "electronic"){
					        Electronics* electronic = dynamic_cast<Electronics*>(shop);
					        if(electronic) {
					        	if(!showDisp){
									categoryDisp(); showDisp = true;
								}
							electronic->display();
							hasElectronic = true;
							}
							pass = true;
					    }
					    else if(categoryChoice == "entertainment"){
					        Entertainment* entertainment = dynamic_cast<Entertainment*>(shop);
							if(entertainment) {
								if(!showDisp){
									categoryDisp(); showDisp = true;
								}	
							entertainment->display();		        
							hasEntertainment = true;
							}
							pass = true;
						}
						else{
							cout<<"\nPlease choose one of the (3) category."<<endl;
						}
					}
				}
				if(!hasCloth && (categoryChoice == "clothing" || categoryChoice == "clothings")){
					cout << "There is no item available for clothing yet." << endl;
				}
				if(!hasElectronic && (categoryChoice == "electronics" || categoryChoice == "electronic")){
					cout << "There is no item available for electronics yet." << endl;
				}
				if(!hasEntertainment && categoryChoice == "entertainment"){
					cout << "There is no item available for entertainment yet." << endl;
				}
			}
			break;
		}
		case 5:
			if (shops.empty()) {
			    cout << "There is no item available yet." << endl;
			}
			else {
				cout << "\nDisplaying all items:" << endl;
				tabs();
			    for (auto& shop : shops) {
			        shop->display();
			    }
			}
			break;
		case 6:{
		bool itemFound = false, proceed = false;
		char ans;
			if (shops.empty()) {
			    cout << "There is no item to search for yet." << endl;
			}
			else {
			    cout << "Enter the ID to search: ";
			    getline(cin, key);
			    for (char& c : key) {
				    c = toupper(c);
				}
				    for (auto& shop : shops) {
				        if (shop->getID() == key) { 
							cout << "\nDisplaying requested item:" << endl;
							tabs();
				            shop->display();
				            
				            proceed = false;
					        while(!proceed){
					            cout<<"\nIs this the correct item? (Y/N): ";
						        cin>>ans;
						    	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
						    	
						    	if(ans == 'y' || ans == 'Y'){
						            itemFound = true; proceed = true;
						            cout<<"Item found! going back to menu..."<<endl;
					        	}
					        	else if(ans == 'n' || ans == 'N'){
									proceed = true;
								}
								else{
									cout<<"\nChoose either Y or N.";
								}
							}
				    	}	
				    }
					if (!itemFound){
					    	cout<<"Item not found! (Please check if ID is correct)."<<endl;
					    	break;
						}
			}
			break;
		}
		case 7:{
			if (shops.empty()) {
			    cout << "There is no item to sort yet." << endl;
			}
			else {
				string sortCriteria;
				bool entry = false;
				
				while(!entry){
	            cout << "\nSort by (quantity or price): ";
	       		getline(cin, sortCriteria);
	       		for (char& c : sortCriteria) {
				    c = tolower(c);
				}
				if(sortCriteria == "quantity" || sortCriteria == "price"){
					entry = true;
				}
				else{
					cout<<"Error. Please try again."<<endl;
					entry = false;
				}
			}
	            Shop::sortItems(shops, sortCriteria);
	            cout << "\nItems sorted successfully by " << sortCriteria << "!" << endl;
				cout << "\nDisplaying sorted items:" << endl;
				tabs();
				 for (auto& shop : shops) {
					shop->display();
				 }
			}
			break;		
		}
		case 8:{
			bool isLow = false, showDisp = false;
			if (shops.empty()) {
			    cout << "There is no items to display yet." << endl;
			}
			else {
				for(auto& shop : shops){
					if(shop->getQuantity() <= 5){
						if(!showDisp){
						cout<<"\nDisplaying Low Stock Items: "<<endl;
						tabs(); showDisp = true;
						}
						shop->display();
						isLow = true;
					}
				}
				if(!isLow){
					cout<<"There is no low stock items."<<endl;
				}
			}
			break;
		}
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