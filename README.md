# C Project Generator

The C Project Generator is a command-line tool designed to streamline the process of starting new C projects. With just a few simple commands, you can create a basic project structure, complete with necessary files and folders.

## Prerequisites

- CMake
- Make
- Unix-based operating system

## Installation

1. Clone the repository to your local machine:

```bash
git clone https://github.com/your_username/c-project-generator.git
```

2. Navigate to the project directory:

```bash
cd c-project-generator
```

3. Build the project using CMake:

```bash
cmake .
```

4. Compile the project with Make:

```bash
make
```

5. (Optional) Add the executable to your system PATH for easier access:

```bash
sudo cp cgen /usr/local/bin
```

## Usage

To use the C Project Generator, follow these simple steps:

1. Open a terminal window.

2. Run the following command to generate a new C project:

```bash
cgen --name your_project_name
```

Replace `your_project_name` with the desired name for your project.

3. Once the command is executed, a new folder will be created in the current directory with the specified project name. Inside this folder, you will find the following files and folders:

- `.gitignore`: A file containing patterns to ignore when using Git version control.
- `CMakeLists.txt`: The CMake build script for your project.
- `src/`: A folder containing your project's source code files.
- `lib/`: A folder for any external libraries your project may depend on.
- `include/`: A folder for header files.
- `main.c`: A basic C source file to get you started.

## Contributing

If you encounter any issues with the C Project Generator or have suggestions for improvements, please feel free to open an issue or submit a pull request on GitHub.

## License

This project is licensed under the MIT License.