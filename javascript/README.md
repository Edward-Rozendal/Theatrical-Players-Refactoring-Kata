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

## Refactoring 2: Rename Variable (137)
- Rename ```thisAmount```, in function ```amountFor```, to ```result``` to make it clearer. It makes its role, the return value from a function, always known.
- Rename the first argument ```perf``` to ```aPerformance```. With a dynamically typed lannguage it is usefull to keep track of types.

## Refactoring 3: Replace Temp with Query (178)
- Get rid of temporary variables like ```play``` because they create a lot of locally scoped names that complicate extractions.
- Begin with extracting the right hand side into a function.
