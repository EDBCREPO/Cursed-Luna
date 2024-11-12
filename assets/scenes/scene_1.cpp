#pragma once

namespace rl { namespace scene {

    void scene_1( ptr_t<Scene> self ) {

        struct NODE {
            bool       b = false;
            bool       x = false;
            string_t tmp = nullptr;
            Vector2  pos = { 0, 0 };
            string_t msg = "You Have Died";
        };  ptr_t<NODE> obj = new NODE();
        
        float width1 = GetRenderWidth()/2 - MeasureText("Reset",48)/2;
        float width2 = GetRenderWidth()/2 - MeasureText(obj->msg.get(),72)/2;

        self->onLoop([=]( float delta ){ [=](){
        coStart

            while( obj->msg != obj->tmp ){
                obj->tmp.push( obj->msg[ obj->tmp.size() ] );
                coDelay(30);
            }

            if( CheckCollisionPointRec( GetMousePosition(), 
                Rectangle({ width1, 400, 150, 40 }) 
            )){ if( IsMouseButtonPressed(0) ){
                    AppendScene( GetAttr("Scene").as<array_t<function_t<void,ptr_t<Scene>>>>()[0] );
                }    obj->b=1;
            } else { obj->b=0; }

        coStop
        }(); [=](){
        coStart; 
            coDelay(100); obj->x =! obj->x;
        coStop
        }(); obj->pos = GetMousePosition(); });

        self->onDraw([=](){
            ClearBackground( BLACK ); // DrawFPS( 5, 5 );
            DrawText( obj->tmp.get(), width2, 100, 72, WHITE );
            DrawText( "Reset", width1, 400, 48, obj->b? WHITE: ORANGE );
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