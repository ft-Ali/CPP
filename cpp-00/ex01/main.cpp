/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:06:09 by alsiavos          #+#    #+#             */
/*   Updated: 2024/11/08 10:09:43 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "color.hpp"

int main(int c, char** v) {
    PhoneBook phonebook;
    std::string command;
    (void)v;
    
    if(c == 1) { 
    while (true) {
        std::cout << GRY2 + "Enter command (ADD, SEARCH, EXIT): " + RESET;
		std::cin.clear();
        std::getline(std::cin, command);
		if(std::cin.eof())
			break ;
        if (command == "ADD") {
            phonebook.add_contact();
        } else if (command == "SEARCH") {
            phonebook.search_contacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command." << std::endl;
            }
        }
    }
    else {
        std::cout << RED1 + "Invalid arguments." + RESET << std::endl;
    }
    return 0;
}

/*
PhoneBook
◦ Représente le répertoire.
◦ Contient un tableau de contacts.
◦ Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème
contact, remplacez le plus ancien par celui-ci.
◦ Notez que l’allocation dynamique est interdite.
• Contact
◦ Représente un contact dans le répertoire

Au lancement du programme,
	le répertoire est vide et l’utilisateur peut entrer une
commande. Le programme accepte les entrées suivantes : ADD, SEARCH et EXIT.
• ADD
◦ Crée un nouveau contact et l’ajoute au répertoire.
◦ L’utilisateur doit entrer les informations suivantes :
▪ Prénom
▪ Nom
▪ Surnom
▪ Numéro de téléphone
▪ Adresse e-mail
▪ Date de naissance
▪ Secret le plus sombre
Si le répertoire est plein, le plus ancien contact est remplacé.
•
 SEARCH
◦ Affiche une liste de tous les contacts dans le répertoire.
◦ L’utilisateur peut sélectionner un contact pour afficher toutes ses informations.
◦ Si le répertoire est vide, affichez un message approprié.
Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
un point (’.’)
Ensuite,
	le programme demande à l’utilisateur d’entrer l’index du contact à afficher. Si l’index ou son format sont incorrects,
	gérez cela de manière pertinente.
Sinon, affichez les informations du contact, une par ligne
• EXIT
◦ Quitte le programme.
• Les informations du contact doivent être affichées dans un format structuré.
• Les informations du contact doivent être tronquées si elles dépassent une certaine longueur.
• Les informations du contact doivent être alignées.
• Les informations du contact doivent être affichées en couleur.


*/
