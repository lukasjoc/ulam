def tokenize(source):
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
    window_size = 7
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
        windows.append(window)
        window = ""
    return windows

toks = tokenize("./smol2.c")
for tok in toks: print(tok)
