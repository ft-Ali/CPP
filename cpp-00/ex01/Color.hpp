#ifndef COLOR_HPP
# define COLOR_HPP


#pragma once 
#include <string>

// const char* RESET = "\033[0m";
// const char* RED = "\033[31m";
// const char* GREEN = "\033[32m";
// const char* YELLOW = "\033[33m";
// const char* MAGENTA = "\033[35m";
// const char* WHITE = "\033[37m";
// const char* UNDERLINE = "\033[4m";
const std::string RED = "\033[0;38;2;255;0;0m"  ;     // Rouge
const std::string RED1 = "\033[0;38;2;210;10;10m" ;    // Rouge
const std::string ORNG = "\033[0;38;2;205;105;0m"  ;   // Orange
const std::string GOLD = "\033[0;38;2;255;215;0m"  ;   // Or
const std::string YLLW = "\033[0;38;2;255;255;0m"    ; // Jaune
const std::string GRNN = "\033[0;38;2;0;128;0m"      ; // Vert foncé
const std::string LIME = "\033[0;38;2;0;255;0m"      ; // Vert lime
const std::string CYAN = "\033[0;38;2;0;255;255m"    ; // Cyan
const std::string BLUE = "\033[0;38;2;80;80;220m"    ; // Bleu
const std::string INDI = "\033[0;38;2;75;0;130m"     ; // Indigo
const std::string PURP = "\033[0;38;2;238;130;238m"  ; // Violet
const std::string MAGN = "\033[0;38;2;255;0;255m"    ; // Magenta
const std::string PINK = "\033[0;38;2;255;192;203m"  ; // Rose
const std::string BROW = "\033[0;38;2;165;42;42m"    ; // Brun
const std::string IVRY = "\033[0;38;2;255;255;240m"  ; // Ivoire
const std::string GRY1 = "\033[0;38;2;128;128;128m"  ; // Gris moyen
const std::string GRY2 = "\033[0;38;2;170;170;170m"  ; // Gris moyen
const std::string SLVR = "\033[0;38;2;192;192;192m"  ; // Argent
const std::string TURQ = "\033[0;38;2;64;224;208m"   ; // Turquoise
const std::string CORL = "\033[0;38;2;255;127;80m"   ; // Corail
const std::string SALM = "\033[0;38;2;250;128;114m"  ; // Saumon
const std::string PLUM = "\033[0;38;2;221;160;221m"  ; // Prune
const std::string TEAL = "\033[0;38;2;0;128;128m"    ; // Sarcelle
const std::string OLIV = "\033[0;38;2;128;128;0m"    ; // Olive
const std::string MINT = "\033[0;38;2;189;252;201m"  ; // Menthe
const std::string NAVY = "\033[0;38;2;0;0;128m"      ; // Marine
const std::string PEAC = "\033[0;38;2;175;238;238m"  ; // Pêche
const std::string LAVN = "\033[0;38;2;230;230;250m"  ; // Lavande
const std::string EMRD = "\033[0;38;2;80;200;120m"   ; // Émeraude
const std::string RUBY = "\033[0;38;2;224;17;95m"    ; // Rubis
const std::string RESET =" \033[0m" ;  // Reset Couleur
const std::string CLRALL=  "\033[2J\033[3J\033[H"    ; // Clear terminal (supprime historique)
const std::string CLR ="\033c"                       ;// Clear terminal (garde historique)
const std::string CLRL = "\033[2K"                   ; // Clear ligne terminal
const std::string BOLD = "\033[1m" ;  // Gras
const std::string ITAL = "\033[3m" ;  // Italique
const std::string SOUL = "\033[4m" ;  // Souligné
const std::string BLKS = "\033[5m" ;  // Clignote (lent)
const std::string BLKF = "\033[6m" ;  // Clignote (lent)
const std::string BARR = "\033[9m" ;  // Barré

#endif
