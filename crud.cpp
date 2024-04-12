#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string email;
    std::string phone;
};

std::vector<Contact> contacts;

void createContact() {
    Contact newContact;
    std::cout << "Enter name: ";
    std::cin >> newContact.name;
    std::cout << "Enter email: ";
    std::cin >> newContact.email;
    std::cout << "Enter phone: ";
    std::cin >> newContact.phone;
    contacts.push_back(newContact);
}

void displayContacts() {
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name << ", Email: " << contact.email << ", Phone: " << contact.phone << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "1. Create Contact\n2. Display Contacts\n3. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                createContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
