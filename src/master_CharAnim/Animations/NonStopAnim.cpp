#include "NonStopAnim.h"
#include "CharacterController.h"

void NonStopAnim::update(const float dt) {
    handleInput(dt);
    if (actualframe > bvh.getNumberOfFrame()) {
        character->setActualAnimIdle(0);
    }
}