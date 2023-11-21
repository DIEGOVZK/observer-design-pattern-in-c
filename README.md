# observer-design-pattern-in-C
This project is an example of the observer design pattern in C. It demonstrates how to create a subject that notifies its observers when its state changes.

![Project Logo](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/doc/hfsh8jwdcdbsfu.jpeg)

## 🤖 Technologies Used

- [C](https://en.wikipedia.org/wiki/C_(programming_language)) - A general-purpose, procedural computer programming language.
- [CMake](https://cmake.org) - An open-source, cross-platform family of tools designed to build, test and package software.
- [Unity](https://github.com/ThrowTheSwitch/Unity/tree/master) - A test framework for C with support for mock objects, test discovery, and detailed test reporting.

## 📝 File structure

```md
|-- include/          // Header files (.h)
|   `-- _.h
|-- src/              // Source files (.c)
|   `-- main.c
|-- test/             // Test files and test data
|   `-- _.test.c
|-- build/            // Compiled binaries and object files
|-- doc/              // Documentation
|-- scripts/          // Build and utility scripts
|-- CMakeLists.txt    // CMake build configuration
|-- README.md         // Project documentation
|-- .gitignore        // Git ignore file
```

## 🛠️ [CMake Script](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/CMakeLists.txt)

This project uses CMake as a build system and dependency manager. Here's what the CMake script does:

1. It sets the minimum required version of CMake to 3.12 and names the project `observer-design-pattern-in-c`.

2. It uses the `FetchContent` module to download the Unity test framework from its GitHub repository.

3. It sets the `SOURCES` variable to the list of source files in the project.

4. It sets the `TESTS` variable to the list of test files in the project.

5. For each test file, it creates an executable target that includes the test file and the source files. It links the Unity library to the target and sets the include directories for the target.

6. It creates an executable target for the main application that includes the main file and the source files. It links the Unity library to the target and sets the include directories for the target.

7. It creates a custom target `run_tests` that builds and runs all the tests. This target depends on all the test targets.

## 📄 [Scripts](https://github.com/DIEGOVZK/observer-design-pattern-in-c/tree/main/scripts)

This project uses several scripts to automate common tasks. Here's what each script does:

### [build.sh](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/scripts/build.sh)

This script is used to build the project. Here's what it does:

1. Creates a `build` directory at the project root.
2. Changes the current directory to the `build` directory.
3. Runs `cmake` to generate Makefiles.
4. Runs `make` to build the project using the generated Makefiles.

### [clean.sh](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/scripts/clean.sh)

This script is used to clean the build files from the project. Here's what it does:

1. Removes all files from the `build` directory at the project root.

### [run_tests.sh](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/scripts/run_tests.sh)

This script is used to run the tests for the project. Here's what it does:

1. Creates a `build` directory at the project root.
2. Changes the current directory to the `build` directory.
3. Runs `cmake` to generate Makefiles.
4. Runs `make` to build the project using the generated Makefiles.
5. Runs `make run_tests` to execute the tests.


## 🧪 [Test Scripts](https://github.com/DIEGOVZK/observer-design-pattern-in-c/tree/main/test)

This project uses several test scripts to verify the functionality of the different components. Here's what each test script does:

### [wordCounter.test.c](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/test/wordCounter.test.c)

This script tests the functionality of the `wordCounter` component. It includes tests for counting total words, even length words, and words that start with a capital letter in a sentence. It also includes adverse tests where the input is not a typical sentence.
> 6 Tests 0 Failures 0 Ignored  
> OK

### [subject.test.c](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/test/subject.test.c)

This script tests the functionality of the `subject` component in the Observer design pattern. It includes tests to verify that the `attach`, `detach`, and `notify` functions are not null. It also includes a test to verify that the observer count is zero when a `subject` is initialized.
> 4 Tests 0 Failures 0 Ignored  
> OK  

### [observer.test.c](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/test/observer.test.c)

This script tests the functionality of the `observer` component in the Observer design pattern. It includes tests to verify that the `update` function is not null, that the `attach` function correctly increases the observer count and adds the observer to the observers array, that the `detach` function correctly decreases the observer count, and that the `update` function doesn't crash when called.
> 5 Tests 0 Failures 0 Ignored  
> OK  

## 📜 [Src file](https://github.com/DIEGOVZK/observer-design-pattern-in-c/tree/main/src)

The [`main.c`](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/src/main.c) file is the entry point of the application. It demonstrates the Observer design pattern using a word counter as an example. Here's what it does:

1. It creates two `ConcreteObserver` instances, `observer1` and `observer2`, and a `ConcreteSubject` instance, `subject`.

2. It attaches `observer1` and `observer2` to `subject`.

3. It defines a sentence, which is a text snippet from the [Bee Movie Script](https://gist.github.com/MattIPv4/045239bc27b16b2bcf7a3a9a4648c08a).

4. It calls the `countWords` function with `subject` and the sentence as arguments. This function counts the total words, even length words, and words that start with a capital letter in the sentence, and notifies the observers of the counts.

5. It detaches `observer1` and `observer2` from `subject`.

Note that since two observers are attached to the subject, the output is printed twice:

> Observer received event: Total words: 126, Even length words: 59, Capital start words: 32  
> Observer received event: Total words: 126, Even length words: 59, Capital start words: 32  

## 📚 [Included Header Files](https://github.com/DIEGOVZK/observer-design-pattern-in-c/tree/main/include)

This project includes several header files that define the interfaces and implementations for the Observer design pattern and the word counter. Here's what each header file does:

### [observer/iobserver.h](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/include/observer/iobserver.h)

This header file defines the `IObserver` interface for the Observer design pattern. It includes a function pointer for the `update` method.

### [observer/isubject.h](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/include/observer/isubject.h)

This header file defines the `ISubject` interface for the Observer design pattern. It includes function pointers for the `attach`, `detach`, and `notify` methods.

### [observer/observer.h](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/include/observer/observer.h)

This header file defines the `ConcreteObserver` and `ConcreteSubject` structures for the Observer design pattern. `ConcreteObserver` includes an `IObserver` and a `ConcreteSubject` includes an `ISubject`. It also includes function declarations for `attach`, `detach`, `notify`, and `update`.

### [wordsHandler/wordCounter.h](https://github.com/DIEGOVZK/observer-design-pattern-in-c/blob/main/include/wordsHandler/wordCounter.h)

This header file defines the `countWords` function that counts the total words, even length words, and words that start with a capital letter in a sentence, and notifies the observers of the counts.