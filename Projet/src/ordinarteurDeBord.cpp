#include "../include/ordinateurDeBord.h"
#include <vector>
#include <math.h>

using namespace std;
ordinateurDeBord::ordinateurDeBord(){
	angle = 3.141592;
	possition.first = 3371000.0;
	possition.second=0;
	vitesse.first=0;
	vitesse.second=465;
	acceleration.first=0;
	acceleration.second=0;
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

float ordinateurDeBord::pression(){
	float altitude = sqrt(pow(possition.first,2)+pow(possition.second,2))-3371000.0;
	if (altitude<350000){
		float pression = 101325*pow(1-(0.0065*altitude/288.15),(sqrt(pow(gravite.first,2)*pow(gravite.second,2)))*0.0289644/(8.31447*0.0065)
	}
	else{
		pression = 0;
	}
	return pression;
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
float ordinateurDeBord::checkMasse(vector lanceurVec){
	float masseTot;
	for (auto x:lanceurVec){
	masseTot+=x.masse;
	masseTot+=x.carburant;	
	}
	return masseTot;
}

void ordinateurDeBord::updateMouv(float t,float masse){
	possition.first = vitesse.first*t;
	possition.second=vitesse.second*t;
	vitesse.first = acceleration.first*t;
	vitesse.second = acceleration.second*t;
	acceleration.first=SommeForces.first/masse
	acceleration.second=SommeForces.second/masse
		
}
