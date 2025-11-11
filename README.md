# **breadlog**

A *tiny lib* that's part of my *"bread libraries"* series.
I probably posted a video about this, *go check it out* plez

## Example

### Advanced

How do you use it, you may ask ? Welp, it's pretty straight forward:
(main.cpp already has a full example)

```cpp
#include "breadlog.hpp"

int main()
{    
    bread::logger::log(bread::logger::logLevel::Success,"Test","main","main.cpp",5);

    return 0;
}
```

**log()** uses the following parameters:
[logLevel], [text message], [function name], [file name], [line]

### Simple

*-Arghh but I don't wanna write all'at each time :(*

Thought of that too:

```cpp
#include "sbreadlog.hpp"

int main()
{
    LOG_SUCCESS("Test");

    return 0;
}
```

**LOG_(log level)()** is basically the same as *log()* but it gets almost all of the parameters automatically (function name, file name, line)

That's pretty much it- oh, one more thing: you can change the colors of the log levels in **"./include/breadlog/cfg.hpp"**

## Build
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
```
