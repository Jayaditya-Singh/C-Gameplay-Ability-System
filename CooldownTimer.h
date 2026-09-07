#pragma once

class CooldownTimer {
    private:
        float duration;
        float remaining;

    public:
        CooldownTimer(float cooldownDuration);

        void Start();
        void Update(float deltaTime);
        bool IsReady() const;
        float GetCooldownProgress() const;
};