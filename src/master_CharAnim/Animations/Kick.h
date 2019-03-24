#ifndef GKIT2LIGHT_MASTER_CHARANIM_KICK_H
#define GKIT2LIGHT_MASTER_CHARANIM_KICK_H


#include "AnimState.h"

class Kick : public AnimState{
public:
    Kick(CharacterController *characterController)
    : AnimState(characterController) {
            bvh.init("data/bvh/motionGraph/frapper.bvh");
            animCorrection = RotationY(90);
    };

    void handleInput(const float dt) override{};

    void update(const float dt) override;
};


#endif //GKIT2LIGHT_MASTER_CHARANIM_KICK_H
