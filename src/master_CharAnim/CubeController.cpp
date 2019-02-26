#include "CubeController.h"

CubeController::CubeController() {
    m_v = 0;
    m_vMax = 100;
    m_forward = true;
}

void CubeController::update(const float dt) {
    bool moveKeyPressed = false;
    if (key_state('z')) {
        setForward(true);
        accelerate(0.5);
        moveKeyPressed = true;
    }
    if (key_state('q')) {
        turnXZ(5.0);
    }
    if (key_state('s')) {
        setForward(false);
        accelerate(0.5);
        moveKeyPressed = true;
    }
    if (key_state('d')) {
        turnXZ(-5.0);
    }
    if (!moveKeyPressed) {
        deccelerate(0.3);
    }
    if (key_state('x')) {
        std::cout << "dt = " << dt << "\n";
        std::cout << "m_v = " << m_v << "\n";
    }
    m_ch2w = m_ch2w * Translation(m_v * (dt / 1000), 0, 0);
}

void CubeController::turnXZ(const float &rot_angle_v) {
    m_ch2w = m_ch2w * RotationY(rot_angle_v);
}

void CubeController::accelerate(const float &speed) {
    if ((m_forward && m_v < 0) || (!m_forward && m_v > 0)) {
        m_v = m_v / 1.1f;
    }
    if (m_v + speed >= m_vMax || m_v + speed <= -1 * m_vMax) {
        if (m_forward) {
            m_v = m_vMax;
        } else {
            m_v = -m_vMax;
        }
    } else {
        if (m_forward) {
            m_v += speed;
        } else {
            m_v -= speed;
        }
    }
}

void CubeController::deccelerate(const float &speed) {
    if ((!m_forward && m_v + speed >= 0) ||
        (m_forward && m_v - speed <= 0)) { m_v = 0; }
    if (m_v > 0 && m_forward) { m_v -= speed; }
    else if (m_v < 0 && !m_forward) { m_v += speed; }
}
