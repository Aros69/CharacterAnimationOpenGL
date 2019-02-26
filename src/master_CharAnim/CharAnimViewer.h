
#ifndef _CHARANIMVIEWER_H
#define _CHARANIMVIEWER_H


#include "quaternion.h"
#include "Viewer.h"
#include "BVH.h"
#include "Skeleton.h"
#include "TransformQ.h"
#include "CubeController.h"
#include "CharacterController.h"

#include <PhysicalWorld.h>

class CharAnimViewer : public Viewer {
public:
    CharAnimViewer();

    int init();

    int render();

    int update(const float time, const float delta);

    static CharAnimViewer &singleton() { return *psingleton; }

protected:

    chara::BVH m_bvh;
    int m_frameNumber;

    Skeleton m_ske;

    PhysicalWorld m_world;

    CubeController cubeController;

    Skeleton characterSkeleton;
    CharacterController characterController;

    double secondNumber = 0;
    Transform testTransform;

    void draw_skeleton(const Skeleton &);

    void draw_character(const Skeleton &);

private:
    static CharAnimViewer *psingleton;
};


#endif