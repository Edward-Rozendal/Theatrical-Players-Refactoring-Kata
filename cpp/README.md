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
