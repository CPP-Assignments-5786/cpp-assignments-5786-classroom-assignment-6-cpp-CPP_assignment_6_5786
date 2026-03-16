/**
 * @file Bird.hpp
 * @brief Header file for the Bird class
 *
 * This file contains the declaration of the Bird class which inherits
 * from Animal and represents birds in the zoo.
 */

#ifndef BIRD_HPP
#define BIRD_HPP

#include "Animal.hpp"

namespace zoo {

    class Bird : public Animal {
    private:
        bool canFly;           // Whether this bird can fly
        double wingspanMeters; // Wingspan in meters (must be > 0)

    public:
        // ============ Constructors ============

        /**
         * @brief Parameterized constructor
         * Prints: "Bird constructed: {name}" (after Animal ctor)
         * @param name The bird's name
         * @param age The bird's age (must be >= 0)
         * @param species The species name
         * @param canFly Whether the bird can fly
         * @param wingspanMeters Wingspan in meters (must be > 0)
         * @throws std::invalid_argument if age is negative or wingspanMeters <= 0
         */
        Bird(const std::string& name, int age, const std::string& species,
             bool canFly, double wingspanMeters);

        /**
         * @brief Copy constructor
         * Prints: "Bird copy-constructed: {name}" (after Animal copy ctor)
         * @param other The bird to copy from
         */
        Bird(const Bird& other);

        /**
         * @brief Destructor
         * Prints: "Bird destructed: {name}" (before Animal dtor)
         */
        ~Bird() override;

        // ============ Override Pure Virtual Functions ============

        /**
         * @brief Get the sound this bird makes
         * @return "Tweet tweet!" if can fly, "Squawk!" if cannot fly
         */
        std::string makeSound() const override;

        /**
         * @brief Get the animal type
         * @return "Bird"
         */
        std::string getAnimalType() const override;

        /**
         * @brief Get the diet
         * @return "Seeds and insects"
         */
        std::string getDiet() const override;

        // ============ Getters (inline) ============

        /**
         * @brief Check if the bird can fly
         */
        inline bool getCanFly() const {
            return canFly;
        }

        /**
         * @brief Get the wingspan in meters
         */
        inline double getWingspanMeters() const {
            return wingspanMeters;
        }

        // ============ Setters (outline) ============

        /**
         * @brief Set the wingspan
         * @param wingspan New wingspan in meters (must be > 0)
         * @throws std::invalid_argument if wingspan <= 0
         */
        void setWingspanMeters(double wingspan);

        /**
         * @brief Set the flying capability
         * @param canFly New flying status
         */
        void setCanFly(bool canFly);
    };

} // namespace zoo

#endif // BIRD_HPP