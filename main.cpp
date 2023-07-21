#include <iostream>
#include <map>
#include <string>
using namespace std;

class Mobilephone 
{
  private:
  map <string, string> addressbook;

  public:
  void addcontact(string* name, string* phonenumber)
  {
    addressbook.insert(pair <string, string> (*name, *phonenumber));
    cout << "contact add" << endl;
    
  }

  void call()
  {
    string contact;
    cout << "enter name contact: ";
    cin >> contact;

    if(addressbook.count(contact) > 0)
    {
      cout << "call " << addressbook[contact] << endl;
    }

    else
    {
      cout << "contact not found" << endl;
    }
  }

  void sendsms()
  {
    string contact, message;
    cout << "enter name contact: ";
    cin >> contact;

    if(addressbook.count(contact) > 0)
    {
      cout << "enter message: ";
      cin.ignore();
      getline(cin, message);
      cout << "send sms to: " << addressbook[contact] << " : " << message << endl;
    } 

    else
    {
      cout << "contact not found" << endl;
    }

  }

};

int main()
{
 Mobilephone phone;
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