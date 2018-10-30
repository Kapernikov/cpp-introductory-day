# cpp-introductory-day-exercises
[![pipeline status](https://gitlab.com/Kapernikov/Intern/cpp-introductory-day-exercises/badges/master/pipeline.svg)](https://gitlab.com/Kapernikov/Intern/cpp-introductory-day-exercises/commits/master)

Public repository containing all public sources for the Kapernikov C++ introductory day.

## Build
### Windows
```Bash
cmake -G Ninja -H. -Bbuild -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=install -DENABLE_SOLUTIONS=OFF -DSFML_INCLUDE_DIRS=<path to sfml>\include -DSFML_LIBRARY_DIRS=<path to sfml>\SFML-2.5.0\lib
ninja install
```
_Note:_ Copy the content of the _\<path to sfml\>/bin_ to the _install/bin_ folder

### Linux
```Bash
cmake -G Ninja -H. -Bbuild -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=install
ninja install
```
