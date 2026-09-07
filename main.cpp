#include <iostream>
#include <conio.h>
#include <windows.h>
#include "AbilitySystem.h"

int main() {
    AbilitySystem system(100.0f, 1.0f);

    system.AddAbility("Fireball", AbilityType::Damage, 50.0f, 5.0f, 20.0f, 1.5f);
    system.AddAbility("Heal", AbilityType::Heal, 30.0f, 3.0f, 10.0f, 1.0f);
    system.AddAbility("Poison Cloud", AbilityType::DOT, 10.0f,8.0f, 25.0f, 2.0f);
    system.AddAbility("Strength Buff", AbilityType::Buff, 5.0f, 10.0f, 30.0f, 0.5f);

    std::cout << "Press 1 to cast Fireball\n";
    std::cout << "Press 2 to cast Ice Heal\n";
    std::cout << "Press 3 to cast Poison Cloud\n";
    std::cout << "Press 4 to cast Strength Buff\n";
    std::cout << "Press Q to cast quit\n\n";

    while (true) {
        system.Update(0.1f);
        system.PrintCastingBars();
        system.PrintCooldownBars();

        if (_kbhit()) {
            char key = _getch();

            if (key == '1') system.UseAbility(0);
            else if (key == '2') system.UseAbility(1);
            else if (key == '3') system.UseAbility(2);
            else if (key == '4') system.UseAbility(3);
            else if (key == 'q' || key == 'Q') break;
        }

        Sleep(100);
    }

    return 0;
}