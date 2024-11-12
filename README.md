# Cursed Luna
A simple game made with C++, Nodepp and raylib

## Dependencies
```bash
📌Nodepp: https://github.com/NodeppOficial/nodepp-wasm
📌Raylib: https://www.raylib.com/
```

## Preview
[Preview](https://github.com/user-attachments/assets/b09a8798-3dba-4e7b-9996-79415deead11)

## Build & Use
```bash
em++ -o www/index.html main.cpp                        \
     -I./include -L./lib -lraylib -lwebsocket.js       \
     -s WEBSOCKET_SUBPROTOCOL=1 -s WEBSOCKET_URL=1     \
     -s ASYNCIFY=1 -s FETCH=1 -s WASM=1                \
     -s USE_GLFW=3 -s USE_PTHREADS=1                   \
     -s ERROR_ON_UNDEFINED_SYMBOLS=0                   \
     --embed-file ./assets/sprites/effect/prop.png     \
     --embed-file ./assets/sprites/effect/bala.png     \
     --embed-file ./assets/sprites/effect/items.png    \
     --embed-file ./assets/sprites/player/player.png   \
     --embed-file ./assets/sprites/enemy/estados.png   \
     --embed-file ./assets/sprites/effect/recharge.png \
     --embed-file ./assets/sprites/effect/selector.png \

g++ -o server server.cpp -lssl -lcrypto ; ./server
```
