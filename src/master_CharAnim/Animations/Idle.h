#ifndef GKIT2LIGHT_MASTER_CHARANIM_IDLE_H
#define GKIT2LIGHT_MASTER_CHARANIM_IDLE_H


#include "AnimState.h"

class Idle : public AnimState {
public:
    Idle(CharacterController *characterController)
            : AnimState(characterController) {
        bvh.init("data/bvh/motionGraph/dancer.bvh");
        animCorrection = RotationY(90);
    };

    virtual void update(const float dt) override;

    virtual void handleInput(const float dt) override;
};


#endif //GKIT2LIGHT_MASTER_CHARANIM_IDLE_H
