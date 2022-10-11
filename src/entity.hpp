#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
public:
    Entity(char symbol, int row_0, int col_0);
    void pos(int row_0, int col_0);  // Change the character's position

    char symbol();
    int row();
    int col();

private:
  int _row;     // Current y position
  int _col;     // Current x position
  char _symbol; // ASCII representation of the Entity
};

#endif // ENTITY_HPP
