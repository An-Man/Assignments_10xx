/* Exercise 2

Try "backward-cpp" (cmake instructions found behind the link),
and check how e.g. assert(0) works before and after you've gotten it to work.
(There should be easily notable difference) */

#include "include/backward.hpp"
#include <cassert>

namespace backward {

backward::SignalHandling sh;
}

int main() {

    using namespace backward;
    StackTrace st; st.load_here(32);
    Printer p; p.print(st);
    
    assert(0); // with the backward stacktrace, this prints more information about assert failing
}