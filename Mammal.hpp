/**
 * @file Mammal.hpp
 * @brief Header file for the Mammal class
 *
 * This file contains the declaration of the Mammal class which inherits
 * from Animal and represents mammals in the zoo.
 */

#ifndef MAMMAL_HPP
#define MAMMAL_HPP

#include "Animal.hpp"

namespace zoo {

    class Mammal : public Animal {
    private:
        bool isDomesticated;   // Whether this mammal is domesticated
        int numberOfLegs;      // Number of legs (must be >= 0)

    public:
        // ============ Constructors ============

        /**
         * @brief Parameterized constructor
         * Prints: "Mammal constructed: {name}" (after Animal ctor)
         * @param name The mammal's name
         * @param age The mammal's age (must be >= 0)
         * @param species The species name
         * @param isDomesticated Whether the mammal is domesticated
         * @param numberOfLegs Number of legs (must be >= 0, default: 4)
         * @throws std::invalid_argument if age is negative or numberOfLegs is negative
         */
        Mammal(const std::string& name, int age, const std::string& species,
               bool isDomesticated, int numberOfLegs = 4);

        /**
         * @brief Copy constructor
         * Prints: "Mammal copy-constructed: {name}" (after Animal copy ctor)
         * @param other The mammal to copy from
         */
        Mammal(const Mammal& other);

        /**
         * @brief Destructor
         * Prints: "Mammal destructed: {name}" (before Animal dtor)
         */
        ~Mammal() override;

        // ============ Override Pure Virtual Functions ============

        /**
         * @brief Get the sound this mammal makes
         * @return "Roar!" if wild (not domesticated), "Purr..." if domesticated
         */
        std::string makeSound() const override;

        /**
         * @brief Get the animal type
         * @return "Mammal"
         */
        std::string getAnimalType() const override;

        /**
         * @brief Get the diet
         * @return "Meat" if wild, "Meat and plants" if domesticated
         */
        std::string getDiet() const override;

        // ============ Getters (inline) ============

        /**
         * @brief Check if the mammal is domesticated
         */
        inline bool getIsDomesticated() const {
            return isDomesticated;
        }

        /**
         * @brief Get the number of legs
         */
        inline int getNumberOfLegs() const {
            return numberOfLegs;
        }

        // ============ Setters (outline) ============

        /**
         * @brief Set the number of legs
         * @param legs New number of legs (must be >= 0)
         * @throws std::invalid_argument if legs is negative
         */
        void setNumberOfLegs(int legs);

        /**
         * @brief Set the domestication status
         * @param domesticated New status
         */
        void setDomesticated(bool domesticated);
    };

} // namespace zoo

#endif // MAMMAL_HPP