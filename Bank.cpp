#include <iostream>
#include <fstream>
using namespace std;

int num;
string na, first_attempt, second_attempt, x, y, p;
int initial, z;
string name_to_find, pass_to_find, to_find, name_to_delete, pass_to_delete;
int to_add, to_takeout,attempts_left_password,attempts_left_amount =0;
bool b;

struct node{
    int Amount;
    string password;
    string name;
    bool locked = false;
    node* next;
};

struct admin_node{
    int ID;
    string Name;
    admin_node* next;
};

node* head = NULL;
node* tail = NULL;


class Queue{
    private:
        node* head2;
        node* tail2;
    public:
        Queue(){
            head2 = nullptr;
            tail2 = nullptr;
        }
        void is_empty(){
            if(head2 == nullptr){
                cout << "There are no locked accounts" << endl;
                return;
            }
            cout << "There are locked accounts" << endl;
            return;
        }
        void insert(int a, string s, string n, bool l){
            node* insert_queue = new node;
            insert_queue->name = n;
            insert_queue->Amount = a;
            insert_queue->password = s;
            insert_queue->locked = l;

            if(head2 == nullptr){
                head2 = insert_queue;
                tail2 = insert_queue;
                return;
            }
            tail2->next = insert_queue;
            tail2 = insert_queue;
            tail2->next = nullptr;
        }
        node* unlock(){
            if(head2 == NULL){
                return head2;
            }
            if(head2 == tail2){
                head2->locked = false;
                node* copyy = head;
                while(copyy != nullptr){
                    if(copyy->name == head2->name && copyy->password == head2->password){
                        copyy->locked = false;
                    }
                    copyy = copyy->next;
                }
                head2 = NULL;
                tail2 = NULL;
                return head2;
            }
            head2->locked = false;
            node* copyy = head;
            while(copyy != nullptr){
                cout << copyy->name << endl;
                if(copyy->name == head2->name && copyy->password == head2->password){
                    copyy->locked = false;
                }
                copyy = copyy->next;
            }
            head2 = head2->next;
            return head2;
        }
        void output(ofstream &qofs){
            node* temp = head2;
            while(temp != nullptr){
                qofs << temp->name << endl;
                qofs << temp->Amount << endl;
                qofs << temp->password << endl;
                qofs << temp->locked << endl;
                temp = temp->next;
            }
        }
};

class Admin{
    private:
        admin_node* adminhead = NULL;
        admin_node* admintail = NULL;
    public:
        void insert_admin_fromFile(ofstream &aofs, ifstream &aifs){
            if(!aofs.eof()){
                aifs.open("Admin.txt");
                while(getline(aifs,x, '\n')){
                    if(x.empty()){
                        continue;
                    }
                    getline(aifs,y, '\n');
                    z = stoi(x);
                    cout << x << endl;
                    cout << y << endl;
                    admin_node* n = new admin_node;
                    n->ID = z;
                    n->Name = y;
                    if(adminhead == nullptr){
                        adminhead = n;
                        admintail = n;
                    }
                    admintail->next = n;
                    admintail = n;
                    admintail->next = nullptr;
                }
            }
            aofs.open("Admin.txt");
        } 
        void insert_admin(int a, string s){
            admin_node* insert_new = new admin_node;
            insert_new->ID = a;
            insert_new->Name = s;
            if(adminhead == nullptr){
                adminhead = insert_new;
                admintail = insert_new;
                return;
            }
            admintail->next = insert_new;
            admintail = insert_new;
            admintail->next = nullptr;
        }
        void outpus_Admin(ofstream &aofs){
            admin_node* temp = adminhead;
            while(temp != nullptr){
                aofs << temp->ID << endl;
                aofs << temp->Name << endl;
                temp = temp->next;
            }
            aofs.flush();
            aofs.close();
        }
        bool find(int to_find_ID){
            admin_node* admin2 = adminhead;
            while(admin2 != nullptr){
                if(admin2->ID == to_find_ID){
                    return true;
                }
                admin2 = admin2->next;
                return false;
            }
        }
};

void print_menu(){
    cout << "-----------------------------------" << endl;
    cout << "    WELCOME TO CAVAZOS'S BANK      " << endl;
    cout << "-----------------------------------" << endl;
    cout << "|    What would you like to do?   |" << endl;
    cout << "|    1) Add New Account           |" << endl;
    cout << "|    2) Add money!                |" << endl;
    cout << "|    3) Delete My Account         |" << endl;
    cout << "|    4) Withdraw Money            |" << endl;
    cout << "|    5) Log me Out!               |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Please Select your wish...." << endl;
}

