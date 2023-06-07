/**
 * @file MagicalContainer.hpp
 * @class MagicalContainer
 * @brief A container that stores a collection of integers with magical properties.
 * The MagicalContainer class provides functionality to add and remove elements
 * retrieve the size of the container, access elements by index, and retrieve a
 * copy of all the elements. The container is implemented using a std::vector<int>
 * @note This file only shows declarations of the function signatures
 * @author Tomer Gozlan
 * @date 06/06/2023
 */

#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
#define MAGICAL_ITERATORS_MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace ariel {

    class MagicalContainer {
    private:

        std::vector<int> elements;

    public:

        MagicalContainer() = default;

        ~MagicalContainer() = default;

        MagicalContainer(const MagicalContainer &other) = default;

        MagicalContainer &operator=(const MagicalContainer &other) = default;

        MagicalContainer(MagicalContainer &&other)

        noexcept =
        default;

        MagicalContainer &operator=(MagicalContainer &&other)

        noexcept =
        default;

        void addElement(int element);

        void removeElement(int element);

        int size() const;

        std::vector<int> getElements() const;

        int getElement(int index) const;

        void setElements(const std::vector<int> &newElements);

/**
 * @class AscendingIterator
 * @brief An iterator that allows iterating over the elements of a MagicalContainer in ascending order.
 * The AscendingIterator class provides functionality to iterate over the elements of a MagicalContainer
 * in ascending order. It keeps track of the current index within the container and provides comparison
 * operators to compare iterators and perform iteration operations.
 * @author Tomer Gozlan
 * @date 06/06/2023
 */
        class AscendingIterator {
        private:

            MagicalContainer &container;
            int currentIndex;

        public:

            AscendingIterator(MagicalContainer &container);

            AscendingIterator(const AscendingIterator &other)

            noexcept;

            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator(AscendingIterator &&other)

            noexcept : container(other.container), currentIndex(other
            .currentIndex) {}

            AscendingIterator &operator=(AscendingIterator &&other)

            noexcept {
                return *this;
            }

            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            AscendingIterator &operator++();

            int operator*() const;

            AscendingIterator begin() const;

            AscendingIterator end() const;

            int getCurrentIndex() const;

            void setCurrentIndex(int index);

            const MagicalContainer &getContainer() const;
        };

/**
 * @class SideCrossIterator
 * @brief An iterator that allows iterating over the elements of a MagicalContainer in a side-cross pattern.
 * The SideCrossIterator class provides functionality to iterate over the elements of a MagicalContainer
 * in a side-cross pattern. It keeps track of the current index within the container, the direction of movement,
 * and provides comparison operators to compare iterators and perform iteration operations.
 * @author Tomer Gozlan
 * @date 06/06/2023
 */

        class SideCrossIterator {

        private:

            const MagicalContainer &container;
            int currentIndex;
            int startIndex;
            int endIndex ;
            int middleIndex ;

        public:

            SideCrossIterator(const MagicalContainer &container);

            SideCrossIterator(const SideCrossIterator &other);

            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);

            SideCrossIterator &operator=(SideCrossIterator &&other)

            noexcept {
                return *this;
            }

            SideCrossIterator(SideCrossIterator &&other)

            noexcept : container(other.container), currentIndex(other
            .currentIndex){}

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            SideCrossIterator &operator++();

            int operator*() const;

            SideCrossIterator begin() const;

            SideCrossIterator end() const;

            int getCurrentIndex() const;

            void setCurrentIndex(int index);

            const MagicalContainer &getContainer() const;
        };


/**
 * @class PrimeIterator
 * @brief An iterator that allows iterating over the prime elements of a MagicalContainer.
 * The PrimeIterator class provides functionality to iterate over the prime elements of a MagicalContainer.
 * It keeps track of the current index within the container and provides comparison operators to compare iterators
 * and perform iteration operations.
 * @author Tomer Gozlan
 * @date 06/06/2023
 */

        class PrimeIterator {
        private:
            const MagicalContainer &container;
            int currentIndex;

            bool isPrime(int num) const;

        public:
            PrimeIterator(const MagicalContainer &container);

            PrimeIterator(const PrimeIterator &other);

            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator &operator=(PrimeIterator &&other)

            noexcept {
                return *this;
            }

            PrimeIterator(PrimeIterator &&other)

            noexcept: container(other.container), currentIndex(other
            .currentIndex) {}

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            bool operator>=(const PrimeIterator &other) const;

            bool operator<=(const PrimeIterator &other) const;

            PrimeIterator &operator++();

            int operator*() const;

            PrimeIterator begin() const;

            PrimeIterator end() const;

            int getCurrentIndex() const;

            void setCurrentIndex(int index);

            const MagicalContainer &getContainer() const;

        };

    };

}

#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_HPP