#include "CooldownTimer.h"

CooldownTimer::CooldownTimer(float cooldownDuration)
    : duration(cooldownDuration), remaining(0.0f) {}

void CooldownTimer::Start() {
    remaining = duration;
}

void CooldownTimer::Update(float deltaTime) {
    if (remaining > 0.0f) {
        remaining -= deltaTime;
        if (remaining < 0.0f) {
            remaining = 0.0f;
        }
    }
}

bool CooldownTimer::IsReady() const {
    return remaining <= 0.0f;
}

float CooldownTimer::GetCooldownProgress() const {
    if (remaining <= 0.0f || duration <= 0.0f) return 0.0f;
    return 1.0f - (remaining / duration);
}