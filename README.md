# Build
Start the docker container environment. Run the build.sh scripts.

```
./sdl3/build.sh
./sfml3/build.sh
```

# Run
SCP the .exe output and supporting .dll files to a windows machine.

```
sdl3/build/hello.exe
sdl3/build/SDL3.dll

sfml3/build/bin/main.exe
sfml3/build/bin/libstdc++-6.dll
sfml3/build/bin/libgcc_s_seh-1.dll
```