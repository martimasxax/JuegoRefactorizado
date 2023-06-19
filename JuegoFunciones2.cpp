#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <mmsystem.h>
using namespace std;

void ataqueJoker(double& enemyDamage) {
    cout << "El Joker se dispone a atacar\n";
    Beep(330, 100);
    Sleep(100);
    Beep(330, 100);
    Sleep(1000);
    enemyDamage = (rand() % 200) * 2;
    if (enemyDamage > 150) {
        enemyDamage = 150;
    }
    cout << "¡El Joker te ha atacado! Ha infligido " << enemyDamage << " puntos de daño.\n";
}

void ataqueEnemigo(double& enemyHP, double playerDamage, const string& enemyName) {
    enemyHP -= playerDamage;
    cout << "¡Has atacado a " << enemyName << "! Has infligido " << playerDamage << " puntos de daño.\n";
    cout << enemyName << " tiene " << enemyHP << " de vida.\n";
    if (enemyHP <= 0) {
        cout << "¡Has derrotado a " << enemyName << "!\n";
    }
}

void concentracionMistica(double& damageMultiplier) {
    damageMultiplier += 0.5;
    cout << "Has utilizado Concentración Mística. Tu daño aumentará en un 50% durante este turno.\n";
}

void startGame() {
    bool enemy1IsAlive = true;
    bool enemy2IsAlive = true;
    double playerHP = 200;
    double playerDamage = 20;
    double enemy1HP = 100;
    double enemy2HP = 150;
    double enemyDamage;

    while (enemy1IsAlive || enemy2IsAlive) {
        cout << "Selecciona una acción:\n";
        cout << "1. Atacar\n";
        cout << "2. Concentración Mística\n";
        int action;
        cin >> action;

        switch (action) {
        case 1:
            ataqueJoker(enemyDamage);
            ataqueEnemigo(playerHP, enemyDamage, "Joker");
            if (!enemy1IsAlive) {
                break;
            }
            ataqueEnemigo(enemy1HP, playerDamage, "Joker");
            break;
        case 2:
            concentracionMistica(playerDamage);
            ataqueEnemigo(enemy1HP, playerDamage, "Joker");
            if (enemy1IsAlive) {
                ataqueEnemigo(enemy1HP, playerDamage, "Joker");
            }
            break;
        default:
            cout << "Acción inválida. Por favor, selecciona una opción válida.\n";
            continue;
        }

        if (playerHP <= 0) {
            cout << "¡Has sido derrotado! Game Over.\n";
            break;
        }

        if (!enemy1IsAlive && !enemy2IsAlive) {
            cout << "¡Has derrotado a todos los enemigos! ¡Eres el ganador!\n";
            break;
        }
    }
}

int main() {

    cout << "¡Bienvenido al juego de Batman!\n";
    cout << "Selecciona un personaje:\n";
    cout << "1. Batman\n";
    cout << "2. Robin\n";
    int characterSelection;
    cin >> characterSelection;

    switch (characterSelection) {
    case 1:
        cout << "Has seleccionado a Batman.\n";
        break;
    case 2:
        cout << "Has seleccionado a Robin.\n";
        break;
    default:
        cout << "Selección inválida. Saliendo del juego.\n";
        return 0;
    }

    startGame();

    return 0;
}
