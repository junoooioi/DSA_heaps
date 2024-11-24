#include <iostream> // For input and output operations
#include <vector>   // To use the vector container for dynamic arrays
#include <algorithm> // To use sorting and other algorithms

using namespace std; // To avoid prefixing with std::

/*
 * Class to represent a Dog with attributes name, breed, age, and height.
 * It includes a constructor for initialization and a method to print details.
 */
class Dog {
public:
    string name;   // Dog's name
    string breed;  // Dog's breed
    int age;       // Dog's age in years
    double height; // Dog's height in cm

    // Constructor to initialize Dog objects
    Dog(string name, string breed, int age, double height)
        : name(name), breed(breed), age(age), height(height) {}

    // Method to print details of a Dog object
    void print() const {
        cout << name << " (" << age << " years, " << breed << ", " << height << " cm)" << endl;
    }
};

/* Comparator classes for sorting based on age and height */
class CompareByAgeMin { // Min-Heap based on age
public:
    bool operator()(const Dog& a, const Dog& b) {
        return a.age > b.age; // Youngest dogs come first
    }
};

class CompareByAgeMax { // Max-Heap based on age
public:
    bool operator()(const Dog& a, const Dog& b) {
        return a.age < b.age; // Oldest dogs come first
    }
};

class CompareByHeightMin { // Min-Heap based on height
public:
    bool operator()(const Dog& a, const Dog& b) {
        return a.height > b.height; // Shortest dogs come first
    }
};

class CompareByHeightMax { // Max-Heap based on height
public:
    bool operator()(const Dog& a, const Dog& b) {
        return a.height < b.height; // Tallest dogs come first
    }
};

/* Function to display the main menu options */
void displayMenu() {
    cout << endl << " ============= T A S K S =============" << endl;
    cout << "1. Add a Dog to the Shelter" << endl;
    cout << "2. Organize Shelter by Age" << endl;
    cout << "3. Organize Shelter by Height" << endl;
    cout << "4. Remove a Dog from the List" << endl;
    cout << "5. Insert a Dog at a Specific Position" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option: ";
}

/* Function to display all dogs currently in the shelter */
void displayDogs(const vector<Dog>& shelter) {
    if (shelter.empty()) { // Check if the shelter is empty
        cout << endl << "The shelter is empty!" << endl;
        return;
    }

    cout << endl << "Dogs currently in the shelter:" << endl;
    for (const Dog& dog : shelter) { // Loop through and print each dog's details
        dog.print();
    }
}

/* Task 1: Add a Dog to the Shelter */
void addDog(vector<Dog>& shelter) {
    string name, breed;
    int age;
    double height;

    // Collect details of the new dog
    cout << endl << "Enter the dog's details:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Breed: ";
    cin >> breed;
    cout << "Age: ";
    cin >> age;
    cout << "Height (in cm): ";
    cin >> height;

    // Add the new dog to the shelter
    shelter.emplace_back(name, breed, age, height);
    cout << endl << "Dog added successfully!" << endl;
}

/* Task 2: Organize Shelter by Age */
void organizeByAge(vector<Dog>& shelter) {
    if (shelter.empty()) { // Check if the shelter is empty
        cout << endl << "The shelter is empty!" << endl;
        return;
    }

    char choice;
    // Ask user how to organize dogs by age
    cout << endl << "Would you like to organize by:" << endl;
    cout << "1. Oldest to Youngest (Max-Heap)" << endl;
    cout << "2. Youngest to Oldest (Min-Heap)" << endl;
    cout << "Choose an option (1/2): ";
    cin >> choice;

    if (choice == '1') {
        // Organize from oldest to youngest
        sort(shelter.begin(), shelter.end(), CompareByAgeMin());
        cout << endl << "Dogs organized by oldest to youngest." << endl;
    } else if (choice == '2') {
        // Organize from youngest to oldest
        sort(shelter.begin(), shelter.end(), CompareByAgeMax());
        cout << endl << "Dogs organized by youngest to oldest." << endl;
    } else {
        cout << endl << "Invalid option. Returning to menu." << endl;
        return;
    }
}

