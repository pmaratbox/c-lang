# 0010 — Structs

Define a `Person` struct with a `name` and an `age`, create one ("Ada", 36),
and print each field. `struct Person { ... }` groups fields; a positional
initializer `{"Ada", 36}` fills them in declaration order (designated
initializers `{.name = "Ada", .age = 36}` are clearer). Fields are read with the
`.` operator.

## Run

    make && ./structs
