/**
 * @file Zoo.hpp
 * @brief Header file for the Zoo class
 *
 * This file contains the declaration of the Zoo class which manages
 * a collection of Animal pointers.
 */

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Reptile.hpp"
#include <string>
#include <iostream>

namespace zoo {

    class Zoo {
    private:
        std::string zooName;
        Animal** animals;    // Dynamic array of Animal pointers (polymorphic!)
        int capacity;
        int count;

        static int totalZoosCreated;

        /**
         * @brief Helper to resize the animals array when capacity is reached
         * Doubles the current capacity.
         */
        void resize();

    public:
        // ============ Constructors ============

        /**
         * @brief Default constructor
         * Creates a zoo named "Unnamed Zoo" with initial capacity of 4.
         */
        Zoo();

        /**
         * @brief Parameterized constructor
         * @param name The zoo's name
         * @param initialCapacity Initial capacity (default: 4)
         * @throws std::invalid_argument if initialCapacity <= 0
         */
        explicit Zoo(const std::string& name, int initialCapacity = 4);

        /**
         * @brief Destructor
         * Must delete all Animal objects through base pointers.
         */
        ~Zoo();

        // Copy constructor and copy assignment are disabled
        Zoo(const Zoo& other) = delete;
        Zoo& operator=(const Zoo& other) = delete;

        // ============ Getters (inline) ============

        /**
         * @brief Get the zoo name
         */
        inline std::string getZooName() const {
            return zooName;
        }

        /**
         * @brief Get number of animals in the zoo
         */
        inline int getCount() const {
            return count;
        }

        /**
         * @brief Get the current capacity
         */
        inline int getCapacity() const {
            return capacity;
        }

        /**
         * @brief Check if the zoo is empty
         */
        inline bool isEmpty() const {
            return count == 0;
        }

        // ============ Setters (outline) ============

        /**
         * @brief Set the zoo name
         * @param name New name
         */
        void setZooName(const std::string& name);

        // ============ Static methods ============

        /**
         * @brief Get total zoos ever created
         */
        static int getTotalZoosCreated();

        // ============ Animal management ============

        /**
         * @brief Add a Mammal to the zoo
         * @param mammal The mammal to add
         */
        void addAnimal(const Mammal& mammal);

        /**
         * @brief Add a Bird to the zoo
         * @param bird The bird to add
         */
        void addAnimal(const Bird& bird);

        /**
         * @brief Add a Reptile to the zoo
         * @param reptile The reptile to add
         */
        void addAnimal(const Reptile& reptile);

        /**
         * @brief Remove an animal by index
         * Shifts remaining animals left to fill the gap.
         * @param index The index of the animal to remove (0-based)
         * @throws std::out_of_range if index is out of bounds
         */
        void removeAnimal(int index);

        /**
         * @brief Get an animal by index (read-only access)
         * @param index The index (0-based)
         * @return Const reference to the Animal
         * @throws std::out_of_range if index is out of bounds
         */
        const Animal& getAnimal(int index) const;

        /**
         * @brief Find an animal by name
         * @param name The name to search for
         * @return Pointer to the Animal if found, nullptr otherwise
         */
        Animal* findAnimal(const std::string& name) const;

        /**
         * @brief Print all animals in the zoo
         * Prints: "=== {zooName} ===" followed by each animal's description
         * numbered from 1, e.g. "1. [Mammal] Leo (Lion), Age: 5, Sound: Roar!, Diet: Meat"
         */
        void printAllAnimals() const;

        /**
         * @brief Make all animals produce their sounds
         * Prints: "{name} says: {sound}" for each animal
         */
        void makeAllSounds() const;
    };

} // namespace zoo

#endif // ZOO_HPP