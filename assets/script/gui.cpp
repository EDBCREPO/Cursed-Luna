#pragma once

/*────────────────────────────────────────────────────────────────────────────*/

namespace rl { namespace game {

    void gui_aim( ptr_t<Item> self ) {

        struct NODE {
            Vector2 pos = { 0, 0 };
            bool      b = false; 
        };  ptr_t<NODE> obj = new NODE(); 
        
        DisableCursor();

        self->onDraw([=](){
            if( obj->b ){
                DrawRectangleV( obj->pos + Vector2({ 0, 5 }), { 1, 5 }, WHITE );
                DrawRectangleV( obj->pos + Vector2({ 0,-9 }), { 1, 5 }, WHITE );
                DrawRectangleV( obj->pos + Vector2({ 5, 0 }), { 5, 1 }, WHITE );
                DrawRectangleV( obj->pos + Vector2({-9, 0 }), { 5, 1 }, WHITE );
                DrawRectangleV( obj->pos, { 1, 1 }, WHITE );
            } else {
                DrawRectangleV( obj->pos + Vector2({ 0, 3 }), { 1, 5 }, WHITE );
                DrawRectangleV( obj->pos + Vector2({ 0,-7 }), { 1, 5 }, WHITE );
                DrawRectangleV( obj->pos + Vector2({ 3, 0 }), { 5, 1 }, WHITE );
                DrawRectangleV( obj->pos + Vector2({-7, 0 }), { 5, 1 }, WHITE );
            }
        });

        self->onLoop([=]( float delta ){[=](){
            obj->pos = GetMousePosition();
        coStart
            obj->b =! obj->b;
            coDelay( 150 );
        coStop
        }();});

    }

}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace rl { namespace game {

    void enemy_stats( ptr_t<Item> self, ptr_t<Item> gui ){

        auto sht = GetScene(). GetItem("enemy").GetAttr("getHealth").as<function_t<float>>();
        float  h = GetRenderHeight(), w = GetRenderWidth();

        gui->onDraw([=](){

            DrawRectangleLines( 8*w/100, 4*h/100, 84*w/100, 4*h/100, WHITE );
            DrawRectangle( 10*w/100, 3*h/100, 80*w/100, 3*h/100,  Color({ 69, 2, 41, 255 }) );
            DrawRectangleLines( 10*w/100, 3*h/100, 80*w/100, 3*h/100, WHITE );
            DrawRectangle( 10*w/100, 3*h/100, 80*w/100*sht(), 3*h/100, WHITE );

        });

    }

}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace rl { namespace game {

    void player_stats( ptr_t<Item> self, ptr_t<Item> gui ){

        auto stt = GetScene().GetItem("player").GetAttr("getState").as<function_t<int*>>();
        auto def = GetScene().GetItem("player").GetAttr("getDeflt").as<function_t<int*>>();
        float  h = GetRenderHeight(), w = GetRenderWidth();

        struct NODE {
           Texture img = GetAttr("Assets").as<array_t<Texture>>()[3];
           uint  frame = 0;
        }; ptr_t<NODE> obj = new NODE();

        gui->onDraw([=](){

            DrawRectangleLines( 2*w/100, 86*h/100, w/13, w/13, WHITE );
            DrawRectangle( 2*w/100+2, 86*h/100+2, w/13, w/13, BLACK );
            DrawRectangleLines( 2*w/100+4, 86*h/100+4, w/13-4, w/13-4, WHITE );

            DrawTexturePro( obj->img, { 64*1.0f*obj->frame, 0, 64, 64 },
                { 5*w/100+9, 90*h/100+9, w/15, w/15 },
                { (w/15)/2, (w/15)/2 }, 0, WHITE 
            );
        
        });

        self->onLoop([=]( float delta ){ [=](){
        coStart; coDelay(100);

            obj->frame++; obj->frame %= 2;

        coStop
        }(); });

        gui->onDraw([=](){

            float a = type::cast<float>( stt()[ stt()[5] ] );
            float b = type::cast<float>( stt()[ 0 ] );
            float c = stt()[ 4 ];
            float d = stt()[ 3 ];

            float _a = type::cast<float>( def()[ stt()[5] ] );
            float _b = type::cast<float>( def()[ 0 ] );
            float _c = def()[ 4 ];
            float _d = def()[ 3 ];

            uint x = 0;

            DrawRectangle( 10*w/100, 86*h/100, b*50, 2*h/100, RED );
            DrawRectangleLines( 10*w/100, 86*h/100, _b*50, 2*h/100, RED );

            DrawRectangle( 10*w/100, 89*h/100, a/2, 2*h/100, YELLOW );
            DrawRectangleLines( 10*w/100, 89*h/100, _a/2, 2*h/100, YELLOW );

            x=0; while( x<_d ){ float add = 3 * w / 95 * x; if( d-->0 ){
                DrawRectangle( 10*w/100+add, 95*h/100, 3*w/100, 2*h/100, GRAY );
            } else {
                DrawRectangleLines( 10*w/100+add, 95*h/100, 3*w/100, 2*h/100, GRAY );
            } x++; }

            x=0; while( x<_c ){ float add = 3 * w / 95 * x; if( c-->0 ){
                DrawRectangle( 10*w/100+add, 92*h/100, 3*w/100, 2*h/100, WHITE );
            } else {
                DrawRectangleLines( 10*w/100+add, 92*h/100, 3*w/100, 2*h/100, WHITE );
            } x++; }

        });

    }

}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace rl { namespace game {

    void gui( ptr_t<Item> self ){

        float h = GetRenderHeight(), w = GetRenderWidth();
        Item p_stat( player_stats, self );
        Item e_stat( enemy_stats, self );
        Item aim   ( gui_aim ); 

        self->onDraw([=](){
            DrawRectangleLines( 10, 10, GetRenderWidth()-20.0f, GetRenderHeight()-20.0f, WHITE );
        });

        self->onRemove([=](){ 
            p_stat.close();
            e_stat.close();
            aim.close();
        });

    }

}}

/*────────────────────────────────────────────────────────────────────────────*/