# cpp-introductory-day-exercises
[![pipeline status](https://gitlab.com/Kapernikov/Intern/cpp-introductory-day-exercises/badges/master/pipeline.svg)](https://gitlab.com/Kapernikov/Intern/cpp-introductory-day-exercises/commits/master)

Public repository containing all public sources for the Kapernikov C++ introductory day.

## Build
### Windows
```Bash
cmake -G Ninja -H. -Bbuild -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=install -DSFML_DIR=<path to sfml>\lib\cmake\SFML
ninja install
```

### Linux
```Bash
cmake -G Ninja -H. -Bbuild -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=install
ninja install
```
