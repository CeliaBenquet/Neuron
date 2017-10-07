#include "Neuron.hpp"
#include "Constantes.hpp"
#include <iostream>
#include <fstream>
using namespace std; 

//pour le temps : 1 double = 1 ms

int main() 
{
	double time(Tstart); 
	Neuron n (tau, potential_reset, c); 
	
	while (time <= Tstop){
		n.update(ext_current, time); 
		time += step; 
	}
	
	//envoyer les deux tableaux dans un fichier
	//potential
	ofstream sortie;
	sortie.open("membrane_potentials.txt"); 
	sortie << "Potentiels de membrane sur l intervalle de temps [" << Tstart << "," << Tstop << "]" <<endl;
	for(int i(0); i< n.getPotentials().size(); ++i){
		sortie << n.getPotentials()[i] << endl; 
	}
	return 0; 
}


/*
 * c = 250 pF
 * tau = 10 ms
 * tau ref = 2ms
 * Vreset = -70 mV => apres un spike
 * h = 0.1 ms
 */
