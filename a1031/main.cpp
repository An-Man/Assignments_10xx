#include <iostream>
#include <new>
#include <vector>
#include <limits>
#include <cstdint>

template<typename T, std::size_t Mem_ByteSize>
struct Allocator
{
    using value_type = T;
    using pointer = T*;
    using size_type = uint8_t;

    Allocator() = default;

    pointer allocate(size_type n) {

        T* ptr = new (block) T();
        return ptr;
    }

    void deallocate(pointer p) noexcept {
        p->~T();
    }

    private:
        static inline uint8_t block [Mem_ByteSize];
};

int main() {

Allocator<uint8_t, 3> a;

uint8_t* ptr = a.allocate(3); // works

std::vector<int, Allocator<int, 3>> x; // rebind problem or smt, won't compile
    
}