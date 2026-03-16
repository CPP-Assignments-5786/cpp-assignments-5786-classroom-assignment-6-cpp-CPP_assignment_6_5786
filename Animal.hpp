/**
 * @file Animal.hpp
 * @brief Header file for the Animal abstract base class
 *
 * This file contains the declaration of the Animal class which serves as
 * the base class for all animal types in the zoo.
 */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include <stdexcept>

namespace zoo {

    class Animal {
    private:
        std::string name;
        int age;           // Age in years (must be >= 0)
        std::string species;

        // Static counter for total animals created
        static int animalCount;

    protected:
        /**
         * @brief Protected parameterized constructor
         * Only derived classes can create Animal objects (since Animal is abstract).
         * Prints: "{species} Animal constructed: {name}"
         * @param name The animal's name
         * @param age The animal's age (must be >= 0)
         * @param species The species name
         * @throws std::invalid_argument if age is negative
         */
        Animal(const std::string& name, int age, const std::string& species);

        /**
         * @brief Protected copy constructor
         * Prints: "{species} Animal copy-constructed: {name}"
         * @param other The animal to copy from
         */
        Animal(const Animal& other);

    public:
        /**
         * @brief Virtual destructor
         * MUST be virtual to ensure proper cleanup through base pointers.
         * Prints: "{species} Animal destructed: {name}"
         */
        virtual ~Animal();

        // ============ Pure Virtual Functions ============

        /**
         * @brief Get the sound this animal makes
         * @return A string representing the sound
         * This is a PURE VIRTUAL function — must be overridden by derived classes.
         */
        virtual std::string makeSound() const = 0;

        /**
         * @brief Get a description of this animal's type
         * @return A string describing the animal type
         * This is a PURE VIRTUAL function — must be overridden by derived classes.
         */
        virtual std::string getAnimalType() const = 0;

        /**
         * @brief Get the food this animal eats
         * @return A string representing the diet
         * This is a PURE VIRTUAL function — must be overridden by derived classes.
         */
        virtual std::string getDiet() const = 0;

        // ============ Getters (inline implementations) ============

        /**
         * @brief Get the animal's name
         * @return The name as a string
         */
        inline std::string getName() const {
            return name;
        }

        /**
         * @brief Get the animal's age
         * @return Age in years
         */
        inline int getAge() const {
            return age;
        }

        /**
         * @brief Get the species name
         * @return The species as a string
         */
        inline std::string getSpecies() const {
            return species;
        }

        // ============ Setters (outline implementations) ============

        /**
         * @brief Set the animal's name
         * @param name New name
         */
        void setName(const std::string& name);

        /**
         * @brief Set the animal's age
         * @param age New age (must be >= 0)
         * @throws std::invalid_argument if age is negative
         */
        void setAge(int age);

        // ============ Static methods ============

        /**
         * @brief Get total number of Animal objects currently in memory
         * @return The current animal count
         */
        static int getAnimalCount();

        // ============ Utility methods ============

        /**
         * @brief Get a full description of this animal
         * @return A formatted string: "[{type}] {name} ({species}), Age: {age}, Sound: {sound}, Diet: {diet}"
         */
        std::string getDescription() const;
    };

} // namespace zoo

#endif // ANIMAL_HPP