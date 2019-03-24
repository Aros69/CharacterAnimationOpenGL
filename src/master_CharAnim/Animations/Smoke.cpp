#include "Smoke.h"
#include "CharacterController.h"

void Smoke::update(const float dt) {
    if (actualframe > bvh.getNumberOfFrame()) {
        character->setActualAnimSmokeIdle(0);
    }
}

