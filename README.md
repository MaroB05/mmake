# mmake (Maro Make)

## "We have Make at home"

Ever been stuck without GNU Make and thought, "I could just build this myself"? Well, that's exactly what happened here. mmake is a minimalist Make alternative born out of necessity during a trip with limited internet access. It's not fancy, it's not feature-complete, but it gets the basic job done when you need to run simple Makefiles.

## Scope

mmake is a lightweight implementation of the core functionality of GNU Make:
- Parse a Makefile
- Execute commands associated with a specified target
- Support for basic directory navigation
- Bonus: you can run a Makefile without being in the same directory as the file.

What mmake is NOT:
- A complete replacement for GNU Make
- Supporting complex features like variables, pattern rules, or prerequisites
- Handling dependencies between targets

## Installation

### Prerequisites
- A C compiler (gcc, clang, etc.)
- Standard C libraries

### Building from source

```bash
git clone https://github.com/your-username/mmake.git
cd mmake
gcc -o mmake main.c -Wall -Werror
```

### Installing system-wide (optional)

```bash
sudo cp mmake /usr/local/bin/
```

## Usage

```
mmake command [path]
```

Where:
- `command` is the target in your Makefile you want to execute
- `[path]` is an optional path to the directory containing the Makefile (defaults to current directory)

### Example Makefile

```makefile
build:
	gcc -o myprogram main.c
	echo "Build completed!"

clean:
	rm -f myprogram
	echo "Cleaned up!"
```

### Running mmake

```bash
# Execute the "build" target in current directory
mmake build

# Execute the "clean" target in a specific directory
mmake clean /path/to/project
```

## How it works

mmake searches for a Makefile in the specified directory, locates the requested target, and executes the tab-indented commands that follow it until it reaches another target (line ending with a colon) or the end of the file.

## Limitations

- mmake does not handle dependencies between targets
- No support for variables or pattern rules
- Very basic error handling
- Tab indentation is strictly enforced

## Contributing

Feel free to fork, submit PRs, or suggest improvements. This was created as a personal project in a pinch, but contributions are welcome!
