# c-lang

Incremental lessons learning C.

## Prerequisites

- A C compiler (Clang or GCC)
- `make`

### Install

- macOS: `xcode-select --install` (installs Apple Clang + make)
- Debian / Ubuntu: `sudo apt install build-essential` (installs GCC + make)
- Fedora: `sudo dnf groupinstall "Development Tools"`

### Verify

    cc --version && make --version

## Lessons

- [0001-hello-world](0001-hello-world/) — print "Hello, world!"
- [0002-variables-and-types](0002-variables-and-types/) — declare and print an int, float, string, and bool
- [0003-arithmetic-and-operators](0003-arithmetic-and-operators/) — sum, difference, product, quotient, modulo of two integers
- [0004-conditionals](0004-conditionals/) — compare to 10 and print less / equal / greater
- [0005-loops](0005-loops/) — print 1..5 with a for-loop
- [0006-functions](0006-functions/) — define add(a, b), call it, print the result
- [0007-collections](0007-collections/) — build a list of 1..5; print its count, first, and last

## How to run

See each lesson's `README.md` for the exact command.
