#include <vector>

#include "filter.cpp"

using namespace std;

class PhoneBook {
    private:
        vector<Contact> contacts;
    public:
        void append(Contact c);

        size_t size();

        Contact* find(string n);

        vector<Contact> filterContacts(filter *f);

        friend ostream& operator<<(ostream &out, const PhoneBook &p);
};
