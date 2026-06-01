# 0042 — Environment Variables

Read the environment variable `LESSON_ENV_VAR`, falling back to `default` when it is unset, and print `value: default`. `getenv` returns a pointer to the value or `NULL` when the variable is absent, so a null check selects the default. The returned string must not be modified.

## Run

    make && ./env
