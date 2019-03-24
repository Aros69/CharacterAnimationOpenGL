#ifndef GKIT2LIGHT_MASTER_CHARANIM_CHARACTERCONTROLLER_H
#define GKIT2LIGHT_MASTER_CHARANIM_CHARACTERCONTROLLER_H

#include "Animations/AnimState.h"
#include "Animations/Idle.h"
#include "Animations/Walk.h"
#include "Animations/Run.h"
#include "Animations/Kick.h"
#include "CubeController.h"

class CharacterController : public CubeController {

public:
    CharacterController();

    ~CharacterController();

    void update(const float dt) override;

    void setAnim(unsigned int index);

    const chara::BVH* getAnim() const {
        return animations[actualAnimationIndex]->getBVH();
    };

    const Transform* getAnimCorrection() const {
        return animations[actualAnimationIndex]->getAnimCorrection();
    };

    void setTimeAnim(unsigned int newTimeAnim) { timeAnim = newTimeAnim; };

    unsigned int getTimeAnim() const { return timeAnim; };

    void setActualAnimIdle(unsigned int goodTimeAnim) {
        setAnim(0);
        timeAnim = goodTimeAnim;
    }

    void setActualAnimWalk(unsigned int goodTimeAnim) {
        setAnim(1);
        timeAnim = goodTimeAnim;
    }

    void setActualAnimRun(unsigned int goodTimeAnim) {
        setAnim(2);
        timeAnim = goodTimeAnim;
    }

    void setActualAnimKick(unsigned int goodTimeAnim) {
        setAnim(3);
        timeAnim = goodTimeAnim;
    }

protected:
    AnimState **animations;
    unsigned int timeAnim;
    unsigned int actualAnimationIndex;
};

#endif //GKIT2LIGHT_MASTER_CHARANIM_CHARACTERCONTROLLER_H
