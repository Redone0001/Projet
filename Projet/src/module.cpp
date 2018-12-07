void module::module(float Masse,float Carburant, float coef, float SurfaceFrot):
masse(Masse),
carburant(Carburant),
coefPuissance(coef),
surfaceFrot(SurfaceFrot)
{
consomation = 0;

}

float module::puissance(){
    float puissance = coefPuissance * consomation;
  
}
