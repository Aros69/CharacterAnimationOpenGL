
#ifndef GKIT2LIGHT_MASTER_CHARANIM_MOTIONGRAPH_H
#define GKIT2LIGHT_MASTER_CHARANIM_MOTIONGRAPH_H

#include <vector>
#include "BVH.h"

class MotionGraph {
public:
    MotionGraph();


protected:
    //! L'ensemble des BVH du graphe d'animation
    std::vector<chara::BVH> m_BVH;

    //! Un noeud du graphe d'animation est repéré par un entier=un identifiant
    typedef int GrapheNodeID;

    //! Une animation BVH est repérée par un identifiant=un entier
    typedef int BVH_ID;

    //! Un noeud du graphe contient l'identifiant de l'animation, le numéro
    //! de la frame et les identifiants des noeuds successeurs
    //! Remarque : du code plus "joli" aurait créer une classe CAGrapheNode
    struct GrapheNode
    {
        BVH_ID id_bvh;
        int frame;
        std::vector<GrapheNodeID> ids_next;     //! Liste des nœuds successeurs
    };


    //! Tous les noeuds du graphe d'animation
    std::vector<GrapheNode> m_GrapheNode;

};


#endif //GKIT2LIGHT_MASTER_CHARANIM_MOTIONGRAPH_H
