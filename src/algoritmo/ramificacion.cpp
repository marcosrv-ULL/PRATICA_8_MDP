#include "../../include/algoritmo/ramificacion.h"

MDPSolution Ramificanacion::solve(MDPInstance& instancia) {
    GRASP* grasp1 = new GRASP(100, new LocalSearch);
    MDPSolution solucionInicial = grasp1->solve(instancia);
    MDPSolution bestSolution = solucionInicial;
    Nodo* raiz = new Nodo(solucionInicial.distance(), nullptr, solucionInicial);
    std::vector<Nodo*> listaActiva = {};
    for (int i = 0; i < instancia.getN(); i++) {
        MDPSolution solucion_hija(instancia);
        solucion_hija.addToSet(i);
        double cotaHija = UB(solucion_hija, instancia);
        if (cotaHija > raiz->cota)
            listaActiva.push_back(new Nodo(cotaHija, raiz, solucion_hija));
    }
    std::sort(listaActiva.begin(), listaActiva.end());
    int maxIter = 1000;
    int iter = 0;
    while(listaActiva.size() > 0 && iter++ < maxIter) {
        int i = 0;
        while(!listaActiva[i++]->activo) {
            listaActiva.erase(listaActiva.begin(), listaActiva.begin() + i);
        }
        Nodo* actual = listaActiva[0];
        if (actual->solucion.conjunto().size() == (unsigned int)instancia.getMMax()) {
            if (actual->solucion.distance() > bestSolution.distance()) {
                bestSolution = actual->solucion;
                bestSolution.showSolution();
            }
            listaActiva.erase(listaActiva.begin(), listaActiva.begin());
        } else {
            for (auto nodo: actual->solucion.conjunto_sin_seleccionar()) {
                MDPSolution solucion_hija(instancia);
                solucion_hija.addToSet(nodo);
                double cotaHija = UB(solucion_hija, instancia);
                if (cotaHija > bestSolution.distance())
                    listaActiva.push_back(new Nodo(cotaHija, raiz, solucion_hija));
                
            }
            listaActiva.erase(listaActiva.begin(), listaActiva.begin());
        }
    }
    return bestSolution;
}

double Ramificanacion::UB(MDPSolution& solucion, MDPInstance& instancia) {
  std::vector<std::vector<double>> elementos_restantes = instancia.elementos();
  MDPSolution solution = solucion;
  std::vector<std::vector<double>> solucion1 = {};
  for(auto nodo: solucion.conjunto()) {
      solucion1.push_back(instancia.elemento(nodo));
  }
  std::vector<double> centro1 = centro(solucion1);
  while (solution.getM() < instancia.getMMax()) {
    double mas_lejano = 0;
    int mas_lejano_index = 0;
    for (auto elemento_no_presente: solution.conjunto_sin_seleccionar()) {
      double distancia = instancia.distance(centro1, instancia.elemento(elemento_no_presente));
      if ( distancia > mas_lejano) {
        mas_lejano = distancia;
        mas_lejano_index = elemento_no_presente;
      }
    }
    solution.addToSet(mas_lejano_index);
    solucion1.push_back(instancia.elemento(mas_lejano_index));
    centro1 = centro(solucion1);
  } 
  return solution.distance();


}