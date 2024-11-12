# time g++ -o main main.cpp -I./include -L./lib -lraylib -lssl -lcrypto ; ./main ; exit
if [ ! -f "www" ] ; then
    mkdir www
fi

em++ -o www/index.js main.cpp                        \
     -I./include -L./lib -lraylib -lwebsocket.js       \
     -s WEBSOCKET_SUBPROTOCOL=1 -s WEBSOCKET_URL=1     \
     -s ASYNCIFY=1 -s FETCH=1 -s WASM=1                \
     -s USE_GLFW=3 -s USE_PTHREADS=1                   \
     -s ERROR_ON_UNDEFINED_SYMBOLS=0                   \
     --embed-file ./assets/sprites/effect/prop.png     \
     --embed-file ./assets/sprites/effect/bala.png     \
     --embed-file ./assets/sprites/enemy/enemy.png     \
     --embed-file ./assets/sprites/effect/items.png    \
     --embed-file ./assets/sprites/player/player.png   \
     --embed-file ./assets/sprites/effect/recharge.png \
     --embed-file ./assets/sprites/effect/selector.png \

./server # g++ -o server server.cpp -lssl -lcrypto ; ./server