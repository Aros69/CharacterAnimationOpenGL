#ifndef GKIT2LIGHT_MASTER_CHARANIM_ANIMSTATE_H
#define GKIT2LIGHT_MASTER_CHARANIM_ANIMSTATE_H

#include <BVH.h>
#include <mat.h>
#include <window.h>

class CharacterController;

// TODO Check how to correctly do transition between animation
// TODO Implement Motion Graph
class AnimState {
protected:
    CharacterController *character;
    chara::BVH bvh;
    Transform animCorrection;

public:
    AnimState() = delete;

    AnimState(CharacterController *characterController) {
        character = characterController;
    }

    const chara::BVH *getBVH() const { return &bvh; };

    const Transform *getAnimCorrection() const { return &animCorrection; };

    virtual void update(const float dt) = 0;

    virtual void handleInput(const float dt) = 0;
};

#endif //GKIT2LIGHT_MASTER_CHARANIM_ANIMSTATE_H
