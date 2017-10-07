#ifndef NEURON_HPP
#define NEURON_HPP

#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

class Neuron 
{
	public :
		Neuron (double tau, double potential, double c); 
		~Neuron ();
		
		void update(const double& ext_current, double time); 
		
		vector<double> getTimes() const; 
		vector<double> getPotentials() const; 

	
	private :
		double potential_membrane_;
		// compte le nombre de spikes
		int nbr_spikes_; 		
		
		//tableau qui stocke les temps ou apparaissent les spikes
		vector <double> spikes_times_; 
		//tableau qui stocke les potentiels
		vector <double> potentials_; 

		//capacite membranaire 
		double c_; 
		//tau = resistance membranaire * capacite membranaire
		double tau_; 
};

#endif
