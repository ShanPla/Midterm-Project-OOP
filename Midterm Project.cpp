#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

bool isOnlyDigits(const string& str) { // Validation for inputs to prevent decimals
    for (char const &c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}
bool digitcheck(const string& str) { // Validation for price so it denies negative numbers or special characters
    if (str.empty()) return false;

    size_t start = 0;
    bool decimalPointFound = false;

    if (str[0] == '-') { // Check if the first character is a negative sign
        start = 1;
    }
    if (start == 1 && str.length() == 1) return false;

    for (size_t i = start; i < str.length(); ++i) {
        if (str[i] == '.') { // Check if the current character is a decimal point
            // Allow only one decimal point in the string
            if (decimalPointFound) return false;
            decimalPointFound = true;
        }
        else if (!isdigit(str[i])) { // If the character is not a digit and not a decimal point, return false
            return false;
        }
    }

    return true;
}
bool isOnlyLetters(const string& str) { // Checks if the string is only letters
    if (str.empty()) return false;

    for (char const &c : str) { // Checks each character if it is a letter
        if (!isalpha(c)) return false;
    }

    return true;
}
class Shop{ // Abstract class
	
	private:
		int quantity;
		double price;
		string ID, name;
	
	public:
		Shop(int tempQuantity, double tempPrice, string tempID, string tempName) : quantity(tempQuantity), price(tempPrice), ID(tempID), name(tempName){}
		
		virtual void addItem() = 0; // Virtual void declarations
		virtual void display() = 0;
		
		void setName(string a){ // Setters
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
		
		string getName(){ // Getters
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
		
		void updateItem(){ // Update function that all three category can use
			
			int qty;
			double newprice;
			string update, input;
			bool isUpdated = false, validInput = false, validCategory = false;
			while(!isUpdated){		
   				while (!validCategory) { // Checks if user input is in line with the options, if not, loops
					cout << "\n(Quantity or Price)" << endl;
				    cout << "What would you like to update for this item?: ";
			        getline(cin, update);        
			        if (isOnlyLetters(update)) {
			        	if(update == "quantity" || update == "price"){
			            validCategory = true; // Passes the loop if correct option
						}
						else{
							cout << "Invalid input! Please enter one of the two choices.\n";
						}
			        } 
					else {
			            cout << "Numbers/Symbols are not allowed. Please try again.\n";
			        }
			        cin.clear();
		   		}	        		        
		        for (char& c : update) { // Makes update case insensitive
				    c = tolower(c);
				}
					
			    system("CLS");
			   	if(update == "quantity"){
			    	while(!validInput){
			           	cout << "Please input the new amount of qty: ";
			           	cin >> input;
			           	if (digitcheck(input)) {
				            qty = stoi(input); // Converts input to numeric value
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
				            newprice = stoi(input); // Converts input to numeric value
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
				        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignores invalid input
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
				    if (sortCriteria == "quantity") { // Sorts quantity in ascending order
				        for (int i = 0; i < n - 1; i++) {
				            for (int j = 0; j < n - i - 1; j++) {
				                if (shops[j]->getQuantity() > shops[j + 1]->getQuantity()) {
	
				                    Shop* temp = shops[j];
				                    shops[j] = shops[j + 1];
				                    shops[j + 1] = temp;
				                }
				            }
				        }
				    } else if (sortCriteria == "price") { // Sorts price in ascending order
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
					if (sortCriteria == "quantity") { // Sorts quantity in descending order		
				        for (int i = 0; i < n - 1; i++) {
				            for (int j = 0; j < n - i - 1; j++) {
				                if (shops[j]->getQuantity() < shops[j + 1]->getQuantity()) {
				            
				                    Shop* temp = shops[j];
				                    shops[j] = shops[j + 1];
				                    shops[j + 1] = temp;
				                }
				            }
				        }
				    } else if (sortCriteria == "price") { // Sorts price in descending order		
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
			for (char& c : inputID) { // Makes ID case insensitive
			    c = toupper(c);
			}	

			int inputQuantity;
			while(!validInput){
				cout<<"\nPlease Input Quantity: ";
				cin>>input;
			if (isOnlyDigits(input)) {
                inputQuantity = stod(input); // Converts input into a double
                if (inputQuantity > 0) { // Checks if inputQuality is valid
                    validInput = true;
                }
                else if(inputQuantity < 1){
                    cout << "Stock must be atleast 1. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter a valid integer.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
        }
        	validInput = false;
			
			double inputPrice;
			while(!validInput){
				cout<<"\nPlease Input Price: ";
				cin>>input;
			if (digitcheck(input)) {
                inputPrice = stod(input); // Converts input into a double
                if (inputPrice > 0) { // Checks if inputPrice is valid
                    validInput = true;
                }
                else if(inputPrice < 1){
                    cout << "Price must be atleast worth 1php. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter a valid integer.\n";
            }
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
        }

			setName(inputName); setID(inputID); setQuantity(inputQuantity); setPrice(inputPrice); // passes the values to setter
			
			cout<<"\nClothing added successfully!"<<endl;		
		}
		
		void display() override{ // Displays the items		
					cout << left << setw(15) << setfill(' ') << getID();
					cout << left << setw(15) << setfill(' ') << getName();
					cout << left << setw(15) << setfill(' ') << getQuantity();
					cout << fixed << setprecision(2) << left << setw(15) << setfill(' ') << getPrice();
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
			for (char& c : inputID) { // Makes ID case insensitive
			    c = toupper(c);
			}
			
			int inputQuantity;
			while(!validInput){
				cout<<"\nPlease Input Quantity: ";
				cin>>input;
			if (isOnlyDigits(input)) {
                inputQuantity = stod(input); // Converts input into a double
                if (inputQuantity > 0) { // Checks if inputQuality is valid
                    validInput = true;
                }
                else if(inputQuantity < 1){
                    cout << "Stock must be atleast be 1. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter a valid integer.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
        }
        	validInput = false;
			
			double inputPrice;
			while(!validInput){
				cout<<"\nPlease Input Price: ";
				cin>>input;
			if (digitcheck(input)) {
                inputPrice = stod(input); // Converts input into a double
                if (inputPrice > 0) { // Checks if inputPrice is valid
                    validInput = true;
                }
                else if(inputPrice < 1){
                    cout << "Price must be atleast be worth 1php. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter a valid integer.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
        }
			
			setName(inputName); setID(inputID); setQuantity(inputQuantity); setPrice(inputPrice); // passes the values to setter

			cout<<"\nElecronic added successfully!"<<endl;		
		}
		
		void display() override{ // Displays the items	
					cout << left << setw(15) << setfill(' ') << getID();
					cout << left << setw(15) << setfill(' ') << getName();
					cout << left << setw(15) << setfill(' ') << getQuantity();
					cout << fixed << setprecision(2) << left << setw(15) << setfill(' ') << getPrice();
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
			for (char& c : inputID) { // Makes ID case insensitive
			    c = toupper(c);
			}
			
			int inputQuantity;
			while(!validInput){
				cout<<"\nPlease Input Quantity: ";
				cin>>input;
			if (isOnlyDigits(input)) {
                inputQuantity = stod(input); // Converts input into a double
                if (inputQuantity > 0) { // Checks if inputQuality is valid
                    validInput = true;
                }
                else if(inputQuantity < 1){
                    cout << "Stock must be atleast be 1. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter a valid integer.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
        }
        	validInput = false;
			
			double inputPrice;
			while(!validInput){
				cout<<"\nPlease Input Price: ";
				cin>>input;
			if (digitcheck(input)) {
                inputPrice = stod(input); // Converts input into a double
                if (inputPrice > 0) { // Checks if inputPrice is valid
                    validInput = true;
                }
                else if(inputPrice < 1){
                    cout << "Price must be atleast be worth 1php. Please try again.\n";
                }
            }
			else {
                cout << "Invalid input! Please enter a valid integer.\n";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
        }
					
			setName(inputName); setID(inputID); setQuantity(inputQuantity); setPrice(inputPrice); // passes the values to setter
			
			cout<<"\nEntertainment added successfully!"<<endl;
		}
		
		void display() override{ // Displays the items		
					cout << left << setw(15) << setfill(' ') << getID();   
					cout << left << setw(15) << setfill(' ') << getName();
					cout << left << setw(15) << setfill(' ') << getQuantity();
					cout << fixed << setprecision(2) << left << setw(15) << setfill(' ') << getPrice();
					cout << left << setw(15) << setfill(' ') << "Entertainment" << endl;
                }
		};	
		
void tabs(){ // Displays the header
			cout << left << setw(15) << setfill(' ') << "ID";
			cout << left << setw(15) << setfill(' ') << "Name";
			cout << left << setw(15) << setfill(' ') << "Quantity";
			cout << left << setw(15) << setfill(' ') << "Price";
			cout << left << setw(15) << setfill(' ') << "Category"<<endl;
			cout << "--------------------------------------------------------------------"<<endl;
		}
void categoryDisp(){
	cout<<"Displaying all items in category:"<<endl;
	tabs();
}
				
void Menu(){
	
	vector<Shop*> shops; // Declares vector to hold pointers to Shop
	bool entry = true;	
	string category, key, input;
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
		
		bool validInput = false; // Declares validInput
        
        while (!validInput) { // Loops until validation is satisfied
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
                cout << "Invalid input! Please choose from the menu.\n";
            }
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
        }            
		system("CLS");
	switch(choice){
		case 1:{
			string categoryChoice;
			cout<<"\nPlease input category (Clothing, Electronics, Entertainment): ";
			getline(cin, categoryChoice);
			cin.clear();
			for (char& c : categoryChoice) {
			    c = tolower(c);
			}
			
				if(categoryChoice == "clothing" || categoryChoice == "clothings"){ // All if statements check for categories
					Shop* cloth = new Clothing(0,0," ", " "); // Declares a pointer cloth to point to Shop, assigns Clothing's address to cloth // Same for the other two categories.
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
					cout<<"\nCategory "<<categoryChoice<<" does not exist!"<<endl; // Displays if input is not of the three categories
				}
			break;
		}
		case 2:{
			bool itemFound = false, itemconfirm = false;
			char ans;
			if (shops.empty()) {
			    cout << "There is no item to update." << endl; // Displays if shops is empty
			    break;
			}
				cout << "Enter the ID to update: ";
			    getline(cin, key);
			    cin.clear();
				for (char& c : key) { // Makes the key case insensitive
				    c = toupper(c);
				}
				    for (auto& shop : shops) {
				        if (shop->getID() == key) { // Checks if getID matches the key
				        	cout<<"Item to be updated: "<<endl;
							tabs();
							shop->display(); // Displays the item to be updated
							
							while(ans != 'n' || ans != 'N'){ // Loops until validation is satisfied
					        	cout<<"\nIs this the correct item? (Y/N): ";
					        	cin>>ans;
					        	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
					        	if(ans == 'y' || ans == 'Y'){
									shop->updateItem(); // Calls updateItem function
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
					if(!itemFound){ // Runs if item is not found
				    	cout<<"Item not found! (Please check if ID is correct)"<<endl;
				    	break;
					}
				break;
			}
		case 3:{
			bool itemFound = false, proceed = false;
			char ans;
				
			if (shops.empty()) {
			    cout << "There is no item to remove." << endl; // Displays if shops is empty
			}
			else {
			    cout << "Enter the ID to remove: ";
			    getline(cin, key);
			    for (char& c : key) { // Makes the key case insensitive
				    c = toupper(c);
				}
				    for (auto it = shops.begin(); it != shops.end(); ++it) {
				        if ((*it)->getID() == key) { // Checks if "it" matches the key
				        	
				        	cout<<"Item to be removed: "<<endl;
							tabs();
							(*it)->display(); // Displays the item to be removed
					
							proceed = false;
							while(!proceed){ // Loops until validation is satisfied
						       	cout<<"\nIs this the correct item? (Y/N): ";
						       	cin>>ans;
						       	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
						       	
						       	if(ans == 'y' || ans == 'Y'){
						        	cout<<"Item "<<(*it)->getName()<<" has been removed from the inventory!"<<endl;
						            delete *it; // Deallocates memory
						            shops.erase(it); // Removes the element from vector
						            itemFound = true; proceed = true;
						            break;
						        }
						        else if(ans == 'n' || ans == 'N'){
									proceed = true; // Sets bool to true to continue to next for loop
								}
								else{
									cout<<"\nChoose either Y or N.";
								}
							}
							if (itemFound) break; // Exits for loop is item is found and removed
				        }
					}
					if (!itemFound) { // Runs if item is not found
				        cout << "Item not found! (Please check if ID is correct)." << endl;
				        break;
				    }
			}
		    break;
		}
		case 4:{
			bool hasCloth = false, hasElectronic = false, hasEntertainment = false, pass = false;
			string categoryChoice;
			if (shops.empty()) {
			    cout << "There is no item available yet." << endl; // Displays if shops is empty
			}
			else {
					while(!pass){ // Loops until validation is satisfied
						cout<<"\n(Clothing, Electronics, Entertainment)";
						cout << "\nPlease input what category you would like to see: ";
						cin>>categoryChoice;  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
						for (char& c : categoryChoice) {
						    c = tolower(c);
						}
						bool showDisp = false, pass = false; // Initializes the bool to false
						if(categoryChoice == "clothing" || categoryChoice == "electronics" || categoryChoice == "entertainment") {
							for(auto& shop : shops){
							    if(categoryChoice == "clothing"){
							        Clothing* cloth = dynamic_cast<Clothing*>(shop); // Checks if shop is pointing to a Clothing object, if it does, dynamic_cast is casted, cloth will point to Clothing
									if(cloth) { // Check if cast is successfull
										if(!showDisp){
											categoryDisp(); showDisp = true; // Displays the header once then sets showDisp to true so header is displayed only once
										}
									cloth->display();		        
									hasCloth = true; // Sets bool to true to mark that there is atleast 1 item
									}
									pass = true;
							    }
							    else if(categoryChoice == "electronics" || categoryChoice == "electronic"){
							        Electronics* electronic = dynamic_cast<Electronics*>(shop);
							        if(electronic) { // Check if cast is successfull
							        	if(!showDisp){
											categoryDisp(); showDisp = true; // Displays the header once then sets showDisp to true so header is displayed only once
										}
									electronic->display();
									hasElectronic = true; // Sets bool to true to mark that there is atleast 1 item
									}
									pass = true;
							    }
							    else if(categoryChoice == "entertainment"){
							        Entertainment* entertainment = dynamic_cast<Entertainment*>(shop);
									if(entertainment) { // Check if cast is successfull
										if(!showDisp){
											categoryDisp(); showDisp = true; // Displays the header once then sets showDisp to true so header is displayed only once
										}	
									entertainment->display();		        
									hasEntertainment = true; // Sets bool to true to mark that there is atleast 1 item
									}
									pass = true;
								}
							
							}
							cout<<"\n";
					if(!hasCloth && categoryChoice == "clothing"){ // Displays if there is no item in clothing
						cout << "There is no item available for clothing yet." << endl;
					}
					if(!hasElectronic && (categoryChoice == "electronics" || categoryChoice == "electronic")){ // Displays if there is no item in electronics
						cout << "There is no item available for electronics yet." << endl;
					}
					if(!hasEntertainment && categoryChoice == "entertainment"){ // Displays if there is no item in entertainment
						cout << "There is no item available for entertainment yet." << endl;
					}
				}
				else{
					cout<<"\nPlease choose one of the (3) category."<<endl; // Displays is user does not input one of the categories
				}
			}
		}
			break;
		}
		case 5:
			if (shops.empty()) {
			    cout << "There is no item available yet." << endl; // Displays if shops is empty
			}
			else {
				cout << "\nDisplaying all items:" << endl;
				tabs();
			    for (auto& shop : shops) { // Iterates through shops to display items
			        shop->display();
			    }
			    cout<<"\n";
			}
			break;
		case 6:{
		bool itemFound = false, proceed = false;
		char ans;
			if (shops.empty()) {
			    cout << "There is no item to search for yet." << endl; // Displays if shops is empty
			}
			else {
			    cout << "Enter the ID to search: ";
			    getline(cin, key);
			    for (char& c : key) {
				    c = toupper(c);
				}

				    for (auto& shop : shops) { // Loops through shops to find the same ID
				        if (shop->getID() == key) {
				        	if(!itemFound){ // Displays the tabs one time
							cout << "\nDisplaying item/s with ID " << key << ": " << endl;
							tabs();
							}
							itemFound = true;
				            shop->display();
				    	}	
				    }
				    cout<<"\n";
					if (!itemFound){ // Runs if item is not found
					    	cout<<"Item not found! (Please check if ID is correct)."<<endl;
					    	break;
						}
			}
			break;
		}
		case 7:{
			if (shops.empty()) {
			    cout << "There is no item to sort yet." << endl; // Displays if shops is empty
			}
			else {
				string sortCriteria;
				bool entry = false;
				
				while(!entry){ // Loops until validation is done
	            cout << "\nSort by (quantity or price): ";
	       		getline(cin, sortCriteria);
	       		for (char& c : sortCriteria) { // Makes sortCriteria case insensitive
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
	            Shop::sortItems(shops, sortCriteria); // Calls the static function sortItems without using an object instance
	            cout << "\nItems sorted successfully by " << sortCriteria << "!" << endl;
				cout << "\nDisplaying sorted items:" << endl;
				tabs();
				 for (auto& shop : shops) { // Displays all items in shops
					shop->display();
				 }
				 cout<<"\n";
			}
			break;		
		}
		case 8:{
			bool isLow = false, showDisp = false;
			if (shops.empty()) {
			    cout << "There is no items to display yet." << endl; // Displays if shops is empty
			}
			else {
				for(auto& shop : shops){
					if(shop->getQuantity() <= 5){ // Runs the code inside if qty of item is 5 or below
						if(!showDisp){
						cout<<"\nDisplaying Low Stock Items: "<<endl;
						tabs(); showDisp = true;
						}
						shop->display();
						isLow = true;
					}
				}
				cout<<"\n";
				if(!isLow){ // Displays if isLow is not set to true by end of case
					cout<<"There is no low stock items."<<endl;
				}
			}
			break;
		}
		case 9:
			cout<<"Terminating program...";
			entry = false; // Exits loop
			break;
		default:
			cout<<"\nInvalid Input. Please try again."<<endl;			
		}
	}
	for(auto& shop : shops){ // Frees the memory
    	delete shop;
	}
	shops.clear();
}
int main(){
		
	Menu(); // Calls Menu functions
	
	return 0;
}