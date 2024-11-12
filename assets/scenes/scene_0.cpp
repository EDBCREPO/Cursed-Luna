#pragma once

#include "../script/player.cpp"
#include "../script/enemy.cpp"
#include "../script/item.cpp"
#include "../script/gui.cpp"

namespace rl { namespace scene {

    void scene_0( ptr_t<Scene> self ) {

        struct NODE {
            bool       x = false;
            Vector2  pos = { 0, 0 };
        };  ptr_t<NODE> obj = new NODE();

        self->AppendItem( "enemy",  rl::game::enemy  );
        self->AppendItem( "item",   rl::game::item   );
        self->AppendItem( "player", rl::game::player );
        self->AppendItem( "gui",    rl::game::gui    );

        self->onLoop([=]( float delta ){ 
            obj->pos = GetMousePosition(); 
        });

        self->onDraw([=](){
            ClearBackground( Color({ 69, 2, 41, 255 }) );
            if( obj->x ){
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

    }

}}