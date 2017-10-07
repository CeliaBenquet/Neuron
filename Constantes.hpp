#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP

#include <string>
#include <iostream>

//constantes 
double const Tstart = 0.0; //temps de debut de l activite du neurone
double const Tstop = 30.0;  //temps jusqu'a laquelle doit aller la simulation
double const step = 0.1; //pas d avancee du temps
double const ext_current = 400; //valeur courant externe
double const potential_reset =-70; //potential apres que le seuil a ete atteint
double const c = 250; //capacite membranaire d un neurone
double const tau =10; // c*r
double const potential_max = -55; //est atteint quand firing threshold


#endif
