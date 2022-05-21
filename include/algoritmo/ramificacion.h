#ifndef RAMIFICACION_H_
#define RAMIFICACION_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "algoritmo.h"
#include "localsearchInterfaz.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "localsearch.h"
#include "grasp.h"

class Nodo
{
public:
    int cota;
    MDPSolution solucion;
    Nodo* padre;
    bool activo;
    std::vector<Nodo*> hijos;
    void addChild(Nodo* hijo) {
        hijos.push_back(hijo);
        hijo->activo = true;
    }
    void removeChilds() {
        for (auto hijo: hijos) {
            hijo->removeChilds();
        }
        hijos = {};
        cota = -1;
        activo = false;

    }
};

class Ramificanacion : public Algoritmo {
    private:
     LocalSearchInterfaz* localsearch;
     int max_iter;
    public:
        Ramificanacion(int max_iter, LocalSearchInterfaz* busqueda);
        MDPSolution solve(MDPInstance&);
        MDPSolution construct(MDPInstance&);
        void generateChilds(Nodo* padre, MDPInstance&, std::vector<Nodo*> nodosActivos);
        double z(MDPSolution& solucion, MDPInstance& instancia);
};

#endif

