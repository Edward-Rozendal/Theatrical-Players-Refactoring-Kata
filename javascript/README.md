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

## 4: Extract right-hand side of assignment to variable play into function playFor
- Replace Temp with Query (178)
- Get rid of temporary variables like ```play``` because they create a lot
  of locally scoped names that complicate extractions.

## 5: Replace temporary variable play by a call to function playFor
- Inline Variable (123)
- The code to look up the play is now executed thrice, but this is unlikely to
  significantly affect performance. Even if it were, it is much easier to
  improve performance of a well-factored code base.

## 6: Use function playFor inside function amountFor instead of parameter play
- Replace Temp with Query (178)
- By using function ```playFor```, parameter ```play``` is no longer needed.

## 7: Delete parameter play from function amountFor
- Change Function Declaration (124)

## 8: Replace temporary variable thisAmount by a call to function amountFor
- Inline Variable (123)

## 9: Extract function volumeCreditsFor
- Extract Function (106)
- Extract the volume credits calculation of a performance.
- The variable ```perf``` is used but not modified, so it can be passed as
  a parameter.
- ```volumeCredits``` is a bit more tricky as it is an accumulator updated
  in each pass. The best bet is to initialize a shadow of it inside the
  extracted function and return it.

## 10: Rename variable volumeCredits, in function volumeCreditsFor, to result
- Rename Variable (137)
- This is a personal convention to make it clearer. It makes its role, the
  return value from a function, always known.

## 11: Rename parameter perf, of function volumeCreditsFor, to aPerformance
- Rename Variable (137)
- With a dynamically typed language it is usefull to keep track of types.

## 12: Replace function variable format with a declared function
- Although this is a refactoring, it isn't named and included in the catalog
  as it is not important enough for that.

## 13: Rename function format to usd
- Change Function Declaration (124)
- The name ```format``` doesn't really convey enough of what it's doing.
- ```formatAsUSD``` would be a bit too long-winded since it's being used in a
  string template.
- Also move the duplication devision by 100 into the function as storing money
  as integer cents is a common approach.

## 14: Separate the accumulation of volumeCredits in function statement
- Split Loop (227)

## 15: Move the declaration of volumeCredits next to the loop.
- Slide Statements (223)
