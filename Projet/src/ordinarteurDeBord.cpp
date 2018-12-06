#include "../include/ordinateurDeBord.h"
#include <vector>

bool ordidanteurDeBord::checkCarburant(module x){
	if (x.carburant<1){
		~x;
		return(true);
	}
	else {
		return(false);
	}
}

void ordinateurDeBord::updateCarburant(module x){
	x.carburant = x.carburant-x.consomation;
}

float ordinateurDeBord::sumPuissance(vector lanceurVec){
	for (auto x:lanceurVec){
		sum += x.puissance();
	}
	return sum;
}

