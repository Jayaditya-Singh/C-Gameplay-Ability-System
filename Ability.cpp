#include "Ability.h"
#include <iostream>

Ability::Ability(const std::string& name, AbilityType type,
                 float value, float cooldownSeconds, float manaCost, float castTime)
    : name(name), type(type), damage(value), cooldown(cooldownSeconds),
      manaCost(manaCost), castTime(castTime)
{
    switch (type) {
        case AbilityType::Damage:
            damage = value;
            break;
        case AbilityType::Heal:
            healAmount = value;
            break;
        case AbilityType::DOT:
            dotDamage = value;
            dotDuration = 3.0f;
            break;
        case AbilityType::Buff:
            buffAmount = value;
            buffDuration = 5.0f;
            break;
    }
}

bool Ability::Use(float& currentMana) {
    if (isCasting) {
        std::cout << name << " is already casting.\n";
        return false;
    }
    
    if (!cooldown.IsReady()) {
        std::cout << name << " is on cooldown.\n";
        return false;
    }

    if (currentMana < manaCost) {
        std::cout << "Not enough mana for " << name << ".\n";
        return false;
    }

    isCasting = true;
    castTimer = castTime;
    std::cout << name << " begins casting (" << castTime << "s)...\n";

    return true;
}

void Ability::Update(float deltaTime, float& currentMana) {
    cooldown.Update(deltaTime);

    if (isCasting) {
        castTimer -= deltaTime;

        if (castTimer <= 0.0f) {
            isCasting = false;
            currentMana -= manaCost;

            switch (type) {
                case AbilityType::Damage:
                    std::cout << name << " deals " << damage << " damage!\n";
                    break;
                case AbilityType::Heal:
                    std::cout << name << " heals " << healAmount << " HP!\n";
                    break;
                case AbilityType::DOT:
                    std::cout << name << " applies a DOT for " << dotDamage << " damage per second.\n";
                    break;
                case AbilityType::Buff:
                    std::cout << name << " applies a buff of +" << buffAmount
                              << " for " << buffDuration << " seconds.\n";
                    break;
            }

            cooldown.Start();
            castJustFinished = true;
        }
    }
}

void Ability::Interrupt() {
    if (isCasting) {
        isCasting = false;
        castTimer = 0.0f;
        std::cout << name << " was interrupted!\n";
    }
}

float Ability::GetCastProgress() const {
    if (!isCasting || castTime <= 0.0f) return 0.0f;
    return 1.0f - (castTimer / castTime);
}

const std::string& Ability::GetName() const {return name;}

bool Ability::IsReady() const { return cooldown.IsReady();}

float Ability::GetCooldownProgress() const { return cooldown.GetCooldownProgress(); }