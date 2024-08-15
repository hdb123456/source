这个 C 程序通过检查变量 `num` 在内存中的存储方式，来判断系统是小端（Little-endian）还是大端（Big-endian）字节序。以下是详细的解释：

### 1. 程序结构

```c
#include <stdio.h>

int main() {
    unsigned int num = 1;
    char *byte = (char*)&num;

    if (*byte) {
        printf("Little-endian\n");
    } else {
        printf("Big-endian\n");
    }

    return 0;
}
```

### 2. 关键部分解释

#### `unsigned int num = 1;`

- 定义了一个无符号整数 `num` 并将其赋值为 `1`。无符号整数在内存中通常占用 4 个字节。

#### `char *byte = (char*)&num;`

- `&num` 获取变量 `num` 的内存地址。
- 通过 `(char*)&num` 将 `num` 的地址强制转换为 `char*` 类型，这意味着我们现在可以通过 `byte` 指针按字节访问 `num` 的内存内容。

#### `if (*byte)`

- `*byte` 访问 `num` 的第一个字节（即内存中存储 `num` 的最低地址处的字节）。
- 如果 `*byte` 的值为 `1`，表示系统是小端字节序；否则表示系统是大端字节序。

### 3. 字节序（Endianness）概念

- **Little-endian**: 低字节存储在低地址处，高字节存储在高地址处。例如，`num` 的值为 `1` 时，在内存中表示为 `01 00 00 00`。
- **Big-endian**: 高字节存储在低地址处，低字节存储在高地址处。例如，`num` 的值为 `1` 时，在内存中表示为 `00 00 00 01`。

### 4. 判断逻辑

- 如果 `num` 的第一个字节（最低地址处）是 `1`，则说明系统是 **Little-endian**，因为 `1` 被存储在最低地址处。
- 如果第一个字节不是 `1`，而是在最高地址处，则说明系统是 **Big-endian**。

### 5. 输出

- 程序将输出 "Little-endian" 或 "Big-endian"，以指示当前系统的字节序。

在大多数现代计算机（如基于 x86 架构的计算机）上，这个程序会输出 "Little-endian"。