void print_admin(){
    cout << "-----------------------------------" << endl;
    cout << "            Welcome                " << endl;
    cout << "-----------------------------------" << endl;
    cout << "|    What would you like to do?   |" << endl;
    cout << "|    1) Fix Locked Account        |" << endl;
    cout << "|    2) Go Back                   |" << endl;
    cout << "|                                 |" << endl;
    cout << "|                                 |" << endl;
    cout << "|                                 |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Please Select your wish...." << endl;
}

int main(){
    Queue qq;
    Admin aa;
    ofstream ofs;
    ifstream ifs;
    ofstream qofs;
    ifstream qifs;
    ofstream aofs;
    ifstream aifs;
    if(!ofs.eof()){
        ifs.open("OUTPUT.txt");
        while(getline(ifs,x, '\n')){
            if(x.empty()){
                continue;
            }
            getline(ifs,y, '\n');
            z = stoi(y);
            getline(ifs,p, '\n');
            ifs >> b;
            cout << x << endl;
            cout << y << endl;
            cout << p << endl;
            cout << b << endl;
            node* n = new node;
            n->name = x;
            n->Amount = z;
            n->password = p;
            n->locked = b;
            if(head == nullptr){
                head = n;
                tail = n;
            }
            tail->next = n;
            tail = n;
            tail->next = nullptr;
         }
    }
    cout << "---------------" << endl;
    if(!qofs.eof()){
        qifs.open("OUTPUTQ.txt");
        while(getline(qifs,x, '\n')){
            if(x.empty()){
                continue;
            }
            getline(qifs,y, '\n');
            z = stoi(y);
            getline(qifs,p, '\n');
            qifs >> b;
            cout << x << endl;
            cout << y << endl;
            cout << p << endl;
            cout << b << endl;
            node* n = new node;
            n->name = x;
            n->Amount = z;
            n->password = p;
            n->locked = b;
            qq.insert(n->Amount, n->password, n->name, n->locked);
         }
    }

    ofs.open("OUTPUT.txt");
    qofs.open("OUTPUTQ.txt");
    print_menu(); 
    cin >> num;
    while(num != 0){
        switch (num){
            case 1:{
                node* new_cust = new node;
                cout << "What is your name?" << endl;
                cin >> na;
                cout << "What is you initial amount?" << endl;
                cin >> initial;
                cout << "Please enter a password" << endl;
                cin >> first_attempt;
                cout << "Please Enter it again" << endl;
                cin >> second_attempt;
                if(first_attempt == second_attempt){
                    cout << "Passsword has been successfully saved!" << endl;
                    new_cust->password = first_attempt;
                }
                new_cust->name =  na;
                new_cust->Amount = initial;
                new_cust->next = nullptr;
                if(head == nullptr){
                    head = new_cust;
                    tail = new_cust;
                }
                tail->next = new_cust;
                tail = new_cust;
                tail->next = nullptr;
                cout << "===========================" << endl;
                cout << "This Account has been added" << endl;
                cout << "-" << new_cust->name << endl;
                cout << "-" << new_cust->Amount << endl;
                cout << "---------------------------" << endl;
                cout << "Now that we got you all set, is there anything else we can help you with?" << endl;
                print_menu();
                cin >> num;
                break;
            }
            case 2:{
                attempts_left_password =0;
                cout << "Plaese enter your name; " << endl;
                cin >> name_to_find;
                node* search = head;
                while(search != nullptr){
                    if(search->name == name_to_find){
                        if(search->locked == true){
                            node*c = head;
                            cout << "Your account has been blocked." << endl;
                            cout << "Please contact a administartor." << endl;
                            while(c != nullptr){
                                ofs << c->name << endl;
                                ofs << c->Amount << endl;
                                ofs << c->password << endl;
                                ofs << c->locked << endl;
                                c = c->next;
                            }
                            aa.outpus_Admin(aofs);
                            qq.output(qofs);
                            ofs.flush();
                            ofs.close();
                            cout << "HAVE AN AMAZING DAY!" << endl;
                            return 0;     
                        }
                        cout << "Please enter your password: " << endl;
                        cin >>  pass_to_find;
                        while(search->password != pass_to_find && attempts_left_password < 3){
                            attempts_left_password++;
                            cout << "Please try again: " << endl;
                            cin >> pass_to_find;
                            cout << "You have " << 3-attempts_left_password << " remaining" << endl;
                        }
                        if(attempts_left_password == 3){
                            node*c = head;
                            cout << "Your account has been blocked." << endl;
                            search->locked = true;
                            qq.insert(search->Amount, search->password, search->name, search->locked);
                            cout << "Please contact a administartor." << endl;
                            while(c != nullptr){
                                ofs << c->name << endl;
                                ofs << c->Amount << endl;
                                ofs << c->password << endl;
                                ofs << c->locked << endl;
                                c = c->next;
                            }
                            aa.outpus_Admin(aofs);
                            ofs.flush();
                            ofs.close();
                            cout << "HAVE AN AMAZING DAY!" << endl;
                            qq.output(qofs);
                            qofs.flush();
                            qofs.close();
                            return 0;
                        }
                        cout << "How much money would you like to add: " << endl;
                        cin >> to_add;
                        search->Amount = search->Amount+to_add;
                        cout << "===========================" << endl;
                        cout << "Your Current amount is: " << search->Amount << endl;
                        cout << "===========================" << endl;
                        break;
                    }
                    search = search->next;
                }
                print_menu();
                cin >> num;
                break;
            }
            case 3:{
                node* current = head;
                node* ahead = current->next;
                attempts_left_password =0;
                cout << "Please enter the name under the account you would like to delete: " << endl;
                cin >> name_to_delete;
                while(current != nullptr){
                    if(current->name == name_to_delete){ //If this is the first element
                        if(current->locked == true){
                            cout << "Your account has been blocked." << endl;
                            cout << "Please contact a administartor." << endl;
                            while(head != nullptr){
                                ofs << head->name << endl;
                                ofs << head->Amount << endl;
                                ofs << head->password << endl;
                                ofs << head->locked << endl;
                                head = head->next;
                            }
                            aa.outpus_Admin(aofs);
                            qq.output(qofs);
                            ofs.flush();
                            ofs.close();
                            qofs.flush();
                            qofs.close();
                            cout << "HAVE AN AMAZING DAY!" << endl;
                            return 0;     
                        }
                        cout << current->name << endl;
                        cout << "Please enter the password: " << endl;
                        cin >> pass_to_delete;
                        while(current->password != pass_to_delete && attempts_left_password < 3){
                            attempts_left_password++;
                            cout << "Please try again: " << endl;
                            cin >> pass_to_delete;
                            cout << "You have " << 3-attempts_left_password << " remaining" << endl;
                        }
                        if(attempts_left_password == 3){
                            cout << "Your account has been blocked." << endl;
                            qq.insert(current->Amount, current->password, current->name, current->locked);
                            current->locked = true;
                            cout << "Please contact a administartor." << endl;
                            while(head != nullptr){
                                ofs << head->name << endl;
                                ofs << head->Amount << endl;
                                ofs << head->password << endl;
                                ofs << head->locked << endl;
                                head = head->next;
                            }
                            aa.outpus_Admin(aofs);
                            qq.output(qofs);
                            ofs.flush();
                            ofs.close();
                            qofs.flush();
                            qofs.close();
                            cout << "HAVE AN AMAZING DAY!" << endl;
                            return 0;
                        }
                        if(current->next == nullptr){
                            head = nullptr;
                            cout << "Your account has been deleted!" << endl;
                            break;
                        }
                        current = ahead;
                        ahead = current->next;
                        cout << "Your account has been deleted!" << endl;
                        break;
                    }
                    if(ahead->name == name_to_delete){
                        if(ahead->locked == true){
                            cout << "Your account has been blocked." << endl;
                            cout << "Please contact a administartor." << endl;
                            while(head != nullptr){
                                ofs << head->name << endl;
                                ofs << head->Amount << endl;
                                ofs << head->password << endl;
                                ofs << head->locked << endl;
                                head = head->next;
                            }
                            aa.outpus_Admin(aofs);
                            qq.output(qofs);
                            ofs.flush();
                            ofs.close();
                            qofs.flush();
                            qofs.close();
                            cout << "HAVE AN AMAZING DAY!" << endl;
                            return 0;     
                        }
                        cout  << ahead->name << endl;
                        cout << "Please enter the password: " << endl;
                        cin >> pass_to_delete;
                        while(ahead->password != pass_to_delete && attempts_left_password < 3){
                            attempts_left_password++;
                            cout << "Please try again: " << endl;
                            cin >> pass_to_delete;  
                            cout << "You have " << 3-attempts_left_password << " remaining" << endl;
                        }
                        if(attempts_left_password == 3){
                            cout << "Your account has been blocked." << endl;
                            qq.insert(ahead->Amount, ahead->password, ahead->name, ahead->locked);
                            ahead->locked = true;
                            cout << "Please contact a administartor." << endl;
                            while(head != nullptr){
                                ofs << head->name << endl;
                                ofs << head->Amount << endl;
                                ofs << head->password << endl;
                                ofs << head->locked << endl;
                                head = head->next;
                            }
                            aa.outpus_Admin(aofs);
                            qq.output(qofs);
                            ofs.flush();
                            ofs.close();
                            qofs.flush();
                            qofs.close();
                            cout << "HAVE AN AMAZING DAY!" << endl;
                            return 0;
                        }
                        current->next = ahead->next;
                        ahead = ahead->next;
                        cout << "Your account has been deleted!" << endl;
                        break;
                    }
                    current = ahead;
                    ahead = current->next;
                }
                print_menu();
                cin >> num;
                break;
            }
            case 4:{
                int new_amount = 0;
                attempts_left_password =0;
                cout << "Plese enter your name; " << endl;
                cin >> name_to_find;
                node* search = head;
                while(search != nullptr){
                    if(search->name == name_to_find ){
                        if(search->locked == true){
                            cout << "Your account has been blocked." << endl;
                            cout << "Please contact a administartor." << endl;
                            while(head != nullptr){
                                ofs << head->name << endl;
                                ofs << head->Amount << endl;
                                ofs << head->password << endl;
                                ofs << head->locked << endl;
                                head = head->next;
                            }
                            aa.outpus_Admin(aofs);
                            qq.output(qofs);
                            ofs.flush();
                            ofs.close();
                            qofs.flush();
                            qofs.close();
                            cout << "HAVE AN AMAZING DAY!" << endl;
                            return 0;     
                        }
                        cout << "Please enter your password: " << endl;
                        cin >>  pass_to_find;
                        while(search->password != pass_to_find && attempts_left_password < 3){
                            attempts_left_password++;
                            cout << "Please try again: " << endl;
                            cin >> pass_to_find;
                            cout << "You have " << 3-attempts_left_password << " remaining" << endl;
                        }
                        if(attempts_left_password == 3){
                            cout << "Your account has been blocked." << endl;
                            qq.insert(search->Amount, search->password, search->name, search->locked);
                            search->locked = true;
                            cout << "Please contact a administartor." << endl;
                            while(head != nullptr){
                                ofs << head->name << endl;
                                ofs << head->Amount << endl;
                                ofs << head->password << endl;
                                ofs << head->locked << endl;
                                head = head->next;
                            }
                            aa.outpus_Admin(aofs);
                            qq.output(qofs);
                            qofs.flush();
                            qofs.close();
                            ofs.flush();
                            ofs.close();
                            cout << "HAVE AN AMAZING DAY!" << endl;
                            return 0;
                        }
                        cout << "How much money would you like to remove: " << endl;
                        cin >> to_takeout;
                        new_amount = search->Amount-to_takeout;
                        while(new_amount <0){
                            cout << "Oops something went wrong" << endl;
                            cout << "Your ASccounts Amount is negative" << endl;
                            cout << "Please try again: " << endl;
                            cout << "-----------------------------------------" << endl;
                            cout << "How much money would you like to remove: " << endl;
                            cin >> to_takeout;
                            new_amount = search->Amount - to_takeout;
                        }
                        search->Amount = search->Amount-to_takeout;
                        break;
                    }
                    search = search->next;
                }
                print_menu();
                cin >> num;
                break;
            }
            case 5:{
                node* c = head;
                while(c != nullptr){
                    ofs << c->name << endl;
                    ofs << c->Amount << endl;
                    ofs << c->password << endl;
                    ofs << c->locked << endl;
                    c = c->next;
                }
                aa.outpus_Admin(aofs);
                ofs.flush();
                ofs.close();
                qofs.flush();
                qofs.close();
                cout << "HAVE AN AMAZING DAY!" << endl;
                return 0;
            }
            case 6:{
                aa.insert_admin_fromFile(aofs, aifs);
                int admin_id;
                int admin_num;
                cout << "Please Enter your Admin ID: " << endl;
                cin >> admin_id;
                while(aa.find(admin_id) == false){
                    cout << "You are not an Admin" << endl;
                    cout << "Please try again" << endl;
                    cin >> admin_id;
                }
                if(aa.find(admin_id) == true){
                    print_admin();
                    cin >> admin_num;
                    while(admin_num != 5){
                        switch (admin_num){
                            case 1:
                                qq.is_empty();
                                qq.unlock();
                                print_admin();
                                cin >> admin_num;
                                break;
                            case 2:
                                break;
                        }
                        print_menu(); 
                        cin >> num;
                        break;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}