/* Task 3: Organize Shelter by Height */
void organizeByHeight(vector<Dog>& shelter) {
    if (shelter.empty()) { // Check if the shelter is empty
        cout << endl << "The shelter is empty!" << endl;
        return;
    }

    char choice;
    // Ask user how to organize dogs by height
    cout << endl << "Would you like to organize by:" << endl;
    cout << "1. Tallest to Shortest (Max-Heap)" << endl;
    cout << "2. Shortest to Tallest (Min-Heap)" << endl;
    cout << "Choose an option (1/2): ";
    cin >> choice;

    if (choice == '1') {
        // Organize from tallest to shortest
        sort(shelter.begin(), shelter.end(), CompareByHeightMin());
        cout << endl << "Dogs organized by tallest to shortest." << endl;
    } else if (choice == '2') {
        // Organize from shortest to tallest
        sort(shelter.begin(), shelter.end(), CompareByHeightMax());
        cout << endl << "Dogs organized by shortest to tallest." << endl;
    } else {
        cout << endl << "Invalid option. Returning to menu." << endl;
        return;
    }
}

/* Task 4: Remove a Dog from the Shelter */
void removeDog(vector<Dog>& shelter) {
    if (shelter.empty()) { // Check if the shelter is empty
        cout << endl << "The shelter is empty!" << endl;
        return;
    }

    string name;
    // Ask user for the name of the dog to remove
    cout << endl << "Enter the name of the dog to remove: ";
    cin >> name;

    // Find the dog in the list
    auto it = find_if(shelter.begin(), shelter.end(), [&](const Dog& dog) {
        return dog.name == name;
    });

    if (it != shelter.end()) {
        // Remove the dog from the list
        shelter.erase(it);
        cout << endl << "Dog removed successfully!" << endl;
    } else {
        cout << endl << "Dog not found in the shelter!" << endl;
    }
}

/* Task 5: Insert a Dog at a Specific Position */
void insertDog(vector<Dog>& shelter) {
    if (shelter.empty()) { // Check if the shelter is empty
        cout << endl << "The shelter is empty! Use 'Add a Dog' first." << endl;
        return;
    }

    int position;
    string name, breed;
    int age;
    double height;

    // Ask user for the position to insert the new dog
    cout << endl << "Enter the position to insert the dog (1 to " << shelter.size() + 1 << "): ";
    cin >> position;

    if (position < 1 || position > shelter.size() + 1) {
        cout << endl << "Invalid position! Please try again." << endl;
        return;
    }

    // Collect details of the new dog
    cout << endl << "Enter the dog's details:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Breed: ";
    cin >> breed;
    cout << "Age: ";
    cin >> age;
    cout << "Height (in cm): ";
    cin >> height;

    // Insert the new dog at the specified position
    shelter.insert(shelter.begin() + (position - 1), Dog(name, breed, age, height));
    cout << endl << "Dog inserted successfully at position " << position << "!" << endl;
}

/* Main Function */
int main() {
    vector<Dog> shelter; // List of dogs in the shelter
    int choice;

    cout << " Welcome to Pawpet Heap Shelter Manager " << endl;

    while (true) {
        displayMenu(); // Display menu options
        cin >> choice;

        switch (choice) {
        case 1:
            addDog(shelter); // Add a dog to the shelter
            break;
        case 2:
            organizeByAge(shelter); // Organize shelter by age
            break;
        case 3:
            organizeByHeight(shelter); // Organize shelter by height
            break;
        case 4:
            removeDog(shelter); // Remove a dog from the shelter
            break;
        case 5:
            insertDog(shelter); // Insert a dog at a specific position
            break;
        case 6:
            // Exit the program
            cout << endl << "Goodbye! Thank you for supporting our furry friends!" << endl;
            return 0;
        default:
            cout << endl << "Invalid choice. Please try again." << endl;
        }

        // Display the updated list of dogs after each operation
        displayDogs(shelter);
    }

    return 0;
}
