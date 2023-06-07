//
// Created by Tomer Gozlan on 04/06/2023.
//

#include "MagicalContainer.hpp"


namespace ariel {

/**
 * @brief Adds an element to the MagicalContainer if it is not already present.
 * @note The method will ensure that duplicate elements are not added to the vector, and the vector remains sorted after adding the new element.
 * @param element The element to be added.
 */
    void MagicalContainer::addElement(int element) {
        bool flag = false;
        for (int i = 0; i < this->size(); ++i) {
            if (this->elements[i] == element) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            this->elements.emplace_back(element);
            std::sort(this->elements.begin(), this->elements.end());
        }
    }

/**
 * @brief Removes an element from the MagicalContainer.
 * This function removes the specified element from the MagicalContainer if it exists.
 * @param element The element to be removed.
 * @throws std::runtime_error if the element is not found in the MagicalContainer.
 */
    void MagicalContainer::removeElement(int element) {
        auto it = elements.begin();
        while (it != elements.end()) {
            if (*it == element) {
                elements.erase(it);
                return;
            }
            ++it;
        }
        throw std::runtime_error("Error: Element not found in MagicalContainer");
    }

/**
 * @brief Get the number of elements in the MagicalContainer.
 * This function returns the size of the MagicalContainer, which is the number of elements currently stored in it.
 * @return The number of elements in the MagicalContainer.
 */
    int MagicalContainer::size() const {
        return (int) this->elements.size();
    }

/**
 * @brief Get a const reference to the elements in the MagicalContainer.
 * @return A const reference to the std::vector<int> containing the elements in the MagicalContainer.
 */
    std::vector<int> MagicalContainer::getElements() const {
        return this->elements;
    }

/**
 * @brief Get the element at the specified index.
 * @param index The index of the element to retrieve.
 * @return The element at the specified index.
 * @throws std::out_of_range if the index is out of range.
 */
    int MagicalContainer::getElement(int index) const {
        if (index < 0 || index >= elements.size()) {
            throw std::out_of_range("Error: Invalid index.");
        }
        return elements[static_cast<std::vector<int>::size_type>(index)];
    }

/**
 * @brief Set the elements of the MagicalContainer.
 * This function replaces the existing elements in the MagicalContainer with the elements provided in the newElements vector.
 * @param newElements The vector containing the new elements to be set.
 * @note The contents of the MagicalContainer will be completely replaced by the elements in newElements.
 */
    void MagicalContainer::setElements(const std::vector<int> &newElements) {
        this->elements = newElements;
    }


/// Implementation of the AscendingIterator class.


/**
 * @brief Constructs an AscendingIterator object for the given MagicalContainer.
 * @param container The MagicalContainer to iterate over.
 */
    MagicalContainer::AscendingIterator::AscendingIterator(ariel::MagicalContainer &container) : container(container),
                                                                                                 currentIndex(0) {}

/**
 * @brief Copy constructor of AscendingIterator object.
 * @param other The AscendingIterator object to copy from.
 */
    MagicalContainer::AscendingIterator::AscendingIterator(const ariel::MagicalContainer::AscendingIterator &other)

