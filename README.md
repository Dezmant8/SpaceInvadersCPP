# Space Invaders (C++17 • ncurses • SFML)

---

## Установка зависимостей (macOS)

```bash
brew update
brew install cmake ncurses sfml
```


## Сборка

```bash
cd SpaceInvaders
mkdir build && cd build
# Вариант 1. Терминальная версия
cmake .. -DUSE_SFML=OFF
make -j
# Вариант 2. Графическая версия
cmake .. -DUSE_SFML=ON
make -j
```

## Запуск

```bash
./space_invaders
```

## Управление

```bash
Клавиша     Действие

← / →	    Перемещение корабля влево/вправо
SPACE	    Выстрел
P	        Пауза / продолжить
Q	        Выйти из игры
```