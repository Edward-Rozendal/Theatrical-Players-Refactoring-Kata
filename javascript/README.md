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

## 16: Extract function totalVolumneCredits
- Extract Function (106)
- Extract the total volume credits calculation.

## 17: Replace temporary variable volumeCredits by a call to function totalVolumneCredits
- Inline Variable (123)

## 18: Separate the accumulation of totalAmount in function statement
- Split Loop (227)

## 19: Move the declaration of totalAmount next to the loop
- Slide Statements (223)

## 20: Extract function to calculate total amount
- Extract Function (106)
- Extract the total amount calculation.
- The best name for the function is ```totalAmount```, but as that is already
  the name of the variable, give the new function a random name.

## 21: Replace temporary variable totalAmount by a call to function to calculate total amount
- Inline Variable (123)

## 22: Rename function to calculate total amount to totalAmount
- Change Function Declaration (124)

## 23: Rename variable totalAmount, in function totalAmount, to result
- Rename Variable (137)
- This is a personal convention to make it clearer. It makes its role, the
  return value from a function, always known.

## 24: Rename variable volumeCredits, in function totalVolumneCredits, to result
- Rename Variable (137)
- This is a personal convention to make it clearer. It makes its role, the
  return value from a function, always known.

## 25: Extract function renderPlainText
- Extract Function (106)
- So far the refactoring has focussed on adding enough structure to the
  functions so that I can understand it and see it in terms of its logical
  parts.
- Now I can begin to focus more on the functionality change: providing an
  HTML version.
- I want the same calculation functions to be used by the text and HTML
  version of the statement.
- Start a Split Phase (154) by applying Extract Function (106) to the code
  that makes up the second phase.

## 26: Add the itermediate data structure statementData
- Create an object that will act as an intermediate data structure between
  the two phases.
- Pass this object in as argument to ```renderText```.

## 27: Add customer to statementData
- I want to move the data that comes from the other arguments used by
  ```renderPlainText``` into the intermediate data structure
- All the calculation code should move into the ```statement``` function so
  ```rederPlainText``` operates soley on data passed to it through the
  ```data``` parameter.
- The first move is to take the customer and add it to itermediate object.

## 28: Add performances to statementData
- Adding performances to the intermediate object allows deleting the
  ```invoices``` parameter to ```renderPlainText```.

## 29: Enrich performance with data from the play
- I like the play name to come from the intermediate data.
- Making a copy of the performance object is the first step.
- I take a shallow copy because I don't want to modify the data passed to the
  function.

## 30: Enrich performance with playFor
- Now I have a spot for the play, I needd to add it.
- I want to apply Move Function (198) to move ```playFor``` from
  ```renderPlainText``` to ```statement```, but as ```playFor``` is still used
  by ```renderPlainText```, the first step is using a copy.

## 31: Use play from statementData
- The second step in Move Function (198) to move ```playFor``` to
  ```statement``` is replacing all the references to ```playFor``` in
  ```renderPlainText``` to use the data instead.

## 32: Enrich performance with amountFor
- Move Function (198)
- Move ```amountFor``` to ```statement```.
- Add ```amountFor``` in ```enrichPerformance```.
- Replace all the references to ```amountFor``` in ```renderPlainText``` to
  use the data instead.

## 33: Enrich performance with volumeCreditsFor
- Move Function (198)
- Move ```volumeCreditsFor``` to ```statement```.
- Add ```volumeCreditsFor``` in ```enrichPerformance```.
- Replace all the references to ```volumeCreditsFor``` in ```renderPlainText```
  to use the data instead.

## 34: Move the two calculations of the total to function statement
- Move Function (198)
- Move ```totalAmount``` and ```totalVolumneCredits``` to ```statement```.
- Pass the statement data as explicit parameter.

## 35: Replace data.performances loops by pipeline operation
- Replace Loop with Pipeline (231)
- Replace ```data.performances``` loops in ```totalAmount``` and
  ```totalVolumneCredits``` by ```reduce``` pipeline operation.

## 36: Extract all first-phase code into its own function
- Extract function ```createStatementData```.

## 37: Move all first-phase code to its own file
- Move ```createStatementData``` to file ```createStatementData.js```.
- Rename ```statementData``` to ```result``` to match personal convention.

## 38: Add HTLM version of statement
- Add function ```htmlStatement```.
- Move function ```usd``` up so that ```renderHtml``` can use it.
- Add a test for ```htmlStatement```.

# Reorganizing the Calculations by Type
- The next feature is supporting more categories of plays, each with its
  own charging and volume credit calculations.
- The natural approach is type polymorphism.
- The overall plan is to set up an inheritance hierarchy with ```comedy``` and
  ```tragedy``` subclasses that contain the calculation logic for those cases.
- A similar structure will be made for the volume credits calculation.

## 39: Create a performance calculator
- The ```enrichPerformance``` function is the key since it populates the
  intermediate data structure with the data for each performance.
- Currently, it calls the conditional functions for amount and volume
  credit. Those functions should be called on a host class.
- As the class hosts functions for calculating data about performances
  it is named ```PeformanceCalculator```.

## 40: Pass the performance play into the performance calculator
- Change Function Declaration (124)
- Moving the play record into the performance calculator is not needed, as
  it's not varying polymorphically, but by keeping all data transforms in
  one place, the code will be cleaner.

## 41: Copy calculating the amount for a performance to the performance calculator
- First part of: Move Function (198)
- Can run Babel to catch any syntax errors in the new function - but little
  more than that.

## 42: Make amountFor a delegating function to the performance calculator
- Take the original function ```amountFor``` and turn in into a delegating
  function so it calls the new function.

## 43: Replace calling amountFor by getting the amount from the performance calculator
- Inline Function (115)

## 44: Copy calculating the volume credits for a performance to the performance calculator
- First part of: Move Function (198)
- Can run Babel to catch any syntax errors in the new function - but little
  more than that.

## 45: Make volumeCredits a delegating function to the performance calculator
- Take the original function ```volumeCredits``` and turn in into a delegating
  function so it calls the new function.

## 46: Replace calling volumeCredits by getting the volume credits from the performance calculator
- Inline Function (115)

## 47: Replace PeformanceCalculator constructor call with function createPerformanceCalculator
- Replace Constructor with Factory Function (334)
