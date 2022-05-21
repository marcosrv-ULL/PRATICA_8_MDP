#include "../../include/algoritmo/ramificacion.h"

MDPSolution Ramificanacion::solve(MDPInstance& instancia) {
    GRASP* grasp1 = new GRASP(100, new LocalSearch);
    MDPSolution solucionInicial = grasp1->solve(instancia);
    std::vector<double> solucionInicial = {};

}


void Ramificanacion::generateChilds(Nodo* padre, MDPInstance& instancia, std::vector<Nodo*> nodosActivos) {
    for (auto punto: padre->solucion.conjunto_sin_seleccionar()) {
        Nodo* hijo = new Nodo;
        hijo->activo = true;
        MDPSolution solucionHijo = padre->solucion;
        solucionHijo.exchange(, int elemento_cambio)
    }
}

double Ramificanacion::z(MDPSolution& solucion, MDPInstance& instancia) {
    double z1 = solucion.distance();
    double z2 = 0;
    double z3 = 0;
    for(auto punto: solucion.conjunto()) {
        for(auto punto_fuera: solucion.conjunto_sin_seleccionar()) {
            z2 += instancia.distance(punto, punto_fuera);
        }
    }


}