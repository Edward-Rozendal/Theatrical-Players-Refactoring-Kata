Theatrical Players Refactoring Kata - C++ version
========================================================

See the [top level readme](https://github.com/emilybache/Theatrical-Players-Refactoring-Kata) for general information about this exercise.

## Dependencies

The tests use the following header-only projects, which are in the `third_party` sub-directory:

| Project | Licence |
| --- | --- |
| [doctest test framework](https://github.com/onqtam/doctest) | [MIT](https://github.com/onqtam/doctest/blob/master/LICENSE.txt) |
| [ApprovalTests.cpp](https://github.com/approvals/ApprovalTests.cpp) | [Apache 2.0](https://github.com/approvals/ApprovalTests.cpp/blob/master/LICENSE) |
| [JSON for Modern C++](https://github.com/nlohmann/json) | [MIT](https://github.com/nlohmann/json/blob/develop/LICENSE.MIT) |

## Build and Run

Generate build files:
```
$ cmake -S . -B build/debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
```

Build:
```
$ cmake --build build/debug
```

Run test:
```
$ ctest --test-dir build/debug
```

# Stage 1 - Decomposing the original function
- The focus is adding enough structure so it easier to understand and to see
  it in terms of its logical parts.

## 1: Extract function amountFor
- Extract Function (106)
- Extract the if statements in the middle to function ```amountFor```.
- The variables ```perf``` and ```play``` are used but not modified, so they
  can be passed as parameters.
- There is only one variable modified ```this_amount```, so it can be returned.

## 2: Rename variable this_amount, in function amountFor, to result
- Rename Variable (137)
- This is a personal convention to make it clearer. It makes its role, the
  return value from a function, always known.

## 3: Rename parameter perf, of function amountFor, to performance
- Rename Variable (137)

## 4: Extract right-hand side of assignment to variable play into function playFor
- Replace Temp with Query (178)
- Get rid of temporary variables like ```play``` because they create a lot
  of locally scoped names that complicate extractions.

## 5: Replace temporary variable play by a call to function playFor
- Inline Variable (123)
- The code to look up the play is now executed thrice, but this is unlikely to
  significantly affect performance. Even if it were, it is much easier to
  improve performance of a well-factored code base.

## 6: Extract function volumeCreditsFor
- Extract Function (106)
- Extract the volume credits calculation of a performance.
- The variables ```perf``` and ```play``` are used but not modified, so they
  can be passed as parameters.
- ```volume_credits``` is a bit more tricky as it is an accumulator updated
  in each pass. The best bet is to initialize a shadow of it inside the
  extracted function and return it.

## 7: Rename variable volume_credits, in function volumeCreditsFor, to result
- Rename Variable (137)
- This is a personal convention to make it clearer. It makes its role, the
  return value from a function, always known.

## 8: Rename parameter perf, of function volumeCreditsFor, to performance
- Rename Variable (137)

## 9: Separate the accumulation of volumeCredits in function statement
- Split Loop (227)

## 10: Move the declaration of volume_credits next to the loop
- Slide Statements (223)

## 11: Extract function totalVolumeCredits
- Extract Function (106)
- Extract the total volume credits calculation.

## 12: Rename variable volume_credits, in function totalVolumeCredits, to result
- Rename Variable (137)
- This is a personal convention to make it clearer. It makes its role, the
  return value from a function, always known.

## 13: Replace temporary variable volume_credits by a call to function totalVolumeCredits
- Inline Variable (123)

## 14: Replace temporary variable this_amount by a call to function amountFor
- Inline Variable (123)

## 15: Separate the accumulation of total_amount in function statement
- Split Loop (227)
