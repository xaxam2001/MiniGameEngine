<<<<<<< HEAD
# Real-Time Engine & Computational Geometry Simulation

A modular C++ real-time engine prototype designed to simulate and visualize 3D computational geometry algorithms, featuring dynamic point cloud generation, 3D Incremental Convex Hull, and 3D Delaunay Triangulation.

---

## Features

- **Decoupled Architecture:** Core simulation, timing, input polling, and OpenGL rendering run through a context-driven structure.
- **Fixed-Step Simulation:** Support for stable `FixedUpdate` physics/simulation steps decoupled from render framerate.
- **Computational Geometry (WIP / Upcoming):**
  - Dynamic 3D point cloud generation and visualization.
  - Incremental 3D Convex Hull.
  - 3D Delaunay Triangulation & Tetrahedralization.

---

## Tech Stack & Prerequisites

- **Language:** C++17 or C++20
- **Rendering:** OpenGL
- **Windowing & Extensions:** GLFW3, GLEW
- **Math:** GLM (recommended)
- **Dependency Manager:** [vcpkg](https://github.com/microsoft/vcpkg)
- **IDE / Build System:** JetBrains Rider or Visual Studio (MSBuild / `.sln`)

---

## Project Structure

```text
.
├── YourProject.sln
└── YourProject/
    ├── YourProject.vcxproj
    ├── assets/              # Shaders, config files, and point data
    ├── include/             # Public header files (.h)
    │   ├── Core/            # EngineContext, InfraStructure, Utils
    │   ├── Input/           # Input handling (GLFW integration)
    │   ├── Math/            # Point cloud, Convex Hull, Delaunay
    │   ├── Render/          # Buffers, shaders, and renderers
    │   └── Time/            # Timer and Clock systems
    └── src/                 # Implementation files (.cpp)
        ├── main.cpp         # Application entry point
        ├── Core/
        ├── Input/
        ├── Math/
        ├── Render/
        └── Time/
```

---

## Getting Started

### 1. Install Dependencies with vcpkg

Ensure `vcpkg` integration is activated for your MSBuild tools:

```bash
vcpkg integrate install
```

### 2. Open and Build

1. Open `YourProject.sln` in **JetBrains Rider** (or Visual Studio).
2. Select your build target configuration (e.g., `Debug | x64` or `Release | x64`).
3. Build the solution (`Ctrl + Shift + B`).
4. Run the application (`F5` or `Shift + F10`).
=======
# MiniGameEngine
Real-Time Engine &amp; Computational Geometry Simulation
>>>>>>> a85baf3bc8d02bb12b0a7d2bd2929054a20c8f53
