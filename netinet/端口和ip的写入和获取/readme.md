# 字节序
* 字节序分为: 大端字节序和小段字节序
- **Little-endian**: 低字节存储在低地址处，高字节存储在高地址处。例如，`num` 的值为 `1` 时，在内存中表示为 `01 00 00 00`。
- **Big-endian**: 高字节存储在低地址处，低字节存储在高地址处。例如，`num` 的值为 `1` 时，在内存中表示为 `00 00 00 01`。

## 网络字节序和主机字节序
主机字节序：即机器字节序，x86为小端字节序
网络字节序：大端字节序

## 将字符串中的数字转为int类型 高级：strtol
int atoi(const char *str);
可以将命令行参数(const char*)字符串中的数字转为int ./myprogram 127.0.0.1 8080
## 主机字节序转网络字节序列
htons将16位主机字节序转为网络字节序
htonl将32位的主机字节序转为网络字节序
### 对应的逆操作
- **`ntohs`**（Network To Host Short）：将网络字节序的 16 位数据转换为主机字节序。
- **`ntohl`**（Network To Host Long）：将网络字节序的 32 位数据转换为主机字节序。

## 点分十进制转网络字节序
int inet_aton(const char *cp, struct in_addr *addr);
### 对应的逆向操作
char *inet_ntoa(struct in_addr in);


### 应用
**写入端口号和ip**
```cpp
struct sockaddr_in addr;
addr.sin_port  = htons(atoi(argv[2]))
int exchange = inet_aton(argv[1], &addr.sin_addr);
//等效addr.sin_addr.s_addr = inet_addr(argv[1]);
inet_addr 被认为是过时的或不推荐的，因为它的错误处理不够严格。为了更安全的转换，通常推荐使用 inet_aton 或 inet_pton。这些函数能更好地处理无效输入。
if(exchange == 0)
{
    printf("error inet_aton\n");
    exit(EXIT_FAILURE);
}
```
### 对应的逆向操作
**获取ip和端口号**
```cpp
getpeername(fd, (struct sockaddr*)&addr, &size);
	std::cout << "fd:" <<fd
			  << ", ip:"<< inet_ntoa(addr.sin_addr) 
			  << ", PORT: " << ntohs(addr.sin_port) << std::endl;
```









