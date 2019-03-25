#include "MotionGraph.h"

MotionGraph::MotionGraph() {
    m_BVH.push_back(chara::BVH("data/bvh/motionGraph_second_life/avatar_impatient.bvh"));
    m_BVH.push_back(chara::BVH("data/bvh/motionGraph_second_life/avatar_slowwlak.bvh"));
    m_BVH.push_back(chara::BVH("data/bvh/motionGraph_second_life/avatar_run.bvh"));
    m_BVH.push_back(chara::BVH("data/bvh/motionGraph_second_life/avatar_kick_roundhouse_R.bvh"));
    /* ... */
}