#include <iostream>
#include "phoneBook.h"

using namespace std;

vector<Contact> contacts;

void PhoneBook::append(Contact c) {
    contacts.push_back(c);
}

size_t PhoneBook::size() {
    return contacts.size();
}

Contact* PhoneBook::find(string n){
    for(auto &c : contacts) {
        if(c.name==n) return &c;
    }
    return nullptr;
}

vector<Contact> PhoneBook::filterContacts(filter *f){
    vector<Contact> app;
    for(const auto &c : contacts) {
        if(f->check(c))
            app.push_back(c);
    }
    return app;
}

ostream& operator<<(ostream &out, const PhoneBook &p){
    for(const auto &c : p.contacts)
        out << c.name << " " << c.surname
            << ": " << c.number << endl;
    return out;
}
