function compd {
  g++ -std=c++17 -Wall -Wextra -Wshadow -O2 -pedantic -Wno-sign-conversion -fsanitize=address -fsanitize=undefined -DLOCAL -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -o $1{,.cpp}
}