    noexcept :
    container(other
    .container),
    currentIndex(other
    .currentIndex) {
}

/**
 * @brief Destructor for the AscendingIterator object.
 */
MagicalContainer::AscendingIterator::~AscendingIterator() {}

/**
* Assignment operator (=) for the AscendingIterator class.
* @param other The AscendingIterator object to be assigned.
* @return A reference to the current AscendingIterator object after assignment.
*/
AscendingIterator &
MagicalContainer::AscendingIterator::operator=(const ariel::MagicalContainer::AscendingIterator &other) {
    if (this == &other) {
        return *this;
    }
    this->currentIndex = other.currentIndex
    return *this;
}

/**
 * @brief Overloads the equality comparison operator (==) for the AscendingIterator class.
 * @param other The AscendingIterator object to compare with.
 * @return true if the currentIndex values are equal, false otherwise.
 */
bool MagicalContainer::AscendingIterator::operator==(const ariel::MagicalContainer::AscendingIterator &other) const {
    return this->currentIndex == other.currentIndex;
}

/**
 * @brief Overloads the inequality comparison operator (!=) for the AscendingIterator class.
 * @param other The AscendingIterator object to compare with.
 * @return true if the currentIndex values are not equal, false otherwise.
 */
bool
MagicalContainer::AscendingIterator::operator!=(const ariel::MagicalContainer::AscendingIterator &other) const {
    return !(*this == other);
}

/**
 * @brief Overloads the greater than (GT) comparison operator (>) for the AscendingIterator class.
 * @param other The AscendingIterator object to compare with.
 * @return true if the currentIndex value of the current object is greater than the currentIndex value of the other object, false otherwise.
 */
bool MagicalContainer::AscendingIterator::operator>(const ariel::MagicalContainer::AscendingIterator &other) const {
    return (this->currentIndex > other.currentIndex);
}

/**
 * @brief Overloads the less than (LS) comparison operator (<) for the AscendingIterator class.
 * @param other The AscendingIterator object to compare with.
 * @return true if the currentIndex value of the current object is less than the currentIndex value of the other object, false otherwise.
 */
bool MagicalContainer::AscendingIterator::operator<(const ariel::MagicalContainer::AscendingIterator &other) const {
    return (this->currentIndex > other.currentIndex);
}

/**
 * @brief Overloads the dereference operator (*) for the AscendingIterator class.
 * @return The value of the element at the current index.
 */
int MagicalContainer::AscendingIterator::operator*() const {
    return container.getElement(currentIndex);
}

/**
 * @brief Overloads the pre-increment operator (++) for the AscendingIterator class.
 * @return Reference to the updated AscendingIterator object.
 */
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    ++currentIndex;
    return *this;
}

/**
 * @brief Returns an iterator pointing to the beginning of the MagicalContainer.
 * @return An AscendingIterator object pointing to the beginning of the container.
 */
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    AscendingIterator beginIter(this->container);
    return beginIter;
}

/**
 * @brief Returns an iterator pointing to the end of the iteration over the MagicalContainer.
 * @return An AscendingIterator object pointing to the end of the container.
 */
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    AscendingIterator it(container);
    it.currentIndex = container.elements.size();
    return it;
}

/**
 * @brief Returns the current index of the iterator.
 * @return The current index of the iterator.
 */
int MagicalContainer::AscendingIterator::getCurrentIndex() const {
    return currentIndex;
}

/**
 * @brief Sets the current index of the iterator.
 * @param index The index to set as the current index.
 */
void MagicalContainer::AscendingIterator::setCurrentIndex(int index) {
    currentIndex = index;
}

/**
 * @brief Returns a reference to the MagicalContainer associated with the iterator.
 * @return A reference to the MagicalContainer associated with the iterator.
 */
const MagicalContainer &MagicalContainer::AscendingIterator::getContainer() const {
    return container;
}


/// Implementation of the SideCrossIterator class.


/**
 * @brief Constructor of a SideCrossIterator object.
 * This constructor initializes a SideCrossIterator object with the specified MagicalContainer
 * object as the underlying container to iterate over. It sets the current index to 0, indicating
 * the start of the iteration.
 * @param container The MagicalContainer object to iterate over.
 */
MagicalContainer::SideCrossIterator::SideCrossIterator(const ariel::MagicalContainer &container) : container(
        container), currentIndex(0) {}

/**
 * @brief Copy constructor  of a SideCrossIterator object.
 * This constructor creates a new SideCrossIterator object by copying the contents of the specified
 * SideCrossIterator object other.
 * @param other The SideCrossIterator object to be copied.
 */
SideCrossIterator::SideCrossIterator(const ariel::MagicalContainer::SideCrossIterator &other)
        : container(other.container), currentIndex(other.currentIndex) {}

/**
 * @brief Destructor for the SideCrossIterator class.
*/
MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

