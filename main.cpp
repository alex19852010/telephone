#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Phone
{
  private:
  class Contact
  {
    public:
    string name;
    string phonenumber;
  };
  vector <Contact> addressbook;

  public:
  void addcontact(string* name, string* phonenumber)
  {
    Contact contact;
    contact.name = *name;
    contact.phonenumber = *phonenumber;
    addressbook.push_back(contact);
    cout << "contact add" << endl;
    
  }

  void call()
  {
    string contact;
    cout << "enter name contact or phone number: ";
    cin >> contact;

    bool found = false;
    for(int i = 0; i < addressbook.size(); i ++)
    {
      if (contact == addressbook[i].name || contact ==addressbook[i].phonenumber)
      {
        cout << "call " << addressbook[i].phonenumber << endl;
        found = true;
        return;
      }
    }

    if(!found)
    {
      cout << "contact not found" << endl;
    }

    
  }

  void sendsms()
  {
    string contact, message;
    cout << "enter name contact or phonenumber: ";
    cin >> contact;

    bool found = 0;

    for(int i = 0; i < addressbook.size(); i ++)
    {
      if (contact == addressbook[i].name || contact ==addressbook[i].phonenumber)
      {
        cout << "enter message:";
        cin.ignore();
        getline(cin, message);
        cout << "send sms: " << addressbook[i].phonenumber << " " << message << endl;
        found = true;
        return;
      }
    }
    if(!found)
    {
      cout << "contact not found" << endl;
    }

  }

};

int main()
{
 Phone phone;
 string command;

 while(command != "exit")

 {
  cout << "enter command add, call, sms, exit: ";
  cin >> command;

  if(command == "add")
  {
    string name, phonenumber;
    cout << "enter name contact: ";
    cin >> name;
    cout << "enter phone number: ";
    cin >> phonenumber;
    if(phonenumber.length() != 10 || phonenumber[0] != '+' || phonenumber[1] != '7')
    {
      cout << "wrong format" << endl;
      continue;
    }
    phone.addcontact(&name, &phonenumber);
    
  }

  else if(command == "call")
  {
    phone.call();
  }

  else if(command == "sms")
  {
    phone.sendsms();
  }
 }
 cout << "program completed" << endl;

    return 0;
}