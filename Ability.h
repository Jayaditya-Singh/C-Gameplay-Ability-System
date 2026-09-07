#pragma once
#include <string>
#include "CooldownTimer.h"

enum class AbilityType {
    Damage,
    Heal,
    DOT,
    Buff
};

class Ability {
    private:
        std::string name;
        float damage;
        float manaCost;
        float castTime;

        CooldownTimer cooldown;

        bool isCasting;
        float castTimer;

        bool castJustFinished;

        AbilityType type;
        float healAmount = 0.0f;
        float dotDamage = 0.0f;
        float dotDuration = 0.0f;
        float buffAmount = 0.0f;
        float buffDuration = 0.0f;

    public:
        Ability(const std::string& name, AbilityType type,
        float value, float cooldownSeconds, float manaCost, float castTime);

        bool Use(float& currentMana);
        void Update(float deltaTime, float& currentMana);

        bool HasFinishedCast() const { return castJustFinished; }
        void ResetCastFlag() { castJustFinished = false;}

        void Interrupt();
        bool IsCasting() const { return isCasting; }
        float GetCastProgress() const;
        const std::string& GetName() const;
        bool IsReady() const;
        float GetCooldownProgress() const;
};