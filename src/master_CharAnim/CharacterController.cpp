#include "CharacterController.h"


CharacterController::CharacterController() : CubeController() {
    timeAnim = 0;
    animations = new AnimState*[4];
    animations[0] = new Idle(this);
    animations[1] = new Walk(this);
    animations[2] = new Run(this);
    animations[3] = new Kick(this);
    setActualAnimIdle(0);
}

CharacterController::~CharacterController() {
    delete []animations;
    animations = nullptr;
}

void CharacterController::setAnim(unsigned int index) {
    actualAnimationIndex = index;
}

void CharacterController::update(const float dt) {
    ++timeAnim;
    animations[actualAnimationIndex]->update(dt);
    m_ch2w = m_ch2w * Translation(m_v*dt, 0, 0);
}