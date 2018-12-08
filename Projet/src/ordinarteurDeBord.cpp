#include "../include/ordinateurDeBord.h"
#include <vector>
#include <math.h>

using namespace std;
ordinateurDeBord::ordinateurDeBord(){
		
}

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
void ordinateurDeBord::calculGravite(vector lanceurVec){
	float masseTot;
	for (auto x:lanceurVec){
	masseTot+=x.masse;
	masseTot+=x.carburant;
		
	}
	gravite.first = pow(6.674,pow(10,-11))*masseTot/pow(position.first,2);
	gravite.second = pow(6.674,pow(10,-11))*masseTot/pow(position.second,2);
}

float ordinateurDeBord::sumFrottement(vector lanceurVec){
	for (auto x:lanceurVec){
		surfaceTot+=x.surfaceDeFrot;
	}
	float forceFrot;
	forceFrot = pow(vitesse.first,2)*pow(vitesse.second,2)*pression()*surfaceTot;
		
	return forceFrot;
	
}

void ordinateurDeBord::sumForce(vector lanceurVec){
	calculGravite(lanceurVec);
	float power = sumPuissance(lanceurVec); 		// ATTENTION ceci ne fonction que si on décolle "vers le haut" si on part de l'autre côté de la terre on va avoir des soucis
	float frot = sumFrottement(lanceurVec);			// il est nécéssaire de bien gérer l'angle de la fussée
	SommeForces.first = gravite.first+power * sin(angle)-frot *sin(angle);
	SommeForces.second = gravite.second+first+power * cos(angle)-frot * cos(angle);
	
}