/**
 * @brief Assignment operator (=) for the SideCrossIterator class.
 * This assignment operator allows for assigning the contents of one SideCrossIterator object to another.
 * It performs a deep copy of the underlying container and current index from the specified other SideCrossIterator object.
 * @param other The SideCrossIterator object to be assigned.
 * @return A reference to the updated SideCrossIterator object.
 */
SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const ariel::MagicalContainer::SideCrossIterator &other) {
    if (this == &other) {
        return *this;
    }
    this->currentIndex = other.currentIndex;
    return *this;
}

/**
 * @brief Overloads the equality comparison operator (==) for the SideCrossIterator class.
 * @param other The SideCrossIterator object to compare with.
 * @return true if the currentIndex values are equal, false otherwise.
 */
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
    return this->currentIndex == other.currentIndex;
}

/**
 * @brief Overloads the inequality comparison operator (!=) for the SideCrossIterator class.
 * @param other The SideCrossIterator object to compare with.
 * @return true if the currentIndex values are not equal, false otherwise.
 */
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
    return !(*this == other);
}

/**
 * @brief Overloads the greater than (GT) comparison operator (>) for the SideCrossIterator class.
 * @param other The SideCrossIterator object to compare with.
 * @return true if the currentIndex value of the current object is greater than the currentIndex value of the other object, false otherwise.
 */
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
    return (this->currentIndex > other.currentIndex);
}

/**
 * @brief Overloads the greater than (LT) comparison operator (<) for the SideCrossIterator class.
 * @param other The SideCrossIterator object to compare with.
 * @return true if the currentIndex value of the current object is greater than the currentIndex value of the other object, false otherwise.
 */
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
    return (this->currentIndex < other.currentIndex);

}

/**
 * @brief Overloads the pre-increment operator (++) for the SideCrossIterator class.
 * @return Reference to the updated SideCrossIterator object.
 */
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if (this->currentIndex == middleIndex) {
        setCurrentIndex(this->cont.size());
    }
    if (this->currentIndex < middleIndex) {
        setCurrentIndex(endIndex);
        endIndex--;
    }
    if (this->currentIndex > middleIndex) {
        startIndex++;
        setCurrentIndex(startIndex);
    }
    return *this;
}

/**
 * @brief Overloads the dereference operator (*) for the SideCrossIterator class.
 * @return The value of the element at the current index.
 */
int MagicalContainer::SideCrossIterator::operator*() const {
    return container.getElement(currentIndex);
}

/**
 * @brief Returns an iterator pointing to the beginning of the MagicalContainer.
 * @return An SideCrossIterator object pointing to the beginning of the container.
 */
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    MagicalContainer::SideCrossIterator beginIter(this->container);
    return beginIter;
}

/**
 * @brief Returns an iterator pointing to the end of the iteration over the MagicalContainer.
 * @return An SideCrossIterator object pointing to the end of the container.
 */
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    MagicalContainer::SideCrossIterator it(this->container);
    it.currentIndex = container.elements.size();
    return it;
}

/**
 * @brief Getter of the field current index of the SideCrossIterator class.
 * @return The current index of the SideCrossIterator.
*/
int MagicalContainer::SideCrossIterator::getCurrentIndex() const {
    return this->currentIndex;
}

/**
 * @brief Setter the current index of the SideCrossIterator class.
 * @param index The index to set as the current index of the SideCrossIterator.
 */
void MagicalContainer::SideCrossIterator::setCurrentIndex(int index) {
    this->currentIndex = index;
}

/**
 * @brief Get the underlying MagicalContainer object of the SideCrossIterator class.
 * @return A reference to the MagicalContainer object.
 */
const MagicalContainer &MagicalContainer::SideCrossIterator::getContainer() const {
    return container;
}


/// Implementation of the PrimeIterator class.



/**
 * @brief Constructor of a PrimeIterator object for the PrimeIterator class.
 * @param container The MagicalContainer to iterate over.
 */
MagicalContainer::PrimeIterator::PrimeIterator(const ariel::MagicalContainer &container) : container(container),
                                                                                           currentIndex(0) {}

