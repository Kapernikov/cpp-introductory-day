# cpp-introductory-day-exercises
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
