/**
 * @file Reptile.hpp
 * @brief Header file for the Reptile class
 *
 * This file contains the declaration of the Reptile class which inherits
 * from Animal and represents reptiles in the zoo.
 */

#ifndef REPTILE_HPP
#define REPTILE_HPP

#include "Animal.hpp"

namespace zoo {

    class Reptile : public Animal {
    private:
        bool isVenomous;       // Whether this reptile is venomous
        double bodyLengthCm;   // Body length in centimeters (must be > 0)

    public:
        // ============ Constructors ============

        /**
         * @brief Parameterized constructor
         * Prints: "Reptile constructed: {name}" (after Animal ctor)
         * @param name The reptile's name
         * @param age The reptile's age (must be >= 0)
         * @param species The species name
         * @param isVenomous Whether the reptile is venomous
         * @param bodyLengthCm Body length in cm (must be > 0)
         * @throws std::invalid_argument if age is negative or bodyLengthCm <= 0
         */
        Reptile(const std::string& name, int age, const std::string& species,
                bool isVenomous, double bodyLengthCm);

        /**
         * @brief Copy constructor
         * Prints: "Reptile copy-constructed: {name}" (after Animal copy ctor)
         * @param other The reptile to copy from
         */
        Reptile(const Reptile& other);

        /**
         * @brief Destructor
         * Prints: "Reptile destructed: {name}" (before Animal dtor)
         */
        ~Reptile() override;

        // ============ Override Pure Virtual Functions ============

        /**
         * @brief Get the sound this reptile makes
         * @return "Hisss!" if venomous, "..." if non-venomous
         */
        std::string makeSound() const override;

        /**
         * @brief Get the animal type
         * @return "Reptile"
         */
        std::string getAnimalType() const override;

        /**
         * @brief Get the diet
         * @return "Rodents and eggs" if venomous, "Insects and plants" if non-venomous
         */
        std::string getDiet() const override;

        // ============ Getters (inline) ============

        /**
         * @brief Check if the reptile is venomous
         */
        inline bool getIsVenomous() const {
            return isVenomous;
        }

        /**
         * @brief Get the body length in centimeters
         */
        inline double getBodyLengthCm() const {
            return bodyLengthCm;
        }

        // ============ Setters (outline) ============

        /**
         * @brief Set the body length
         * @param length New body length in cm (must be > 0)
         * @throws std::invalid_argument if length <= 0
         */
        void setBodyLengthCm(double length);

        /**
         * @brief Set the venomous status
         * @param venomous New venomous status
         */
        void setVenomous(bool venomous);
    };

} // namespace zoo

#endif // REPTILE_HPP