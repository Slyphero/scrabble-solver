struct Position {
  unsigned int line;
  unsigned int column;
  Position() : line(0), column(0) {}
  Position(unsigned int l, unsigned int c) : line(l), column(c) {}
};