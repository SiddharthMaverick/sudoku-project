# Fullstack Sudoku Solver

A modern, containerized fullstack Sudoku application. This project features a lightning-fast C++ backend API for generating and solving Sudoku puzzles and a clean, vanilla JavaScript frontend for interactive gameplay.

## 🚀 Features

- **C++ Backend Engine**: A highly optimized Sudoku engine written in C++17, exposed as a REST API using the [Crow](https://crowcpp.org/) microframework.
- **Vanilla JS Frontend**: A lightweight, responsive, and intuitive web UI built without heavy frameworks. 
- **Dockerized Architecture**: Fully containerized setup via Docker and Docker Compose, utilizing Nginx as a reverse proxy for seamless API routing.
- **RESTful Endpoints**: Simple JSON-based API to instantly generate and solve Sudoku puzzles.

## 🛠️ Tech Stack

- **Backend**: C++, Crow, CMake
- **Frontend**: HTML5, CSS3, Vanilla JavaScript
- **Deployment**: Docker, Docker Compose, Nginx (Alpine)

## 📦 Getting Started

### Prerequisites
Make sure you have the following installed on your machine:
- [Docker](https://docs.docker.com/get-docker/)
- [Docker Compose](https://docs.docker.com/compose/install/)

### Running the Project

Running the entire stack is as simple as a single command. Docker will automatically build the C++ backend using an Alpine builder image, set up Nginx, and serve the frontend.

1. Clone the repository:
   ```bash
   git clone https://github.com/SiddharthMaverick/sudoku-project.git
   cd sudoku-project
   ```

2. Start the services using Docker Compose:
   ```bash
   docker-compose up -d --build
   ```

3. Open your browser and navigate to:
   **http://localhost/**

To stop the containers, run:
```bash
docker-compose down
```

## 🔌 API Documentation

If you want to interact with the backend directly (or build your own client), the Nginx proxy exposes the following endpoints at `http://localhost/api/`:

### `GET /api/generate`
Generates a new, random Sudoku puzzle.

**Response (200 OK)**
```json
{
  "board": [
    [8, 9, 0, 6, 7, 1, 3, 0, 0],
    [4, 6, 2, 3, 9, 5, 0, 0, 7],
    ...
  ]
}
```
*(Zeros represent empty cells)*

### `POST /api/solve`
Solves a given Sudoku puzzle.

**Request Body**
Provide the `board` matrix you want to solve.
```json
{
  "board": [
    [8, 9, 0, 6, 7, 1, 3, 0, 0],
    [4, 6, 2, 3, 9, 5, 0, 0, 7],
    ...
  ]
}
```

**Response (200 OK)**
Returns the fully solved grid.
```json
{
  "board": [
    [8, 9, 5, 6, 7, 1, 3, 4, 2],
    [4, 6, 2, 3, 9, 5, 1, 8, 7],
    ...
  ]
}
```
*(Returns a `400 Bad Request` if the puzzle is unsolvable or the format is invalid)*

## 📂 Project Structure

```text
sudoku-project/
├── CMakeLists.txt          # Root CMake configuration
├── docker-compose.yml      # Orchestrates backend and frontend containers
├── Dockerfile.backend      # Multi-stage C++ build and runtime image
├── engine/                 # Core C++ Sudoku generator and solver logic
├── apps/
│   ├── sudoku-api/         # Crow HTTP API implementation
│   └── sudoku-cli/         # Legacy CLI implementation
├── frontend/               # Vanilla JS Web UI
│   ├── index.html
│   ├── style.css
│   ├── app.js
│   ├── nginx.conf          # Nginx reverse proxy configuration
│   └── Dockerfile          # Nginx container image
└── third_party/            # Submodules/Dependencies (e.g., Crow)
```

## 📄 License

This project is licensed under the MIT License.
