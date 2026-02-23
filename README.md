# 🎮 Pacman - Game Engine in C++ with SFML

## 📋 Table of Contents
1. [Project Description](#project-description)
2. [Project Architecture](#project-architecture)
3. [Installation and Running](#installation-and-running)
4. [Gameplay](#gameplay)
5. [Implemented Design Patterns](#implemented-design-patterns)
6. [Code Structure](#code-structure)
7. [Requirements](#requirements)
8. [Author](#author)

## 🎯 Project Description

**Pacman** is a modern implementation of the classic Pacman game, developed as an educational project to study advanced C++ programming techniques. The project demonstrates the application of 8 key design patterns in the context of a game engine.

### 🎮 Key Features:
- **Application States**: Menu, Game, Exit
- **Dynamic Maze Generation**: Simple and complex levels
- **Entity System**: Pacman, enemies, food with different behaviors
- **Graphical Interface**: Buttons, menus, animations via SFML
- **Action Undo System**: Revert to previous game states

## 🏗️ Project Architecture

### 1. **State Machine (State Pattern)**
The core application mechanism is a finite state machine with three states:
- **`SelectState`**: Level selection menu
- **`GameState`**: Gameplay
- **`ExitState`**: Application termination

Each state implements the `IState` interface with a `do_step()` method, and `Application` manages transitions between states via `IStateManager`.

### 2. **Window Management (Multiple Inheritance)**
`SelectState` and `GameState` inherit from both `IState` and `IWindowKeeper`, allowing them to function as application states while also owning SFML windows.

### 3. **Graphical Interface (Composite + Command Patterns)**
- **`Menu`** contains **`Button`** (Composite)
- Buttons execute **`ISelectCommand`** (Command)
- Separation of UI from business logic

### 4. **Maze and Entities (Visitor Pattern)**
- **`Maze`** consists of **`Room`** with **`IRoomSide`** (Pass/Wall)
- **`IEntity`** (Pacman, Enemy, Food) interact through **`IVisitor`**
- Dynamic entities have an `action()` method

### 5. **Game Context (Prototype Pattern)**
- **`GameContext`** stores the game state
- Entities are cloned via `clone()` for history preservation
- **`ContextManager`** manages the state stack

### 6. **Level Generation (Builder Pattern)**
- **`GameBuilderDirector`** manages builders
- **`SimpleBuilder`** and **`ComplexBuilder`** create different mazes
- **`CommonBuilder`** contains common logic

### 7. **Game Events (Command Pattern)**
- **`IGameEvent`** (DeleteStaticEntity, LostGame)
- Collision handling through events
- Context modification via `handle()`

### 8. **Game Loop (Template Method Pattern)**
- `event_handling()` → `update()` → `render()`
- Rendering preparation via `IPrepareable`
- Control via WASD, action undo via Ctrl+Z

## 🚀 Installation and Running

### Requirements:
- **C++17**
- **CMake 3.0+**
- **SFML 3.0.2**

### Quick Start:
```bash
# 1. Clone the repository
git clone https://github.com/qaplwso7/pacman.git
cd pacman

# 2. Build the project
# [Add build commands here based on your platform]

# 3. Run
./Pacman  # or Pacman.exe on Windows
```

### For Developers:
```bash
# [Add development build/run commands here]
```

## 🎮 Gameplay

### Controls:
- **WASD** or **Arrow Keys** — Move Pacman
- **ESC** — Return to menu
- **Ctrl+Z** — Undo last action
- **Left Click** — Menu selection

### Difficulty Levels:
1. **Easy**: Simple maze, no enemies
2. **Hard**: Complex maze, with enemies

### Mechanics:
- **Collect Food**: Eat dots to complete the level
- **Avoid Enemies**: Collision = game over
- **Undo Actions**: Step back if you make a mistake
- **Dynamic Camera**: Follows Pacman

## 🏆 Implemented Design Patterns

| Pattern | Implementation | Purpose |
|---------|----------------|---------|
| **State** | `IState`, `Application` | Application state management |
| **Composite** | `Menu` → `Button` | UI element hierarchy |
| **Command** | `ISelectCommand`, `IGameEvent` | Decoupling UI and logic |
| **Singleton** | `MyFont` | Single access point for fonts |
| **Builder** | `IGameBuilder`, `Director` | Level generation |
| **Prototype** | `IEntity::clone()` | Entity cloning |
| **Visitor** | `IVisitor`, `Pacman` | Collision handling |
| **Template Method** | `IPrepareable` | Render preparation |

## 📁 Code Structure

```
pacman/
├── application/          # Application core
│   ├── core/            # State Machine
│   ├── states/          # Concrete states
│   └── IWindowKeeper.h  # Window interface
├── ui/                  # User Interface
│   ├── Button.*         # Buttons
│   ├── Menu.*           # Menu
│   └── commands/        # Commands
├── game/                # Game logic
│   ├── maze/            # Maze
│   ├── entities/        # Entities
│   ├── context/         # Game context
│   ├── builder/         # Level builders
│   └── visitor/         # Visitor for collisions
├── utils/               # Utility classes
│   ├── MyFont.*         # Font Singleton
│   ├── config.h         # Configuration
│   └── ContextManager.* # State manager
├── assets/              # Resources
│   ├── fonts/           # Fonts
│   └── textures/        # Textures
├── tests/               # Unit tests
├── docs/                # Documentation
├── CMakeLists.txt       # Build configuration
└── README.md            # This file
```

### Contacts
- **GitHub**: https://github.com/qaplwso7
- **Repository**: https://github.com/qaplwso7/pacman.git

### Implementation Highlights:
- ✅ Modern C++17 (smart pointers, RAII)
- ✅ Clean Architecture (SOLID principles)
- ✅ Unit Testing
- ✅ Detailed Documentation
- ✅ Cross-Platform

## 📄 License

This project is created for educational purposes at HSE (Higher School of Economics).

