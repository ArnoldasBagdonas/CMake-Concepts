/*
MIT License

Copyright (c) 2023 Arnoldas Bagdonas

Permission is hereby granted, free of charge, to any person obtaining a copy of this
software and associated documentation files (the "Software"), to deal in the Software
without restriction, including without limitation the rights to use, copy, modify,
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be included in all copies
or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Reference List:

- https://spdk.io/doc/version_8h.html#a044fb88313d084d910632cea5a06c620
- https://stackoverflow.com/questions/11697820/how-to-use-date-and-time-predefined-macros-in-as-two-integers-then-stri
*/

#pragma once

extern const int PROJECT_VERSION_MAJOR;
extern const int PROJECT_VERSION_MINOR;
extern const int PROJECT_VERSION_PATCH;

extern const char PROJECT_NAME[];
extern const char PROJECT_GIT_COMMIT_ID[];
extern const char PROJECT_BUILD_MACHINE[];
extern const char PROJECT_GIT_REPOSITORY_URL[];
extern const char PROJECT_BUILD_DATE_TIME[];
extern const char PROJECT_VERSION_STRING[];

// Single numeric value representing a version number for compile-time comparisons.
// Example usage:
//
// #if PROJECT_VERSION >= PROJECT_VERSION_NUM(17, 7, 0)
//   Use feature from PROJECT v17.07
// #endif
#define PROJECT_VERSION_NUM(major, minor, patch)    (((major) * 100 + (minor)) * 100 + (patch))

// Current version as a PROJECT_VERSION_NUM.
#define PROJECT_VERSION   PROJECT_VERSION_NUM(PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH)

// Human-readable version string.
extern const char PROJECT_VERSION_STRING[];