/**
 * @brief Copy constructor of PrimeIterator object.
 * @param other The PrimeIterator object to copy from.
 */
MagicalContainer::PrimeIterator::PrimeIterator(const ariel::MagicalContainer::PrimeIterator &other) : container(
        other.container), currentIndex(other.currentIndex) {}

/**
 * @brief Destructor for the PrimeIterator object.
 */
MagicalContainer::PrimeIterator::~PrimeIterator() {}

/**
 * @brief Check if a number is prime.
 * @param num The number to check for primality.
 * @return `true` if the number is prime, `false` otherwise.
 */
bool MagicalContainer::PrimeIterator::isPrime(int num) const {
    if (num < 2)
        return false;

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

/**
 * @brief Assignment operator (=) for the PrimeIterator class.
 * @param other The PrimeIterator object to be assigned.
 * @return A reference to the current PrimeIterator object after assignment.
 */
PrimeIterator &MagicalContainer::PrimeIterator::operator=(const ariel::MagicalContainer::PrimeIterator &other) {
    if (this == &other) {
        return *this;
    }
    this->currentIndex = other.currentIndex
    return *this;
}

/**
 * @brief Overloads the equality comparison operator (==) for the PrimeIterator class.
 * @param other The PrimeIterator object to compare with.
 * @return true if the currentIndex values are equal, false otherwise.
 */
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
    return this->currentIndex == other.currentIndex;
}

/**
 * @brief Overloads the inequality comparison operator (!=) for the PrimeIterator class.
 * @param other The PrimeIterator object to compare with.
 * @return true if the currentIndex values are not equal, false otherwise.
 */
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
    return !(*this == other);
}

/**
 * @brief Overloads the greater than (GT) comparison operator (>) for the PrimeIterator class.
 * @param other The PrimeIterator object to compare with.
 * @return true if the currentIndex value of the current object is greater than the currentIndex value of the other object, false otherwise.
 */
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
    return (this->currentIndex > other.currentIndex);
}

/**
 * @brief Overloads the less than (LT) comparison operator (<) for the PrimeIterator class.
 * @param other The PrimeIterator object to compare with.
 * @return true if the currentIndex value of the current object is less than the currentIndex value of the other object, false otherwise.
 */
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
    return (this->currentIndex < other.currentIndex);
}

/**
 * @brief Overloads the pre-increment operator (++) for the PrimeIterator class.
 * @return Reference to the updated PrimeIterator object.
 */
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    currentIndex++;
    while (currentIndex < container.size() && !isPrime(container.getElement(currentIndex))) {
        currentIndex++;
    }
    return *this;
}

/**
 * @brief Overloads the dereference operator (*) for the PrimeIterator class.
 * @return The value of the element at the current index.
 */
int MagicalContainer::PrimeIterator::operator*() const {
    return container.getElement(currentIndex);
}

/**
 * @brief Returns an iterator pointing to the beginning of the MagicalContainer.
 * @return A PrimeIterator object pointing to the beginning of the container.
 */
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
    PrimeIterator beginIter(container);
    beginIter.setCurrentIndex(0);
    return beginIter;
}

/**
 * @brief Returns an iterator pointing to the end of the iteration over the MagicalContainer.
 * @return A PrimeIterator object pointing to the end of the container.
 */
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    PrimeIterator it(container);
    it.currentIndex = container.elements.size();
    return it;
}

/**
 * @brief Get the current index of the iterator.
 * @return The current index of the iterator.
 */
int MagicalContainer::PrimeIterator::getCurrentIndex() const {
    return this->currentIndex;
}

/**
 * @brief Set the current index of the iterator.
 * @param index The index to set as the current index of the iterator.
 */
void MagicalContainer::PrimeIterator::setCurrentIndex(int index) {
    currentIndex = index;
}

/**
 * @brief Get the container being iterated over.
 * @return A const reference to the MagicalContainer object.
 */
const MagicalContainer &MagicalContainer::PrimeIterator::getContainer() const {
    return container;
}

}