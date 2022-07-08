#include <iostream>
#include <string>
#include <vector>

#include "phoneBook.cpp"

using namespace std;

class first2Numbers : public filter {
    private:
        int count=0;
    public:
        bool check(Contact c) {
            count+=1;
            return count <= 2;
        }
};

class last2Numbers : public filter {
    private:
        int count=0;
        int size;
    public:
        last2Numbers(size_t size) : filter(){
            this->size=size;
        }
        bool check(Contact c) {
            count+=1;
            return count > size-2;
        }
};

class italianNumber : public filter {
    public:
        bool check(Contact c) {
            if(c.number.size()<3) return false;
            return c.number.substr(0,3)=="+39";
        }
};

class nameStartsWith : public filter {
    private:
        string l;
    public:
        nameStartsWith(string l) : filter() {
            this->l=l;
        }
        bool check(Contact c) {
            if(c.name.size()<l.size()) return false;
            return c.name.substr(0,l.size())==l;
        }
};

int main() {
    PhoneBook a;
    a.append({"alessandro","borghi","+39232455"});
    a.append({"martina","santagati","+39278604"});
    a.append({"gianpiero","ramazzola","+06998445211"});
    vector<Contact> filtered = a.filterContacts(new last2Numbers(a.size()));
    cout << filtered.size() << endl;
}
