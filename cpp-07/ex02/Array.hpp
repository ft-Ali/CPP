#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // Pour std::out_of_range
#include <iostream>  // Juste pour les tests dans main.cpp

// ------------------------------
// Template de classe générique : Array<T>
// Implémente un tableau dynamique de type T
// Respecte les contraintes du sujet ex02 du module C++
// ------------------------------
template <typename T>
class Array {
public:
    // ------------------------------
    // Constructeur par défaut
    // Crée un tableau vide (taille 0, pointeur nul)
    // ------------------------------
    Array() : _data(0), _size(0) {}

    // ------------------------------
    // Constructeur avec taille
    // Crée un tableau de n éléments initialisés par défaut
    // Utilise new[] comme exigé
    // ------------------------------
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // ------------------------------
    // Constructeur par copie
    // Copie profonde du tableau
    // ------------------------------
    Array(const Array &other) : _data(0), _size(0) {
        *this = other; // réutilise l’opérateur d’affectation
    }

    // ------------------------------
    // Destructeur
    // Libère la mémoire allouée avec new[]
    // ------------------------------
    ~Array() {
        delete[] _data;
    }

    // ------------------------------
    // Opérateur d’affectation
    // Copie profonde : les deux tableaux seront indépendants
    // ------------------------------
    Array &operator=(const Array &other) {
        if (this != &other) { // sécurité auto-affectation
            delete[] _data;
            _size = other._size;
            _data = new T[_size]; // allocation dynamique
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
        return *this;
    }

    // ------------------------------
    // Accès en écriture et lecture
    // avec vérification de dépassement
    // Lève std::out_of_range si index invalide
    // ------------------------------
    T &operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    // ------------------------------
    // Version const pour l'accès en lecture
    // Permet d’utiliser Array<T> const
    // ------------------------------
    const T &operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    // ------------------------------
    // Fonction membre size()
    // Retourne le nombre d’éléments du tableau
    // Ne modifie pas l'objet (const)
    // ------------------------------
    unsigned int size() const {
        return _size;
    }

private:
    T* _data;             // pointeur vers le tableau
    unsigned int _size;   // nombre d'éléments
};

#endif
