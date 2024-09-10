#include <iostream>
#include <memory>  // Include for std::shared_ptr

// Define the MyClass class
class MyClass {
public:
    MyClass() { std::cout << "MyClass constructor called." << std::endl; }
    ~MyClass() { std::cout << "MyClass destructor called." << std::endl; }

    void display() { std::cout << "Hello from MyClass!" << std::endl; }
};

// Define a new class that owns a shared pointer to MyClass
class OwnerClass {
private:
    std::shared_ptr<MyClass> myClassPtr;  // Shared pointer to MyClass

public:
    // Constructor that initializes the shared_ptr
    OwnerClass(const std::shared_ptr<MyClass>& ptr) : myClassPtr(ptr) {
        std::cout << "OwnerClass constructor called." << std::endl;
    }

    // Function to access MyClass functions through the shared pointer
    void useMyClass() {
        if (myClassPtr) {
            myClassPtr->display();  // Call MyClass's display function
        } else {
            std::cout << "No MyClass instance to use." << std::endl;
        }
    }

    // Destructor
    ~OwnerClass() { std::cout << "OwnerClass destructor called." << std::endl; }
};

int main() {
    // Create a shared_ptr to a new MyClass instance
    std::shared_ptr<MyClass> myClassInstance = std::make_shared<MyClass>();

    // Create an OwnerClass instance that owns the shared pointer
    OwnerClass owner(myClassInstance);

    // Use OwnerClass to interact with MyClass
    owner.useMyClass();

    // Create another shared_ptr pointing to the same MyClass instance
    {
        OwnerClass anotherOwner(myClassInstance);
        anotherOwner.useMyClass();  // Still able to use MyClass

        // anotherOwner goes out of scope here
    }

    // myClassInstance is still alive as long as owner has a reference
    std::cout << "Back in the main scope." << std::endl;

    // End of main, all shared_ptr instances go out of scope
    return 0;
}