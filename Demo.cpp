#include <iostream>
#include <random>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
int main() {

    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    // Print container size
    std::cout << "Size of container: " << container.size() << std::endl;

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;

    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;

    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17
    }
    std::cout << std::endl;

    // Remove an element from the container and display the size
    container.removeElement(9);
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;

    return 0;

}
/*

    MagicalContainer container;

    // Set up a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1000);

    // Add random numbers from 1 to 1000 to the container of at least 100 numbers
    for (int i = 0; i <= 100; ++i) {
        int randomNumber = dis(gen);
        container.addElement(randomNumber);
    }

    int containerSize=container.size();
    std::cout<<container.size()<<std::endl;

    //Remove the two first number to check the remove function
    std::vector<int> containerElements = container.getElements();
    if (containerElements.size() >= 2) {
        int num1 = containerElements[0];
        int num2 = containerElements[1];
        container.removeElement(num1);
        container.removeElement(num2);
        std::cout << "Removed numbers: " << num1 << ", " << num2 << std::endl;
    }

    // Check if the size matches the expected value of 100
    int expectedSize = containerSize-2;
    if (container.size() == expectedSize) {
        std::cout << "The size of the container matches the expected value of " << expectedSize << std::endl;
    } else {
        std::cout << "The size of the container does not match the expected value of " << expectedSize << std::endl;
    }

    // Use AscendingIterator to display elements in ascending order
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Using the additional methods of AscendingIterator
    MagicalContainer::AscendingIterator iter1(container);
    MagicalContainer::AscendingIterator iter2(container);

    // Check if iter1 and iter2 are equal
    if (iter1 == iter2) {
        std::cout << "iter1 is equal to iter2" << std::endl;
    } else {
        std::cout << "iter1 is not equal to iter2" << std::endl;
    }

    // Increment iter1
    ++iter1;

    // Check if iter1 is not equal to iter2
    if (iter1 != iter2) {
        std::cout << "iter1 is not equal to iter2" << std::endl;
    } else {
        std::cout << "iter1 is equal to iter2" << std::endl;
    }

    // Compare iter1 and iter2 using > and <
    if (iter1 > iter2) {
        std::cout << "iter1 is greater than iter2" << std::endl;
    } else if (iter1 < iter2) {
        std::cout << "iter1 is less than iter2" << std::endl;
    } else {
        std::cout << "iter1 and iter2 are equal" << std::endl;
    }

    // Dereference iter1 and iter2
    std::cout << "Value of iter1: " << *iter1 << std::endl;
    std::cout << "Value of iter2: " << *iter2 << std::endl;

    // Get the begin and end iterators
    MagicalContainer::AscendingIterator beginIter = ascIter.begin();
    int firstElement = *beginIter;
    std::cout << "First element: " << firstElement << std::endl;

    MagicalContainer::AscendingIterator endIter = ascIter.end();
    int lastElement = *endIter;
    std::cout << "Last element: " << lastElement << std::endl;

    //*********************************************************************

    // Use SideCrossIterator to display elements in a side-cross pattern
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container);
    int mid = crossIter.getContainer().getElement(container.size()/2);
    std::cout<<"The middle element: "<<mid<<std::endl;

    int count = 0;

    for (auto it = crossIter.begin(); it != crossIter.end() && count < crossIter.getContainer().size(); ++it) {
        std::cout << *it << ' ';
        std::cout << "The current idx: " << it.getCurrentIndex() << std::endl;
        count++;
    }

    std::cout << std::endl;


    // Using the additional methods of SideCrossIterator
    MagicalContainer::SideCrossIterator iter11(container);
    MagicalContainer::SideCrossIterator iter22(container);

    // Check if iter1 and iter2 are equal
    if (iter11 == iter22) {
        std::cout << "iter1 is equal to iter2" << std::endl;
    } else {
        std::cout << "iter1 is not equal to iter2" << std::endl;
    }

    // Increment iter1
    ++iter11;

    // Check if iter1 is not equal to iter2
    if (iter11 != iter22) {
        std::cout << "iter1 is not equal to iter2" << std::endl;
    } else {
        std::cout << "iter1 is equal to iter2" << std::endl;
    }

    // Compare iter1 and iter2 using > and <
    if (iter11 > iter22) {
        std::cout << "iter1 is greater than iter2" << std::endl;
    } else if (iter11 < iter22) {
        std::cout << "iter1 is less than iter2" << std::endl;
    } else {
        std::cout << "iter1 and iter2 are equal" << std::endl;
    }

    // Dereference iter1 and iter2
    std::cout << "Value of iter1: " << *iter11 << std::endl;
    std::cout << "Value of iter2: " << *iter22 << std::endl;

    // Get the beginning and end iterators
    MagicalContainer::SideCrossIterator beginIter1 =crossIter.begin();
    int firstElement1 = *beginIter1;
    std::cout << "First element: " << firstElement1 << std::endl;

    MagicalContainer::SideCrossIterator endIter1 = crossIter.end();
    int lastElement1 = *endIter1;
    std::cout << "Last element: " << lastElement1 << std::endl;

    //*********************************************************************

    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Using the additional methods of SideCrossIterator
    MagicalContainer::PrimeIterator iter111(container);
    MagicalContainer::PrimeIterator iter222(container);

    // Check if iter1 and iter2 are equal
    if (iter111 == iter222) {
        std::cout << "iter1 is equal to iter2" << std::endl;
    } else {
        std::cout << "iter1 is not equal to iter2" << std::endl;
    }

    // Increment iter1
    ++iter111;

    // Check if iter1 is not equal to iter2
    if (iter111 != iter222) {
        std::cout << "iter1 is not equal to iter2" << std::endl;
    } else {
        std::cout << "iter1 is equal to iter2" << std::endl;
    }

    // Compare iter1 and iter2 using > and <
    if (iter111 > iter222) {
        std::cout << "iter1 is greater than iter2" << std::endl;
    } else if (iter111 < iter222) {
        std::cout << "iter1 is less than iter2" << std::endl;
    } else {
        std::cout << "iter1 and iter2 are equal" << std::endl;
    }

    // Dereference iter1 and iter2
    std::cout << "Value of iter1: " << *iter111 << std::endl;
    std::cout << "Value of iter2: " << *iter111 << std::endl;

    // Get the beginning and end iterators
    MagicalContainer::PrimeIterator beginIter111 =primeIter.begin();
    int firstElement111 = *beginIter111;
    std::cout << "First element: " << firstElement111 << std::endl;

    MagicalContainer::PrimeIterator endIter111 = primeIter.end();
    int lastElement111 = *endIter111;
    std::cout << "Last element: " << lastElement111 << std::endl;

    return 0;

}
*/