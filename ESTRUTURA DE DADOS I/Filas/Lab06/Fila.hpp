#pragma once

class Fila {
    public:
        // destrutor virtual
        virtual ~Fila() {}      

        // funções virtuais puras
        virtual void enqueue(int v) = 0;    
        virtual int dequeue() = 0;
        virtual bool isEmpty() = 0;
        virtual void reset() = 0;
};