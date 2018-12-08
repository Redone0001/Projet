#include <utility>

class ordinateurDeBord{
	public :
	bool checkCarburant(module); //vérifie que le carburant est pas trop bas et si c'est à un niveau critique éjecte(supprime) le module
	void updateCarburant(module);//update le carburant 
	float sumPuissance(vector);// dans le sens du mouvement
	void sumForces(vector); // modifie la pair de float Somme des forces
	void calculGravite(vector);  // modifie la pair de float gravite
	float sumFrottement(vector);//dans le sens opposé au mouvement
	void updateMouv(float);
	float checkMasse(vector);
	pair <float,float> gravite;
	pair <float,float> position; // la possition de la fussée est repéré dans un référentiel placé au centre de la terre et immobile
	pair <float,float> vitesse; // la vitesse est dans le même repère que la possition 
	pair <float,float> acceleration; //idem
	pair <float,float> SommeForces;
	float angle; // angle de la fusée / à la verticale
	
};



