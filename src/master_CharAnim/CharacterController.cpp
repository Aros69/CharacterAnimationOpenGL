#include "CharacterController.h"


CharacterController::CharacterController() : CubeController() {

    chara::BVH idle, walk, run, kick;
    idle.init("data/bvh/motionGraph/dancer.bvh");
    std::pair<chara::BVH, Transform> idlePair(idle, RotationY(90));
    bvhs.push_back(idlePair);
    walk.init("data/bvh/motionGraph/marcher.bvh");
    std::pair<chara::BVH, Transform> walkPair(walk, Transform());
    bvhs.push_back(walkPair);
    run.init("data/bvh/motionGraph/courir.bvh");
    std::pair<chara::BVH, Transform> runPair(run, Transform());
    bvhs.push_back(runPair);
    kick.init("data/bvh/motionGraph/frapper.bvh");
    std::pair<chara::BVH, Transform> kickPair(kick, RotationY(90));
    bvhs.push_back(kickPair);
    actualAnim = &bvhs[0].first;
    animCorrection = &bvhs[0].second;
    timeAnim = 0;
    timeKicking = -1;
}

void CharacterController::setAnim(int index) {
    actualAnim = &bvhs[index].first;
    animCorrection = &bvhs[index].second;
    timeAnim = 0;
}

void CharacterController::update(const float dt) {
    bool moveKeyPressed = false;
    ++timeAnim;
    if (timeKicking == -1) {
        // Handling input
        if (key_state('z')) {
            setForward(true);
            accelerate(dt);
            moveKeyPressed = true;
        }
        if (key_state('q')) {
            turnXZ(5.0);
        }
        if (key_state('s')) {
            setForward(false);
            accelerate(dt);
            moveKeyPressed = true;
        }
        if (key_state('d')) {
            turnXZ(-5.0);
        }
        if (key_state('x')) {
            timeKicking = 0;
            setVelocity(0);
        }
        if (!moveKeyPressed) {
            deccelerate(dt);
        }

        // Update animation
        if (m_v == 0) {
            if (timeKicking == -1) {
                if (actualAnim != getAnim(0)) {
                    setAnim(0);
                } // idling animation
            } else {
                setAnim(3); // kicking animation
            }
        } else if (m_v < m_vMax / 2 && m_v > -m_vMax / 2 &&
                   actualAnim != getAnim(1)) {
            setAnim(1); // walking animation
        } else if ((m_v >= m_vMax / 2 || m_v <= -m_vMax / 2) &&
                   actualAnim != getAnim(2)) {
            setAnim(2); // running animation
        }
    } else {
        if (timeAnim - timeKicking > getAnim().getNumberOfFrame()) {
            timeKicking = -1;
        }
    };


    m_ch2w = m_ch2w * Translation(m_v*dt, 0, 0);

}