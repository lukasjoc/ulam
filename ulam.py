def next_iteration(data, pos, row_size, val, dist, debug=False):
    # right
    if debug:
        print("A=", pos+1)
    if pos+1 >= len(data):
        return data, pos, row_size, val, dist
    if data[pos+1] != 0:
        dist += 1
    if data[pos+1] != 0:
        raise ValueError("cannot go right")
    for _ in range(dist):
        val += 1
        data[pos+1] = val
        pos = pos+1

    # up
    if data[pos-row_size] != 0:
        dist += 1
    if pos+1 >= len(data):
        return data, pos, row_size, val, dist
    if data[pos-row_size] != 0:
        val += 1
        data[pos+1] = val
        pos = pos+1
    for _ in range(dist):
        val += 1
        data[pos-row_size] = val
        pos = pos-row_size

    # left
    if data[pos-1] != 0:
        dist += 1
    if pos-1 >= len(data):
        return data, pos, row_size, val, dist
    if data[pos-1] != 0:
        raise ValueError("cannot go left")
    for _ in range(dist):
        val += 1
        data[pos-1] = val
        pos = pos-1

    # down
    if data[pos+row_size] != 0:
        dist += 1
    if pos+row_size >= len(data):
        return data, pos, row_size, val, dist
    if data[pos+row_size] != 0:
        val += 1
        data[pos-1] = val
        pos = pos - 1
    for _ in range(dist):
        val += 1
        data[pos+row_size] = val
        pos = pos+row_size

    if debug:
        print("D=", dist)
    if debug:
        print_spiral(data, row_size)
    return data, pos, row_size, val, dist


def create_spiral(row_size):
    if row_size % 2 == 0:
        raise ValueError("pick an odd number")
    cap = row_size ** 2
    data = [0] * cap
    val = 1
    pos = cap//2
    data[pos] = val
    dist = 1
    while True:
        if val >= cap:
            break
        data, pos, row_size, val, dist = next_iteration(
            data, pos, row_size, val, dist)
    return data

def prime(n):
    if n <= 1: return False
    for i in range(2, (n//2)+1):
        if n%i==0: return False
    return True
    # return n>1 and all(n%i for i in range(2, int(n**.5)+1))

def print_spiral(sp, row_size):
    for pos in range(len(sp)):
        if (pos % row_size) == 0:
            print()
        p = prime(sp[pos])
        if p:
            print(str(sp[pos]).rjust(len(str(row_size**2))), end=" ")
            # f"\x1B[5m{str(sp[pos]).rjust(len(str(r**2)))}\x1B[25m", end=" ")
        else:
            print(str().rjust(len(str(row_size**2))), end=" ")
    print()


def print_spiral_box(sp, row_size):
    for pos in range(len(sp)):
        if (pos % row_size) == 0:
            print()
        p = prime(sp[pos])
        if p:
            print(".", end=" ")
        else:
            print(" ", end=" ")
    print()


def tokenize(source, window_size=7):
    import clang.cindex as clang
    COMMENT = clang.TokenKind.COMMENT
    IDENT = clang.TokenKind.IDENTIFIER
    KEYWORD = clang.TokenKind.KEYWORD
    clang.Config.set_library_file("/usr/lib/llvm-14/lib/libclang.so.1")
    index = clang.Index.create()
    unit = index.parse(source)
    toks = [tok
            for tok in unit.get_tokens(extent=unit.cursor.extent)
            if tok.kind != COMMENT]
    windows = []
    window = ""
    i = 0
    while i < len(toks):
        if toks[i].kind == IDENT and toks[i-1].kind == KEYWORD:
            window += " "
        window += toks[i].spelling
        if len(window) >= window_size:
            windows.append(window.strip())
            window = ""
        i += 1
    if len(window) != 0:
        windows.append(window.strip())
        window = ""
    return windows

def print_spiral_c(source, sp, row_size):
    toks = tokenize("./smol2.c", window_size=7)
    # print(toks[len(toks)-10:])
    i = 0
    pc = 0
    for pos in range(len(sp)):
        if (pos % row_size) == 0: print("", end="\n"*2)
        p = prime(sp[pos])
        if p:
            pc += 1
            if i+1 > len(toks):
                print(" " * 7, end=" ")
            else:
                tok = toks[i]
                print(toks[i], end=" ")
                i += 1
        else:
            print(" " * 7, end=" ")
    # print(len(toks), pc)
    print()

if __name__ == "__main__":
    import sys
    sp_size = int(sys.argv[1])
    sp = create_spiral(sp_size)
    # print_spiral(sp, sp_size)
    # print_spiral_box(sp, sp_size)
    print_spiral_c("./smol2.c", sp, sp_size)
