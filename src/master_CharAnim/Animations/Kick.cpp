#include "Kick.h"
#include "CharacterController.h"

void Kick::update(const float dt) {
    handleInput(dt);
    if (character->getTimeAnim() > bvh.getNumberOfFrame()) {
        character->setActualAnimIdle(0);
    } /*else {
        character->setTimeAnim(character->getTimeAnim() + 1);
    }*/
}

void Kick::handleInput(const float dt) {}
