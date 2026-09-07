#include "AbilitySystem.h"
#include <iostream>

AbilitySystem::AbilitySystem(float startingMana, float globalCooldownSeconds) : mana(startingMana), globalCooldown(globalCooldownSeconds) {}

void AbilitySystem::AddAbility(const std::string& name, AbilityType type, float value, float cooldownSeconds, float manaCost, float castTime)
{
    abilities.push_back(std::make_unique<Ability>(name, type, value, cooldownSeconds, manaCost, castTime));
}

void AbilitySystem::Update(float deltaTime) {
    mana += manaRegenRate * deltaTime;
    if (mana > maxMana) mana = maxMana;
    
    globalCooldown.Update(deltaTime);

    for (auto& ability : abilities) {
        ability->Update(deltaTime, mana);

        if (ability->HasFinishedCast()) {
            globalCooldown.Start();
            ability->ResetCastFlag();
        }
    }

    if (globalCooldown.IsReady() && queuedAbility != -1) {
        std::cout << "Global cooldown finished. Using queued ability...\n";
        UseAbility(queuedAbility);
        queuedAbility = -1;
    }
}

void AbilitySystem::UseAbility(int index) {
    if (index < 0 || index >= abilities.size()) {
        std::cout << "Invalid ability index.\n";
        return;
    }

    if (!globalCooldown.IsReady()) {
        std::cout << "Global cooldown active. Queuing ability...\n";
        queuedAbility = index;
        return;
    }

    for (auto& ability : abilities) {
        if (ability->IsCasting()) {
            ability->Interrupt();
        }
    }

    bool fired = abilities[index]->Use(mana);

    if (fired) {
        queuedAbility = -1;
    }

    std::cout << "Current mana: " << mana << "\n";
}

void AbilitySystem::PrintCastingBars() const {
    bool printedAny = false;

    for (const auto& ability : abilities) {
        if (ability->IsCasting()) {
            printedAny = true;

            float progress = ability->GetCastProgress();
            int barWidth = 20;
            int filled = static_cast<int>(progress * barWidth);

            std::cout << ability->GetName() << " [";

            for (int i = 0; i < barWidth; ++i) {
                if (i < filled) std::cout << "#";
                else std::cout << "-";
            }

            std::cout << "] " << static_cast<int>(progress * 100) << "%\n";
        }
    }
    
    if (!printedAny) {
    }
}

void AbilitySystem::PrintCooldownBars() const {
    for (const auto& ability : abilities) {
        if (!ability->IsCasting() && !ability->IsReady()) {
            float progress = ability->GetCooldownProgress();
            int barWidth = 20;
            int filled = static_cast<int>(progress * barWidth);

            std::cout << ability->GetName() << " CD [";

            for (int i = 0; i < barWidth; ++i) {
                if (i < filled) std::cout << "#";
                else std::cout << "-";
            }

            std::cout << "] " << static_cast<int>(progress * 100) << "%\n";
        }
    }
}