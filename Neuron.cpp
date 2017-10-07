#include "Neuron.hpp"
#include "Constantes.hpp"


//constructeur
//user chooses the Tstart but most of the time 0
Neuron::Neuron (double tau, double potential, double c)
: tau_(tau), potential_membrane_(potential_reset), c_(c)
{
	nbr_spikes_=0;
	spikes_times_.push_back(Tstart);
	potentials_.clear(); 
}

//destruteur
Neuron::~Neuron(){}

//update the neuron from time_ to time time_+T avec un pas de 1 (h)
void Neuron::update(const double& ext_current, double time)
{

	//stocker le temps des spikes dans le tableau 
	//si le potentiel est au dessus du seuil de -55mV (potential_max)
	if (potential_membrane_ > potential_max) {
		potential_membrane_ = potential_reset; 
		spikes_times_.push_back(time); 
	}
	
	//stocker les potentiels dans un tableau
	potentials_.push_back(potential_membrane_);
		
	//on met a jour le potentiel 
	//sauf si periode de refraction c est a dire pas la premiere fois
	if((time > (spikes_times_.back() + 1)) or (spikes_times_.back() == Tstart)){
	//update potentiel de membrane si pas de spike
	potential_membrane_ = exp(-time/tau_)*potential_membrane_ + ext_current/c*(1-exp(-time/tau_)); 
	}
}

//getters
vector<double> Neuron::getPotentials() const {return potentials_;} 
vector<double> Neuron::getTimes() const {return spikes_times_;}
