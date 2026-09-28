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

## Refactoring 4: Inline Variable (123)
- Next is replacing the tempporary variable ```play``` by a function call.
- The code to look up the play is now executed thrice, but this is unlikely to significantly affect performance.
Even if it were, it is much easier to improve performance of a well-factored code base.

## Refactoring 5: Change Function Declaration (124) - step 1
- The ```play``` parameter can be removed from ```amountFor```.
- Step 1 is using the new function inside ```amountFor```.

## Refactoring 6: Change Function Declaration (124) - step 2
- Step 2 is deleting the parameter.

## Refactoring 7: Inline Variable (123)
- While done with the arguments of ```amountFor```, look back where it's called.
- It's being used to set a temporary variable that's not updated again, so inline it.
- Note: ```playFor``` is now called 6 times in each loop iteration.

## Refactoring 8: Extract Function (106)
- Extract volume credits.
- As it is an accumulator updated in each pass, the best bet is to initialize a shadow
of it inside the extracted function and return it.

## Refactoring 9: Rename Variable (137)
- Rename the variables inside the function to make them clearer and consistent ```amountFor```.

## Refactoring 10: Change a function variable to a declared function
- Although this is a refactoring, it isn't named and included in the catalog as it is not important enough for that.
- ```format``` is a case of assigning a function to a temp.

## Refactoring 11: Change Function Declaration (124)
- The name ```format``` doesn't really convey enough of what it's doing.
- ```formatAsUSD``` would be a bit too long-winded since it's being used in a string template.
- Also move the duplication devision by 100 into the function as storing money as integer cents
is a common approach.

## Refactoring 12: Split Loop (227)
- The next target is variable ```volumeCredits```.
- It's build up during the iteration of the loop.
- Use split loop to separate the accumulation of ```volumeCredits```.

## Refactoring 13: Slide Statements (223)
- Move the declaration of ```volumeCredits``` next to the loop.

## Refactoring 14: Extract Function (106)
- Apply Extract Fuction to the the overall calculation of ```volumeCredits```.

## Refactoring 16: Inline Variable (123)
- The extracted function ```totalVolumneCredits``` is only being used to set a temporary variable that's not updated again, so inline it.

## Refactoring 17: Extract Function (106)
- Extract total amount.
- The best name for the function is ```totalAmount```, but as that is already the name
of the variable, give the new function a random name.

## Refactoring 18: Inline Variable (123)
- Inline variable ```totalAmount```.

## Refactoring 19: Change Function Declaration (124)
- Rename the function with a random name to ```totalAmount```.

## Refactoring 20: Rename Variable (137)
- Rename the variables inside the extracted function to adhere to the used convention.

## Refactoring 21: Extract Function (106)
- So far the refactoring has focussed on adding enough structure to the functions so
that I can understand it and see it in terms of its logical parts.
- Now I can begin to focus more on the functionality change: providing an HTML version.
- I want the same calculation functions to be used by the text and HTML version of the statement.
- Start a Split Phase (154) by applying Extract Function to the code that makes up the second phase.

## Refactoring 22: Add an itermediate data structure
- Create an object that will act as an intermediate data structure between the two phases.
- Pass this object in as argument to ```renderText```.

## Refactoring 23: Add customer to the itermediate object
- Examine the other arguments used by ```renderPlainText```.
- All the calculation code should move into the ```statement``` function so ```rederPlainText```
operates soley on data passed to it through the ```data``` parameter.
- The first move is to take the customer and add it to itermediate object.

## Refactoring 24: Add performances to the itermediate object
- Adding performances to the intermediate object allows deleting the ```invoices```
parameter to ```renderPlainText```.

## Refactoring 25: Enrich performance with data from the play
- I like the play name to come from the intermediate data.
- Making a copy of the performance object is the first step.
- I take a shallow copy because I don't want to modify the data passed to the function.

## Refactoring 26: Enrich performance with playFor.
- Now I have a spot for the play, I needd to add it.
- I need to apply Move Function (198) to ```playFor``` and ```statement```.
- As ```playFor``` is still used by ```renderPlainText```, the first step is using a copy.

## Refactoring 27: Use play from data
- Replace all the references to ```playFor``` in ```renderPlainText``` to use the data instead.
