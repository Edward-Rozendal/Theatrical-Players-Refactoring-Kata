Theatrical Players in Javascript
================================

For exercise instructions see [top level README](../README.md).

To run tests:

    npm install
    npm test

## Refactoring 1: Extract Function (106)
- Extract the switch statement in the middle.
- The variables ```perf``` and ```play``` are used but modified,
  so they can be passed as parameters.
- There is only one variable modified ```thisAmount```, so it can be returned.
