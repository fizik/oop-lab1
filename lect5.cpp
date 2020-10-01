class TheCollection { // На динамическом массиве
  public:  
    TheCollection();
    TheCollection(const TheCollection&);
    TheCollection(const TheCollection&&);
    ~TheCollection();
    void add(const TheData &obj);
    void del(int pos);
    void del(const TheData &obj);
    TheData &get(int pos);
    void set(int pos, const TheData&);
  private:
    TheData *objects;// Массив объектов
    int count; // Число объектов.
};


class TheCollection { // На динамическом массиве
  public:  
    TheCollection();
    TheCollection(const TheCollection&);
    TheCollection(const TheCollection&&);
    ~TheCollection();
    void add(const TheData &obj);
    void del(int pos);
    void del(const TheData &obj);
    TheData &get(int pos);
    void set(int pos, const TheData&);

    // Или так (лучше). 
  private:
    TheData *objects; // Массив объектов
    int count; // Число объектов.
    int allocated; // Выделено объектов.
    // Выделять, освобождать память долго.
    // Резервируем дополнительную память на  несколько (а не один) объектов.
    void grow(); // Выделяем здесь.
};


// Выберите одно решение из двух.
TheCollection::TheCollection() {
    objects=NULL; 
    count=allocated=0;
}

// В стиле С++98 можно так:
TheCollection::TheCollection() :objects(NULL),count(0),allocated(0) {
}

