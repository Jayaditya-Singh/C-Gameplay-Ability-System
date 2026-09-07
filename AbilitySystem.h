#pragma once
#include <vector>
#include <memory>
#include "Ability.h"
#include "CooldownTimer.h"

class AbilitySystem {
    private:
        std::vector<std::unique_ptr<Ability>> abilities;
        float mana;
        CooldownTimer globalCooldown;
        int queuedAbility = -1;
        float manaRegenRate = 5.0f;
        float maxMana = 100.0f;

    public:
        AbilitySystem(float startingMana, float globalCooldownSeconds);
    
        void AddAbility(const std::string& name, AbilityType type,
                float value, float cooldownSeconds, float manaCost, float castTime);
        void Update(float deltaTime);
        void UseAbility(int index);
        void PrintCastingBars() const;
        void PrintCooldownBars() const;
};