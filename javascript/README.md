Theatrical Players in Javascript
================================

For exercise instructions see [top level README](../README.md).

To run tests:

    npm install
    npm test

The tests use the ```Jest``` testing framework with the *approval testing*
approach:

```expect(statement(invoice, plays)).toMatchSnapshot();```

It means Jest is taking the output of ```statement(invoice, plays)``` ,
saving it as a snapshot (in ```__snapshots__/statement.test.js.snap```),
and comparing it against the previously saved snapshot. If the output changes,
the test fails.


## 1: Extract function amountFor
- Extract Function (106)
- Extract the switch statement in the middle to function ```amountFor```.
- The variables ```perf``` and ```play``` are used but not modified, so they
  can be passed as parameters.
- There is only one variable modified ```thisAmount```, so it can be returned.

## 2: Rename variable thisAmount, in function amountFor, to result
- Rename Variable (137)
- This is a personal convention to make it clearer. It makes its role, the
  return value from a function, always known.

## 3: Rename parameter perf, of function amountFor, to aPerformance
- Rename Variable (137)
- With a dynamically typed language it is usefull to keep track of types.
