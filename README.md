# C HTTP/1.1 Web server (From Scratch)
A lightweight, modular HTTP/1.1 web server built from scratch in C on windows using the Winsock2 API. This is an ongoing, multi-month systems programing project focused on low-level TCP/IP networking, manual memory management, HTTP protocol, and concurrent request handling.
## Roadmap
-[x]**Phase 1:** Core TCP socket list & HTTP/1.1'200 ok' response('main.C')
-[]**Phase 2:**Modular routing &static '.html'/'.css' file serving ('socket.c','http_parser.c', 'router.c')
-[]**Phase 3:**MUlti-threaded worker pool for concurrent connections ('thread_pool.c')
-[]**Phase 4:** In -memory LRU file caching & request logging ('cache.c')
## Build & Run (Windows)
'''Powershell
gcc main.c -o server.ex-lws2_32
.\server. exe
'''
Open 'http://localhost:8080' in your browser to test.
