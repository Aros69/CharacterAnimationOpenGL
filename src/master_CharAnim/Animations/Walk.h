#ifndef GKIT2LIGHT_MASTER_CHARANIM_WALK_H
#define GKIT2LIGHT_MASTER_CHARANIM_WALK_H


#include "Idle.h"

class Walk : public Idle {
public:
    Walk(CharacterController *characterController) {
        character = characterController;
        bvh.init("data/bvh/motionGraph/marcher.bvh");
        animCorrection = Transform();
    };

    virtual void update(const float dt) override;
};


#endif //GKIT2LIGHT_MASTER_CHARANIM_WALK_H
