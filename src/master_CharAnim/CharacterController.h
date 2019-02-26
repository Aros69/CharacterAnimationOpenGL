#ifndef GKIT2LIGHT_MASTER_CHARANIM_CHARACTERCONTROLLER_H
#define GKIT2LIGHT_MASTER_CHARANIM_CHARACTERCONTROLLER_H

#include "CubeController.h"

class CharacterController : public CubeController {

public:
    CharacterController();

    void update(const float dt) override;

    void setAnim(int index);

    chara::BVH getAnim() const { return *actualAnim; };

    Transform getAnimCorrection() const { return *animCorrection; };

    unsigned int getTimeAnim() const { return timeAnim; };

protected:

    std::vector<std::pair<chara::BVH, Transform>> bvhs;
    chara::BVH *actualAnim;
    Transform *animCorrection;
    unsigned int timeAnim;
    int timeKicking;

private:
    const chara::BVH *getAnim(unsigned int index) const {
        return &bvhs[index].first;
    };
};

#endif //GKIT2LIGHT_MASTER_CHARANIM_CHARACTERCONTROLLER_H
