#include "../../include/algoritmo/tabu_II.h"

Tabu_II::Tabu_II(int iters, LocalSearchInterfaz* busqueda) {
  localsearch = busqueda;
  max_iter = iters;
}

MDPSolution Tabu_II::solve(MDPInstance& instancia) {
  MDPSolution bestSolution;
  std::vector<int> frecuencia(instancia.elementos().size(), 0);
  std::vector<int> calidad(instancia.elementos().size(), 0);
  double beta = 0.1, delta = 0.001;
  double max_frecuencia = 1;
  double max_calidad = 1;
  for (int iteracion = 1; iteracion < max_iter; iteracion++) {
    MDPSolution currentSolution(instancia);     
    std::vector<std::vector<double>> elementos_restantes = instancia.elementos();
    std::vector<double> centro1 = centro(elementos_restantes);
    std::vector<std::vector<double>> solution = {};
    
    do {
        int mas_lejano = 0;
        double criterio_value = 0;
        for (auto elemento_no_presente: currentSolution.conjunto_sin_seleccionar()) {
            double distancia_a_centro = instancia.distance(centro1, instancia.elemento(elemento_no_presente));
            double criterio = distancia_a_centro - ( beta * distancia_a_centro * (frecuencia[elemento_no_presente]/max_frecuencia)) + (delta * distancia_a_centro * (calidad[elemento_no_presente] / max_calidad));
            if ( criterio > criterio_value) {
                criterio_value = criterio;
                mas_lejano = elemento_no_presente;
            }
        }
        currentSolution.addToSet(mas_lejano);
        frecuencia[mas_lejano] += 1;
        max_frecuencia = (max_frecuencia < frecuencia[mas_lejano]) ? frecuencia[mas_lejano]: max_frecuencia;
        solution.push_back(instancia.elemento(mas_lejano));
        centro1 = centro(solution);
    } while (currentSolution.getM() < instancia.getMMax());
    for (unsigned int i = 0; i < calidad.size(); i++) {
        calidad[i] = (calidad[i] * (frecuencia[i] - 1) + currentSolution.distance()) / frecuencia[i];
        if (calidad[i] > max_calidad) max_calidad = calidad[i];
    }
    currentSolution = localsearch->solve(currentSolution, instancia);
    if (iteracion == 1 || currentSolution.distance() > bestSolution.distance()) {
        bestSolution = currentSolution;
    }
  }
  
  return bestSolution;
}